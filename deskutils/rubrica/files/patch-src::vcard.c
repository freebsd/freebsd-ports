--- src/vcard.c.orig	Fri Jun  6 23:57:31 2003
+++ src/vcard.c	Fri Oct 24 00:59:04 2003
@@ -128,9 +128,6 @@
   RubricaVCardParamType param;
   RubricaVCardValueType value;
 
-  parray[ARRAY_SIZE] = BAD_PARAM;
-  varray[ARRAY_SIZE] = BAD_VALUE;
-
   gchar buffer_token[32], buffer_param[32], buffer_val[32]; 
   gchar data[1024];
 //  gchar *binary_data;
@@ -139,6 +136,9 @@
   gint ch;
   gint i = 0, j = 0, k = 0, l = 0, p = 0;  
   gboolean new_card = TRUE;
+
+  parray[ARRAY_SIZE] = BAD_PARAM;
+  varray[ARRAY_SIZE] = BAD_VALUE;
 
   state = BUILD_TOKEN_STATE;
   
