--- include/xfs_bit.h.orig	2015-07-24 04:28:04 UTC
+++ include/xfs_bit.h
@@ -47,7 +47,7 @@ static inline int xfs_highbit32(__uint32
 /* Get high bit set out of 64-bit argument, -1 if none set */
 static inline int xfs_highbit64(__uint64_t v)
 {
-	return fls64(v) - 1;
+	return flsll(v) - 1;
 }
 
 /* Get low bit set out of 32-bit argument, -1 if none set */
