--- ui/gfx/native_widget_types.h.orig	2025-06-30 07:04:30 UTC
+++ ui/gfx/native_widget_types.h
@@ -102,7 +102,7 @@ class SkBitmap;
 #endif
 class SkBitmap;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern "C" {
 struct _AtkObject;
 using AtkObject = struct _AtkObject;
@@ -186,7 +186,7 @@ using NativeViewAccessible = base::apple::OwnedNSAcces
 using NativeViewAccessible = base::apple::OwnedNSObject;
 #elif BUILDFLAG(IS_MAC)
 using NativeViewAccessible = base::apple::OwnedNSAccessibility;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Linux doesn't have a native accessibility type.
 using NativeViewAccessible = AtkObject*;
 #else
