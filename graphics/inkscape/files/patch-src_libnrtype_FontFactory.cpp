--- src/libnrtype/FontFactory.cpp.orig	2018-03-11 20:38:09 UTC
+++ src/libnrtype/FontFactory.cpp
@@ -704,8 +704,9 @@ font_instance *font_factory::Face(PangoFontDescription
             guint script_index = -1;
             if( pango_ot_info_find_script( info, PANGO_OT_TABLE_GSUB, scripts[i], &script_index )) {
 
+		PangoOTTag language_tag;
                 PangoOTTag* languages =
-                    pango_ot_info_list_languages( info, PANGO_OT_TABLE_GSUB, script_index, NULL);
+                    pango_ot_info_list_languages( info, PANGO_OT_TABLE_GSUB, script_index, language_tag);
                 // if( languages[0] != 0 )
                 //   std::cout << "      languages: " << std::endl;
 
