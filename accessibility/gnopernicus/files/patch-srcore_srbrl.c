--- srcore/srbrl.c.orig	Wed Mar 23 04:02:10 2005
+++ srcore/srbrl.c	Wed Mar 23 17:32:38 2005
@@ -763,6 +763,11 @@
 src_braille_load_values (SRCBraille *braille)
 {
     gint default_port = DEFAULT_BRAILLE_PORT_NO;
+    gint default_pos_sensor;
+    gint default_opt_sensor;
+    gchar *default_braille_transaltion_table;
+    gchar *default_braille_style;
+    gchar *default_braille_cursor_style;
 
     sru_assert (braille);
     
@@ -786,7 +791,7 @@
     	SET_BRAILLE_CONFIG_DATA (BRAILLE_PORT_NO, CFGT_INT, &braille->port);
     }    
     
-    gchar *default_braille_transaltion_table = DEFAULT_BRAILLE_TRANSLATION;
+    default_braille_transaltion_table = DEFAULT_BRAILLE_TRANSLATION;
     GET_BRAILLE_CONFIG_DATA_WITH_DEFAULT (BRAILLE_TRANSLATION, CFGT_STRING, 
 					  &braille->translation_table, 
 					  default_braille_transaltion_table);		
@@ -798,22 +803,22 @@
     }
 	
     
-    gchar *default_braille_style = DEFAULT_BRAILLE_STYLE;
+    default_braille_style = DEFAULT_BRAILLE_STYLE;
     GET_BRAILLE_CONFIG_DATA_WITH_DEFAULT (BRAILLE_STYLE, CFGT_STRING, 
 					  &braille->style, 
 					  default_braille_style);
 					  
-    gchar *default_braille_cursor_style = DEFAULT_BRAILLE_CURSOR_STYLE;
+    default_braille_cursor_style = DEFAULT_BRAILLE_CURSOR_STYLE;
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
