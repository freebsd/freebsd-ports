--- libmergeant/mg-parameter.c.orig	Thu Aug 12 22:25:38 2004
+++ libmergeant/mg-parameter.c	Thu Aug 12 22:25:53 2004
@@ -608,9 +608,9 @@
 mg_parameter_set_value (MgParameter *param, const GdaValue *value)
 {
 	gboolean changed = TRUE;
+	const GdaValue *current_val;
 	g_return_if_fail (param && IS_MG_PARAMETER (param));
 	g_return_if_fail (param->priv);
-	const GdaValue *current_val;
 
 	param->priv->invalid_forced = FALSE;
 
