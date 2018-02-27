--- hotspot/src/cpu/zero/vm/methodHandles_zero.cpp.orig
+++ hotspot/src/cpu/zero/vm/methodHandles_zero.cpp
@@ -180,3 +180,9 @@ address MethodHandles::generate_method_handle_interpre
     return NULL;
   }
 }
+
+#ifndef PRODUCT
+void MethodHandles::trace_method_handle(MacroAssembler* _masm, const char* adaptername) {
+  // This is just a stub.
+}
+#endif //PRODUCT
