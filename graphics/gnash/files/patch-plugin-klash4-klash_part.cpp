--- plugin/klash4/klash_part.cpp.orig	2009-03-02 18:29:50.000000000 +0300
+++ plugin/klash4/klash_part.cpp	2009-03-06 05:44:08.000000000 +0300
@@ -147,7 +147,7 @@
         }
     }
     KParts::Part::setWidget (new KlashView (wparent));
-    setXMLFile("klashpartui.rc");
+    setXMLFile("klash/klashpartui.rc");
     setProgressInfoEnabled (false);
 
     if (m_fullscreen)
