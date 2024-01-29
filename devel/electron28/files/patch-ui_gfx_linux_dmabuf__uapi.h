--- ui/gfx/linux/dmabuf_uapi.h.orig	2023-10-19 19:59:21 UTC
+++ ui/gfx/linux/dmabuf_uapi.h
@@ -5,12 +5,11 @@
 #ifndef UI_GFX_LINUX_DMABUF_UAPI_H_
 #define UI_GFX_LINUX_DMABUF_UAPI_H_
 
-#include <linux/version.h>
+#include <sys/types.h>
 
-#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 11, 0)
-#include <linux/dma-buf.h>
-#else
-#include <linux/types.h>
+typedef int32_t  __s32;
+typedef uint32_t __u32;
+typedef uint64_t __u64;
 
 struct dma_buf_sync {
   __u64 flags;
@@ -26,9 +25,7 @@ constexpr __u64 DMA_BUF_SYNC_END = 1 << 2;
 constexpr char DMA_BUF_BASE = 'b';
 constexpr unsigned long DMA_BUF_IOCTL_SYNC =
     _IOW(DMA_BUF_BASE, 0, struct dma_buf_sync);
-#endif
 
-#if LINUX_VERSION_CODE < KERNEL_VERSION(6, 0, 0)
 struct dma_buf_export_sync_file {
   __u32 flags;
   __s32 fd;
@@ -43,6 +40,5 @@ constexpr unsigned long DMA_BUF_IOCTL_EXPORT_SYNC_FILE
     _IOWR(DMA_BUF_BASE, 2, struct dma_buf_export_sync_file);
 constexpr unsigned long DMA_BUF_IOCTL_IMPORT_SYNC_FILE =
     _IOW(DMA_BUF_BASE, 3, struct dma_buf_import_sync_file);
-#endif
 
 #endif  // UI_GFX_LINUX_DMABUF_UAPI_H_
