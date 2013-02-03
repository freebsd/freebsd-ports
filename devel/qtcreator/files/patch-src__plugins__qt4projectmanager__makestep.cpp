--- ./src/plugins/qt4projectmanager/makestep.cpp.orig	2012-09-10 07:29:16.000000000 -0700
+++ ./src/plugins/qt4projectmanager/makestep.cpp	2012-09-15 09:10:41.176369913 -0700
@@ -237,8 +237,10 @@
     // but for now this is the least invasive change
     // We also prepend "L" to the MAKEFLAGS, so that nmake / jom are less verbose
     if (tc && m_makeCmd.isEmpty()) {
+#ifndef Q_OS_FREEBSD
         if (tc->targetAbi().binaryFormat() != Abi::PEFormat )
             Utils::QtcProcess::addArg(&args, QLatin1String("-w"));
+#endif
         if (tc->targetAbi().os() == Abi::WindowsOS
                 && tc->targetAbi().osFlavor() != Abi::WindowsMSysFlavor) {
             const QString makeFlags = QLatin1String("MAKEFLAGS");
