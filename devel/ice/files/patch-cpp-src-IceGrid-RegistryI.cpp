--- cpp/src/IceGrid/RegistryI.cpp.orig	2019-08-12 19:54:18 UTC
+++ cpp/src/IceGrid/RegistryI.cpp
@@ -46,6 +46,13 @@ using namespace std;
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
 
@@ -157,6 +164,7 @@ RegistryI::RegistryI(const CommunicatorPtr& communicat
 
 RegistryI::~RegistryI()
 {
+    IceGrid::setRegistryPluginFacade(0);
 }
 
 bool
