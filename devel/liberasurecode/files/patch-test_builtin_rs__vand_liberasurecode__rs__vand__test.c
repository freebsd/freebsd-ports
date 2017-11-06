--- test/builtin/rs_vand/liberasurecode_rs_vand_test.c.orig	2017-04-06 11:14:01 UTC
+++ test/builtin/rs_vand/liberasurecode_rs_vand_test.c
@@ -32,6 +32,10 @@
 #include <time.h>
 #include <liberasurecode_rs_vand.h>
 
+#ifdef __FreeBSD__
+#include <sys/stat.h>
+#endif
+
 int test_make_systematic_matrix(int k, int m)
 {
   int *matrix = make_systematic_matrix(k, m);
