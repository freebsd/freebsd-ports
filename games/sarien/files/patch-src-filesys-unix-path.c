--- src/filesys/unix/path.c.orig	Sun Aug  5 01:59:48 2001
+++ src/filesys/unix/path.c	Thu May 27 15:11:02 2004
@@ -46,6 +46,6 @@
 #endif
 #endif
 
-	return "/etc/sarien.conf";
+	return "%%PREFIX%%/etc/sarien.conf";
 }
 
