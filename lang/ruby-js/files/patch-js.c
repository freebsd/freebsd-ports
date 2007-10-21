Index: js.c
@@ -112,9 +112,9 @@
 static VALUE
 rb_js_eval(VALUE obj, VALUE code)
 {
-  JSInterpPtr interp;
-  Data_Get_Struct(obj, JSInterpPtr, (void *) interp);
-  return rb_js_evalcode(interp, code);
+  void *interp;
+  Data_Get_Struct(obj, JSInterpPtr, interp);
+  return rb_js_evalcode((JSInterpPtr) interp, code);
 }
 
 void
