diff -ur work/mt-daapd-0.2.0/src/mDNSClientAPI.h work.orig/mt-daapd-0.2.0/src/mDNSClientAPI.h
--- src/mDNSClientAPI.h        Thu Oct 21 09:52:05 2004
+++ src/mDNSClientAPI.h.orig   Mon Mar 29 19:55:17 2004
@@ -486,8 +486,8 @@
 typedef unsigned char  mDNSu8;
 typedef   signed short mDNSs16;
 typedef unsigned short mDNSu16;
+typedef   signed int   mDNSs32;
+typedef unsigned int   mDNSu32;
-typedef   signed long  mDNSs32;
-typedef unsigned long  mDNSu32;
 
 // To enforce useful type checking, we make mDNSInterfaceID be a pointer to a dummy struct
 // This way, mDNSInterfaceIDs can be assigned, and compared with each other, but not with other types
