--- libsidutils/include/sidplay/utils/SidUsage.h.orig	2004-06-14 20:08:08 UTC
+++ libsidutils/include/sidplay/utils/SidUsage.h
@@ -33,7 +33,7 @@ struct sid2_usage_t: public sid_usage_t
     uint_least16_t length;  // usage scan length
 
     // Copy common parts of basic usage to extended usage.
-    sid2_usage_t &sid2_usage_t::operator= (const sid_usage_t &usage)
+    sid2_usage_t &operator= (const sid_usage_t &usage)
     {
         *((sid_usage_t *) this) = usage;
         return *this;
