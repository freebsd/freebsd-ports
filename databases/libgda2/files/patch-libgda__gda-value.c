--- libgda/gda-value.c.orig	Fri Mar 17 11:08:32 2006
+++ libgda/gda-value.c	Fri Mar 24 22:31:12 2006
@@ -1281,8 +1281,8 @@ gda_value_is_null (GdaValue *value)
 gboolean
 gda_value_is_number (GdaValue *value)
 {
-	g_return_val_if_fail (value && G_IS_VALUE(value), FALSE);
 	GdaValueType type;
+	g_return_val_if_fail (value && G_IS_VALUE(value), FALSE);
 	
 	type = GDA_VALUE_TYPE(value);
 	switch (type) {
