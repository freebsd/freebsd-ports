--- ../jvmaccess/source/sunversion.cxx.orig	Mon Jun  2 00:00:25 2003
+++ ../jvmaccess/source/sunversion.cxx	Mon Jun  2 00:06:00 2003
@@ -231,6 +231,8 @@
             m_preRelease = Rel_BETA;
         else if (! strcmp(pCur, "rc1"))
             m_preRelease = Rel_RC1;
+        else if (*pCur == 'p')
+            m_preRelease = Rel_BETA;
         else
             return false;
     }
