--- ui/views/widget/widget.h.orig	2022-10-24 13:33:33 UTC
+++ ui/views/widget/widget.h
@@ -402,7 +402,7 @@ class VIEWS_EXPORT Widget : public internal::NativeWid
     // If set, the widget was created in headless mode.
     bool headless_mode = false;
 
-#if defined(USE_AURA) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if defined(USE_AURA) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
     // Indicates whether the desktop native widget is required for the widget.
     // This may enforce changing the type of the underlying platform window.
     // See crbug.com/1280332
