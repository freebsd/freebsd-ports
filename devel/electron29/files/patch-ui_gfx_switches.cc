--- ui/gfx/switches.cc.orig	2024-02-21 00:21:15 UTC
+++ ui/gfx/switches.cc
@@ -28,7 +28,7 @@ const char kHeadless[] = "headless";
 // Run in headless mode, i.e., without a UI or display server dependencies.
 const char kHeadless[] = "headless";
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Which X11 display to connect to. Emulates the GTK+ "--display=" command line
 // argument. In use only with Ozone/X11.
 const char kX11Display[] = "display";
