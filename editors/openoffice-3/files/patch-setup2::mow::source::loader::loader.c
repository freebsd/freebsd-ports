--- ../setup2/mow/source/loader/loader.c.orig	Thu Dec 13 17:44:58 2001
+++ ../setup2/mow/source/loader/loader.c	Wed Apr  3 01:07:58 2002
@@ -615,6 +615,14 @@
 "    LD_LIBRARY_PATH=.:./lib:$LD_LIBRARY_PATH\n" \
 "    export LD_LIBRARY_PATH\n" \
 "    ;;\n" \
+"  FreeBSD)\n" \
+"    LD_LIBRARY_PATH=.:./lib:$LD_LIBRARY_PATH\n" \
+"    export LD_LIBRARY_PATH\n" \
+"    ;;\n" \
+"  NetBSD)\n" \
+"    LD_LIBRARY_PATH=.:./lib:$LD_LIBRARY_PATH\n" \
+"    export LD_LIBRARY_PATH\n" \
+"    ;;\n" \
 "      *)\n" \
 "    ;;\n" \
 "esac\n" \
