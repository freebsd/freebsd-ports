--- ui/gfx/native_widget_types.h.orig	2025-04-22 20:15:27 UTC
+++ ui/gfx/native_widget_types.h
@@ -104,7 +104,7 @@ class SkBitmap;
 #endif
 class SkBitmap;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern "C" {
 struct _AtkObject;
 using AtkObject = struct _AtkObject;
@@ -194,7 +194,7 @@ using NativeViewAccessible = struct objc_object*;
 #else
 using NativeViewAccessible = struct objc_object*;
 #endif
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Linux doesn't have a native font type.
 using NativeViewAccessible = AtkObject*;
 #else
