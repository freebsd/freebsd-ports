--- fex/fex/blargg_common.h.orig	2019-02-11 08:38:11 UTC
+++ fex/fex/blargg_common.h
@@ -12,7 +12,7 @@
 typedef const char* blargg_err_t; // 0 on success, otherwise error string
 
 // Success; no error
-int const blargg_ok = 0;
+const char* const blargg_ok = 0;
 
 // BLARGG_RESTRICT: equivalent to C99's restrict, where supported
 #if __GNUC__ >= 3 || _MSC_VER >= 1100
