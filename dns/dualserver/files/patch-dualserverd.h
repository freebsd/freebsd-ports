--- dualserverd.h	2013-05-06 19:27:45.000000000 +0200
+++ dualserverd.h	2013-05-18 16:36:54.000000000 +0200
@@ -623,10 +623,19 @@
 
 struct msg_control
 {
+#ifdef __FreeBSD__
+  u_long cmsg_len;
+#else
 	ulong cmsg_len;
+#endif
 	int cmsg_level;
 	int cmsg_type;
+#ifdef __FreeBSD__
+    // Arbitrary size, when the size is required we use sizeof
+    unsigned char pktinfo[100];
+#else
 	in_pktinfo pktinfo;
+#endif
 };
 
 #if defined(__hppa__) || \
@@ -744,7 +753,11 @@
 	union
 	{
 		int broadCastVal;
+#ifdef __FreeBSD__
+        int pktinfoVal;
+#else
 		bool pktinfoVal;
+#endif
 	};
 	union
 	{
