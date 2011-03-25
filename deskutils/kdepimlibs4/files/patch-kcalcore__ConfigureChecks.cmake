--- ./kcalcore/ConfigureChecks.cmake.orig	2010-12-03 15:38:57.478419881 +1000
+++ ./kcalcore/ConfigureChecks.cmake	2010-12-03 15:59:50.369411055 +1000
@@ -2,6 +2,11 @@
 include(CheckLibraryExists)
 
 check_include_files(uuid/uuid.h HAVE_UUID_UUID_H)
-check_library_exists(uuid uuid_generate_random "" HAVE_UUID_LIBRARY)
+find_library(UUID_LIBRARY uuid)
+set(UUID_LIBRARY_DIR "")
+if(UUID_LIBRARY)
+   get_filename_component(UUID_LIBRARY_DIR ${UUID_LIBRARY} PATH)
+endif(UUID_LIBRARY)
+check_library_exists(uuid uuid_generate_random "${UUID_LIBRARY_DIR}" HAVE_UUID_LIBRARY)
 
 
