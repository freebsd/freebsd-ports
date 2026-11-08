-- Fall back to system harfbuzz when skia was built with skia_use_system_harfbuzz=true.
-- Make icudtl.dat copy conditional on the file existing; when skia uses system ICU,
-- the dat file is not present and not needed.

--- laf/cmake/FindSkia.cmake.orig	2026-08-20 17:52:30 UTC
+++ laf/cmake/FindSkia.cmake
@@ -175,11 +175,24 @@ set(FREETYPE_LIBRARIES ${FREETYPE_LIBRARY})
 set(FREETYPE_FOUND ON)
 find_library(FREETYPE_LIBRARY freetype2 PATH "${SKIA_LIBRARY_DIR}" NO_DEFAULT_PATH)
 set(FREETYPE_LIBRARIES ${FREETYPE_LIBRARY})
-set(FREETYPE_INCLUDE_DIRS "${SKIA_DIR}/third_party/externals/freetype/include")
+find_path(FREETYPE_INCLUDE_DIR NAMES ft2build.h PATH_SUFFIXES freetype2)
+if(FREETYPE_INCLUDE_DIR)
+  set(FREETYPE_INCLUDE_DIRS ${FREETYPE_INCLUDE_DIR})
+else()
+  set(FREETYPE_INCLUDE_DIRS "${SKIA_DIR}/third_party/externals/freetype/include")
+endif()
 
 find_library(HARFBUZZ_LIBRARY harfbuzz PATH "${SKIA_LIBRARY_DIR}" NO_DEFAULT_PATH)
-set(HARFBUZZ_LIBRARIES ${HARFBUZZ_LIBRARY})
-set(HARFBUZZ_INCLUDE_DIRS "${SKIA_DIR}/third_party/externals/harfbuzz/src")
+if(HARFBUZZ_LIBRARY)
+  set(HARFBUZZ_LIBRARIES ${HARFBUZZ_LIBRARY})
+  set(HARFBUZZ_INCLUDE_DIRS "${SKIA_DIR}/third_party/externals/harfbuzz/src")
+elseif(NOT HARFBUZZ_LIBRARIES)
+  # Fall back to system harfbuzz (when skia was built with skia_use_system_harfbuzz=true)
+  find_library(HARFBUZZ_LIBRARY harfbuzz)
+  find_path(HARFBUZZ_INCLUDE_DIR NAMES hb.h PATH_SUFFIXES harfbuzz)
+  set(HARFBUZZ_LIBRARIES ${HARFBUZZ_LIBRARY})
+  set(HARFBUZZ_INCLUDE_DIRS ${HARFBUZZ_INCLUDE_DIR})
+endif()
 
 set(SKIA_LIBRARIES
   ${SKIA_LIBRARY}
@@ -193,6 +206,7 @@ target_link_libraries(skia INTERFACE ${SKIA_LIBRARIES}
   ${HARFBUZZ_INCLUDE_DIRS}
   ${PNG_INCLUDE_DIRS})
 target_link_libraries(skia INTERFACE ${SKIA_LIBRARIES})
+target_link_libraries(skia INTERFACE libjpeg-turbo)
 target_compile_definitions(skia INTERFACE
   SK_INTERNAL
   SK_GAMMA_SRGB
@@ -242,7 +256,9 @@ add_library(skunicode INTERFACE)
 endif()
 
 add_library(skunicode INTERFACE)
+find_library(ICUUC_LIBRARY icuuc)
 target_link_libraries(skunicode INTERFACE ${SKUNICODE_LIBRARY})
+target_link_libraries(skunicode INTERFACE ${ICUUC_LIBRARY})
 target_compile_definitions(skunicode INTERFACE
   SK_UNICODE_AVAILABLE)
 
@@ -260,11 +276,13 @@ set(SKIA_ICUDATA_FILE_OUTPUT ${SKIA_ICUDATA_OUTPUT_DIR
 
 set(SKIA_ICUDATA_FILE ${SKIA_DIR}/third_party/externals/icu/flutter/icudtl.dat)
 set(SKIA_ICUDATA_FILE_OUTPUT ${SKIA_ICUDATA_OUTPUT_DIR}/icudtl.dat)
-add_custom_command(
-  OUTPUT ${SKIA_ICUDATA_FILE_OUTPUT}
-  COMMAND ${CMAKE_COMMAND} -E copy_if_different ${SKIA_ICUDATA_FILE} ${SKIA_ICUDATA_FILE_OUTPUT}
-  MAIN_DEPENDENCY ${SKIA_ICUDATA_FILE}
-  DEPENDS ${GEN_DEP})
-add_custom_target(skia_copy_icudata
-  DEPENDS ${SKIA_ICUDATA_FILE_OUTPUT})
-add_dependencies(skunicode skia_copy_icudata)
+if(EXISTS ${SKIA_ICUDATA_FILE})
+  add_custom_command(
+    OUTPUT ${SKIA_ICUDATA_FILE_OUTPUT}
+    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${SKIA_ICUDATA_FILE} ${SKIA_ICUDATA_FILE_OUTPUT}
+    MAIN_DEPENDENCY ${SKIA_ICUDATA_FILE}
+    DEPENDS ${GEN_DEP})
+  add_custom_target(skia_copy_icudata
+    DEPENDS ${SKIA_ICUDATA_FILE_OUTPUT})
+  add_dependencies(skunicode skia_copy_icudata)
+endif()
