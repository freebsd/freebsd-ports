--- printing/backend/cups_helper.h.orig	2025-08-26 20:49:50 UTC
+++ printing/backend/cups_helper.h
@@ -32,7 +32,7 @@ constexpr cups_ptype_t kDestinationsFilterMask =
 constexpr cups_ptype_t kDestinationsFilterMask =
     CUPS_PRINTER_FAX | CUPS_PRINTER_SCANNER | CUPS_PRINTER_DISCOVERED;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Helper wrapper around http_t structure, with connection and cleanup
 // functionality.
 class COMPONENT_EXPORT(PRINT_BACKEND) HttpConnectionCUPS {
