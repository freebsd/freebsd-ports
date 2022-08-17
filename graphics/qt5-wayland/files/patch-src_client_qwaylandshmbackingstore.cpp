--- src/client/qwaylandshmbackingstore.cpp.orig	2022-06-20 20:17:21 UTC
+++ src/client/qwaylandshmbackingstore.cpp
@@ -76,6 +76,8 @@ QWaylandShmBuffer::QWaylandShmBuffer(QWaylandDisplay *
 
 #ifdef SYS_memfd_create
     fd = syscall(SYS_memfd_create, "wayland-shm", MFD_CLOEXEC);
+#elif defined(__FreeBSD__) && __FreeBSD_version >= 1300048
+    fd = memfd_create("wayland-shm", MFD_CLOEXEC);
 #endif
 
     QScopedPointer<QFile> filePointer;
