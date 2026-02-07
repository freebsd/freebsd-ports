--- swift-syntax/cmake/modules/AddSwiftHostLibrary.cmake.orig	2024-05-07 16:02:05 UTC
+++ swift-syntax/cmake/modules/AddSwiftHostLibrary.cmake
@@ -44,6 +44,7 @@ function(add_swift_syntax_library name)
   set(module_base "${module_dir}/${name}.swiftmodule")
   set(module_file "${module_base}/${SWIFT_HOST_MODULE_TRIPLE}.swiftmodule")
   set(module_interface_file "${module_base}/${SWIFT_HOST_MODULE_TRIPLE}.swiftinterface")
+  set(module_private_interface_file "${module_base}/${SWIFT_HOST_MODULE_TRIPLE}.private.swiftinterface")
   set(module_sourceinfo_file "${module_base}/${SWIFT_HOST_MODULE_TRIPLE}.swiftsourceinfo")
 
   # Add a custom target to create the module directory.
@@ -76,7 +77,8 @@ function(add_swift_syntax_library name)
       -enable-library-evolution;
       -emit-module-path;${module_file};
       -emit-module-source-info-path;${module_sourceinfo_file};
-      -emit-module-interface-path;${module_interface_file}
+      -emit-module-interface-path;${module_interface_file};
+      -emit-private-module-interface-path;${module_private_interface_file}
     >)
   if(SWIFT_MODULE_ABI_NAME_PREFIX)
     # ABI name prefix. this can be used to avoid name conflicts.
