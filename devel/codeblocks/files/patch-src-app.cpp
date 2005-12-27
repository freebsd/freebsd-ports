--- src/app.cpp.orig	Sun Nov 27 14:14:16 2005
+++ src/app.cpp	Sun Nov 27 14:14:39 2005
@@ -80,6 +80,8 @@
 DDEServer* g_DDEServer = 0L;
 #endif
 
+#define APP_PREFIX "/usr/local"
+
 IMPLEMENT_APP(CodeBlocksApp)
 
 BEGIN_EVENT_TABLE(CodeBlocksApp, wxApp)
