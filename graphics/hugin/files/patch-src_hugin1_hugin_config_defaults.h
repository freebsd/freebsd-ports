--- src/hugin1/hugin/config_defaults.h.orig	2008-06-20 17:21:28.000000000 +0300
+++ src/hugin1/hugin/config_defaults.h	2008-06-20 17:22:40.000000000 +0300
@@ -160,8 +160,8 @@
 #define HUGIN_APKOLOR_EXE                     ""
 #define HUGIN_APKOLOR_ARGS                    ""
 
-#define HUGIN_APSIFT_EXE                      "autopano-sift-c"
-#define HUGIN_APSIFT_ARGS                     "--maxmatches %p %o %i"
+#define HUGIN_APSIFT_EXE                      "autopano-complete"
+#define HUGIN_APSIFT_ARGS                     "-o %o -p %p %i"
 #define HUGIN_STITCHER_RUN_EDITOR             0l
 #define HUGIN_STITCHER_EDITOR                 "gimp-remote"
 #define HUGIN_STITCHER_EDITOR_ARGS            "%f"
