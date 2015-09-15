--- tools/db_stress.cc.orig	2015-08-31 18:23:39 UTC
+++ tools/db_stress.cc
@@ -222,7 +222,7 @@ DEFINE_int32(set_options_one_in, 0,
 DEFINE_int32(set_in_place_one_in, 0,
              "With a chance of 1/N, toggle in place support option");
 
-DEFINE_int64(cache_size, 2 * KB * KB * KB,
+DEFINE_int64(cache_size, 2LL * KB * KB * KB,
              "Number of bytes to use as a cache of uncompressed data.");
 
 static bool ValidateInt32Positive(const char* flagname, int32_t value) {
