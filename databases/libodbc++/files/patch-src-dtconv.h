--- src/dtconv.h.orig	2012-11-04 17:17:28.000000000 +0700
+++ src/dtconv.h	2012-11-04 17:17:56.000000000 +0700
@@ -113,7 +113,7 @@
     snprintf(buf,LONG_STR_LEN,
 # endif
 # if defined(PRId64)
-             ODBCXX_STRING_PERCENT PRId64
+             ODBCXX_STRING_CONST("%") PRId64
 # elif ODBCXX_SIZEOF_LONG==8
              ODBCXX_STRING_CONST("%ld")
 # else
