--- ./src/plugins/qt4projectmanager/makestep.cpp.orig	2012-01-24 14:37:13.000000000 +0000
+++ ./src/plugins/qt4projectmanager/makestep.cpp	2012-02-26 15:30:04.084747079 +0000
@@ -201,10 +201,12 @@
     // FIXME doing this without the user having a way to override this is rather bad
     // so we only do it for unix and if the user didn't override the make command
     // but for now this is the least invasive change
+#ifndef Q_OS_FREEBSD
     if (toolchain
             && toolchain->targetAbi().binaryFormat() != ProjectExplorer::Abi::PEFormat
             && m_makeCmd.isEmpty())
         Utils::QtcProcess::addArg(&args, QLatin1String("-w"));
+#endif
 
     setEnabled(true);
     pp->setArguments(args);
