--- SeDecl.h.orig	Sat Nov  8 08:56:16 1997
+++ SeDecl.h	Sat Nov  8 10:53:12 1997
@@ -56,7 +56,9 @@
 extern FILE    *open_file(),
                *open_file_va();
 extern void     send_break(),
-                usleep(),
+		#if !defined(__FreeBSD__) || (__FreeBSD__ < 3)
+                	usleep(),
+		#endif
                 show(),
                 showf(),
                 SeyonMessage(),
