--- printing/mojom/printing_context_mojom_traits.cc.orig	2023-11-29 21:40:08 UTC
+++ printing/mojom/printing_context_mojom_traits.cc
@@ -19,7 +19,7 @@
 #include "base/numerics/safe_conversions.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "mojo/public/mojom/base/values.mojom.h"
 #endif
 
@@ -161,7 +161,7 @@ bool StructTraits<
   }
 
   out->set_pages_per_sheet(data.pages_per_sheet());
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   DCHECK(out->advanced_settings().empty());
   if (!data.ReadAdvancedSettings(&out->advanced_settings()))
     return false;
@@ -238,7 +238,7 @@ bool StructTraits<
     if (system_print_dialog_data.size() != dictionary_entries) {
       return false;
     }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // The dictionary must contain three strings.
     const base::Value* value = system_print_dialog_data.Find(
         printing::kLinuxSystemPrintDialogDataPrinter);
