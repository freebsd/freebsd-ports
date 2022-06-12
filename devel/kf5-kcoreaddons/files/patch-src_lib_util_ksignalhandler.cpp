--- src/lib/util/ksignalhandler.cpp.orig	2022-06-17 18:38:49 UTC
+++ src/lib/util/ksignalhandler.cpp
@@ -9,6 +9,7 @@
 #include <QSocketNotifier>
 
 #ifndef Q_OS_WIN
+#include <cerrno>
 #include <signal.h>
 #include <sys/socket.h>
 #include <unistd.h>
