--- weblayer/browser/browser_main_parts_impl.cc.orig	2022-05-19 05:18:02 UTC
+++ weblayer/browser/browser_main_parts_impl.cc
@@ -78,7 +78,7 @@
 
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if defined(USE_AURA) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if defined(USE_AURA) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
 #include "ui/base/ime/init/input_method_initializer.h"
 #endif
 
@@ -196,7 +196,7 @@ int BrowserMainPartsImpl::PreEarlyInitialization() {
 
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if defined(USE_AURA) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if defined(USE_AURA) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
   ui::InitializeInputMethodForTesting();
 #endif
 #if BUILDFLAG(IS_ANDROID)
