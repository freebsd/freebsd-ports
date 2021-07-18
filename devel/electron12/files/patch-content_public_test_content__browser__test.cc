--- content/public/test/content_browser_test.cc.orig	2021-04-14 01:08:48 UTC
+++ content/public/test/content_browser_test.cc
@@ -29,7 +29,7 @@
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/base/ime/init/input_method_initializer.h"
 #endif
 
@@ -92,7 +92,7 @@ void ContentBrowserTest::SetUp() {
   // LinuxInputMethodContextFactory has to be initialized.
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_LINUX) || defined(OS_BSD)
   ui::InitializeInputMethodForTesting();
 #endif
 
@@ -107,7 +107,7 @@ void ContentBrowserTest::TearDown() {
   // LinuxInputMethodContextFactory has to be shutdown.
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_LINUX) || defined(OS_BSD)
   ui::ShutdownInputMethodForTesting();
 #endif
 }
