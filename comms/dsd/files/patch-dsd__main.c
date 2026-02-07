--- dsd_main.c.orig	2020-08-28 19:59:00 UTC
+++ dsd_main.c
@@ -25,6 +25,8 @@
 #include "dmr_const.h"
 #include "provoice_const.h"
 
+int exitflag;
+
 int
 comp (const void *a, const void *b)
 {
