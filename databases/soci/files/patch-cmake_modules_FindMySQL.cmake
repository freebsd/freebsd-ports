Prevent CMAKE_REQUIRED_LIBRARIES from leaking out of this module.
If the embedded libs are not found, we don't want to have the
not-found libraries required by other modules.

--- cmake/modules/FindMySQL.cmake.orig	2013-08-21 22:40:11 UTC
+++ cmake/modules/FindMySQL.cmake
@@ -119,6 +119,7 @@ endif(MYSQL_EMBEDDED_LIBRARIES)
 set( CMAKE_REQUIRED_INCLUDES ${MYSQL_INCLUDE_DIR} )
 set( CMAKE_REQUIRED_LIBRARIES ${MYSQL_EMBEDDED_LIBRARIES} )
 check_cxx_source_compiles( "#include <mysql.h>\nint main() { int i = MYSQL_OPT_USE_EMBEDDED_CONNECTION; }" HAVE_MYSQL_OPT_EMBEDDED_CONNECTION )
+unset( CMAKE_REQUIRED_LIBRARIES )
 
 if(MYSQL_INCLUDE_DIR AND MYSQL_LIBRARIES)
    set(MYSQL_FOUND TRUE)
