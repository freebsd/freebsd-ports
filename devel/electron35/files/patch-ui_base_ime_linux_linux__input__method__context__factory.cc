--- ui/base/ime/linux/linux_input_method_context_factory.cc.orig	2022-09-27 14:30:33 UTC
+++ ui/base/ime/linux/linux_input_method_context_factory.cc
@@ -9,7 +9,7 @@
 #include "build/build_config.h"
 #include "ui/base/ime/linux/fake_input_method_context.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #include "ui/linux/linux_ui_delegate.h"
 #endif
@@ -32,7 +32,7 @@ std::unique_ptr<LinuxInputMethodContext> CreateLinuxIn
   if (auto factory = GetInputMethodContextFactoryForTest())
     return factory.Run(delegate);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Give the toolkit a chance to create the context.
   if (auto* linux_ui = LinuxUi::instance()) {
     if (auto context = linux_ui->CreateInputMethodContext(delegate))
