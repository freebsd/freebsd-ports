--- inst/include/Rcpp/exceptions_impl.h.orig	2026-04-23 14:10:21 UTC
+++ inst/include/Rcpp/exceptions_impl.h
@@ -2,7 +2,7 @@
 //
 // Copyright (C) 2012 - 2019  Dirk Eddelbuettel and Romain Francois
 // Copyright (C) 2020 - 2024  Dirk Eddelbuettel, Romain Francois, and Joshua N. Pritikin
-// Copyright (C) 2025         Dirk Eddelbuettel, Romain Francois, Joshua N. Pritikin, and Iñaki Ucar
+// Copyright (C) 2025 - 2026  Dirk Eddelbuettel, Romain Francois, Joshua N. Pritikin, and Iñaki Ucar
 //
 // This file is part of Rcpp.
 //
@@ -23,15 +23,33 @@
 #define Rcpp__exceptions_impl__h
 
 // enable demangler on platforms where execinfo.h is present
+// and that are not actively blacklisted
 #ifndef RCPP_DEMANGLER_ENABLED
-# define RCPP_DEMANGLER_ENABLED 0
-# if defined __has_include
-#  if __has_include (<execinfo.h>)
-#   include <execinfo.h>
-#   undef RCPP_DEMANGLER_ENABLED
-#   define RCPP_DEMANGLER_ENABLED 1
+// set a fallback default
+#define RCPP_DEMANGLER_ENABLED 0
+#  if defined(_WIN32)       || \
+     defined(__FreeBSD__)   || \
+     defined(__NetBSD__)    || \
+     defined(__OpenBSD__)   || \
+     defined(__DragonFly__) || \
+     defined(__CYGWIN__)    || \
+     defined(__sun)         || \
+     defined(_AIX)          || \
+     defined(__MUSL__)      || \
+     defined(__HAIKU__)     || \
+     defined(__ANDROID__)
+//   nothing to do here so just redefining
+#    undef RCPP_DEMANGLER_ENABLED
+#    define RCPP_DEMANGLER_ENABLED 0
+#  elif defined __has_include
+//   if we can test for headers
+#    if __has_include (<execinfo.h>)
+//     if we have the header, include and use it
+#      include <execinfo.h>
+#      undef RCPP_DEMANGLER_ENABLED
+#      define RCPP_DEMANGLER_ENABLED 1
+#    endif
 #  endif
-# endif
 #endif
 
 namespace Rcpp {
