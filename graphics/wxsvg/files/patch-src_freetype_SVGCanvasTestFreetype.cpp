--- src/freetype/SVGCanvasTextFreetype.cpp.orig	Thu Jul 20 18:46:14 2006
+++ src/freetype/SVGCanvasTextFreetype.cpp	Thu Feb 22 18:42:55 2007
@@ -163,7 +163,7 @@
   }
 }
 
-static gint moveto(FT_Vector* to, gpointer data)
+static gint moveto(const FT_Vector* to, gpointer data)
 {
   wxSVGCanvasTextFreetype* canvasText = (wxSVGCanvasTextFreetype*) data;
   
@@ -179,7 +179,7 @@
   return 0;
 }
 
-static gint lineto (FT_Vector* to, gpointer data)
+static gint lineto (const FT_Vector* to, gpointer data)
 {
   wxSVGCanvasTextFreetype* canvasText = (wxSVGCanvasTextFreetype*) data;
   if (!canvasText->m_endpath)
@@ -192,7 +192,7 @@
   return 0;
 }
 
-static gint conicto(FT_Vector* ftcontrol, FT_Vector* to, gpointer data)
+static gint conicto(const FT_Vector* ftcontrol, const FT_Vector* to, gpointer data)
 {
   wxSVGCanvasTextFreetype* canvasText = (wxSVGCanvasTextFreetype*) data;
   if (!canvasText->m_endpath)
@@ -207,8 +207,8 @@
   return 0;
 }
 
-static gint cubicto(FT_Vector* ftcontrol1, FT_Vector* ftcontrol2,
- FT_Vector* to, gpointer data)
+static gint cubicto(const FT_Vector* ftcontrol1, const FT_Vector* ftcontrol2,
+ const FT_Vector* to, gpointer data)
 {
   wxSVGCanvasTextFreetype* canvasText = (wxSVGCanvasTextFreetype*) data;
   if (!canvasText->m_endpath)
@@ -225,7 +225,7 @@
   return 0;
 }
 
-static const FT_Outline_Funcs outline_funcs =
+static FT_Outline_Funcs outline_funcs =
 {
   moveto, lineto, conicto, cubicto, 0, 0
 };
