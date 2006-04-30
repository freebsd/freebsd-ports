--- dualserver.h.orig	Sun Apr 30 11:33:14 2006
+++ dualserver.h	Sun Apr 30 11:33:37 2006
@@ -98,7 +98,7 @@
 			BYTE rcode: 4;
 			BYTE z: 3;
 			BYTE ra: 1;
-		};
+		} flags;
 	};
 	union {
 		WORD zcount;
