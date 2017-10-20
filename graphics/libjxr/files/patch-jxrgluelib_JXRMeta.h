Description: Fix typos and remove some warnings
Author: Mathieu Malaterre <malat@debian.org>

Cleaned up for FreeBSD by mi

--- jxrgluelib/JXRMeta.h.orig	2017-10-20 15:09:28 UTC
+++ jxrgluelib/JXRMeta.h
@@ -34,7 +34,7 @@
 
 #ifndef UNREFERENCED_PARAMETER
 #define UNREFERENCED_PARAMETER(P) { (P) = (P); }
-#endif UNREFERENCED_PARAMETER
+#endif /*UNREFERENCED_PARAMETER*/
 
 //================================================================
 // Container
