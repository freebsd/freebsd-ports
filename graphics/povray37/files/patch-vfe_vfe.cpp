--- vfe/vfe.cpp.orig	2012-06-19 11:29:39.000000000 -0500
+++ vfe/vfe.cpp
@@ -640,7 +640,7 @@ void vfeProcessRenderOptions::WriteError
 //
 ////////////////////////////////////////////////////////////////////////////////////////
 
-VirtualFrontEnd::VirtualFrontEnd(vfeSession& session, POVMSContext ctx, POVMSAddress addr, POVMS_Object& msg, POVMS_Object *result, shared_ptr<Console>& console) :
+VirtualFrontEnd::VirtualFrontEnd(vfeSession& session, POVMSContext ctx, POVMSAddress addr, POVMS_Object& msg, POVMS_Object *result, boost::shared_ptr<Console>& console) :
   m_Session(&session), m_PlatformBase(session), renderFrontend (ctx)
 {
   backendAddress = addr ;
@@ -747,7 +747,7 @@ bool VirtualFrontEnd::Start(POVMS_Object
 
     if (m_Session->OutputToFileSet())
     {
-      imageProcessing = shared_ptr<ImageProcessing> (new ImageProcessing (opts));
+      imageProcessing = boost::shared_ptr<ImageProcessing> (new ImageProcessing (opts));
       UCS2String filename = imageProcessing->GetOutputFilename (opts, 0, 0);
       options.SetUCS2String (kPOVAttrib_OutputFile, filename.c_str());
 
@@ -774,8 +774,8 @@ bool VirtualFrontEnd::Start(POVMS_Object
     opts.Set(kPOVAttrib_Declare, declares);
     imageProcessing.reset();
     if (m_Session->OutputToFileSet())
-      imageProcessing = shared_ptr<ImageProcessing> (new ImageProcessing (opts)) ;
-    animationProcessing = shared_ptr<AnimationProcessing> (new AnimationProcessing (opts)) ;
+      imageProcessing = boost::shared_ptr<ImageProcessing> (new ImageProcessing (opts)) ;
+    animationProcessing = boost::shared_ptr<AnimationProcessing> (new AnimationProcessing (opts)) ;
     options = animationProcessing->GetFrameRenderOptions () ;
   }
 
@@ -1151,7 +1151,7 @@ State VirtualFrontEnd::Process()
           }
 
           // now we display the render window, if enabled
-          shared_ptr<Display> display(GetDisplay());
+          boost::shared_ptr<Display> display(GetDisplay());
           if (display != NULL)
           {
             vfeDisplay *disp = dynamic_cast<vfeDisplay *>(display.get());
