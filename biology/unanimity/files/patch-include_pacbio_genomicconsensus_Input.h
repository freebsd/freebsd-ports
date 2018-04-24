--- include/pacbio/genomicconsensus/Input.h.orig	2018-03-07 23:10:34 UTC
+++ include/pacbio/genomicconsensus/Input.h
@@ -25,7 +25,12 @@ namespace GenomicConsensus {
 class Input
 {
 public:
-    explicit Input(const Settings& settings) : settings_{settings} {}
+    // Original
+    //explicit Input(const Settings& settings) : settings_{settings} {}
+    // Probably OK
+    //explicit Input(const Settings& settings) { settings_ = settings; }
+    // https://forums.freebsd.org/threads/compile-error-with-clang-3-4.65595/#post-385293
+    explicit Input(const Settings& settings) : settings_(settings) {}
 
     Input() = delete;
     Input(const Input&) = delete;
