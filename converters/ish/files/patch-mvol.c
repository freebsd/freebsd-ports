--- mvol.c.orig
+++ mvol.c
@@ -4,6 +4,7 @@
 /*    930823    modified (aka)		 */
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <fcntl.h>
 #include <ctype.h>
 #include <string.h>
@@ -25,6 +26,8 @@
 extern char   tname[];
 extern int    delvol;
 
+void restore_done(char *, char *, long);
+
 #define	ID    "ID block for multi volume ish file"
 
 typedef    struct {
@@ -208,6 +211,7 @@
 
 #define    COPY_BUF    1024
 
+void
 restore_done(src, dst,sz)
 char    *src;
 char    *dst;
