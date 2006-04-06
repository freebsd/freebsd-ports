--- Source/RIGSProxySetup.h.orig	Wed Apr  5 09:19:44 2006
+++ Source/RIGSProxySetup.h	Wed Apr  5 09:25:41 2006
@@ -90,7 +90,7 @@
  * objective-C runtime. 
  */
 int _RIGS_ruby_method_arity(const char *rb_class_name, const char *rb_mth_name);
-id  _RIGS_register_ruby_class (VALUE rb_class);
+Class _RIGS_register_ruby_class (VALUE rb_class);
 VALUE _RIGS_register_ruby_class_from_ruby (VALUE self, VALUE rb_class);
 BOOL _RIGS_build_objc_types(VALUE rb_class, const char *rb_mth_name,
 			    const char retValueType, int nbArgs, char *sigBuf);
