$FreeBSD$

--- wmfortune.c.orig	Thu May 16 11:01:43 2002
+++ wmfortune.c	Thu May 16 11:02:18 2002
@@ -21,7 +21,7 @@
  *
  */
 #define BUFF_SIZE 1024
-#define SCROLL_DEFAULT_SPEED 1000
+#define SCROLL_DEFAULT_SPEED 10000
 
 #include <unistd.h>
 #include <stdio.h>
@@ -110,7 +110,7 @@
 
 static DAProgramOption options[] = {
   {"-d", "--displayname", "display to use.", DOString, False, {&displayName}},
-  {"-s", "--speed", "scrolling speed. (default 1000 dot/ms)", DOInteger, False, {&speed}},
+  {"-s", "--speed", "scrolling speed. (default 10000 dot/ms)", DOInteger, False, {&speed}},
 };
 
 static void
