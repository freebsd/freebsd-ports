--- aflib/aflibConverter.cc.orig	2007-01-16 19:26:39 UTC
+++ aflib/aflibConverter.cc
@@ -226,7 +226,7 @@ aflibConverter::resample(       /* numbe
 
 
 int
-aflibConverter::err_ret(char *s)
+aflibConverter::err_ret(const char *s)
 {
     aflib_debug("resample: %s \n\n",s); /* Display error message  */
     return -1;
