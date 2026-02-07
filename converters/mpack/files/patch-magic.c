--- magic.c.orig	2003-07-21 16:35:31.000000000 -0400
+++ magic.c	2011-02-17 15:17:14.374973627 -0500
@@ -23,6 +23,7 @@
  * SOFTWARE.
  */
 #include <stdio.h>
+#include <string.h>
 
 /* Description of the various file formats and their magic numbers */
 struct magic {
@@ -35,6 +36,7 @@
 static struct magic magic[] = {
     { "image/gif", "GIF", 0 },
     { "image/jpeg", "\377\330\377", 0 },
+    { "image/png", "\211PNG", 0 },
     { "video/mpeg", "\0\0\001\263", 4 },
     { "application/postscript", "%!", 0 },
 };
