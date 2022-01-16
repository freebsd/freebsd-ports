--- cpp/src/IceGrid/PluginFacadeI.cpp.orig	2021-06-21 14:44:58 UTC
+++ cpp/src/IceGrid/PluginFacadeI.cpp
@@ -29,10 +29,16 @@ class Init (public)
         IceGrid::setRegistryPluginFacade(new RegistryPluginFacadeI);
     }
 
-    ~Init()
-    {
-        IceGrid::setRegistryPluginFacade(0);
-    }
+/*  This is a bad idea, see
+ *  https://isocpp.org/wiki/faq/ctors#construct-on-first-use-v2
+ *  That's why we disabled it and make sure the registrypluginfacace
+ *  is reset somwhere else. Construction is still here, so that
+ *  registry plugins work as expected.
+ *  ~Init()
+ *   {
+ *       IceGrid::setRegistryPluginFacade(0);
+ *   }
+ */
 };
 
 Init init;
