--- pdf/out_of_process_instance.cc.orig	2022-05-19 05:17:45 UTC
+++ pdf/out_of_process_instance.cc
@@ -74,7 +74,7 @@
 #include "ui/gfx/geometry/size.h"
 #include "url/gurl.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "pdf/ppapi_migration/pdfium_font_linux.h"
 #endif
 
@@ -734,7 +734,7 @@ void OutOfProcessInstance::RotateCounterclockwise() {
 }
 
 void OutOfProcessInstance::SetLastPluginInstance() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   SetLastPepperInstance(this);
 #endif
 }
