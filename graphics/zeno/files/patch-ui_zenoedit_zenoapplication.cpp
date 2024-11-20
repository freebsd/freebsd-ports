--- ui/zenoedit/zenoapplication.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoedit/zenoapplication.cpp
@@ -13,9 +13,9 @@ ZenoApplication::ZenoApplication(int &argc, char **arg
 
 ZenoApplication::ZenoApplication(int &argc, char **argv)
     : QApplication(argc, argv)
-#if defined(ZENO_MULTIPROCESS) && defined(ZENO_IPC_USE_TCP)
+//#if defined(ZENO_MULTIPROCESS) && defined(ZENO_IPC_USE_TCP)
     , m_server(nullptr)
-#endif
+//#endif
     , m_bUIApp(true)
 {
     initMetaTypes();
@@ -175,7 +175,7 @@ QStandardItemModel* ZenoApplication::logModel() const
     return graphsManagment()->logModel();
 }
 
-#if defined(ZENO_MULTIPROCESS) && defined(ZENO_IPC_USE_TCP)
+//#if defined(ZENO_MULTIPROCESS) && defined(ZENO_IPC_USE_TCP)
 ZTcpServer* ZenoApplication::getServer()
 {
     if (!m_server) {
@@ -184,7 +184,7 @@ ZTcpServer* ZenoApplication::getServer()
     }
     return m_server;
 }
-#endif
+//#endif
 
 ZenoMainWindow* ZenoApplication::getMainWindow()
 {
