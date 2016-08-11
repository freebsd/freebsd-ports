--- uppsrc/Core/Core.h.orig	2015-11-29 14:17:07 UTC
+++ uppsrc/Core/Core.h
@@ -342,12 +342,12 @@ static const MemDiagCls sMemDiagHelper__
 
 //some global definitions
 
-#if !defined(STLPORT) && _MSC_VER < 1600
+#if !defined(STLPORT) && _MSC_VER < 1600 && !defined(_LIBCPP_VERSION)
 inline UPP::int64  abs(UPP::int64 x)          { return x < 0 ? -x : x; }
 #endif
 
-#ifdef COMPILER_GCC
-inline double abs(double x)                   { return fabs(x); }
+#if defined(COMPILER_GCC) && !defined(_LIBCPP_VERSION)
+inline double abs(double x) throw()           { return fabs(x); }
 #endif
 
 void      RegisterTopic__(const char *topicfile, const char *topic, const char *title, const UPP::byte *data, int len);
