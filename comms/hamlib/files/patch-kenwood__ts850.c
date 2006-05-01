--- kenwood/ts850.c.orig	Sun Apr  9 23:36:11 2006
+++ kenwood/ts850.c	Sun Apr  9 23:49:51 2006
@@ -226,7 +226,8 @@
 int ts850_set_rit(RIG * rig, vfo_t vfo, shortfreq_t rit)
 {
         unsigned char buf[50], infobuf[50], c;
-        int retval, info_len, len, i;
+        int retval, len, i;
+	size_t info_len;
 
 
         info_len = 0;
@@ -255,7 +256,8 @@
 int ts850_set_xit(RIG * rig, vfo_t vfo, shortfreq_t xit)
 {
         unsigned char buf[50], infobuf[50], c;
-        int retval, info_len, len, i;
+        int retval, len, i;
+	size_t info_len;
 
         info_len = 0;
         if (xit == 0)
@@ -297,7 +299,8 @@
 int ts850_get_mode(RIG *rig, vfo_t vfo, rmode_t *mode, pbwidth_t *width)
 {
                 unsigned char infobuf[50];
-                int info_len, retval;
+                int retval;
+		size_t info_len;
 		int f,f1,f2;
 
                 info_len = 50;
@@ -387,7 +390,8 @@
 int ts850_set_mode(RIG *rig, vfo_t vfo, rmode_t mode, pbwidth_t width)
 {
                 unsigned char mdbuf[16],ackbuf[16];
-                int mdbuf_len, ack_len, kmode, retval;
+                int mdbuf_len, kmode, retval;
+		size_t ack_len;
 
 		 kmode=mode_to_char(mode);
 		 if(kmode==RIG_MODE_NONE) {
@@ -426,7 +430,8 @@
 {
         const struct rig_caps *caps;
         unsigned char tonebuf[16], ackbuf[16];
-        int tone_len, ack_len;
+        int tone_len;
+	size_t ack_len;
         int i;
 
         caps = rig->caps;
@@ -447,7 +452,8 @@
 int ts850_set_func(RIG *rig, vfo_t vfo, setting_t func, int status)
 {
                 unsigned char fctbuf[16], ackbuf[16];
-                int fct_len, ack_len;
+                int fct_len;
+		size_t ack_len;
 
 		if (vfo != RIG_VFO_CURR) 
 			return -RIG_EINVAL;
@@ -474,7 +480,8 @@
 int ts850_get_func(RIG *rig, vfo_t vfo, setting_t func, int *status)
 {
                 unsigned char fctbuf[16], ackbuf[16];
-                int retval, fct_len, ack_len;
+                int retval, fct_len;
+		size_t ack_len;
 
 		if (vfo != RIG_VFO_CURR) 
 			return -RIG_EINVAL;
@@ -505,7 +512,8 @@
 int ts850_get_level(RIG *rig, vfo_t vfo, setting_t level, value_t *val)
 {
                 unsigned char lvlbuf[50];
-                int i, lvl_len, retval;
+                int i, retval;
+		size_t lvl_len;
 
 		if(vfo!=RIG_VFO_CURR)
 			return -RIG_EINVAL;
@@ -587,7 +595,8 @@
 int ts850_set_level(RIG *rig, vfo_t vfo, setting_t level, value_t val)
 {
                 unsigned char lvlbuf[16], ackbuf[16];
-                int lvl_len, ack_len;
+                int lvl_len;
+		size_t ack_len;
 
                 if(level != RIG_LEVEL_CWPITCH)
 			return -RIG_EINVAL;
@@ -604,7 +613,8 @@
 int ts850_get_mem(RIG *rig, vfo_t vfo, int *ch)
 {
                 unsigned char infobuf[50];
-                int info_len, retval;
+                int retval;
+		size_t info_len;
 
                 info_len = 50;
                 retval = kenwood_transaction (rig, "IF;", 3, infobuf, &info_len)
@@ -642,7 +652,8 @@
 int ts850_get_channel (RIG * rig, channel_t * chan)
 {
                 unsigned char cmdbuf[16], membuf[30];
-                int retval, cmd_len,mem_len,num;
+                int retval, cmd_len, num;
+		size_t mem_len;
 
 		num=chan->channel_num;
 
@@ -693,7 +704,8 @@
 int ts850_set_channel (RIG * rig, const channel_t * chan)
 {
                 unsigned char cmdbuf[30], membuf[30];
-                int retval, cmd_len,mem_len;
+                int retval, cmd_len;
+		size_t mem_len;
 		int num,freq,tx_freq,tone;
 		char mode,tx_mode,split,tones;
 
