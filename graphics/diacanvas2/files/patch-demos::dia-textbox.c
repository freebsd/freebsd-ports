--- demos/dia-textbox.c.orig	Mon Oct  6 03:18:15 2003
+++ demos/dia-textbox.c	Sat Aug 28 00:07:51 2004
@@ -140,7 +140,7 @@
 	textbox->text = dia_canvas_item_create (DIA_TYPE_CANVAS_TEXT, NULL);
 	dia_canvas_item_set_child_of (textbox->text, DIA_CANVAS_ITEM (textbox));
 	
-	g_message (__FUNCTION__": %p %p %p %p %p", textbox, textbox->text, textbox->text->parent, DIA_CANVAS_ITEM (textbox)->canvas, textbox->text->canvas);
+	g_message ("%s: %p %p %p %p %p", __func__, textbox, textbox->text, textbox->text->parent, DIA_CANVAS_ITEM (textbox)->canvas, textbox->text->canvas);
 }
 
 static void
