--- vfe/vfe.h.orig	2012-06-19 11:29:39.000000000 -0500
+++ vfe/vfe.h
@@ -267,7 +267,7 @@ namespace vfe
   class VirtualFrontEnd
   {
     public:
-      VirtualFrontEnd(vfeSession& session, POVMSContext ctx, POVMSAddress addr, POVMS_Object& msg, POVMS_Object *result, shared_ptr<Console>& console) ;
+      VirtualFrontEnd(vfeSession& session, POVMSContext ctx, POVMSAddress addr, POVMS_Object& msg, POVMS_Object *result, boost::shared_ptr<Console>& console) ;
       virtual ~VirtualFrontEnd() ;
 
       virtual bool Start(POVMS_Object& opts) ;
@@ -298,9 +298,9 @@ namespace vfe
       POVMS_Object options;
       RenderFrontendBase::SceneId sceneId;
       RenderFrontendBase::ViewId viewId;
-      shared_ptr<AnimationProcessing> animationProcessing ;
-      shared_ptr<ImageProcessing> imageProcessing ;
-      shared_ptr<ShelloutProcessing> shelloutProcessing;
+      boost::shared_ptr<AnimationProcessing> animationProcessing ;
+      boost::shared_ptr<ImageProcessing> imageProcessing ;
+      boost::shared_ptr<ShelloutProcessing> shelloutProcessing;
       Console **consoleResult;
       Display **displayResult;
       vfeSession* m_Session;
