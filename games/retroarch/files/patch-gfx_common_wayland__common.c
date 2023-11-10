--- gfx/common/wayland_common.c.orig	2023-11-06 19:16:56 UTC
+++ gfx/common/wayland_common.c
@@ -419,7 +419,7 @@ bool gfx_ctx_wl_get_metrics_common(void *data,
 static int create_shm_file(off_t size)
 {
    int fd, ret;
-   if ((fd = syscall(SYS_memfd_create, SPLASH_SHM_NAME,
+   if ((fd = memfd_create(SPLASH_SHM_NAME,
                MFD_CLOEXEC | MFD_ALLOW_SEALING)) >= 0)
    {
       fcntl(fd, F_ADD_SEALS, F_SEAL_SHRINK);
