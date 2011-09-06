--- plugin/klash4/klash_part.cpp.orig	2011-06-16 18:56:30.869545798 -0400
+++ plugin/klash4/klash_part.cpp	2011-06-16 18:57:04.979892841 -0400
@@ -148,7 +148,7 @@
         }
     }
     KParts::Part::setWidget (new KlashView (wparent));
-    setXMLFile("klashpartui.rc");
+    setXMLFile("klash/klashpartui.rc");
     setProgressInfoEnabled (false);
 
     if (m_fullscreen)
