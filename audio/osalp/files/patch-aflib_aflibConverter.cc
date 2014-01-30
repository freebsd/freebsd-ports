--- ./aflib/aflibConverter.cc.orig	2014-01-30 14:56:04.000000000 +0100
+++ ./aflib/aflibConverter.cc	2014-01-30 14:56:11.000000000 +0100
@@ -226,7 +226,7 @@
 
 
 int
-aflibConverter::err_ret(char *s)
+aflibConverter::err_ret(const char *s)
 {
     aflib_debug("resample: %s \n\n",s); /* Display error message  */
     return -1;
