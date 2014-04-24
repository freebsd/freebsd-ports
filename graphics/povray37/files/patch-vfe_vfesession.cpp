--- vfe/vfesession.cpp.orig	2014-04-21 07:36:50.000000000 -0500
+++ vfe/vfesession.cpp
@@ -602,7 +602,7 @@ const char *vfeSession::GetBackendStateN
 boost::shared_ptr<Display> vfeSession::GetDisplay() const
 {
   if (m_Frontend == NULL)
-    return (shared_ptr<Display>());
+    return (boost::shared_ptr<Display>());
   return m_Frontend->GetDisplay();
 }
 
@@ -640,7 +640,7 @@ void vfeSession::WorkerThread()
   m_BackendThread = povray_init (boost::bind(&vfeSession::BackendThreadNotify, this), const_cast<void **>(&pov::RenderThreadAddr)) ;
   POVMS_Output_Context = pov::POVMS_GUI_Context ;
 
-  m_Console = shared_ptr<vfeConsole> (new vfeConsole(this, m_ConsoleWidth)) ;
+  m_Console = boost::shared_ptr<vfeConsole> (new vfeConsole(this, m_ConsoleWidth)) ;
 
   POVMS_Object obj ;
   m_Frontend = new VirtualFrontEnd (*this, POVMS_Output_Context, (POVMSAddress) pov::RenderThreadAddr, obj, NULL, m_Console) ;
