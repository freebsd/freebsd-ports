--- ./src/libs/utils/savefile.cpp.orig	2012-09-15 10:44:22.784493688 -0700
+++ ./src/libs/utils/savefile.cpp	2012-09-15 10:45:06.714516257 -0700
@@ -89,7 +89,7 @@
     }
 #ifdef Q_OS_WIN
     FlushFileBuffers(reinterpret_cast<HANDLE>(handle()));
-#elif defined(Q_OS_MAC)
+#elif defined(Q_OS_MAC) || defined(Q_OS_FREEBSD)
     fsync(handle());
 #else
     fdatasync(handle());
