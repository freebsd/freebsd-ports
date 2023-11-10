--- src/Geno.cpp.orig	2022-08-03 06:01:52 UTC
+++ src/Geno.cpp
@@ -2948,7 +2948,7 @@ void Geno::bgen2bed(const vector<uint32_t> &raw_marker
         }
         //LOGGER.i(0, "MIDDLE: " + to_string(index) + "NUM_thread: " + to_string(omp_get_max_threads()));
 
-        #pragma omp ordered
+        // Conflict with previous on 2759 #pragma omp ordered
         save_bed(buf, num_marker);
         delete[] buf;
         delete[] dec_data;
