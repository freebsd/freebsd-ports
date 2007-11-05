--- lib/fsplib/fsplib.h.orig	2005-01-19 03:04:02.000000000 +0100
+++ lib/fsplib/fsplib.h	2007-11-05 16:37:32.000000000 +0100
@@ -1,6 +1,8 @@
 #ifndef _FSPLIB_H
 #define _FSPLIB_H 1
 #include <time.h>
+#include <stddef.h>
+
 /* The FSP v2 protocol support library - public interface */
 
 /*
@@ -138,6 +140,12 @@
 		      unsigned int pos;          /* position of next packet */
 } FSP_FILE;
 
+
+typedef union dirent_workaround {
+      struct dirent dirent;
+      char fill[offsetof (struct dirent, d_name) + MAXNAMLEN + 1];
+} dirent_workaround;
+ 
 /* function prototypes */
 
 /* session management */
