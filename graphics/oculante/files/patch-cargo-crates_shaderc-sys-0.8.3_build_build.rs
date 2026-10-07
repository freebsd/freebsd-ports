--- cargo-crates/shaderc-sys-0.8.3/build/build.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/shaderc-sys-0.8.3/build/build.rs
@@ -70,7 +70,9 @@ fn build_shaderc_unix(shaderc_dir: &PathBuf, use_ninja
         .define("SHADERC_SKIP_TESTS", "ON")
         // SPIRV-Tools options
         .define("SPIRV_SKIP_EXECUTABLES", "ON")
-        .define("SPIRV_WERROR", "OFF");
+        .define("SPIRV_WERROR", "OFF")
+        // CMake 4.5 compatibility
+        .define("CMAKE_POLICY_VERSION_MINIMUM", "3.5");
     if use_ninja {
         config.generator("Ninja");
     }
