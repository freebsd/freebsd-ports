--- plugin.cc.orig	Sun Jan 25 16:55:21 2004
+++ plugin.cc	Wed Feb 11 18:51:51 2004
@@ -5,6 +5,9 @@
 #include <string>
 #include <iostream>
 #include <time.h>
+#include <unistd.h>
+#include <fcntl.h>
+#include <limits.h>
 
 #include <xmms/plugin.h>
 #include <xmms/xmmsctrl.h> 
@@ -21,6 +24,7 @@
 
 // Local vars
 static Imms *imms = NULL;
+static int urandom = -1;
 unsigned int time_left = 1000, sloppy_skips = 0;
 int last_plpos = -2, cur_plpos, pl_length = -1;
 int good_length = 0, song_length = 0, delay = 0;
@@ -39,6 +43,15 @@
     FIND_NEXT   = 2
 } state;
 
+// Random
+int imms_random(int max)
+{
+    unsigned long rand_num;
+    (void)read(urandom, &rand_num, sizeof(rand_num));
+    double cof = rand_num / (ULONG_MAX + 1.0);
+    return (int)(max * cof);
+}
+
 // Wrapper that frees memory
 string imms_get_playlist_item(int at)
 {
@@ -62,14 +75,17 @@
 
 void imms_init()
 {
-    if (!imms)
+    if (!imms) {
         imms = new Imms();
+	urandom = open("/dev/urandom", O_RDONLY);
+    }
 
     state = IDLE;
 }
 
 void imms_cleanup(void)
 {
+    close(urandom);
     delete imms;
     imms = 0;
 }
