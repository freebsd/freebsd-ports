--- common/cseries.h.orig	Sat Feb  9 14:57:31 2002
+++ common/cseries.h	Sat Feb  9 14:57:34 2002
@@ -70,6 +70,7 @@
 #define HIGH_WORD(n) (((n)>>16)&0xffff)
 #define LOW_WORD(n) ((n)&0xffff)
 
+#ifndef __FreeBSD__
 #ifdef little_endian
 #define ntohl(q) (((((unsigned long) (q)))>>24) | ((((unsigned long) (q))>>8)&0xff00) | ((((unsigned long) (q))<<8)&0xff0000) | ((((unsigned long) (q))<<24)&0xff000000))
 #define htonl(q) (((((unsigned long) (q)))>>24) | ((((unsigned long) (q))>>8)&0xff00) | ((((unsigned long) (q))<<8)&0xff0000) | ((((unsigned long) (q))<<24)&0xff000000))
@@ -81,6 +82,7 @@
 	#define htonl(q) (q)
 	#define ntohs(q) (q)
 	#define htons(q) (q)
+#endif
 #endif
 #endif
 
