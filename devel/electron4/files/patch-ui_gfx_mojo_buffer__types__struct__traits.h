--- ui/gfx/mojo/buffer_types_struct_traits.h.orig	2019-03-15 06:38:28 UTC
+++ ui/gfx/mojo/buffer_types_struct_traits.h
@@ -291,7 +291,7 @@ template <>
 struct StructTraits<gfx::mojom::NativePixmapHandleDataView,
                     gfx::NativePixmapHandle> {
   static bool IsNull(const gfx::NativePixmapHandle& handle) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     return false;
 #else
     // NativePixmapHandle are not used on non-linux platforms.
