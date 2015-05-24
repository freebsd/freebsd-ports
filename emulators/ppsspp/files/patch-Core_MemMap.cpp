--- Core/MemMap.cpp.orig	2015-02-26 20:05:06 UTC
+++ Core/MemMap.cpp
@@ -194,7 +194,11 @@ static bool Memory_TryBase(u32 flags) {
 			*view.out_ptr = *views[i - 1].out_ptr;
 		} else {
 			*view.out_ptr = (u8*)g_arena.CreateView(
+#ifdef _ARCH_32
 				position, view.size, base + (view.virtual_address & MEMVIEW32_MASK));
+#else
+				position, view.size, base + view.virtual_address);
+#endif
 			if (!*view.out_ptr)
 				goto bail;
 		}
