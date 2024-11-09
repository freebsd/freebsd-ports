--- vfe/vfeconf.h.orig	2021-07-08 09:56:01 UTC
+++ vfe/vfeconf.h
@@ -61,12 +61,12 @@ namespace vfe
   int vfe_POVMS_Sys_QueueSend(POVMS_Sys_QueueNode *q, void *p, int l) ;
   int Allow_File_Write (const char *Filename, const unsigned int FileType);
   int Allow_File_Read (const char *Filename, const unsigned int FileType);
-  int Allow_File_Read (const unsigned short *Filename, const unsigned int FileType);
-  int Allow_File_Write (const unsigned short *Filename, const unsigned int FileType);
+  int Allow_File_Read (const char16_t *Filename, const unsigned int FileType);
+  int Allow_File_Write (const char16_t *Filename, const unsigned int FileType);
   POVMS_Sys_Thread_Type POVMS_GetCurrentThread();
   void vfeAssert (const char *message, const char *filename, int line) ;
-  FILE *vfeFOpen (const std::basic_string<unsigned short>& name, const char *mode);
-  bool vfeRemove (const std::basic_string<unsigned short>& name);
+  FILE *vfeFOpen (const std::u16string& name, const char *mode);
+  bool vfeRemove (const std::u16string& name);
 
 #if defined _DEBUG
   void *vfe_POVMS_Sys_Malloc(size_t size, const char *func, const char *file, int line) ;
