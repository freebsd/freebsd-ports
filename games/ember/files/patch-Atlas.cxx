--- src/framework/bindings/lua/atlas/Atlas.cxx.orig	2014-03-11 07:55:38.000000000 +0100
+++ src/framework/bindings/lua/atlas/Atlas.cxx	2014-03-11 07:55:51.000000000 +0100
@@ -1908,7 +1908,7 @@
   if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
 #endif
   {
-   bool tolua_ret = (bool)  self->operator==(*value);
+   bool tolua_ret = (*self==*value);
    tolua_pushboolean(tolua_S,(bool)tolua_ret);
   }
  }
