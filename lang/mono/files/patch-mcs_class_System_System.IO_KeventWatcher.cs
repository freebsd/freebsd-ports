
$FreeBSD$

https://bugzilla.novell.com/show_bug.cgi?id=542485

--- mcs/class/System/System.IO/KeventWatcher.cs.orig
+++ mcs/class/System/System.IO/KeventWatcher.cs
@@ -38,11 +38,11 @@
 namespace System.IO {
 
 	struct kevent : IDisposable {
-		public int ident;
+		public IntPtr ident;
 		public short filter;
 		public ushort flags;
 		public uint fflags;
-		public int data;
+		public IntPtr data;
 		public IntPtr udata;
 
 		public void Dispose ()
@@ -53,8 +53,8 @@
 	}
 
 	struct timespec {
-		public int tv_sec;
-		public int tv_usec;
+		public IntPtr tv_sec;
+		public IntPtr tv_usec;
 	}
 
 	class KeventFileData {
@@ -88,6 +88,31 @@
 		static Thread thread;
 		static int conn;
 		static bool stop;
+
+		/* Flags */
+
+		const int EV_ADD     = 0x0001;	/* add event to kq (implies enable) */
+		const int EV_DELETE  = 0x0002;	/* delete event from kq */
+		const int EV_ENABLE  = 0x0004;	/* enable event */
+		const int EV_DISABLE = 0x0008;	/* disable event (not reported) */
+		const int EV_ONESHOT = 0x0010;	/* only report one occurrence */
+		const int EV_CLEAR   = 0x0020;	/* clear event state after reporting */
+		const int EV_EOF     = 0x8000;	/* EOF detected */
+		const int EV_ERROR   = 0x4000;	/* error, data contains errno */
+
+		/* System defined filters */
+		const int EVFILT_READ  = -1;
+		const int EVFILT_VNODE = -4;	/* attached to vnodes */
+
+		/* Events */
+
+		const int NOTE_DELETE = 0x0001;	/* vnode was removed */
+		const int NOTE_WRITE  = 0x0002;	/* data contents changed */
+		const int NOTE_EXTEND = 0x0004;	/* size increased */
+		const int NOTE_ATTRIB = 0x0008;	/* attributes changed */
+		const int NOTE_LINK   = 0x0010;	/* link count changed */
+		const int NOTE_RENAME = 0x0020;	/* vnode was renamed */
+		const int NOTE_REVOKE = 0x0040;	/* vnode access was revoked */
 		
 		private KeventWatcher ()
 		{
@@ -142,9 +167,9 @@
 
 				data.Enabled = true;
 				lock (this) {
+					stop = false;
 					StartMonitoringDirectory (data);
 					watches [fsw] = data;
-					stop = false;
 				}
 			}
 		}
@@ -162,20 +187,23 @@
 			kevent ev = new kevent();
 			ev.udata = IntPtr.Zero;
 			timespec nullts = new timespec();
-			nullts.tv_sec = 0;
-			nullts.tv_usec = 0;
+			nullts.tv_sec = IntPtr.Zero;
+			nullts.tv_usec = IntPtr.Zero;
 			if (fd > 0) {
-				ev.ident = fd;
-				ev.filter = -4;
-				ev.flags = 1 | 4 | 20;
-				ev.fflags = 20 | 2 | 1 | 8;
-				ev.data = 0;
+				ev.ident = (IntPtr)fd;
+				ev.filter = EVFILT_VNODE;
+				ev.flags = EV_ADD | EV_ENABLE | EV_CLEAR;
+				ev.fflags = NOTE_RENAME | NOTE_WRITE | NOTE_DELETE | NOTE_ATTRIB;
+				ev.data = IntPtr.Zero;
 				ev.udata = Marshal.StringToHGlobalAuto (data.Directory);
 				kevent outev = new kevent();
 				outev.udata = IntPtr.Zero;
-				kevent (conn, ref ev, 1, ref outev, 0, ref nullts);
+				int ret = kevent (conn, ref ev, 1, ref outev, 0, ref nullts);
+				if ((ret == -1) || ((ev.flags & EV_ERROR) > 0)) {
+					return;
+				}
 				data.ev = ev;
-				requests [fd] = data;
+				requests [(IntPtr)fd] = data;
 			}
 			
 			if (!data.IncludeSubdirs)
@@ -204,31 +232,35 @@
 
 		static void StopMonitoringDirectory (KeventData data)
 		{
-			close(data.ev.ident);
+			close((int)(data.ev.ident));
 		}
 
 		void Monitor ()
 		{
-		
+
 			while (!stop) {
 				kevent ev = new kevent();
 				ev.udata = IntPtr.Zero;
 				kevent nullev = new kevent();
 				nullev.udata = IntPtr.Zero;
 				timespec ts = new timespec();
-				ts.tv_sec = 0;
-				ts.tv_usec = 0;
+				ts.tv_sec = IntPtr.Zero;
+				ts.tv_usec = IntPtr.Zero;
 				int haveEvents;
 				lock (this) {
 					haveEvents = kevent (conn, ref nullev, 0, ref ev, 1, ref ts);
 				}
 
-				if (haveEvents > 0) {
-					// Restart monitoring
-					KeventData data = (KeventData) requests [ev.ident];
-					StopMonitoringDirectory (data);
-					StartMonitoringDirectory (data);
-					ProcessEvent (ev);
+				if (haveEvents != 0) {
+					if ((haveEvents == -1) || ((ev.flags & EV_ERROR) > 0)) {
+						Error ();
+					} else {
+						// Restart monitoring
+						KeventData data = (KeventData) requests [(IntPtr)(ev.ident)];
+						StopMonitoringDirectory (data);
+						StartMonitoringDirectory (data);
+						ProcessEvent (ev);
+					}
 				} else {
 					System.Threading.Thread.Sleep (500);
 				}
@@ -240,10 +272,18 @@
 			}
 		}
 
+		void Error ()
+		{
+			// Something went wrong. Stop the thread.
+			lock (this) {
+				stop = true;
+			}
+		}
+
 		void ProcessEvent (kevent ev)
 		{
 			lock (this) {
-				KeventData data = (KeventData) requests [ev.ident];
+				KeventData data = (KeventData) requests [(IntPtr)(ev.ident)];
 				if (!data.Enabled)
 					return;
 
@@ -265,7 +305,7 @@
 								data.DirEntries [fsi.FullName] = new KeventFileData(fsi, fsi.LastAccessTime, fsi.LastWriteTime);
 								if (fsw.IncludeSubdirectories && fsi is DirectoryInfo) {
 									data.Directory = filename;
-									requests [ev.ident] = data;
+									requests [(IntPtr)(ev.ident)] = data;
 									ProcessEvent(ev);
 								}
 								PostEvent(filename, fsw, fa, changedFsi);
@@ -348,10 +388,10 @@
 		[DllImport ("libc")]
 		extern static int close(int fd);
 
-		[DllImport ("libc")]
+		[DllImport ("libc", SetLastError=true)]
 		extern static int kqueue();
 
-		[DllImport ("libc")]
+		[DllImport ("libc", SetLastError=true)]
 		extern static int kevent(int kqueue, ref kevent ev, int nchanges, ref kevent evtlist,  int nevents, ref timespec ts);
 	}
 }
