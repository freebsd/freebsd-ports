--- src/common/containers.h.orig
+++ src/common/containers.h
@@ -591,7 +591,7 @@
 							memoryBase		=	new unsigned char[pageSize+16];
 							memory			=	memoryBase+16;
 							available		=	pageSize;
-							savedPages		=	NULL;
+							savedPages		=	(T64*)NULL;
 						}
 
 						~CMemStack() {
