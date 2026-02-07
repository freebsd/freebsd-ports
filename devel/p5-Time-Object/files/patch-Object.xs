--- ./Object.xs.orig	2001-10-22 17:48:04.000000000 +0800
+++ ./Object.xs	2007-09-10 11:07:31.866215125 +0800
@@ -42,6 +42,10 @@
 # define init_tm(ptm)
 #endif
 
+#ifdef mini_mktime
+#undef mini_mktime
+#endif
+
 /*
  * mini_mktime - normalise struct tm values without the localtime()
  * semantics (and overhead) of mktime().
