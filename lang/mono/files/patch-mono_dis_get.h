--- mono/dis/get.h.orig	Thu Aug 25 11:12:40 2005
+++ mono/dis/get.h	Sun Oct  2 16:21:54 2005
@@ -44,6 +44,7 @@
 char *dis_stringify_method_signature (MonoImage *m, MonoMethodSignature *method, int methoddef_row,
 				      MonoGenericContext *context, gboolean fully_qualified);
 char *dis_stringify_function_ptr (MonoImage *m, MonoMethodSignature *method);
+char *dis_stringify_marshal_spec (MonoMarshalSpec *spec);
 
 guint32 method_dor_to_token (guint32 idx);
 
