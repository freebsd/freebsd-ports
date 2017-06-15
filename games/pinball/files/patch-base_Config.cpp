--- base/Config.cpp.orig	2003-11-21 07:59:09 UTC
+++ base/Config.cpp
@@ -423,8 +423,8 @@ void Config::setPaths(char const * const
   m_sDataDir = string(EM_DATADIR) + "/";
   m_sExeDir = "./";
   if ( *( m_sDataDir.c_str() ) != '/' ) {
-    char* ptr=0; 
-    char* ptrw = 0;
+    const char* ptr=0; 
+    const char* ptrw = 0;
     //cout<<"relative to exe file"<<endl;
     ptr = (strrchr(argv0,'/')); // unix /cygwin / check win32 
 #ifdef WIN32
