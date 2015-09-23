Obtained from:	https://github.com/uclouvain/openjpeg/commit/a4e93c3b0af1c42770206b5d25014a05a60ec8f5
		https://github.com/uclouvain/openjpeg/commit/c16c91797f4b15eb55d56f85fd497d588331e71f
		https://github.com/uclouvain/openjpeg/commit/55dbf8acff9afab1591b6a094b744d8426a32dd4

--- src/lib/openjp2/j2k.c.orig	2015-09-16 18:49:45 UTC
+++ src/lib/openjp2/j2k.c
@@ -8603,8 +8603,10 @@ static opj_codestream_index_t* opj_j2k_c
         cstr_index->marknum = 0;
         cstr_index->marker = (opj_marker_info_t*)
                         opj_calloc(cstr_index->maxmarknum, sizeof(opj_marker_info_t));
-        if (!cstr_index-> marker)
+        if (!cstr_index-> marker) {
+                opj_free(cstr_index);
                 return NULL;
+        }
 
         cstr_index->tile_index = NULL;
 
@@ -9668,14 +9670,14 @@ static OPJ_BOOL opj_j2k_decode_one_tile 
                                  *  so move to the last SOT read */
                                 if ( !(opj_stream_read_seek(p_stream, p_j2k->m_specific_param.m_decoder.m_last_sot_read_pos+2, p_manager)) ){
                                         opj_event_msg(p_manager, EVT_ERROR, "Problem with seek function\n");
-                        opj_free(l_current_data);
+                                        opj_free(l_current_data);
                                         return OPJ_FALSE;
                                 }
                         }
                         else{
                                 if ( !(opj_stream_read_seek(p_stream, p_j2k->cstr_index->tile_index[l_tile_no_to_dec].tp_index[0].start_pos+2, p_manager)) ) {
                                         opj_event_msg(p_manager, EVT_ERROR, "Problem with seek function\n");
-                        opj_free(l_current_data);
+                                        opj_free(l_current_data);
                                         return OPJ_FALSE;
                                 }
                         }
@@ -9733,6 +9735,7 @@ static OPJ_BOOL opj_j2k_decode_one_tile 
                         /* move into the codestream to the the first SOT (FIXME or not move?)*/
                         if (!(opj_stream_read_seek(p_stream, p_j2k->cstr_index->main_head_end + 2, p_manager) ) ) {
                                 opj_event_msg(p_manager, EVT_ERROR, "Problem with seek function\n");
+                                opj_free(l_current_data);
                                 return OPJ_FALSE;
                         }
                         break;
@@ -9998,11 +10001,15 @@ OPJ_BOOL opj_j2k_encode(opj_j2k_t * p_j2
                         /* now copy this data into the tile component */
                         if (! opj_tcd_copy_tile_data(p_j2k->m_tcd,l_current_data,l_current_tile_size)) {
 																opj_event_msg(p_manager, EVT_ERROR, "Size mismatch between tile data and sent data." );
+																opj_free(l_current_data);
 																return OPJ_FALSE;
                         }
                 }
 
                 if (! opj_j2k_post_write_tile (p_j2k,p_stream,p_manager)) {
+                        if (l_current_data) {
+                                opj_free(l_current_data);
+                        }
                         return OPJ_FALSE;
                 }
         }
