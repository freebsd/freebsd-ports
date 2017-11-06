--- src/libnrtype/FontFactory.cpp.orig	2017-01-05 22:10:01.490293000 +0100
+++ src/libnrtype/FontFactory.cpp	2017-01-05 22:13:37.547401000 +0100
@@ -695,8 +695,9 @@
             guint script_index = -1;
             if( pango_ot_info_find_script( info, PANGO_OT_TABLE_GSUB, scripts[i], &script_index )) {
 
+		PangoOTTag language_tag;
                 PangoOTTag* languages =
-                    pango_ot_info_list_languages( info, PANGO_OT_TABLE_GSUB, script_index, NULL);
+                    pango_ot_info_list_languages( info, PANGO_OT_TABLE_GSUB, script_index, language_tag);
                 // if( languages[0] != 0 )
                 //   std::cout << "      languages: " << std::endl;
 
