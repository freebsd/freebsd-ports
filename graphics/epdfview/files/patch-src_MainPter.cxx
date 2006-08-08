--- src/MainPter.cxx.orig	Tue Aug  8 09:28:54 2006
+++ src/MainPter.cxx	Tue Aug  8 09:29:35 2006
@@ -52,6 +52,7 @@
     m_Document->attach (this);
     m_View = NULL;
     m_PagePter = NULL;
+    m_FindPter = NULL;
     m_PasswordTries = 3;
 #if defined (DEBUG)
     G_LOCK (fileLoaded);
