--- mDNS/mDNSClientAPI.h.orig	Wed Mar 17 23:45:20 2004
+++ mDNS/mDNSClientAPI.h	Wed Mar 17 23:45:36 2004
@@ -480,8 +480,8 @@
 typedef unsigned char  mDNSu8;
 typedef   signed short mDNSs16;
 typedef unsigned short mDNSu16;
-typedef   signed long  mDNSs32;
-typedef unsigned long  mDNSu32;
+typedef   signed int  mDNSs32;
+typedef unsigned int  mDNSu32;
 
 // To enforce useful type checking, we make mDNSInterfaceID be a pointer to a dummy struct
 // This way, mDNSInterfaceIDs can be assigned, and compared with each other, but not with other types
