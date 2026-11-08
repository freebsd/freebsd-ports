--- plugin/klash4/klash_part.cpp.orig	2016-07-21 12:25:09 UTC
+++ plugin/klash4/klash_part.cpp
@@ -148,7 +148,7 @@ KDE_NO_CDTOR_EXPORT KlashPart::KlashPart
         }
     }
     KParts::Part::setWidget (new KlashView (wparent));
-    setXMLFile("klashpartui.rc");
+    setXMLFile("klash/klashpartui.rc");
     setProgressInfoEnabled (false);
 
     if (m_fullscreen)
