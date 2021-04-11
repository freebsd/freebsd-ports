--- sandbox/share/cmake/Modules/FindImath.cmake.orig	2019-08-31 15:49:01 UTC
+++ sandbox/share/cmake/Modules/FindImath.cmake
@@ -39,10 +39,8 @@
 
 include (FindPackageHandleStandardArgs)
 
-find_path (IMATH_INCLUDE_DIR NAMES OpenEXR/ImathVec.h)
+find_path (IMATH_INCLUDE_DIR NAMES Imath/ImathVec.h)
 
-find_library (IMATH_HALF_LIBRARY NAMES Half)
-find_library (IMATH_IEX_LIBRARY NAMES Iex)
 find_library (IMATH_MATH_LIBRARY NAMES Imath)
 
 # Handle the QUIETLY and REQUIRED arguments and set IMATH_FOUND.
