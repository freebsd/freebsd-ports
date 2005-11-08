--- ../../work-/libgda-1.9.100/libgda/gda-value.c	Tue Nov  8 14:56:44 2005
+++ libgda/gda-value.c	Tue Nov  8 14:57:29 2005
@@ -1263,8 +1263,8 @@
 gboolean
 gda_value_is_number (GdaValue *value)
 {
-	g_return_val_if_fail (value && G_IS_VALUE(value), FALSE);
 	GdaValueType type;
+	g_return_val_if_fail (value && G_IS_VALUE(value), FALSE);
 	
 	type = GDA_VALUE_TYPE(value);
 	switch (type) {
@@ -1437,10 +1437,10 @@
 void
 gda_value_set_blob (GdaValue *value, const GdaBlob *val)
 {
+	GdaBlob *blob;
 	g_return_if_fail (value);
 	g_return_if_fail (GDA_IS_BLOB (val));
 	
-	GdaBlob *blob;
 	l_g_value_unset (value);
 	g_value_init (value, G_VALUE_TYPE_BLOB);
 	
