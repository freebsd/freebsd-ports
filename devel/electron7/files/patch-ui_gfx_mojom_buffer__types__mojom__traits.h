--- ui/gfx/mojom/buffer_types_mojom_traits.h.orig	2019-12-12 12:41:33 UTC
+++ ui/gfx/mojom/buffer_types_mojom_traits.h
@@ -191,7 +191,7 @@ struct StructTraits<gfx::mojom::GpuMemoryBufferIdDataV
   }
 };
 
-#if defined(OS_LINUX) || defined(USE_OZONE)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(USE_OZONE)
 template <>
 struct StructTraits<gfx::mojom::NativePixmapPlaneDataView,
                     gfx::NativePixmapPlane> {
@@ -217,7 +217,7 @@ struct StructTraits<gfx::mojom::NativePixmapHandleData
     return pixmap_handle.planes;
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   static uint64_t modifier(const gfx::NativePixmapHandle& pixmap_handle) {
     return pixmap_handle.modifier;
   }
@@ -241,7 +241,7 @@ struct StructTraits<gfx::mojom::NativePixmapHandleData
   static bool Read(gfx::mojom::NativePixmapHandleDataView data,
                    gfx::NativePixmapHandle* out);
 };
-#endif  // defined(OS_LINUX) || defined(USE_OZONE)
+#endif  // defined(OS_LINUX) || defined(OS_BSD) || defined(USE_OZONE)
 
 template <>
 struct StructTraits<gfx::mojom::GpuMemoryBufferHandleDataView,
