--- ../setup2/mow/source/loader/loader.c.orig	Thu Oct 31 21:46:52 2002
+++ ../setup2/mow/source/loader/loader.c	Wed Jan 22 14:56:44 2003
@@ -85,6 +85,12 @@
 # include <sys/statvfs.h>
 #endif
 
+#ifdef FREEBSD
+#if (OSVERSION < 500000)
+#define iswspace(c) ((c)==' ' || (c)=='\t' || (c)=='\n')
+#endif
+#endif
+
 #include "bitmap"
 #include "logo.xpm"
 
@@ -580,6 +580,8 @@
 #define GCC_FILE_PATTERN                    "libgcc_s.so.1"
 #define CPLUS_FILE_PATTERN                  "libstdc++.so.3.0.1"
 #define STL_FILE_PATTERN                    "libstlport_gcc.so"
+#elif defined (FREEBSD)
+#define STL_FILE_PATTERN                    "libstlport_gcc.so"
 #else
 #define STL_FILE_PATTERN                    "libstlport_sunpro.so"
 #endif
@@ -650,6 +656,14 @@
 "    export LD_LIBRARY_PATH\n" \
 "    ;;\n" \
 "  Linux)\n" \
+"    LD_LIBRARY_PATH=.:./lib:$LD_LIBRARY_PATH\n" \
+"    export LD_LIBRARY_PATH\n" \
+"    ;;\n" \
+"  FreeBSD)\n" \
+"    LD_LIBRARY_PATH=.:./lib:$LD_LIBRARY_PATH\n" \
+"    export LD_LIBRARY_PATH\n" \
+"    ;;\n" \
+"  NetBSD)\n" \
 "    LD_LIBRARY_PATH=.:./lib:$LD_LIBRARY_PATH\n" \
 "    export LD_LIBRARY_PATH\n" \
 "    ;;\n" \
