--- plug-ins/python/pydia-geometry.c.orig	Sat Jul 19 00:22:20 2003
+++ plug-ins/python/pydia-geometry.c	Sat Jul 19 00:22:34 2003
@@ -211,7 +211,7 @@
 {
 #define I_OR_F(v) \
   (self->is_int ? \
-   PyInt_FromLong(self->r.ri.##v) : PyFloat_FromDouble(self->r.rf.##v))
+   PyInt_FromLong(self->r.ri./**/v) : PyFloat_FromDouble(self->r.rf./**/v))
 
   if (!strcmp(attr, "__members__"))
     return Py_BuildValue("[ssss]", "top", "left", "right", "bottom" );
