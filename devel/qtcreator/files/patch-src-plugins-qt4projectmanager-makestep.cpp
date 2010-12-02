--- ./src/plugins/qt4projectmanager/makestep.cpp.orig	2010-08-24 11:46:09.000000000 +0400
+++ ./src/plugins/qt4projectmanager/makestep.cpp	2010-11-29 00:21:08.727128457 +0300
@@ -163,8 +163,10 @@
     if (toolchain) {
         if (toolchain->type() != ProjectExplorer::ToolChain::MSVC &&
             toolchain->type() != ProjectExplorer::ToolChain::WINCE) {
+#ifndef Q_OS_FREEBSD
             if (m_makeCmd.isEmpty())
                 args << "-w";
+#endif
         }
     }
 
