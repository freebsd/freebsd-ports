--- kenwood/tmv7.c.orig	Mon Apr 10 01:16:47 2006
+++ kenwood/tmv7.c	Mon Apr 10 02:15:58 2006
@@ -216,7 +216,8 @@
 int tmv7_decode_event (RIG *rig)
 {
     char asyncbuf[ACKBUF_LEN];
-    int retval, asyncbuf_len = ACKBUF_LEN-1;
+    int retval;
+    size_t asyncbuf_len = ACKBUF_LEN-1;
     rig_debug(RIG_DEBUG_TRACE, "%s: called\n", __FUNCTION__);
 
     retval = kenwood_transaction(rig, NULL, 0, asyncbuf, &asyncbuf_len);
@@ -324,7 +325,8 @@
 int tmv7_set_vfo (RIG *rig, vfo_t vfo)
 {
     char vfobuf[16], ackbuf[ACKBUF_LEN];
-    int retval,ack_len;
+    int retval;
+    size_t ack_len;
 
     rig_debug(RIG_DEBUG_TRACE, "%s: called %d\n", __FUNCTION__,vfo);
 
@@ -383,7 +385,8 @@
 int tmv7_get_mode (RIG *rig, vfo_t vfo, rmode_t *mode, pbwidth_t *width)
 {
     char ackbuf[ACKBUF_LEN];
-    int retval,ack_len=ACKBUF_LEN;
+    int retval;
+    size_t ack_len=ACKBUF_LEN;
     int step;
     freq_t freq;
 
@@ -428,7 +431,8 @@
 int tmv7_get_channel(RIG *rig, channel_t *chan)
 {
     char membuf[64],ackbuf[ACKBUF_LEN];
-    int retval,ack_len;
+    int retval;
+    size_t ack_len;
     freq_t freq;
     char req[16],scf[128];
     int step, shift, rev, tone, ctcss, tonefq, ctcssfq;
@@ -540,7 +544,8 @@
 int tmv7_set_channel(RIG *rig, const channel_t *chan)
 {
     char membuf[ACKBUF_LEN],ackbuf[ACKBUF_LEN];
-    int retval,ack_len;
+    int retval;
+    size_t ack_len;
     char req[64];
     long long freq;   
     int chn, step, shift, tone, ctcss, tonefq, ctcssfq;
@@ -617,11 +622,11 @@
 
     if(chan->channel_num<221)
     	sprintf(membuf, "%s,%011"PRIll",%01d,%01d,0,%01d,%01d,0,%02d,000,%02d,0,0"EOM,
-                    req,(long long)freq, step, shift, tone,
+                    req,(long)freq, step, shift, tone,
                     ctcss, tonefq, ctcssfq);
     else
     	sprintf(membuf, "%s,%011"PRIll",%01d,%01d,0,%01d,%01d,0,%02d,000,%02d,"EOM,
-                    req, (long long)freq, step, shift, tone,
+                    req, (long)freq, step, shift, tone,
                     ctcss, tonefq, ctcssfq);
 
     ack_len=ACKBUF_LEN;
@@ -631,7 +636,7 @@
 
     if(chan->tx_freq!=RIG_FREQ_NONE) {
 	req[5]='1';
-    	sprintf(membuf, "%s,%011"PRIll",%01d"EOM, req,(long long)chan->tx_freq, step);
+    	sprintf(membuf, "%s,%011"PRIll",%01d"EOM, req,(long)chan->tx_freq, step);
         ack_len=ACKBUF_LEN;
     	retval = kenwood_transaction(rig, membuf, strlen(membuf), ackbuf, &ack_len);
         if (retval != RIG_OK)
@@ -656,7 +661,8 @@
 int tmv7_open(RIG *rig)
 {
     char ackbuf[ACKBUF_LEN];
-    int retval,ack_len=ACKBUF_LEN;
+    int retval;
+    size_t ack_len=ACKBUF_LEN;
 
 	/* just to be sure it's a TM-V7 */
     retval = kenwood_transaction(rig, "ID"EOM, 3, ackbuf, &ack_len);
