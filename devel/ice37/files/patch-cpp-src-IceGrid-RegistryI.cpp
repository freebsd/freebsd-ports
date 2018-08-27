--- cpp/src/IceGrid/RegistryI.cpp.orig	2018-04-20 15:02:08 UTC
+++ cpp/src/IceGrid/RegistryI.cpp
@@ -46,6 +46,13 @@ using namespace std;
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
 
@@ -183,6 +190,7 @@ RegistryI::RegistryI(const CommunicatorP
 
 RegistryI::~RegistryI()
 {
+    IceGrid::setRegistryPluginFacade(0);
 }
 
 bool
