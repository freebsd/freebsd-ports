--- weblayer/browser/browser_main_parts_impl.cc.orig	2022-05-25 04:01:58 UTC
+++ weblayer/browser/browser_main_parts_impl.cc
@@ -79,7 +79,7 @@
 
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if defined(USE_AURA) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if defined(USE_AURA) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
 #include "ui/base/ime/init/input_method_initializer.h"
 #endif
 
@@ -198,7 +198,7 @@ int BrowserMainPartsImpl::PreEarlyInitialization() {
 
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if defined(USE_AURA) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if defined(USE_AURA) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
   ui::InitializeInputMethodForTesting();
 #endif
 #if BUILDFLAG(IS_ANDROID)
