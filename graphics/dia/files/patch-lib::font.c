
$FreeBSD$

--- lib/font.c	2002/06/03 08:27:47	1.1
+++ lib/font.c	2002/06/03 08:34:08
@@ -467,7 +467,8 @@
 
 char *last_resort_fonts[] = {
   "-adobe-courier-medium-r-normal-*-%d-*-*-*-*-*-*-*",
-#ifndef G_OS_WIN32
+  "-*-courier-medium-r-normal-*-%d-*-*-*-*-*-*-*",
+#ifdef G_OS_WIN32
   "system" /* Must be last. This is guaranteed to exist on a MS-Windows 
               system. */
 #else
