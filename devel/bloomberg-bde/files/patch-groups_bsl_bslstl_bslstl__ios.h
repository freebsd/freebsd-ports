--- groups/bsl/bslstl/bslstl_ios.h.orig	2023-07-31 18:54:31 UTC
+++ groups/bsl/bslstl/bslstl_ios.h
@@ -26,6 +26,11 @@ BSLS_IDENT("$Id: $")
 
 #include <ios>
 
+#ifdef BSLS_PLATFORM_OS_FREEBSD
+#include <istream>
+#include <locale>
+#endif
+
 #ifndef BDE_DONT_ALLOW_TRANSITIVE_INCLUDES
 #include <bsls_nativestd.h>
 #endif // BDE_DONT_ALLOW_TRANSITIVE_INCLUDES
