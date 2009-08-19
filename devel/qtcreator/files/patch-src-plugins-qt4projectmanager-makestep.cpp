--- src/plugins/qt4projectmanager/makestep.cpp.orig	2009-07-10 15:38:08.000000000 +0300
+++ src/plugins/qt4projectmanager/makestep.cpp	2009-08-15 16:59:49.000000000 +0300
@@ -101,8 +101,10 @@
     // but for now this is the least invasive change
     ProjectExplorer::ToolChain::ToolChainType t =  qobject_cast<Qt4Project *>(project())->qtVersion(name)->toolchainType();
     if (t != ProjectExplorer::ToolChain::MSVC && t != ProjectExplorer::ToolChain::WINCE) {
+#ifndef Q_OS_FREEBSD    
         if (value(name, "makeCmd").toString().isEmpty())
             args << "-w";
+#endif            
     }
 
     setEnabled(name, !skipMakeClean);
