--- app/tools/gimptexttool.c.orig	Thu Feb  5 01:52:53 2004
+++ app/tools/gimptexttool.c	Thu Feb  5 01:53:00 2004
@@ -218,7 +218,7 @@
 			     GdkModifierType  state,
 			     GimpDisplay     *gdisp)
 {
-  GimpTextTool *text_tool = GIMP_TEXT_TOOL (tool);;
+  GimpTextTool *text_tool = GIMP_TEXT_TOOL (tool);
   GimpDrawable *drawable;
   GimpText     *text  = NULL;
   gint          off_x = 0;
