--- bcf_ordered_writer.cpp.orig	2020-07-27 13:12:44 UTC
+++ bcf_ordered_writer.cpp
@@ -155,7 +155,7 @@ void BCFOrderedWriter::write(bcf1_t *v)
 
                 if (i==buffer.end())
                 {
-                    int32_t cutoff_pos1 =  std::max(bcf_get_pos1(buffer.front())-window,1);
+                    int32_t cutoff_pos1 =  std::max(bcf_get_pos1(buffer.front())-window,(hts_pos_t)1);
                     if (bcf_get_pos1(v)<cutoff_pos1)
                     {
                         fprintf(stderr, "[%s:%d %s] Might not be sorted for window size %d at current record %s:%d < %d (%d [last record] - %d), please increase window size to at least %d.\n",
@@ -251,7 +251,7 @@ void BCFOrderedWriter::flush(bool force)
     {
         if (buffer.size()>1)
         {
-            int32_t cutoff_pos1 =  std::max(bcf_get_pos1(buffer.front())-window,1);
+            int32_t cutoff_pos1 =  std::max(bcf_get_pos1(buffer.front())-window,(hts_pos_t)1);
 
             while (buffer.size()>1)
             {
