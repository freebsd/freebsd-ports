Index: modules/flann/include/opencv2/flann/lsh_index.h
===================================================================
--- modules/flann/include/opencv2/flann/lsh_index.h	(revision 6880)
+++ modules/flann/include/opencv2/flann/lsh_index.h	(revision 6881)
@@ -56,7 +56,7 @@
 
 struct LshIndexParams : public IndexParams
 {
-    LshIndexParams(unsigned int table_number, unsigned int key_size, unsigned int multi_probe_level)
+    LshIndexParams(unsigned int table_number = 12, unsigned int key_size = 20, unsigned int multi_probe_level = 2)
     {
         (* this)["algorithm"] = FLANN_INDEX_LSH;
         // The number of hash tables to use
