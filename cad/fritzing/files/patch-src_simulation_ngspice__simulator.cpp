--- src/simulation/ngspice_simulator.cpp.orig	2025-04-02 10:33:24 UTC
+++ src/simulation/ngspice_simulator.cpp
@@ -94,7 +94,7 @@ void NgSpiceSimulator::init()
 				DebugDialog::debug("  " + path);
 			}
 		}
-#ifdef Q_OS_LINUX
+#ifdef Q_OS_FREEBSD
 		const QString libName = "libngspice.so";
 #elif defined Q_OS_MACOS
 		const QString libName = "libngspice.0.dylib";
