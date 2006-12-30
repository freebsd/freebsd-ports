--- include/IrrCompileConfig.h	Fri Dec 29 19:14:48 2006
+++ include/IrrCompileConfig.h	Fri Dec 29 19:15:49 2006
@@ -90,7 +90,7 @@
 //! Define _IRR_USE_NON_SYSTEM_ZLIB_ to let irrlicht use the zlib which comes with irrlicht.
 /** If this is commented out, Irrlicht will try to compile using the zlib installed in the system.
  This is only used when _IRR_COMPILE_WITH_ZLIB_ is defined. */
-#define _IRR_USE_NON_SYSTEM_ZLIB_
+//#define _IRR_USE_NON_SYSTEM_ZLIB_
 
 
 //! Define _IRR_COMPILE_WITH_JPEGLIB_ to enable compiling the engine using libjpeg.
@@ -101,7 +101,7 @@
 //! Define _IRR_USE_NON_SYSTEM_JPEG_LIB_ to let irrlicht use the jpeglib which comes with irrlicht.
 /** If this is commented out, Irrlicht will try to compile using the jpeg lib installed in the system.
  This is only used when _IRR_COMPILE_WITH_LIBJPEG_ is defined. */
-#define _IRR_USE_NON_SYSTEM_JPEG_LIB_
+//#define _IRR_USE_NON_SYSTEM_JPEG_LIB_
 
 
 //! Define _IRR_COMPILE_WITH_LIBPNG_ to enable compiling the engine using libpng.
@@ -112,7 +112,7 @@
 //! Define _IRR_USE_NON_SYSTEM_LIBPNG_ to let irrlicht use the libpng which comes with irrlicht.
 /** If this is commented out, Irrlicht will try to compile using the libpng installed in the system.
  This is only used when _IRR_COMPILE_WITH_LIBPNG_ is defined. */
-#define _IRR_USE_NON_SYSTEM_LIB_PNG_
+//#define _IRR_USE_NON_SYSTEM_LIB_PNG_
 
 
 //! Define _IRR_D3D_NO_SHADER_DEBUGGING to disable shader debugging in D3D9
