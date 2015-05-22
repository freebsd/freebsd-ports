--- sys/dev/virtio/virtio.h.orig	2012-08-22 09:25:24.732287379 +0900
+++ sys/dev/virtio/virtio.h	2012-08-22 09:27:32.411327803 +0900
@@ -150,4 +150,8 @@
 VIRTIO_RDWR_DEVICE_CONFIG(2, uint16_t);
 VIRTIO_RDWR_DEVICE_CONFIG(4, uint32_t);
 
+#ifndef DEVMETHOD_END
+#define DEVMETHOD_END	{ NULL, NULL }
+#endif
+
 #endif /* _VIRTIO_H_ */
