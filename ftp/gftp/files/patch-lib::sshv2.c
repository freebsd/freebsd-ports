--- lib/sshv2.c.orig	Sat Nov 23 15:34:25 2002
+++ lib/sshv2.c	Thu Apr 24 21:57:04 2003
@@ -543,8 +543,13 @@
   if (request->sftpserv_path == NULL ||
       *request->sftpserv_path == '\0')
     {
+#ifdef __FreeBSD__
+      p1 = "/usr/libexec";
+      p2 = '/';
+#else
       p1 = "";
       p2 = ' ';
+#endif
     }
   else
     {
@@ -570,6 +575,15 @@
   else
     {
       s[0] = s[1] = 0;
+#ifdef __FreeBSD__
+      if( openpty( &fdm, &fds, &pts_name, NULL, NULL ) < 0 )
+        {
+          request->logging_function (gftp_logging_error, request->user_data,
+        	                 _("Cannot create a socket pair: %s\n"),
+                                 g_strerror (errno));
+          return (-2);
+	}
+#else
       if ((fdm = ptym_open (pts_name)) < 0)
         {
           request->logging_function (gftp_logging_error, request->user_data,
@@ -577,6 +591,7 @@
                                 g_strerror (errno));
           return (-2);
         }
+#endif
     }
  
   if ((child = fork ()) == 0)
@@ -589,6 +604,13 @@
         }
       else
         {
+#ifdef __FreeBSD__
+          close (fdm);
+          if( ioctl( fds, TIOCSCTTY, NULL ) < 0 )
+            {
+              return( -2 );
+            }
+#else
           if ((fds = ptys_open (fdm, pts_name)) < 0)
             {
               printf ("Cannot open slave pts %s: %s\n", pts_name, 
@@ -596,6 +618,7 @@
               return (-1);
             }
           close (fdm);
+#endif
         }
 
       tty_raw (fds);
