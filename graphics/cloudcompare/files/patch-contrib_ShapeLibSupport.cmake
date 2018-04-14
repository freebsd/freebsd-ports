--- contrib/ShapeLibSupport.cmake.orig	2018-03-16 21:26:02 UTC
+++ contrib/ShapeLibSupport.cmake
@@ -4,14 +4,14 @@
 
 OPTION( OPTION_USE_SHAPE_LIB "Build with ShapeLib (SHP files support)" OFF )
 if( ${OPTION_USE_SHAPE_LIB} )
-	add_subdirectory(contrib/shapelib-1.3.0)
-	include_directories( ${SHAPELIB_SOURCE_DIR} )
+	#add_subdirectory(contrib/shapelib-1.3.0)
+	#include_directories( ${SHAPELIB_SOURCE_DIR} )
 endif()
 
 # Link project with shapelib library
 function( target_link_SHAPE_LIB ) # 2 arguments: ARGV0 = project name
 	if( ${OPTION_USE_SHAPE_LIB} )
-		target_link_libraries( ${PROJECT_NAME} SHAPELIB )	
+		target_link_libraries( ${PROJECT_NAME} shp )	
 		set_property( TARGET ${PROJECT_NAME} APPEND PROPERTY COMPILE_DEFINITIONS CC_SHP_SUPPORT )
 	endif()
 endfunction()
