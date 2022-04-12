--- test/builtin/rs_vand/liberasurecode_rs_vand_test.c.orig	2022-04-08 23:59:40 UTC
+++ test/builtin/rs_vand/liberasurecode_rs_vand_test.c
@@ -33,6 +33,10 @@
 #include <liberasurecode_rs_vand.h>
 #include <sys/stat.h>
 
+#ifdef __FreeBSD__
+#include <sys/stat.h>
+#endif
+
 int test_make_systematic_matrix(int k, int m)
 {
   int *matrix = make_systematic_matrix(k, m);
