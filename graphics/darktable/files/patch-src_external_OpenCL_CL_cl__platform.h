--- src/external/OpenCL/CL/cl_platform.h.orig	2020-11-17 15:04:41 UTC
+++ src/external/OpenCL/CL/cl_platform.h
@@ -355,7 +355,9 @@ typedef unsigned int cl_GLenum;
 
 /* Define basic vector types */
 #if defined( __VEC__ )
-   #include <altivec.h>   /* may be omitted depending on compiler. AltiVec spec provides no way to detect whether the header is required. */
+   #if !defined(__clang__)
+      #include <altivec.h>   /* may be omitted depending on compiler. AltiVec spec provides no way to detect whether the header is required. */
+   #endif
    typedef __vector unsigned char     __cl_uchar16;
    typedef __vector signed char       __cl_char16;
    typedef __vector unsigned short    __cl_ushort8;
