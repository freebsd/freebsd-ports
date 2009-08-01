--- biewlib/sysdep/generic/unix/keyboard.c.orig	2009-01-31 17:11:34.000000000 +0600
+++ biewlib/sysdep/generic/unix/keyboard.c	2009-03-18 04:11:03.000000000 +0600
@@ -59,6 +59,9 @@
 unsigned rawkb_mode=0;
 int rawkb_escape;
 
+static void *nls_handle;
+static int is_unicode=0;
+
 #ifdef	_VT100_
 
 #include <fcntl.h>
@@ -75,9 +78,6 @@
 static int in_fd;
 static struct termios sattr;
 
-static void *nls_handle;
-static int is_unicode=0;
-
 typedef struct {
     char c;
     int key;
