--- ../jvmaccess/source/sunversion.cxx.orig	Thu May 22 18:41:23 2003
+++ ../jvmaccess/source/sunversion.cxx	Tue Sep  2 21:31:04 2003
@@ -244,6 +244,22 @@
             m_preRelease = Rel_RC1;
         else if (! strcmp(pCur, "rc2"))
             m_preRelease = Rel_RC2;
+        else if (! strcmp(pCur, "p8"))
+            m_preRelease = Rel_BETA;
+        else if (! strcmp(pCur, "p7"))
+            m_preRelease = Rel_BETA;
+        else if (! strcmp(pCur, "p6"))
+            m_preRelease = Rel_BETA;
+        else if (! strcmp(pCur, "p5"))
+            m_preRelease = Rel_BETA;
+        else if (! strcmp(pCur, "p4"))
+            m_preRelease = Rel_BETA;
+        else if (! strcmp(pCur, "p3"))
+            m_preRelease = Rel_BETA;
+        else if (! strcmp(pCur, "p2"))
+            m_preRelease = Rel_BETA;
+        else if (! strcmp(pCur, "p1"))
+            m_preRelease = Rel_BETA;
         else
             return false;
     }
