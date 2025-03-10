--- src/ES2Command/Src/Utils/ESAccessor.h.orig	2024-09-12 07:10:32 UTC
+++ src/ES2Command/Src/Utils/ESAccessor.h
@@ -174,7 +174,7 @@ class CESAccessor{ (protected)
   {
   }
   CSetterFunc(const CSetterFunc& rhs)
-   : m_func(rhs.func)
+   : m_func(rhs.m_func)
   {
   }
   virtual ISetterFunc* Clone()
