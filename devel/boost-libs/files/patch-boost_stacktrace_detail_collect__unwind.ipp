Expose _Unwind_Backtrace in libcxxrt

--- boost/stacktrace/detail/collect_unwind.ipp.orig	2017-09-02 09:56:17 UTC
+++ boost/stacktrace/detail/collect_unwind.ipp
@@ -14,7 +14,18 @@
 
 #include <boost/stacktrace/safe_dump_to.hpp>
 
+#ifndef _GNU_SOURCE
+#define _GNU_SOURCE
+#define _GNU_SOURCE_TEMPORARY
+#endif
 #include <unwind.h>
+#ifdef _GNU_SOURCE_TEMPORARY
+#undef _GNU_SOURCE
+#undef _GNU_SOURCE_TEMPORARY
+#endif
+#if !defined(_URC_NO_REASON) && defined(__arm__) && !defined(__ARM_DWARF_EH__)
+#define _URC_NO_REASON _URC_OK
+#endif
 #include <cstdio>
 
 #if !defined(_GNU_SOURCE) && !defined(BOOST_STACKTRACE_GNU_SOURCE_NOT_REQUIRED) && !defined(BOOST_WINDOWS)
