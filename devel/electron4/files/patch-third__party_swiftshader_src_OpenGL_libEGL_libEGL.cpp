--- third_party/swiftshader/src/OpenGL/libEGL/libEGL.cpp.orig	2019-03-15 06:41:56 UTC
+++ third_party/swiftshader/src/OpenGL/libEGL/libEGL.cpp
@@ -119,7 +119,7 @@ EGLDisplay GetDisplay(EGLNativeDisplayType display_id)
 		// FIXME: Check if display_id is the default display
 	}
 
-	#if defined(__linux__) && !defined(__ANDROID__)
+	#if (defined(__linux__) || defined(__FreeBSD)) && !defined(__ANDROID__)
 		#if defined(USE_X11)
 		if(!libX11)
 		#endif  // Non X11 linux is headless only
@@ -178,7 +178,7 @@ const char *QueryString(EGLDisplay dpy, EGLint name)
 	{
 		return success(
 			"EGL_KHR_client_get_all_proc_addresses "
-#if defined(__linux__) && !defined(__ANDROID__)
+#if (defined(__linux__) || defined(__FreeBSD__)) && !defined(__ANDROID__)
 			"EGL_KHR_platform_gbm "
 #endif
 #if defined(USE_X11)
@@ -1172,7 +1172,7 @@ EGLDisplay GetPlatformDisplayEXT(EGLenum platform, voi
 {
 	TRACE("(EGLenum platform = 0x%X, void *native_display = %p, const EGLint *attrib_list = %p)", platform, native_display, attrib_list);
 
-	#if defined(__linux__) && !defined(__ANDROID__)
+	#if (defined(__linux__) || defined(__FreeBSD__)) && !defined(__ANDROID__)
 		switch(platform)
 		{
 		#if defined(USE_X11)
