--- global.h.orig	2001-01-02 05:49:16.000000000 +1100
+++ global.h	2009-02-22 13:18:18.000000000 +1100
@@ -5,7 +5,7 @@
     copyright            : (C) 2000 by Perdig
     email                : perdig@linuxbr.com.br
 
-    $Id: global.h,v 1.9 2001/01/01 18:49:16 perdig Exp $
+    $Id: global.h,v 1.10 2001/01/11 15:28:03 perdig Exp $
  ***************************************************************************/
 
 /***************************************************************************
@@ -181,10 +181,12 @@
 #define _D_INFO "\x1b[33m"
 #define _D_CRIT "\x1b[31m"
 #define _D_WARN "\x1b[36m"
-#define _D(args...) do { \
-        printf("\x1b[33m" __PRETTY_FUNCTION__ " \x1b[37m[" __FILE__ \
-        ":%d] " _D_INFO, __LINE__); printf (args); printf ("\x1b[0m\n"); \
-        } while (0)
+#define _D(args...) { \
+        printf("\x1b[33m%s \x1b[37m[%s:%d]%s", \
+	__PRETTY_FUNCTION__, __FILE__, __LINE__, _D_INFO); \
+	printf(args); \
+	printf("\x1b[0m\n"); \
+        }
 
 #define ldbg(STR...) { if (DEBUG&4) _D(_D_INFO STR); }
 #define dbg(STR...)  { if (DEBUG&2) _D(_D_WARN STR); }
@@ -213,4 +215,13 @@
 
 #define PLAYABLE
 
+#ifndef USE_SOUND
+#define sound_switch()
+#define sound_stop()
+#define sound_volume(a)
+#define sound_start()
+#define sound_select(a)
+#define sound_load(a)
+#endif
+
 #endif
