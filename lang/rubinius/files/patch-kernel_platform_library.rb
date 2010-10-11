--- kernel/platform/library.rb.orig	2010-10-11 00:22:14.000000000 -0700
+++ kernel/platform/library.rb	2010-10-11 00:23:09.000000000 -0700
@@ -187,7 +187,7 @@
 
     dlopen = find_symbol(FFI::Pointer::CURRENT_PROCESS, "dlopen")
 
-    pointer_as_function :open_library, dlopen, [:string, :int], :pointer
+    pointer_as_function :open_library, FFI::Pointer::DLOPEN, [:string, :int], :pointer
 
     dlerror = find_symbol(FFI::Pointer::CURRENT_PROCESS, "dlerror")
 
@@ -195,8 +195,8 @@
 
     RTLD_LAZY = 0x1
     RTLD_NOW  = 0x2
-    RTLD_GLOBAL = 0x4
-    RTLD_LOCAL  = 0x8
+    RTLD_GLOBAL = 0x100
+    RTLD_LOCAL  = 0x0
 
     class << self
       alias_method :open, :new
