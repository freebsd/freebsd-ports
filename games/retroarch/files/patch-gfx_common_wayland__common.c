--- gfx/common/wayland_common.c.orig	2024-02-03 00:11:03 UTC
+++ gfx/common/wayland_common.c
@@ -440,7 +440,7 @@ static int create_shm_file(off_t size)
 static int create_shm_file(off_t size)
 {
    int fd, ret;
-   if ((fd = syscall(SYS_memfd_create, SPLASH_SHM_NAME,
+   if ((fd = memfd_create(SPLASH_SHM_NAME,
                MFD_CLOEXEC | MFD_ALLOW_SEALING)) >= 0)
    {
       fcntl(fd, F_ADD_SEALS, F_SEAL_SHRINK);
