https://github.com/RPCS3/rpcs3/issues/6529

--- rpcs3/Emu/IdManager.h.orig	2019-09-09 16:16:02 UTC
+++ rpcs3/Emu/IdManager.h
@@ -30,7 +30,7 @@ namespace id_manager
 		static const u32 base    = T::id_base;
 		static const u32 step    = T::id_step;
 		static const u32 count   = T::id_count;
-		static const u32 invalid = base > 0 ? 0 : -1;
+		static constexpr u32 invalid = base > 0 ? 0 : -1;
 
 		// Note: full 32 bits range cannot be used at current implementation
 		static_assert(count > 0 && step > 0 && u64{step} * count + base < u64{UINT32_MAX} + (base != 0 ? 1 : 0), "ID traits: invalid object range");
