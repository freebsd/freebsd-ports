--- printing/backend/cups_helper.cc.orig	2021-07-15 19:13:43 UTC
+++ printing/backend/cups_helper.cc
@@ -24,7 +24,7 @@
 #include "printing/units.h"
 #include "url/gurl.h"
 
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 #include <unistd.h>
 
 #include "base/files/scoped_file.h"
@@ -578,7 +578,7 @@ bool ParsePpdCapabilities(cups_dest_t* dest,
                           base::StringPiece printer_capabilities,
                           PrinterSemanticCapsAndDefaults* printer_info) {
   base::FilePath ppd_file_path;
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   // A file created while in a sandbox will be automatically deleted once all
   // handles to it have been closed.  This precludes the use of multiple
   // operations against a file path.
@@ -625,7 +625,7 @@ bool ParsePpdCapabilities(cups_dest_t* dest,
     ppd_status_t ppd_status = ppdLastError(&line);
     LOG(ERROR) << "Failed to open PDD file: error " << ppd_status << " at line "
                << line << ", " << ppdErrorString(ppd_status);
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
     if (ppd_status != PPD_FILE_OPEN_ERROR) {
       // When the error is not from opening the file then the CUPS library
       // internals will have already closed the file descriptor.  It is
@@ -716,7 +716,7 @@ bool ParsePpdCapabilities(cups_dest_t* dest,
   }
 
   ppdClose(ppd);
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   // The CUPS library internals close the file descriptor upon successfully
   // reading it.  Explicitly release the `ScopedFD` to prevent a crash caused
   // by a bad file descriptor.
