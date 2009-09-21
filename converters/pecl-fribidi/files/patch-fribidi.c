--- fribidi.c.orig	2003-04-08 13:03:25.000000000 +0200
+++ fribidi.c	2009-09-21 09:51:54.000000000 +0200
@@ -32,15 +32,14 @@
 #include <fribidi/fribidi.h>
 
 /* The fribidi guys dont believe in BC */
-/*#ifndef FRIBIDI_CHARSET_UTF8
+#ifndef FRIBIDI_CHARSET_UTF8
 #define FRIBIDI_CHARSET_UTF8                FRIBIDI_CHAR_SET_UTF8
 #define FRIBIDI_CHARSET_ISO8859_6           FRIBIDI_CHAR_SET_ISO8859_6
 #define FRIBIDI_CHARSET_ISO8859_8           FRIBIDI_CHAR_SET_ISO8859_8
 #define FRIBIDI_CHARSET_CP1255              FRIBIDI_CHAR_SET_CP1255
 #define FRIBIDI_CHARSET_CP1256              FRIBIDI_CHAR_SET_CP1256
-#define FRIBIDI_CHARSET_ISIRI_3342          FRIBIDI_CHAR_SET_ISIRI_3342
 #define FRIBIDI_CHARSET_CAP_RTL             FRIBIDI_CHAR_SET_CAP_RTL
-#endif*/
+#endif
 
 function_entry fribidi_functions[] = {
 	PHP_FE(fribidi_log2vis,	     NULL)
@@ -76,7 +75,6 @@
 	REGISTER_LONG_CONSTANT("FRIBIDI_CHARSET_8859_8", FRIBIDI_CHARSET_ISO8859_8, CONST_CS | CONST_PERSISTENT);
 	REGISTER_LONG_CONSTANT("FRIBIDI_CHARSET_CP1255", FRIBIDI_CHARSET_CP1255, CONST_CS | CONST_PERSISTENT);
 	REGISTER_LONG_CONSTANT("FRIBIDI_CHARSET_CP1256", FRIBIDI_CHARSET_CP1256, CONST_CS | CONST_PERSISTENT);
-	REGISTER_LONG_CONSTANT("FRIBIDI_CHARSET_ISIRI_3342", FRIBIDI_CHARSET_ISIRI_3342, CONST_CS | CONST_PERSISTENT);
 	REGISTER_LONG_CONSTANT("FRIBIDI_CHARSET_CAP_RTL", FRIBIDI_CHARSET_CAP_RTL, CONST_CS | CONST_PERSISTENT);
 	
 	/* Directions */
@@ -125,7 +123,6 @@
 |              FRIBIDI_CHARSET_8859_8                        |
 |              FRIBIDI_CHARSET_CP1255                        |
 |              FRIBIDI_CHARSET_CP1256                        |
-|              FRIBIDI_CHARSET_ISIRI_3342                    |
 |              FRIBIDI_CHARSET_CAP_RTL                       |
 |                                                            |
 | Output: on success: The visual string.                     |
@@ -193,7 +190,6 @@
 		case FRIBIDI_CHARSET_ISO8859_8:
 		case FRIBIDI_CHARSET_CP1255:
 		case FRIBIDI_CHARSET_CP1256:
-		case FRIBIDI_CHARSET_ISIRI_3342:
 		case FRIBIDI_CHARSET_CAP_RTL:
 			len = fribidi_charset_to_unicode(Z_LVAL_PP(charset), in_string, len, u_logical_str);
 			break;
@@ -212,11 +208,7 @@
 	
 	out_string = (char *) emalloc(sizeof(char)*alloc_len);
 
-#if FRIBIDI_MAJOR_VERSION == 0 && FRIBIDI_MINOR_VERSION <= 10
 	fribidi_log2vis(u_logical_str, len, &base_dir, u_visual_str, position_L_to_V_list, position_V_to_L_list, embedding_level_list);
-#else
-	fribidi_log2vis(NULL, u_logical_str, len, &base_dir, u_visual_str, position_L_to_V_list, position_V_to_L_list, embedding_level_list);
-#endif
 	
 	/* convert back to original char set */
 	switch(Z_LVAL_PP(charset)) {
@@ -225,7 +217,6 @@
 		case FRIBIDI_CHARSET_ISO8859_8:
 		case FRIBIDI_CHARSET_CP1255:
 		case FRIBIDI_CHARSET_CP1256:
-		case FRIBIDI_CHARSET_ISIRI_3342:
 		case FRIBIDI_CHARSET_CAP_RTL:
 			fribidi_unicode_to_charset(Z_LVAL_PP(charset), u_visual_str, len, out_string);
 			break;									
@@ -270,7 +261,6 @@
 		case FRIBIDI_CHARSET_ISO8859_8:
 		case FRIBIDI_CHARSET_CP1255:
 		case FRIBIDI_CHARSET_CP1256:
-		case FRIBIDI_CHARSET_ISIRI_3342:
 		case FRIBIDI_CHARSET_CAP_RTL:
 			array_init(return_value);
 			
@@ -308,7 +298,6 @@
 	add_index_string(return_value, FRIBIDI_CHARSET_ISO8859_8, "FRIBIDI_CHARSET_8859_8", 1);
 	add_index_string(return_value, FRIBIDI_CHARSET_CP1255, "FRIBIDI_CHARSET_CP1255", 1);
 	add_index_string(return_value, FRIBIDI_CHARSET_CP1256, "FRIBIDI_CHARSET_CP1256", 1);
-	add_index_string(return_value, FRIBIDI_CHARSET_ISIRI_3342, "FRIBIDI_CHARSET_ISIRI_3342", 1);
 }
 /* }}} */
 
