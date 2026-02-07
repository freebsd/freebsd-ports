https://codereview.qt-project.org/c/qt/qtbase/+/651678

--- src/network/socket/qnativesocketengine_unix.cpp.orig	2025-05-14 09:43:58 UTC
+++ src/network/socket/qnativesocketengine_unix.cpp
@@ -1387,7 +1387,7 @@ int QNativeSocketEnginePrivate::nativeSelect(QDeadline
     }
 
     static const short read_flags = POLLIN | POLLHUP | POLLERR;
-    static const short write_flags = POLLOUT | POLLERR;
+    static const short write_flags = POLLOUT | POLLHUP | POLLERR;
 
     *selectForRead = ((pfd.revents & read_flags) != 0);
     *selectForWrite = ((pfd.revents & write_flags) != 0);
