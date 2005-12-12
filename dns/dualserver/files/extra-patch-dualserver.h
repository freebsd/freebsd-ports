--- dualserver.h.orig	Mon Dec 12 10:40:55 2005
+++ dualserver.h	Mon Dec 12 10:41:23 2005
@@ -94,7 +94,7 @@
 			BYTE rcode:4;
 			BYTE z:3;
 			BYTE ra:1;
-		};
+		} flags;
 	};
 	union {
 		WORD zcount;
