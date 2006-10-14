--- src/freetype/SVGCanvasTextFreetype.cpp.orig	Thu Sep 21 21:42:35 2006
+++ src/freetype/SVGCanvasTextFreetype.cpp	Thu Sep 21 21:45:02 2006
@@ -165,7 +165,7 @@
   }
 }
 
-gint moveto(FT_Vector* to, gpointer data)
+gint moveto(const FT_Vector* to, gpointer data)
 {
   wxSVGCanvasTextFreetype* canvasText = (wxSVGCanvasTextFreetype*) data;
   
@@ -181,7 +181,7 @@
   return 0;
 }
 
-static gint lineto (FT_Vector* to, gpointer data)
+static gint lineto (const FT_Vector* to, gpointer data)
 {
   wxSVGCanvasTextFreetype* canvasText = (wxSVGCanvasTextFreetype*) data;
   if (!canvasText->m_endpath)
@@ -194,7 +194,7 @@
   return 0;
 }
 
-static gint conicto(FT_Vector* ftcontrol, FT_Vector* to, gpointer data)
+static gint conicto(const FT_Vector* ftcontrol, const FT_Vector* to, gpointer data)
 {
   wxSVGCanvasTextFreetype* canvasText = (wxSVGCanvasTextFreetype*) data;
   if (!canvasText->m_endpath)
@@ -209,8 +209,8 @@
   return 0;
 }
 
-static gint cubicto(FT_Vector* ftcontrol1, FT_Vector* ftcontrol2,
- FT_Vector* to, gpointer data)
+static gint cubicto(const FT_Vector* ftcontrol1, const FT_Vector* ftcontrol2,
+ const FT_Vector* to, gpointer data)
 {
   wxSVGCanvasTextFreetype* canvasText = (wxSVGCanvasTextFreetype*) data;
   if (!canvasText->m_endpath)
@@ -227,7 +227,7 @@
   return 0;
 }
 
-static const FT_Outline_Funcs outline_funcs =
+static FT_Outline_Funcs outline_funcs =
 {
   moveto, lineto, conicto, cubicto, 0, 0
 };
