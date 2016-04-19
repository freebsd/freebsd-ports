--- include/mdds/multi_type_vector_def.inl.orig	2016-01-29 00:31:44 UTC
+++ include/mdds/multi_type_vector_def.inl
@@ -1936,7 +1936,6 @@ multi_type_vector<_CellBlockFunc, _Event
         else
         {
             // Just move the whole block over.
-            block* blk = m_blocks[block_index2];
             dest.m_blocks[dest_block_pos] = blk;
             if (blk->mp_data)
             {
