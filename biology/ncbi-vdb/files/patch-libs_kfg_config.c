--- libs/kfg/config.c.orig	2021-03-15 18:16:43 UTC
+++ libs/kfg/config.c
@@ -2577,7 +2577,7 @@ bool load_from_std_location ( KConfig *self, const KDi
     const char * std_locs [] =
     {
 #if ! WINDOWS
-        "/etc/ncbi",
+        @@PREFIX@@ "/etc/ncbi",
 #else
         "/c/ncbi",
 #endif
@@ -2850,6 +2850,8 @@ void add_predefined_nodes ( KConfig * self, const char
     #define OS "win"
 #elif SUN
     #define OS "sun"
+#elif BSD
+    #define OS "bsd"
 #else
     #error unrecognized OS
 #endif
