--- src/plugins/cantushashvalue.c.orig	2007-08-03 14:31:22.000000000 +0200
+++ source/cantus/cantushashvalue.c	2007-08-03 14:35:10.000000000 +0200
@@ -81,7 +81,7 @@
   g_assert(hvalue != NULL);
   switch (type) {
   case G_TYPE_INT:
-    value_set_int(hvalue, (gint)value);
+    value_set_int(hvalue, (gint64)value);
     break;
   
   case G_TYPE_CHAR:
@@ -90,7 +90,7 @@
     break;
   
   case G_TYPE_BOOLEAN:
-    value_set_bool(hvalue, (gboolean)value);
+    value_set_bool(hvalue, (gint64)value);
     break;
   
   case G_TYPE_POINTER:
@@ -157,7 +157,7 @@
   if (hvalue->type != G_TYPE_BOOLEAN)
     g_warning("G_TYPE_BOOLEAN value requested from non-G_TYPE_BOOLEAN"
               " container.\n");
-  return (gboolean)hvalue->value;
+  return (gint64) hvalue->value;
 }
 
 
