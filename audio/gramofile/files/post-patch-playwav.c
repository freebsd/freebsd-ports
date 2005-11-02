Index: playwav.c
@@ -32,7 +32,7 @@
 #include <curses.h>
 #endif
 
-#define BPLAYCMD "/usr/lib/gramofile/bplay_gramo"
+#define BPLAYCMD "bplay_gramo"
 
 void
 playwav_playit (char *filename, int usebeginendtime, double begintime,
