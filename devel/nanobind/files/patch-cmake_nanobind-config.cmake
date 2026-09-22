-- remove -mtls-dialect=gnu2 since it breaks generated binaries
-- and they can't be loaded with unknown relocation entry types

--- cmake/nanobind-config.cmake.orig	2026-09-18 15:58:10 UTC
+++ cmake/nanobind-config.cmake
@@ -113,10 +113,10 @@ set(NB_OPT_SIZE $<OR:$<CONFIG:Release>,$<CONFIG:MinSiz
 # Probe for the faster TLSDESC thread-local storage ABI (Linux/x86_64)
 # ---------------------------------------------------------------------------
 
-if (NOT (MSVC OR WIN32 OR APPLE))
-  include(CheckCXXCompilerFlag)
-  check_cxx_compiler_flag(-mtls-dialect=gnu2 NB_HAS_MTLS_GNU2)
-endif()
+#if (NOT (MSVC OR WIN32 OR APPLE))
+#  include(CheckCXXCompilerFlag)
+#  check_cxx_compiler_flag(-mtls-dialect=gnu2 NB_HAS_MTLS_GNU2)
+#endif()
 
 # ---------------------------------------------------------------------------
 # Helper function to handle undefined CPython API symbols on macOS
