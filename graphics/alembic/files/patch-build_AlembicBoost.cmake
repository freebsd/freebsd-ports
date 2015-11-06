--- build/AlembicBoost.cmake.orig	2015-01-15 18:28:49 UTC
+++ build/AlembicBoost.cmake
@@ -107,13 +107,13 @@ ENDIF()
 # Find the static and multi-threaded version only
 #-******************************************************************************
 #-******************************************************************************
-SET( Boost_USE_STATIC_LIBS TRUE )
+SET( Boost_USE_STATIC_LIBS FALSE )
 SET( Boost_USE_MULTITHREADED TRUE )
 SET( Boost_NO_BOOST_CMAKE TRUE ) 
 
 #- Alembic's python bridge boost-python 1.44 (for bug fixes)
 SET( Boost_ADDITIONAL_VERSIONS "1.44" "1.42" "1.42.0" "1.43" "1.43.0" "1.44" "1.44.0" "1.45.0" )
-FIND_PACKAGE( Boost COMPONENTS program_options python REQUIRED thread )
+FIND_PACKAGE( Boost COMPONENTS thread OPTIONAL_COMPONENTS python)
 
 
 #-******************************************************************************
