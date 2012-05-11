--- ./src/plugins/qt4projectmanager/makestep.cpp.orig	2012-05-09 12:13:19.000000000 +0000
+++ ./src/plugins/qt4projectmanager/makestep.cpp	2012-05-10 09:13:05.254056057 +0000
@@ -211,8 +211,10 @@
     // We also prepend "L" to the MAKEFLAGS, so that nmake / jom are less verbose
     ProjectExplorer::ToolChain *toolChain = bc->toolChain();
     if (toolChain && m_makeCmd.isEmpty()) {
+#ifndef Q_OS_FREEBSD
         if (toolChain->targetAbi().binaryFormat() != ProjectExplorer::Abi::PEFormat )
             Utils::QtcProcess::addArg(&args, QLatin1String("-w"));
+#endif
         if (toolChain->targetAbi().os() == ProjectExplorer::Abi::WindowsOS
                 && toolChain->targetAbi().osFlavor() != ProjectExplorer::Abi::WindowsMSysFlavor) {
             const QString makeFlags = QLatin1String("MAKEFLAGS");
