--- common/tty/terminals.c.orig	2011-09-21 06:29:53.000000000 +0000
+++ common/tty/terminals.c
@@ -236,7 +236,9 @@ allocate_pty_desc (pty_desc **desc) {
 #ifndef NLDLY
 #define NLDLY 0
 #define CRDLY 0
+#ifndef TABDLY
 #define TABDLY 0
+#endif
 #define BSDLY 0
 #define VTDLY 0
 #define FFDLY 0
