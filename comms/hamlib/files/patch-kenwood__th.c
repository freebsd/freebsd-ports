--- kenwood/th.c.orig	Mon Apr 10 01:19:35 2006
+++ kenwood/th.c	Mon Apr 10 02:34:23 2006
@@ -64,7 +64,8 @@
 th_decode_event (RIG *rig)
 {
     char asyncbuf[128];
-    int retval,async_len=128;
+    int retval;
+    size_t async_len=128;
 
     rig_debug(RIG_DEBUG_TRACE, "%s: called\n", __FUNCTION__);
 
@@ -182,7 +183,8 @@
 th_set_freq (RIG *rig, vfo_t vfo, freq_t freq)
 {
     char freqbuf[ACKBUF_LEN], ackbuf[ACKBUF_LEN];
-    int retval, step,ack_len=ACKBUF_LEN;
+    int retval, step;
+    size_t ack_len=ACKBUF_LEN;
     long long f;
 
     rig_debug(RIG_DEBUG_TRACE, "%s: called\n", __FUNCTION__);
@@ -193,7 +195,7 @@
 	}
 
     step = 1;
-    f=(long long) freq;
+    f=(long) freq;
     sprintf(freqbuf, "FQ %011"PRIll",%1d"EOM, f, step);
     retval = kenwood_transaction(rig, freqbuf, strlen(freqbuf), ackbuf, &ack_len);
     if (retval != RIG_OK)
@@ -210,7 +212,8 @@
 th_get_freq (RIG *rig, vfo_t vfo, freq_t *freq)
 {
     char freqbuf[24], ackbuf[ACKBUF_LEN];
-    int retval, step,ack_len=ACKBUF_LEN;
+    int retval, step;
+    size_t ack_len=ACKBUF_LEN;
 
     rig_debug(RIG_DEBUG_TRACE, "%s: called\n", __FUNCTION__);
 
@@ -243,7 +246,8 @@
 th_set_mode (RIG *rig, vfo_t vfo, rmode_t mode, pbwidth_t width)
 {
     char kmode, mdbuf[24], ackbuf[ACKBUF_LEN];
-    int retval,ack_len=ACKBUF_LEN;
+    int retval;
+    size_t ack_len=ACKBUF_LEN;
     rig_debug(RIG_DEBUG_TRACE, "%s: called\n", __FUNCTION__);
 
       if(vfo!=RIG_VFO_CURR) {
@@ -276,7 +280,8 @@
 th_get_mode (RIG *rig, vfo_t vfo, rmode_t *mode, pbwidth_t *width)
 {
     char vch, ackbuf[ACKBUF_LEN];
-    int retval,ack_len=ACKBUF_LEN;
+    int retval;
+    size_t ack_len=ACKBUF_LEN;
     rig_debug(RIG_DEBUG_TRACE, "%s: called\n", __FUNCTION__);
 
       if(vfo!=RIG_VFO_CURR) {
@@ -316,7 +321,8 @@
 th_set_vfo (RIG *rig, vfo_t vfo)
 {
     char vfobuf[16], ackbuf[ACKBUF_LEN];
-    int retval,ack_len=ACKBUF_LEN;
+    int retval;
+    size_t ack_len=ACKBUF_LEN;
 
     rig_debug(RIG_DEBUG_TRACE, "%s: called\n", __FUNCTION__);
 
@@ -368,7 +374,8 @@
 th_get_vfo (RIG *rig, vfo_t *vfo)
 {
     char cmdbuf[16], ackbuf[ACKBUF_LEN],vfoc;
-    int retval,ack_len;
+    int retval;
+    size_t ack_len;
 
     rig_debug(RIG_DEBUG_TRACE, "%s: called\n", __FUNCTION__);
 
@@ -425,7 +432,8 @@
 th_set_trn(RIG *rig, int trn)
 {
     char trnbuf[16], ackbuf[ACKBUF_LEN];
-    int retval,ack_len=ACKBUF_LEN;
+    int retval;
+    size_t ack_len=ACKBUF_LEN;
 
     rig_debug(RIG_DEBUG_TRACE, "%s: called\n", __FUNCTION__);
 
@@ -445,7 +453,8 @@
 th_get_trn (RIG *rig, int *trn)
 {
     char ackbuf[ACKBUF_LEN];
-    int retval,ack_len=ACKBUF_LEN;
+    int retval;
+    size_t ack_len=ACKBUF_LEN;
 
     rig_debug(RIG_DEBUG_TRACE, "%s: called\n", __FUNCTION__);
 
@@ -471,7 +480,8 @@
 static int th_get_kenwood_func (RIG *rig, const char *cmd, int *status)
 {
     char ackbuf[ACKBUF_LEN];
-    int retval,ack_len=ACKBUF_LEN;
+    int retval;
+    size_t ack_len=ACKBUF_LEN;
     rig_debug(RIG_DEBUG_TRACE, "%s: called\n", __FUNCTION__);
 
     retval = kenwood_transaction (rig, cmd, strlen(cmd), ackbuf, &ack_len);
@@ -528,7 +538,8 @@
 static int th_tburst(RIG *rig, vfo_t vfo, int status)
 {
     char ackbuf[ACKBUF_LEN];
-    int retval,ack_len=ACKBUF_LEN;
+    int retval;
+    size_t ack_len=ACKBUF_LEN;
 
     if(status==1) {
     retval = kenwood_transaction(rig, "TT"EOM, 3, ackbuf, &ack_len);
@@ -550,7 +561,8 @@
 static int th_set_kenwood_func (RIG *rig, const char *cmd, int status)
 {
     char trbuf[16], ackbuf[ACKBUF_LEN];
-    int retval,ack_len=ACKBUF_LEN;
+    int retval;
+    size_t ack_len=ACKBUF_LEN;
 
     rig_debug(RIG_DEBUG_TRACE, "%s: called\n", __FUNCTION__);
 
@@ -641,7 +653,8 @@
 th_get_level (RIG *rig, vfo_t vfo, setting_t level, value_t *val)
 {
     char vch, lvlbuf[32], ackbuf[ACKBUF_LEN];
-    int retval, v, l,ack_len=ACKBUF_LEN;
+    int retval, v, l;
+    size_t ack_len=ACKBUF_LEN;
     vfo_t tvfo;
 
     rig_debug(RIG_DEBUG_TRACE, "%s: called\n", __FUNCTION__);
@@ -734,7 +747,8 @@
 int th_set_level (RIG *rig, vfo_t vfo, setting_t level, value_t val)
 {
     char vch, lvlbuf[32], ackbuf[ACKBUF_LEN];
-    int retval,ack_len=ACKBUF_LEN;
+    int retval;
+    size_t ack_len=ACKBUF_LEN;
     vfo_t tvfo;
 
     rig_debug(RIG_DEBUG_TRACE, "%s: called\n", __FUNCTION__);
@@ -788,7 +802,8 @@
 {
       const struct rig_caps *caps;
       unsigned char tonebuf[16], ackbuf[ACKBUF_LEN];
-      int i, retval,ack_len=ACKBUF_LEN;
+      int i, retval;
+      size_t ack_len=ACKBUF_LEN;
 
 	rig_debug(RIG_DEBUG_TRACE, "%s: called\n", __FUNCTION__);
 
@@ -819,7 +834,8 @@
 {
     struct rig_caps *caps;
     char ackbuf[ACKBUF_LEN];
-    int retval,ack_len=ACKBUF_LEN;
+    int retval;
+    size_t ack_len=ACKBUF_LEN;
 	unsigned int tone_idx;
     rig_debug(RIG_DEBUG_TRACE, "%s: called\n", __FUNCTION__);
 
@@ -851,7 +867,8 @@
 th_get_info(RIG *rig)
 {
 	static unsigned char firmbuf[16];
-	int retval,firm_len=16;
+	int retval;
+        size_t firm_len=16;
 
 	rig_debug(RIG_DEBUG_TRACE, "%s: called\n", __FUNCTION__);
 
@@ -877,7 +894,8 @@
 th_set_mem(RIG *rig, vfo_t vfo, int ch)
 {
 	unsigned char vsel, membuf[16], ackbuf[16];
-	int retval, ack_len = 16;
+	int retval;
+        size_t ack_len = 16;
 	vfo_t tvfo;
 
 	rig_debug(RIG_DEBUG_TRACE, "%s: called\n", __FUNCTION__);
@@ -913,7 +931,8 @@
 th_get_mem(RIG *rig, vfo_t vfo, int *ch)
 {
 	unsigned char *membuf, ackbuf[ACKBUF_LEN];
-	int retval,ack_len=ACKBUF_LEN;
+	int retval;
+        size_t ack_len=ACKBUF_LEN;
 	vfo_t tvfo,cvfo;
 
 	rig_debug(RIG_DEBUG_TRACE, "%s: called\n", __FUNCTION__);
@@ -966,7 +985,8 @@
 th_set_ptt(RIG *rig, vfo_t vfo, ptt_t ptt)
 {
 	unsigned char *membuf, ackbuf[ACKBUF_LEN];
-	int retval,ack_len=ACKBUF_LEN;
+	int retval;
+        size_t ack_len=ACKBUF_LEN;
 
         rig_debug(RIG_DEBUG_TRACE, "%s: called\n", __FUNCTION__);
 
@@ -1017,7 +1037,8 @@
 int th_get_powerstat(RIG *rig, powerstat_t *status)
 {
                 unsigned char pwrbuf[50];
-                int pwr_len = 50, retval;
+                int retval;
+		size_t pwr_len = 50;
                                                                                                                             
                 retval = kenwood_transaction (rig, "PS;", 3, pwrbuf, &pwr_len);
                 if (retval != RIG_OK)
@@ -1037,7 +1058,8 @@
 int th_get_dcd(RIG *rig, vfo_t vfo, dcd_t *dcd)
 {
         unsigned char *membuf, ackbuf[ACKBUF_LEN];
-        int retval, ack_len=ACKBUF_LEN;
+        int retval;
+        size_t ack_len=ACKBUF_LEN;
 
 	switch (vfo) {
 	  case RIG_VFO_VFO:
@@ -1081,7 +1103,8 @@
 {
 
 	unsigned char *membuf,ackbuf[ACKBUF_LEN];
-	int retval,ack_len=ACKBUF_LEN;
+	int retval;
+        size_t ack_len=ACKBUF_LEN;
 
         rig_debug(RIG_DEBUG_TRACE, "%s: called\n", __FUNCTION__);
 
@@ -1123,7 +1146,8 @@
 int th_get_channel(RIG *rig, channel_t *chan)
 {
     char membuf[64],ackbuf[ACKBUF_LEN];
-    int retval,ack_len;
+    int retval;
+    size_t ack_len;
     freq_t freq,offset;
     char req[16],scf[128];
     int step, shift, rev, tone, ctcss, tonefq, ctcssfq;
@@ -1228,7 +1252,8 @@
 int th_set_channel(RIG *rig, const channel_t *chan)
 {
     char membuf[ACKBUF_LEN],ackbuf[ACKBUF_LEN];
-    int retval,ack_len;
+    int retval;
+    size_t ack_len;
     char req[64];
     long long freq,offset;   
     int chn, step, shift, tone, ctcss, tonefq, ctcssfq;
@@ -1298,12 +1323,12 @@
 
     if(chan->channel_num<=220)
     sprintf(membuf, "%s,%011"PRIll",%01d,%01d,0,%01d,%01d,,%02d,,%02d,%09"PRIll",0"EOM,
-                    req,(long long)freq, step, shift, tone,
-                    ctcss, tonefq, ctcssfq, (long long)offset);
+                    req,(long)freq, step, shift, tone,
+                    ctcss, tonefq, ctcssfq, (long)offset);
     else
     sprintf(membuf, "%s,%011"PRIll",%01d,%01d,0,%01d,%01d,,%02d,,%02d,%09"PRIll EOM,
-                    req, (long long)freq, step, shift, tone,
-                    ctcss, tonefq, ctcssfq, (long long)offset);
+                    req, (long)freq, step, shift, tone,
+                    ctcss, tonefq, ctcssfq, (long)offset);
 
     ack_len=ACKBUF_LEN;
     retval = kenwood_transaction(rig, membuf, strlen(membuf), ackbuf, &ack_len);
@@ -1312,7 +1337,7 @@
 
     if(chan->channel_num<223 && chan->tx_freq!=RIG_FREQ_NONE) {
 	req[5]='1';
-    	sprintf(membuf, "%s,%011"PRIll",%01d"EOM, req,(long long)chan->tx_freq, step);
+    	sprintf(membuf, "%s,%011"PRIll",%01d"EOM, req,(long)chan->tx_freq, step);
         ack_len=ACKBUF_LEN;
     	retval = kenwood_transaction(rig, membuf, strlen(membuf), ackbuf, &ack_len);
         if (retval != RIG_OK)
