--- src/lsz.c.orig	2026-10-04 09:46:51 UTC
+++ src/lsz.c
@@ -1426,7 +1426,7 @@ getzrxinit(void)
 				blklen = Rxbuflen;
 			if (blkopt && blklen > blkopt)
 				blklen = blkopt;
-			DPRINTF(DEBUG_WINDOWHANDLING, "Rxbuflen=%u blklen=%lu\n", Rxbuflen, blklen);
+			DPRINTF(DEBUG_WINDOWHANDLING, "Rxbuflen=%u blklen=%zu\n", Rxbuflen, blklen);
 			DPRINTF(DEBUG_WINDOWHANDLING, "Txwindow = %u Txwspac = %u\n", Txwindow, Txwspac);
 			Rxtimeout=old_timeout;
                         if (debugmode & DEBUG_WINDOWHANDLING) {
