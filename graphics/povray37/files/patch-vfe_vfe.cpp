--- vfe/vfe.cpp.orig	2021-07-08 09:56:01 UTC
+++ vfe/vfe.cpp
@@ -1372,7 +1372,7 @@ int Allow_File_Write (const char *Filename, const unsi
   return (vfeSession::GetSessionFromThreadID()->TestAccessAllowed(Filename, true));
 }
 
-int Allow_File_Write (const unsigned short *Filename, const unsigned int FileType)
+int Allow_File_Write (const char16_t *Filename, const unsigned int FileType)
 {
   if (strcmp(UCS2toASCIIString(Filename).c_str(), "stdout") == 0 || strcmp(UCS2toASCIIString(Filename).c_str(), "stderr") == 0)
     return true;
@@ -1384,12 +1384,12 @@ int Allow_File_Read (const char *Filename, const unsig
   return (vfeSession::GetSessionFromThreadID()->TestAccessAllowed(Filename, false));
 }
 
-int Allow_File_Read (const unsigned short *Filename, const unsigned int FileType)
+int Allow_File_Read (const char16_t *Filename, const unsigned int FileType)
 {
   return (vfeSession::GetSessionFromThreadID()->TestAccessAllowed(Filename, false));
 }
 
-FILE *vfeFOpen (const std::basic_string<unsigned short>& name, const char *mode)
+FILE *vfeFOpen (const UCS2String& name, const char *mode)
 {
   return (fopen (UCS2toASCIIString (name).c_str(), mode)) ;
 }
