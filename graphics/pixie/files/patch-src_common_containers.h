--- src/common/containers.h.orig
+++ src/common/containers.h
@@ -589,7 +589,7 @@
 							memoryBase		=	new unsigned char[pageSize+16];
 							memory			=	memoryBase+16;
 							available		=	pageSize;
-							savedPages		=	NULL;
+							savedPages		=	(T32 *)NULL;
 						}
 
 						~CMemStack() {
