--- src/ES2Command/Src/Utils/ESAccessor.h.orig	2021-11-25 00:56:55 UTC
+++ src/ES2Command/Src/Utils/ESAccessor.h
@@ -177,7 +177,7 @@ class CESAccessor{ (protected)
   {
   }
   CSetterFunc(const CSetterFunc& rhs)
-   : m_func(rhs.func)
+   : m_func(rhs.m_func)
   {
   }
   virtual ISetterFunc* Clone()
