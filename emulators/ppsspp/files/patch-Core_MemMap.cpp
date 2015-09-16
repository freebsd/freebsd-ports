--- Core/MemMap.cpp.orig	2015-02-26 20:05:06 UTC
+++ Core/MemMap.cpp
@@ -185,7 +185,7 @@ static bool Memory_TryBase(u32 flags) {
 			if (!*view.out_ptr_low)
 				goto bail;
 		}
-#ifdef _M_X64
+#if defined(_ARCH_64)
 		*view.out_ptr = (u8*)g_arena.CreateView(
 			position, view.size, base + view.virtual_address);
 #else
