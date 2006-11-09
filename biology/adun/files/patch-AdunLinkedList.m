--- Kernel/AdunKernel/Framework/AdunLinkedList.m.orig	Tue Jun 13 12:16:44 2006
+++ Kernel/AdunKernel/Framework/AdunLinkedList.m	Sun Nov  5 13:34:01 2006
@@ -109,7 +109,11 @@
 	NSDebugLLog(@"AdListMemoryManagement", @"Creating New Block - There are now %d blocks", block_no);
 	//On 64 bit machines we should align on a 64 bit boundary
 
+#ifndef __FreeBSD__
 	posix_memalign((void**)&listPointer, 32, BLOCKSIZE*sizeof(ListElement));
+#else
+	listPointer = malloc(BLOCKSIZE*sizeof(ListElement));
+#endif
 	blocks[block_no-1] = listPointer;
 
 	return blocks[block_no-1];
