--- third-party/abc/src/sat/glucose2/System2.cpp.orig	2022-02-10 03:16:53 UTC
+++ third-party/abc/src/sat/glucose2/System2.cpp
@@ -86,7 +86,7 @@ double Gluco2::memUsed(void) {
     struct rusage ru;
     getrusage(RUSAGE_SELF, &ru);
     return (double)ru.ru_maxrss / 1024; }
-double memUsedPeak(void) { return memUsed(); }
+double Gluco2::memUsedPeak(void) { return memUsed(); }
 
 ABC_NAMESPACE_IMPL_END
 
