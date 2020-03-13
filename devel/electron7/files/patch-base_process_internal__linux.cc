--- base/process/internal_linux.cc.orig	2019-12-12 12:38:59 UTC
+++ base/process/internal_linux.cc
@@ -60,10 +60,13 @@ bool ReadProcFile(const FilePath& file, std::string* b
   // Synchronously reading files in /proc is safe.
   ThreadRestrictions::ScopedAllowIO allow_io;
 
+#if !defined(OS_BSD)
   if (!ReadFileToString(file, buffer)) {
     DLOG(WARNING) << "Failed to read " << file.MaybeAsASCII();
     return false;
   }
+#endif
+
   return !buffer->empty();
 }
 
