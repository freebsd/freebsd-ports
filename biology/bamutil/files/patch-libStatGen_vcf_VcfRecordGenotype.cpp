--- libStatGen/vcf/VcfRecordGenotype.cpp.orig	2021-10-12 15:13:03 UTC
+++ libStatGen/vcf/VcfRecordGenotype.cpp
@@ -176,7 +176,7 @@ bool VcfRecordGenotype::setString(const std::string& k
     if(sampleNum >= mySamples.size())
     {
         // Out of range sample index.
-        return(NULL);
+        return(false);
     }
     // Set the field in the sample.
     return(mySamples.get(sampleNum).setString(key, value));
