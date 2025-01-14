--- common/log.c.orig	2023-09-25 08:47:42 UTC
+++ common/log.c
@@ -18,7 +18,6 @@
 #include <fcntl.h>
 #include <libgen.h>
 #include <limits.h>
-#include <stdint.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -706,30 +705,18 @@ apply_with(int (*db_func)(SCR *, recno_t, CHAR_T *, si
     recno_t lno, u_char *p, size_t len)
 {
 #ifdef USE_WIDECHAR
-	typedef unsigned long nword;
-
 	static size_t blen;
-	static nword *bp;
-	nword *lp = (nword *)((uintptr_t)p / sizeof(nword) * sizeof(nword));
+	static u_char *bp;
 
-	if (lp != (nword *)p) {
-		int offl = ((uintptr_t)p - (uintptr_t)lp) << 3;
-		int offr = (sizeof(nword) << 3) - offl;
-		size_t i, cnt = (len + sizeof(nword) / 2) / sizeof(nword);
-
+	if (!is_aligned(p, sizeof(unsigned long))) {
 		if (len > blen) {
 			blen = p2roundup(MAX(len, 512));
-			REALLOC(sp, bp, nword *, blen);
+			REALLOC(sp, bp, u_char *, blen);
 			if (bp == NULL)
 				return (1);
 		}
-		for (i = 0; i < cnt; ++i)
-#if BYTE_ORDER == BIG_ENDIAN
-			bp[i] = (lp[i] << offl) ^ (lp[i+1] >> offr);
-#else
-			bp[i] = (lp[i] >> offl) ^ (lp[i+1] << offr);
-#endif
-		p = (u_char *)bp;
+		memmove(bp, p, len);
+		p = bp;
 	}
 #endif
 	return db_func(sp, lno, (CHAR_T *)p, len / sizeof(CHAR_T));
