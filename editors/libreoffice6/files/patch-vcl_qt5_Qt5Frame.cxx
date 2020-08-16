--- vcl/qt5/Qt5Frame.cxx.orig	2020-05-13 11:19:20 UTC
+++ vcl/qt5/Qt5Frame.cxx
@@ -318,7 +318,7 @@ SalGraphics* Qt5Frame::AcquireGraphics()
 
     if (m_bUseCairo)
     {
-        if (!m_pOurSvpGraphics.get() || m_bGraphicsInvalid)
+        if (!m_pOurSvpGraphics.get())
         {
             m_pOurSvpGraphics.reset(new Qt5SvpGraphics(this));
             InitQt5SvpGraphics(m_pOurSvpGraphics.get());
