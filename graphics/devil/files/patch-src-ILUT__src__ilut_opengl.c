--- src-ILUT/src/ilut_opengl.c.orig	2009-02-07 03:17:36.000000000 +0900
+++ src-ILUT/src/ilut_opengl.c	2009-02-19 00:18:59.000000000 +0900
@@ -58,7 +58,7 @@
 //	#pragma comment(lib, "freeglut.lib")
 #endif
 
-#ifdef linux
+#if defined(linux) || defined(__FreeBSD__)
 	// fix for glXGetProcAddressARB
 	#define GLX_GLXEXT_PROTOTYPES
 	#include <GL/glx.h>
@@ -84,7 +84,7 @@
 
 static ILboolean HasCubemapHardware = IL_FALSE;
 static ILboolean HasNonPowerOfTwoHardware = IL_FALSE;
-#if defined(_WIN32) || defined(_WIN64) || defined(linux) || defined(__APPLE__)
+#if defined(_WIN32) || defined(_WIN64) || defined(linux) || defined(__APPLE__) || defined(__FreeBSD__)
 	ILGLTEXIMAGE3DARBPROC			ilGLTexImage3D = NULL;
 	ILGLTEXSUBIMAGE3DARBPROC		ilGLTexSubImage3D = NULL;
 	ILGLCOMPRESSEDTEXIMAGE2DARBPROC	ilGLCompressed2D = NULL;
@@ -127,7 +127,7 @@
 			IsExtensionSupported("GL_EXT_texture3D")) {
 				ilGLCompressed3D = (ILGLCOMPRESSEDTEXIMAGE3DARBPROC)wglGetProcAddress("glCompressedTexImage3DARB");
 		}
-	#elif linux
+	#elif (defined(linux) || defined(__FreeBSD__))
 		if (IsExtensionSupported("GL_ARB_texture_compression") &&
 			IsExtensionSupported("GL_EXT_texture_compression_s3tc")) {
 				ilGLCompressed2D = (ILGLCOMPRESSEDTEXIMAGE2DARBPROC)
@@ -246,7 +246,7 @@
 ILboolean ILAPIENTRY ilutGLTexImage_(GLuint Level, GLuint Target, ILimage *Image)
 {
 	ILimage	*ImageCopy, *OldImage;
-#if defined (_MSC_VER) || defined (linux) || defined(__APPLE__)
+#if defined (_MSC_VER) || defined (linux) || defined(__APPLE__) || defined(__FreeBSD__)
 	ILenum	DXTCFormat;
 	ILuint	Size;
 	ILubyte	*Buffer;
@@ -259,7 +259,7 @@
 
 	OldImage = ilGetCurImage();
 
-#if defined (_MSC_VER) || defined (linux) || defined(__APPLE__)
+#if defined (_MSC_VER) || defined (linux) || defined(__APPLE__) || defined(__FreeBSD__)
 	if (ilutGetBoolean(ILUT_GL_USE_S3TC) && ilGLCompressed2D != NULL) {
 		if (Image->DxtcData != NULL && Image->DxtcSize != 0) {
 			DXTCFormat = GLGetDXTCNum(Image->DxtcFormat);
