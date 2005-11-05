--- cairo/pycairo-font.c.orig	Mon Aug  1 05:31:41 2005
+++ cairo/pycairo-font.c	Wed Aug  3 01:09:38 2005
@@ -196,6 +196,7 @@ scaled_font_new (PyTypeObject *type, PyO
     PycairoFontFace *ff;
     PycairoFontOptions *fo;
     PycairoMatrix *mx1, *mx2;
+    PyObject *o;
 
     if (!PyArg_ParseTuple(args, "O!O!O!O!:ScaledFont.__new__",
 			  &PycairoFontFace_Type, &ff,
@@ -204,7 +205,7 @@ scaled_font_new (PyTypeObject *type, PyO
 			  &PycairoFontOptions_Type, &fo))
 	return NULL;
 
-    PyObject *o = type->tp_alloc(type, 0);
+    o = type->tp_alloc(type, 0);
     if (o) {
 	cairo_scaled_font_t *scaled_font = cairo_scaled_font_create 
 	    (ff->font_face, &mx1->matrix, &mx2->matrix, fo->font_options);
