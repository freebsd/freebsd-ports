--- include/pacbio/genomicconsensus/Output.h.orig	2018-03-07 23:10:34 UTC
+++ include/pacbio/genomicconsensus/Output.h
@@ -80,8 +80,15 @@ inline void PrintVcfLite(const Variant& 
         << "\tPASS\n";
 }
 
-inline Output::Output(const Settings& settings) : settings_{settings}
+// Original
+//inline Output::Output(const Settings& settings) : settings_{settings}
+// Probably OK patch
+//inline Output::Output(const Settings& settings)
+// https://forums.freebsd.org/threads/compile-error-with-clang-3-4.65595/#post-385293
+inline Output::Output(const Settings& settings) : settings_(settings)
 {
+    // Probably OK patch
+    //settings_ = settings;
     // initialize maps
     PacBio::BAM::FastaSequenceQuery fasta{settings_.referenceFilename};
     for (const auto& seq : fasta) {
