--- driver/virtio_gpu_qemu.c.orig	2026-09-28 08:34:33 UTC
+++ driver/virtio_gpu_qemu.c
@@ -112,6 +112,12 @@
 
 #define	VTGPUQ_FEATURES		0
 
+#if _BYTE_ORDER == _BIG_ENDIAN
+#define	VTGPUQ_FORMAT		VIRTIO_GPU_FORMAT_X8R8G8B8_UNORM
+#else
+#define	VTGPUQ_FORMAT		VIRTIO_GPU_FORMAT_B8G8R8X8_UNORM
+#endif
+
 /* The guest can allocate resource IDs, we only need one */
 #define	VTGPUQ_RESOURCE_ID	1
 
@@ -1101,7 +1107,7 @@ vtgpuq_create_2d(struct vtgpuq_softc *sc)
 	    atomic_fetchadd_64(&sc->vtgpu_next_fence, 1));
 
 	s.req.resource_id = htole32(VTGPUQ_RESOURCE_ID);
-	s.req.format = htole32(VIRTIO_GPU_FORMAT_B8G8R8X8_UNORM);
+	s.req.format = htole32(VTGPUQ_FORMAT);
 	s.req.width = htole32(sc->vtgpu_fb_info.fb_width);
 	s.req.height = htole32(sc->vtgpu_fb_info.fb_height);
 
