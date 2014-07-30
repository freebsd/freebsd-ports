--- src/cpu/mem.h.orig
+++ src/cpu/mem.h
@@ -23,7 +23,7 @@
 
 #include "system/types.h"
 
-bool	ppc_init_physical_memory(uint size);
+bool	FASTCALL ppc_init_physical_memory(uint size);
 
 uint32  ppc_get_memory_size();
 
