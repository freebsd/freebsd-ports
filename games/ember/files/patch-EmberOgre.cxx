--- src/components/ogre/scripting/bindings/lua/EmberOgre.cxx.orig	2014-03-11 22:11:48.000000000 +0100
+++ src/components/ogre/scripting/bindings/lua/EmberOgre.cxx	2014-03-11 22:12:58.000000000 +0100
@@ -17592,7 +17592,7 @@
   if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
 #endif
   {
-   bool tolua_ret = (bool)  self->operator==(*value);
+   bool tolua_ret = (*self==*value);
    tolua_pushboolean(tolua_S,(bool)tolua_ret);
   }
  }
@@ -24412,7 +24412,7 @@
   if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
 #endif
   {
-   bool tolua_ret = (bool)  self->operator==(*value);
+   bool tolua_ret = (*self)==(*value);
    tolua_pushboolean(tolua_S,(bool)tolua_ret);
   }
  }
