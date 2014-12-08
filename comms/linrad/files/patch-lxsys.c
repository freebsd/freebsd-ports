--- lxsys.c.orig	2014-12-08 03:10:46.000000000 -0800
+++ lxsys.c	2014-12-08 03:11:39.000000000 -0800
@@ -120,9 +120,9 @@
 char *fsse=" sse";
 char *fht=" ht";
 char *fprocessor="processor";
+int no_of_ht;
 #endif
 int xxprint;
-int no_of_ht;
 // If there is no mmx, do not use simd either.
 tickspersec = sysconf(_SC_CLK_TCK);
 xxprint=0;
