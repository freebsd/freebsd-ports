--- Tomboy/Utils.cs.orig	Tue Oct 17 18:50:40 2006
+++ Tomboy/Utils.cs	Thu Aug 10 09:12:49 2006
@@ -767,24 +767,9 @@
 			RegisterSignalHandlers ();
 		}
 
-		[DllImport("libc")]
-		private static extern int prctl (int option, 
-						 byte [] arg2, 
-						 IntPtr arg3, 
-						 IntPtr arg4, 
-						 IntPtr arg5);
-
 		// From Banshee: Banshee.Base/Utilities.cs
 		public static void SetProcessName (string name)
 		{
-			if (prctl (15 /* PR_SET_NAME */, 
-				   Encoding.ASCII.GetBytes (name + "\0"),
-				   IntPtr.Zero, 
-				   IntPtr.Zero, 
-				   IntPtr.Zero) != 0)
-				throw new ApplicationException (
-					"Error setting process name: " +
-					Mono.Unix.Native.Stdlib.GetLastError ());
 		}
 
 		static void RegisterSignalHandlers ()
