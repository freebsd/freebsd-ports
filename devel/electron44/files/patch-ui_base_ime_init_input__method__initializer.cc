--- ui/base/ime/init/input_method_initializer.cc.orig	2025-03-24 20:50:14 UTC
+++ ui/base/ime/init/input_method_initializer.cc
@@ -9,7 +9,7 @@
 #include "base/trace_event/trace_event.h"
 #include "build/build_config.h"
 
-#if defined(USE_AURA) && BUILDFLAG(IS_LINUX)
+#if defined(USE_AURA) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
 #include "ui/base/ime/linux/fake_input_method_context.h"
 #include "ui/base/ime/linux/linux_input_method_context_factory.h"
 #elif BUILDFLAG(IS_WIN)
@@ -33,7 +33,7 @@ void InitializeInputMethodForTesting() {
 }
 
 void InitializeInputMethodForTesting() {
-#if defined(USE_AURA) && BUILDFLAG(IS_LINUX)
+#if defined(USE_AURA) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
   GetInputMethodContextFactoryForTest() =
       base::BindRepeating([](LinuxInputMethodContextDelegate* delegate)
                               -> std::unique_ptr<LinuxInputMethodContext> {
@@ -45,7 +45,7 @@ void ShutdownInputMethodForTesting() {
 }
 
 void ShutdownInputMethodForTesting() {
-#if defined(USE_AURA) && BUILDFLAG(IS_LINUX)
+#if defined(USE_AURA) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
   // The function owns the factory (as a static variable that's returned by
   // reference), so setting this to an empty factory will free the old one.
   GetInputMethodContextFactoryForTest() = LinuxInputMethodContextFactory();
