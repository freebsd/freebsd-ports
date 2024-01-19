--- src/client/qwaylandshmbackingstore.cpp.orig	2023-10-04 20:59:02 UTC
+++ src/client/qwaylandshmbackingstore.cpp
@@ -82,6 +82,8 @@ QWaylandShmBuffer::QWaylandShmBuffer(QWaylandDisplay *
     fd = syscall(SYS_memfd_create, "wayland-shm", MFD_CLOEXEC | MFD_ALLOW_SEALING);
     if (fd >= 0)
         fcntl(fd, F_ADD_SEALS, F_SEAL_SHRINK | F_SEAL_SEAL);
+#elif defined(__FreeBSD__)
+    fd = memfd_create("wayland-shm", MFD_CLOEXEC);
 #endif
 
     QScopedPointer<QFile> filePointer;
