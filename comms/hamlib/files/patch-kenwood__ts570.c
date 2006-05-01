--- kenwood/ts570.c.orig	Mon Apr 10 00:54:20 2006
+++ kenwood/ts570.c	Mon Apr 10 01:04:43 2006
@@ -65,7 +65,8 @@
 static int ts570_get_mode(RIG *rig, vfo_t vfo, rmode_t *mode, pbwidth_t *width)
 {
   unsigned char buf[50];
-  int buf_len, retval;
+  int retval;
+  size_t buf_len;
 
 
   buf_len = 50;
@@ -146,7 +147,8 @@
 static int ts570_set_mode(RIG *rig, vfo_t vfo, rmode_t mode, pbwidth_t width)
 {
   unsigned char buf[16],ackbuf[16];
-  int buf_len, ack_len, kmode, retval;
+  int buf_len, kmode, retval;
+  size_t ack_len;
 
   switch (mode) 
   {
@@ -203,7 +205,8 @@
 static int ts570_set_ant(RIG *rig, vfo_t vfo, ant_t ant)
 {
 	unsigned char buf[6], ackbuf[16];
-	int len, ack_len, retval;
+	int len, retval;
+	size_t ack_len;
 
 	len = sprintf(buf,"AN%c;", ant==RIG_ANT_1?'1':'2');
 
@@ -220,7 +223,8 @@
 static int ts570_get_ant(RIG *rig, vfo_t vfo, ant_t *ant)
 {
 	unsigned char infobuf[50];
-	int info_len, retval;
+	int retval;
+	size_t info_len;
 
 	info_len = 5;
 	retval = kenwood_transaction (rig, "AN;", 3, infobuf, &info_len);
