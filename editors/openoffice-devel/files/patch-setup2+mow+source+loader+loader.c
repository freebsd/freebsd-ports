--- ../setup2/mow/source/loader/loader.c.orig	Sun Mar 30 23:14:14 2003
+++ ../setup2/mow/source/loader/loader.c	Sun Mar 30 23:14:50 2003
@@ -580,6 +580,8 @@
 #define GCC_FILE_PATTERN                    "libgcc_s.so.1"
 #define CPLUS_FILE_PATTERN                  "libstdc++.so.3.0.1"
 #define STL_FILE_PATTERN                    "libstlport_gcc.so"
+#elif defined (FREEBSD)
+#define STL_FILE_PATTERN                    "libstlport_gcc.so"
 #else
 #define STL_FILE_PATTERN                    "libstlport_sunpro.so"
 #endif
