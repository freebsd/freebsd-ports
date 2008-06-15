--- src/include/hugin/config_defaults.h.orig	2008-06-15 18:26:33.000000000 +0300
+++ src/include/hugin/config_defaults.h	2008-06-15 18:27:33.000000000 +0300
@@ -150,8 +150,8 @@
 #define HUGIN_APKOLOR_EXE                     ""
 #define HUGIN_APKOLOR_ARGS                    ""
 
-#define HUGIN_APSIFT_EXE                      "autopano-complete.sh"
-#define HUGIN_APSIFT_ARGS                     "--output %o --points %p %i"
+#define HUGIN_APSIFT_EXE                      "autopano-complete"
+#define HUGIN_APSIFT_ARGS                     "-o %o -p %p %i"
 #define HUGIN_STITCHER_RUN_EDITOR             0l
 #define HUGIN_STITCHER_EDITOR                 "gimp-remote"
 #define HUGIN_STITCHER_EDITOR_ARGS            "%f"
