--- cpp/src/IceGrid/RegistryI.cpp.orig	2015-07-03 17:43:25.231459982 +0200
+++ cpp/src/IceGrid/RegistryI.cpp	2015-07-03 17:46:57.991198982 +0200
@@ -48,6 +48,13 @@
 using namespace Ice;
 using namespace IceGrid;
 
+namespace IceGrid
+{
+
+ICE_GRID_API void setRegistryPluginFacade(const RegistryPluginFacadePtr&);
+
+}
+
 namespace
 {
 
@@ -159,6 +166,7 @@
 
 RegistryI::~RegistryI()
 {
+    IceGrid::setRegistryPluginFacade(0);
 }
 
 bool
