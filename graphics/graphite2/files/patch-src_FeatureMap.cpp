--- src/FeatureMap.cpp.orig	2016-11-11 09:53:21 UTC
+++ src/FeatureMap.cpp
@@ -275,7 +275,8 @@ bool FeatureRef::applyValToFeature(uint3
     else
       if (pDest.m_pMap!=&m_pFace->theSill().theFeatureMap())
         return false;       //incompatible
-    pDest.reserve(m_index);
+    if (m_index >= pDest.size())
+        pDest.resize(m_index+1);
     pDest[m_index] &= ~m_mask;
     pDest[m_index] |= (uint32(val) << m_bits);
     return true;
