--- srcore/srbrl.c.orig	Wed Jul 14 20:51:31 2004
+++ srcore/srbrl.c	Wed Jul 14 20:55:57 2004
@@ -723,6 +723,12 @@
 static void
 src_braille_load_values (SRCBraille *braille)
 {
+    gint default_pos_sensor;
+    gint default_opt_sensor;
+    gchar *default_braille_transaltion_table;
+    gchar *default_braille_style;
+    gchar *default_braille_cursor_style;
+
     sru_assert (braille);
     
     if (!braille->device)
@@ -749,7 +755,7 @@
 	}					  
     }    
     
-    gchar *default_braille_transaltion_table = DEFAULT_BRAILLE_TRANSLATION;
+    *default_braille_transaltion_table = DEFAULT_BRAILLE_TRANSLATION;
     GET_BRAILLE_CONFIG_DATA_WITH_DEFAULT (BRAILLE_TRANSLATION, CFGT_STRING, 
 					  &braille->translation_table, 
 					  default_braille_transaltion_table);		
@@ -761,22 +767,22 @@
     }
 	
     
-    gchar *default_braille_style = DEFAULT_BRAILLE_STYLE;
+    *default_braille_style = DEFAULT_BRAILLE_STYLE;
     GET_BRAILLE_CONFIG_DATA_WITH_DEFAULT (BRAILLE_STYLE, CFGT_STRING, 
 					  &braille->style, 
 					  default_braille_style);
 					  
-    gchar *default_braille_cursor_style = DEFAULT_BRAILLE_CURSOR_STYLE;
+    *default_braille_cursor_style = DEFAULT_BRAILLE_CURSOR_STYLE;
     GET_BRAILLE_CONFIG_DATA_WITH_DEFAULT (BRAILLE_CURSOR_STYLE, CFGT_STRING, 
 					  &braille->cursor_style, 
 					  default_braille_cursor_style);
 					  
-    gint default_pos_sensor = DEFAULT_BRAILLE_POSITION_SENSOR;
+    default_pos_sensor = DEFAULT_BRAILLE_POSITION_SENSOR;
     GET_BRAILLE_CONFIG_DATA_WITH_DEFAULT (BRAILLE_POSITION_SENSOR, CFGT_INT, 
 					  &braille->position_sensor, 
 					  &default_pos_sensor);
     
-    gint default_opt_sensor = DEFAULT_BRAILLE_OPTICAL_SENSOR;
+    default_opt_sensor = DEFAULT_BRAILLE_OPTICAL_SENSOR;
     GET_BRAILLE_CONFIG_DATA_WITH_DEFAULT (BRAILLE_OPTICAL_SENSOR, CFGT_INT, 
 					  &braille->optical_sensor, 
 					  &default_opt_sensor);
