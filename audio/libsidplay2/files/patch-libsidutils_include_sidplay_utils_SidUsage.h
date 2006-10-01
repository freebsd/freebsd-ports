--- libsidutils/include/sidplay/utils/SidUsage.h.orig	Sat Sep 30 19:49:52 2006
+++ libsidutils/include/sidplay/utils/SidUsage.h	Sat Sep 30 19:50:54 2006
@@ -33,7 +33,7 @@
     uint_least16_t length;  // usage scan length
 
     // Copy common parts of basic usage to extended usage.
-    sid2_usage_t &sid2_usage_t::operator= (const sid_usage_t &usage)
+    sid2_usage_t &operator= (const sid_usage_t &usage)
     {
         *((sid_usage_t *) this) = usage;
         return *this;
