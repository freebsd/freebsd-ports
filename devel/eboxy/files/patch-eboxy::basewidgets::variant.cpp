--- eboxy/basewidgets/variant.cpp.orig	2007-08-03 16:10:33.000000000 +0200
+++ eboxy/basewidgets/variant.cpp	2007-08-03 16:10:52.000000000 +0200
@@ -90,7 +90,7 @@
 
 Variant Variant::operator= (void *value) {
   SetType(VARTYPE_OBJREF);
-  intvalue = (int)value;
+  intvalue = (intptr_t)value;
   return *this;
 }
 
