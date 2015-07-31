--- cpp/src/IceGrid/PluginFacadeI.cpp.orig	2015-07-03 17:38:27.734242982 +0200
+++ cpp/src/IceGrid/PluginFacadeI.cpp	2015-07-03 17:42:42.990740982 +0200
@@ -34,10 +34,16 @@
         IceGrid::setRegistryPluginFacade(new RegistryPluginFacadeI);
     }
 
-    ~Init()
-    {
-        IceGrid::setRegistryPluginFacade(0);
-    }
+/*	This is a bad idea, see
+ *	https://isocpp.org/wiki/faq/ctors#construct-on-first-use-v2
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
