--- third-party/abc/src/sat/glucose/System.cpp.orig	2022-02-10 03:16:18 UTC
+++ third-party/abc/src/sat/glucose/System.cpp
@@ -86,7 +86,7 @@ double Gluco::memUsed(void) {
     struct rusage ru;
     getrusage(RUSAGE_SELF, &ru);
     return (double)ru.ru_maxrss / 1024; }
-double memUsedPeak(void) { return memUsed(); }
+double Gluco::memUsedPeak(void) { return memUsed(); }
 
 ABC_NAMESPACE_IMPL_END
 
