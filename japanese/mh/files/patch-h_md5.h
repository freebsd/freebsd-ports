--- h/md5.h.orig	1999-02-09 11:30:00 UTC
+++ h/md5.h
@@ -20,11 +20,15 @@ typedef unsigned short int UINT2;
 typedef unsigned short int UINT2;
 
 /* UINT4 defines a four byte word */
+#if 0
 #ifndef __alpha
 typedef unsigned long int UINT4;
 #else
 typedef unsigned int UINT4;
 #endif
+#endif
+#include <sys/types.h>
+typedef uint32_t UINT4;
 
 /* PROTO_LIST is defined depending on how PROTOTYPES is defined above.
 If using PROTOTYPES, then PROTO_LIST returns the list, otherwise it
