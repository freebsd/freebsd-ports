Index: server/change.c
===================================================================
RCS file: /home/wine/wine/server/change.c,v
retrieving revision 1.32
diff -u -3 -p -r1.32 change.c
--- change.c	30 Jan 2006 18:46:00 -0000	1.32
+++ change.c	3 Feb 2006 21:12:14 -0000
@@ -406,6 +406,7 @@ static void inotify_do_change_notify( st
 
 static void inotify_poll_event( struct fd *fd, int event )
 {
+#ifdef linux
     int r, ofs, unix_fd;
     char buffer[0x1000];
     struct inotify_event *ie;
@@ -427,6 +428,7 @@ static void inotify_poll_event( struct f
         inotify_do_change_notify( dir );
         ofs += (sizeof (*ie) + ie->len - 1);
     }
+#endif
 }
 
 static int inotify_get_info( struct fd *fd )
@@ -436,6 +438,7 @@ static int inotify_get_info( struct fd *
 
 static void inotify_adjust_changes( struct dir *dir )
 {
+#ifdef linux
     int filter = dir->filter;
     unsigned int mask = 0;
     char link[32];
@@ -461,6 +464,7 @@ static void inotify_adjust_changes( stru
     dir->wd = inotify_add_watch( get_unix_fd( dir->inotify_fd ), link, mask );
     if (dir->wd != -1)
         set_fd_events( dir->inotify_fd, POLLIN );
+#endif
 }
 
 static struct fd *create_inotify_fd( struct dir *dir )
