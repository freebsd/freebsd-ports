--- src/plugins/qt4projectmanager/makestep.cpp.orig	2010-01-15 12:36:53.000000000 -0500
+++ src/plugins/qt4projectmanager/makestep.cpp	2010-03-22 11:12:02.280703600 -0400
@@ -106,8 +106,10 @@
     if (toolchain)
         type = toolchain->type();
     if (type != ProjectExplorer::ToolChain::MSVC && type != ProjectExplorer::ToolChain::WINCE) {
+#ifndef Q_OS_FREEBSD
         if (value(name, "makeCmd").toString().isEmpty())
             args << "-w";
+#endif
     }
 
     setEnabled(name, true);
