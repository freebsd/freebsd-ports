--- src/VBox/Runtime/common/misc/handletablectx.cpp.orig	2025-10-16 14:35:39 UTC
+++ src/VBox/Runtime/common/misc/handletablectx.cpp
@@ -48,7 +48,9 @@
 #include <iprt/param.h>
 #include <iprt/string.h>
 #include <iprt/asm.h>
+#ifndef IN_GUEST
 #include <iprt/system.h>
+#endif
 #include "internal/magics.h"
 #include "handletable.h"
 
@@ -118,7 +120,11 @@ RTDECL(int)     RTHandleTableAllocWithCtx(RTHANDLETABL
              */
             uint32_t const  iLevel1 = pThis->cCur / RTHT_LEVEL2_ENTRIES;
             uint32_t        cLevel1 = iLevel1 >= pThis->cLevel1
+#ifndef IN_GUEST 
                                     ? pThis->cLevel1 + RTSystemGetPageSize() / sizeof(void *)
+#else
+                                    ? pThis->cLevel1 + PAGE_SIZE / sizeof(void *)
+#endif
                                     : 0;
             if (cLevel1 > pThis->cMax / RTHT_LEVEL2_ENTRIES)
                 cLevel1 = pThis->cMax / RTHT_LEVEL2_ENTRIES;
