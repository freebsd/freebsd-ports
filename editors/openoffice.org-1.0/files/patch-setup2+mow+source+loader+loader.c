--- setup2/mow/source/loader/loader.c.orig	Thu Oct 31 21:46:52 2002
+++ setup2/mow/source/loader/loader.c	Wed Jan 22 14:56:44 2003
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
