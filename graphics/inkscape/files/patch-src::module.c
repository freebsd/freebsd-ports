--- src/module.c.orig	Fri Dec 12 00:10:31 2003
+++ src/module.c	Fri Dec 12 00:14:45 2003
@@ -38,7 +38,7 @@
 static void sp_module_private_build (SPModule *module, SPRepr *repr);
 static void sp_module_load_default (SPModule * module);
 static void sp_module_unload_default (SPModule * module);
-static SPModule * sp_module_new (GType type, SPRepr *repr);
+SPModule * sp_module_new (GType type, SPRepr *repr);
 
 /** 
 	\var module_parent_class
@@ -283,7 +283,7 @@
 	A reference to the SPRepr structure is added in this function so it
 	should not need to be added by each individual subclass.
 */
-static SPModule *
+SPModule *
 sp_module_new (GType type, SPRepr *repr)
 {
 	SPModule *module;
