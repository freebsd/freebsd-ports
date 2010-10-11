--- vm/builtin/ffi_pointer.cpp.orig	2010-10-11 00:23:21.000000000 -0700
+++ vm/builtin/ffi_pointer.cpp	2010-10-11 00:23:59.000000000 -0700
@@ -38,6 +38,9 @@
     G(ffi_pointer)->set_const(state, "DLSYM",
       Pointer::create(state, (void*)dlsym));
 
+    G(ffi_pointer)->set_const(state, "DLOPEN",
+      Pointer::create(state, (void*)dlopen));
+
     // Not exactly the right place, but FFI needs this and this is the main
     // FFI file atm.
     Array* suffix = Array::create(state, 2);
