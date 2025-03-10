--- ui/base/ime/init/input_method_initializer.cc.orig	2024-06-01 07:22:39 UTC
+++ ui/base/ime/init/input_method_initializer.cc
@@ -10,7 +10,7 @@
 #include "build/chromeos_buildflags.h"
 
 #if !BUILDFLAG(IS_CHROMEOS_ASH) && defined(USE_AURA) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
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
@@ -46,7 +46,7 @@ void ShutdownInputMethodForTesting() {
 
 void ShutdownInputMethodForTesting() {
 #if !BUILDFLAG(IS_CHROMEOS_ASH) && defined(USE_AURA) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
   // The function owns the factory (as a static variable that's returned by
   // reference), so setting this to an empty factory will free the old one.
   GetInputMethodContextFactoryForTest() = LinuxInputMethodContextFactory();
