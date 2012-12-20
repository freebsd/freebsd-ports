--- dualserverd.h	2012-11-09 15:45:52.000000000 +0100
+++ dualserverd.h	2012-11-09 15:55:00.000000000 +0100
@@ -52,9 +52,11 @@
 #define INADDR_NONE ULONG_MAX
 #endif
 
+#ifndef __FreeBSD__
 #ifndef IFF_DYNAMIC
 #define IFF_DYNAMIC 0x8000
 #endif
+#endif
 
 #define MYWORD unsigned short
 #define MYBYTE unsigned char
@@ -594,10 +596,15 @@
 
 struct msg_control
 {
-	ulong cmsg_len;
+	u_long cmsg_len;
 	int cmsg_level;
 	int cmsg_type;
-	in_pktinfo pktinfo;
+  #ifdef __FreeBSD__
+  // Arbitrary size, when the size is required we use sizeof
+  unsigned char pktinfo[100];
+  #else
+  in_pktinfo pktinfo;
+  #endif
 };
 
 #if defined(__hppa__) || \
@@ -713,7 +720,7 @@
 	union
 	{
 		int broadCastVal;
-		bool pktinfoVal;
+		int pktinfoVal;
 	};
 	union
 	{
