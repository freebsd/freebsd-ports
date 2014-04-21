--- vfe/vfesession.h.orig	2012-06-19 11:29:40.000000000 -0500
+++ vfe/vfesession.h
@@ -1294,7 +1294,7 @@ namespace vfe
 
       static bool m_Initialized;
       static vfeSession *m_CurrentSessionTemporaryHack;
-      shared_ptr<Console> m_Console;
+      boost::shared_ptr<Console> m_Console;
 
       virtual vfeDisplay *DefaultDisplayCreator (unsigned int width, unsigned int height, GammaCurvePtr gamma, vfeSession *session, bool visible);
       DisplayCreator m_DisplayCreator;
