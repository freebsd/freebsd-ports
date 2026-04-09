--- tools/browser/canvas/browser-canvas-text.c.orig	2020-11-08 20:23:20 UTC
+++ tools/browser/canvas/browser-canvas-text.c
@@ -231,7 +231,7 @@ browser_canvas_text_set_property (GObject *object,
 	const gchar *cstr = NULL;
 	gchar *str;
 	gdouble size = 0;
-	gboolean bool = FALSE;
+	gboolean bool_var = FALSE;
 
 	ct = BROWSER_CANVAS_TEXT (object);
 
@@ -269,11 +269,11 @@ browser_canvas_text_set_property (GObject *object,
 			ct->priv->highlight_color = g_strdup (BROWSER_CANVAS_ENTITY_COLOR);
 		break;
 	case PROP_UNDERLINE:
-		bool = g_value_get_boolean (value);
-		ct->priv->underline = bool;
+		bool_var = g_value_get_boolean (value);
+		ct->priv->underline = bool_var;
 		adjust_text_pango_attributes (ct);
 		if (ct->priv->text_item) {
-			if (bool) {
+			if (bool_var) {
 				str = g_strdup_printf ("<u>%s</u>", ct->priv->text);
 				g_object_set (G_OBJECT (ct->priv->text_item), 
 					      "text", str,
@@ -286,8 +286,8 @@ browser_canvas_text_set_property (GObject *object,
 					      "use-markup", FALSE, NULL);
 		}
 	case PROP_BOLD:
-		bool = g_value_get_boolean (value);
-		ct->priv->bold = bool;
+		bool_var = g_value_get_boolean (value);
+		ct->priv->bold = bool_var;
 		adjust_text_pango_attributes (ct);
 		break;
 	default:
