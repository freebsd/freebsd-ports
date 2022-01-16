--- cpp/src/IceGrid/RegistryI.cpp.orig	2021-06-21 14:44:58 UTC
+++ cpp/src/IceGrid/RegistryI.cpp
@@ -41,6 +41,13 @@ using namespace std;
 using namespace Ice;
 using namespace IceGrid;
 
+namespace IceGrid
+{
+
+ICEGRID_API void setRegistryPluginFacade(const RegistryPluginFacadePtr&);
+
+}
+
 namespace
 {
 
@@ -178,6 +185,7 @@ RegistryI::RegistryI(const CommunicatorPtr& communicat
 
 RegistryI::~RegistryI()
 {
+    IceGrid::setRegistryPluginFacade(0);
 }
 
 bool
