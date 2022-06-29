--- ui/views/linux_ui/linux_ui.cc.orig	2022-05-19 05:18:02 UTC
+++ ui/views/linux_ui/linux_ui.cc
@@ -21,7 +21,7 @@ void LinuxUI::SetInstance(std::unique_ptr<LinuxUI> ins
   g_linux_ui = instance.release();
 
   SkiaFontDelegate::SetInstance(g_linux_ui);
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMECAST)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CHROMECAST)
   ShellDialogLinux::SetInstance(g_linux_ui);
 #endif
   ui::SetTextEditKeyBindingsDelegate(g_linux_ui);
