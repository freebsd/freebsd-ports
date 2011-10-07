--- src/mod_term/terminals.c.orig	2011-10-06 14:07:55.000000000 +0200
+++ src/mod_term/terminals.c	2011-10-06 16:21:40.000000000 +0200
@@ -263,7 +263,9 @@
 #ifndef NLDLY
 #define NLDLY 0
 #define CRDLY 0
+#ifndef TABDLY
 #define TABDLY 0
+#endif
 #define BSDLY 0
 #define VTDLY 0
 #define FFDLY 0
