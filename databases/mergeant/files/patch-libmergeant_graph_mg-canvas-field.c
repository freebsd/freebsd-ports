--- libmergeant/graph/mg-canvas-field.c.orig	Sat Aug 14 04:04:07 2004
+++ libmergeant/graph/mg-canvas-field.c	Sat Aug 14 04:04:40 2004
@@ -146,13 +146,13 @@
 	gpointer ptr;
 	GString *string;
 	MgServerDataType *dtype;
+	MgEntity *ent;
 
 	cf = MG_CANVAS_FIELD (object);
 
 	switch (param_id) {
 	case PROP_FIELD:
 		ptr = g_value_get_pointer (value);
-		MgEntity *ent;
 		g_return_if_fail (IS_MG_FIELD (ptr));
 
 		/* signals management */
