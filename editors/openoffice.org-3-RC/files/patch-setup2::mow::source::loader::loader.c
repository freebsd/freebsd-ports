--- ../setup2/mow/source/loader/loader.c.orig	Sun Mar  3 01:41:47 2002
+++ ../setup2/mow/source/loader/loader.c	Sun Mar  3 01:42:19 2002
@@ -603,6 +603,14 @@
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
