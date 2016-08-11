Required by CMake >= 3.6.0, which properly separates HDF5_LIBRARIES (libraries
for the requested language bindings) and HDF5_HL_LIBRARIES (high-level
libraries for the requested language bindings).

This patch can be removed when Alembic is updated to 1.6.0 or later, which
drops the usage of HDF5's high-level libraries.
--- build/AlembicHDF5.cmake.orig	2016-07-23 11:57:11 UTC
+++ build/AlembicHDF5.cmake
@@ -87,7 +87,7 @@ IF( HDF5_FOUND )
   ENDIF()
   SET( ALEMBIC_HDF5_LIB ${HDF5_C_LIBRARIES} )
   SET( ALEMBIC_HDF5_HL_LIB ${HDF5_CXX_LIBRARIES} )
-  SET( ALEMBIC_HDF5_LIBS ${HDF5_LIBRARIES} )
+  SET( ALEMBIC_HDF5_LIBS ${HDF5_LIBRARIES} ${HDF5_HL_LIBRARIES} )
   SET( ALEMBIC_HDF5_FOUND TRUE )
 
   MESSAGE(STATUS "HDF5 INCLUDE PATH: ${ALEMBIC_HDF5_INCLUDE_PATH}" )
