--- drivers/netjack/net_driver.c.orig	2009-02-11 20:49:54.000000000 +0100
+++ drivers/netjack/net_driver.c	2009-02-11 20:50:05.000000000 +0100
@@ -497,7 +497,7 @@
     {
 	int r;
 
-#ifdef __APPLE__
+#if !defined(MSG_CONFIRM)
 	static const int flag = 0;
 #else
 	static const int flag = MSG_CONFIRM;
