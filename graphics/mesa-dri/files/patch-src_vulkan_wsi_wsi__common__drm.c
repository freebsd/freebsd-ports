--- src/vulkan/wsi/wsi_common_drm.c.orig	2022-10-11 18:53:31 UTC
+++ src/vulkan/wsi/wsi_common_drm.c
@@ -30,29 +30,15 @@
 #include "vk_physical_device.h"
 #include "vk_util.h"
 #include "drm-uapi/drm_fourcc.h"
+#include "drm-uapi/dma-buf.h"
 
 #include <errno.h>
-#include <linux/dma-buf.h>
-#include <linux/sync_file.h>
 #include <time.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <xf86drm.h>
 
-struct dma_buf_export_sync_file_wsi {
-   __u32 flags;
-   __s32 fd;
-};
-
-struct dma_buf_import_sync_file_wsi {
-   __u32 flags;
-   __s32 fd;
-};
-
-#define DMA_BUF_IOCTL_EXPORT_SYNC_FILE_WSI   _IOWR(DMA_BUF_BASE, 2, struct dma_buf_export_sync_file_wsi)
-#define DMA_BUF_IOCTL_IMPORT_SYNC_FILE_WSI   _IOW(DMA_BUF_BASE, 3, struct dma_buf_import_sync_file_wsi)
-
 static VkResult
 wsi_dma_buf_export_sync_file(int dma_buf_fd, int *sync_file_fd)
 {
@@ -61,11 +47,11 @@ wsi_dma_buf_export_sync_file(int dma_buf_fd, int *sync
    if (no_dma_buf_sync_file)
       return VK_ERROR_FEATURE_NOT_PRESENT;
 
-   struct dma_buf_export_sync_file_wsi export = {
+   struct dma_buf_export_sync_file export = {
       .flags = DMA_BUF_SYNC_RW,
       .fd = -1,
    };
-   int ret = drmIoctl(dma_buf_fd, DMA_BUF_IOCTL_EXPORT_SYNC_FILE_WSI, &export);
+   int ret = drmIoctl(dma_buf_fd, DMA_BUF_IOCTL_EXPORT_SYNC_FILE, &export);
    if (ret) {
       if (errno == ENOTTY || errno == EBADF || errno == ENOSYS) {
          no_dma_buf_sync_file = true;
@@ -88,11 +74,11 @@ wsi_dma_buf_import_sync_file(int dma_buf_fd, int sync_
    if (no_dma_buf_sync_file)
       return VK_ERROR_FEATURE_NOT_PRESENT;
 
-   struct dma_buf_import_sync_file_wsi import = {
+   struct dma_buf_import_sync_file import = {
       .flags = DMA_BUF_SYNC_RW,
       .fd = sync_file_fd,
    };
-   int ret = drmIoctl(dma_buf_fd, DMA_BUF_IOCTL_IMPORT_SYNC_FILE_WSI, &import);
+   int ret = drmIoctl(dma_buf_fd, DMA_BUF_IOCTL_IMPORT_SYNC_FILE, &import);
    if (ret) {
       if (errno == ENOTTY || errno == EBADF || errno == ENOSYS) {
          no_dma_buf_sync_file = true;
