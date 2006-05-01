--- kenwood/kenwood.c.orig	Mon Apr 10 00:28:17 2006
+++ kenwood/kenwood.c	Mon Apr 10 00:48:27 2006
@@ -239,7 +239,8 @@
 int kenwood_set_vfo(RIG *rig, vfo_t vfo)
 {
 	unsigned char cmdbuf[16], ackbuf[16];
-	int cmd_len, ack_len, retval;
+	int cmd_len, retval;
+	size_t ack_len;
 	char vfo_function;
 
 	switch (vfo) {
@@ -273,7 +274,8 @@
 int kenwood_set_split_vfo(RIG *rig, vfo_t vfo, split_t split, vfo_t txvfo)
 {
 	unsigned char cmdbuf[16], ackbuf[16];
-	int cmd_len, ack_len, retval;
+	int cmd_len, retval;
+	size_t ack_len;
 	char vfo_function;
 
 	if(vfo !=RIG_VFO_CURR) {
@@ -326,7 +328,8 @@
 int kenwood_get_vfo(RIG *rig, vfo_t *vfo)
 {
 	unsigned char infobuf[50];
-	int info_len, retval;
+	int retval;
+	size_t info_len;
 
 	info_len = 50;
 	retval = kenwood_transaction (rig, "IF;", 3, infobuf, &info_len);
@@ -358,7 +361,8 @@
 int kenwood_set_freq(RIG *rig, vfo_t vfo, freq_t freq)
 {
 	unsigned char freqbuf[16], ackbuf[16];
-	int freq_len, ack_len, retval;
+	int freq_len, retval;
+	size_t ack_len;
 	char vfo_letter;
 	vfo_t	tvfo;
 
@@ -373,7 +377,7 @@
 							vfo);
 		return -RIG_EINVAL;
 	}
-	freq_len = sprintf(freqbuf,"F%c%011"PRIll";", vfo_letter, (long long)freq);
+	freq_len = sprintf(freqbuf,"F%c%011"PRIll";", vfo_letter, (long)freq);
 
 	ack_len = 0;
 	retval = kenwood_transaction (rig, freqbuf, freq_len, ackbuf, &ack_len);
@@ -389,7 +393,8 @@
 {
 	unsigned char freqbuf[50];
 	unsigned char cmdbuf[4];
-	int cmd_len, freq_len, retval;
+	int cmd_len, retval;
+	size_t freq_len;
 	char vfo_letter;
 	vfo_t	tvfo;
 
@@ -426,7 +431,8 @@
 int kenwood_get_rit(RIG *rig, vfo_t vfo, shortfreq_t * rit)
 {
 	unsigned char infobuf[50];
-	int info_len, retval;
+	int retval;
+	size_t info_len;
 
 	info_len = 50;
 	retval = kenwood_transaction (rig, "IF;", 3, infobuf, &info_len);
@@ -451,7 +457,8 @@
 int kenwood_set_rit(RIG * rig, vfo_t vfo, shortfreq_t rit)
 {
         unsigned char buf[50], infobuf[50], c;
-        int retval, info_len, len, i;
+        int retval, len, i;
+	size_t info_len;
 
 	
 	info_len = 0;
@@ -491,7 +498,7 @@
 int kenwood_scan(RIG * rig, vfo_t vfo, scan_t scan, int ch)
 {
 	unsigned char ackbuf[16];
-	int ack_len = 0;
+	size_t ack_len = 0;
 
 	return kenwood_transaction (rig, scan==RIG_SCAN_STOP? "SC0;":"SC1;", 4, 
 						ackbuf, &ack_len);
@@ -505,7 +512,8 @@
 int kenwood_set_mode(RIG *rig, vfo_t vfo, rmode_t mode, pbwidth_t width)
 {
 	unsigned char mdbuf[16],ackbuf[16];
-	int mdbuf_len, ack_len, kmode, retval;
+	int mdbuf_len, kmode, retval;
+	size_t ack_len;
 
 	switch (mode) {
 		case RIG_MODE_CW:       kmode = MD_CW; break;
@@ -536,7 +544,8 @@
 int kenwood_get_mode(RIG *rig, vfo_t vfo, rmode_t *mode, pbwidth_t *width)
 {
 	unsigned char modebuf[50];
-	int mode_len, retval;
+	int retval;
+	size_t mode_len;
 
 
 	mode_len = 50;
@@ -574,7 +583,8 @@
 int kenwood_set_level(RIG *rig, vfo_t vfo, setting_t level, value_t val)
 {
 	unsigned char levelbuf[16], ackbuf[16];
-	int level_len, ack_len, retval;
+	int level_len, retval;
+	size_t ack_len;
 	int i, kenwood_val;
 
 	if (RIG_LEVEL_IS_FLOAT(level))
@@ -636,7 +646,8 @@
 int get_kenwood_level(RIG *rig, const char *cmd, int cmd_len, float *f)
 {
 	unsigned char lvlbuf[50];
-	int lvl_len, retval;
+	int retval;
+	size_t lvl_len;
 	int lvl;
 
 	lvl_len = 50;
@@ -667,7 +678,8 @@
 int kenwood_get_level(RIG *rig, vfo_t vfo, setting_t level, value_t *val)
 {
 	unsigned char lvlbuf[50];
-	int lvl_len, retval;
+	int retval;
+	size_t lvl_len;
 	int lvl;
 	int i, ret, agclevel;
 
@@ -769,7 +781,8 @@
 int kenwood_set_func(RIG *rig, vfo_t vfo, setting_t func, int status)
 {
 	unsigned char fctbuf[16], ackbuf[16];
-	int fct_len, ack_len;
+	int fct_len;
+	size_t ack_len;
 
 	/* Optimize:
 	 *   sort the switch cases with the most frequent first
@@ -836,7 +849,8 @@
 static int get_kenwood_func(RIG *rig, const char *cmd, int cmd_len, int *status)
 {
 	unsigned char fctbuf[50];
-	int fct_len, retval;
+	int retval;
+	size_t fct_len;
 
 	fct_len = 50;
 	retval = kenwood_transaction (rig, cmd, cmd_len, fctbuf, &fct_len);
@@ -862,7 +876,8 @@
 int kenwood_get_func(RIG *rig, vfo_t vfo, setting_t func, int *status)
 {
 	unsigned char fctbuf[50];
-	int fct_len, retval;
+	int retval;
+	size_t fct_len;
 
 	fct_len = 50;
 
@@ -933,7 +948,8 @@
 {
 	const struct rig_caps *caps;
 	unsigned char tonebuf[16], ackbuf[16];
-	int tone_len, ack_len;
+	int tone_len;
+	size_t ack_len;
 	int i;
 								 
 	caps = rig->caps;
@@ -961,7 +977,8 @@
 {
 	const struct rig_caps *caps;
 	unsigned char tonebuf[50];
-	int tone_len, i, retval;
+	int i, retval;
+	size_t tone_len;
 	unsigned int tone_idx;
 								 
 	caps = rig->caps;
@@ -1006,7 +1023,8 @@
 int kenwood_get_ptt(RIG *rig, vfo_t vfo, ptt_t *ptt)
 {
 	unsigned char infobuf[50];
-	int info_len, retval;
+	int retval;
+	size_t info_len;
 
 	info_len = 50;
 	retval = kenwood_transaction (rig, "IF;", 3, infobuf, &info_len);
@@ -1032,7 +1050,7 @@
 int kenwood_set_ptt(RIG *rig, vfo_t vfo, ptt_t ptt)
 {
 	unsigned char ackbuf[16];
-	int ack_len = 0;
+	size_t ack_len = 0;
 
 	return kenwood_transaction (rig, ptt==RIG_PTT_ON? "TX;":"RX;", 3, 
 					ackbuf, &ack_len);
@@ -1046,7 +1064,8 @@
 int kenwood_get_dcd(RIG *rig, vfo_t vfo, dcd_t *dcd)
 {
 	unsigned char busybuf[50];
-	int busy_len, retval;
+	int retval;
+	size_t busy_len;
 								 
 	busy_len = 50;
 	retval = kenwood_transaction (rig, "BY;", 3, busybuf, &busy_len);
@@ -1071,7 +1090,8 @@
 int kenwood_set_trn(RIG *rig, int trn)
 {
 	unsigned char trnbuf[16], ackbuf[16];
-	int trn_len, ack_len = 0;
+	int trn_len;
+	size_t ack_len = 0;
 
 	trn_len = sprintf(trnbuf,"AI%c;", trn==RIG_TRN_RIG?'1':'0');
 
@@ -1085,7 +1105,8 @@
 int kenwood_get_trn(RIG *rig, int *trn)
 {
 	unsigned char trnbuf[50];
-	int trn_len, retval;
+	int retval;
+	size_t trn_len;
 
 	trn_len = 50;
 	retval = kenwood_transaction (rig, "AI;", 3, trnbuf, &trn_len);
@@ -1109,7 +1130,8 @@
 int kenwood_set_powerstat(RIG *rig, powerstat_t status)
 {
 	unsigned char pwrbuf[16], ackbuf[16];
-	int pwr_len, ack_len = 0;
+	int pwr_len;
+	size_t ack_len = 0;
 
 	pwr_len = sprintf(pwrbuf,"PS%c;", status==RIG_POWER_ON?'1':'0');
 
@@ -1123,7 +1145,8 @@
 int kenwood_get_powerstat(RIG *rig, powerstat_t *status)
 {
 	unsigned char pwrbuf[50];
-	int pwr_len = 50, retval;
+	int retval;
+	size_t pwr_len = 50;
 
 	retval = kenwood_transaction (rig, "PS;", 3, pwrbuf, &pwr_len);
 	if (retval != RIG_OK)
@@ -1146,7 +1169,8 @@
 int kenwood_reset(RIG *rig, reset_t reset)
 {
 	unsigned char rstbuf[16], ackbuf[16];
-	int rst_len, ack_len = 0;
+	int rst_len;
+	size_t ack_len = 0;
 	char rst;
 
 	switch(reset) {
@@ -1169,7 +1193,8 @@
 int kenwood_send_morse(RIG *rig, vfo_t vfo, const char *msg)
 {
 	unsigned char morsebuf[30], m2[30], ackbuf[16];
-	int morse_len, ack_len;
+	int morse_len;
+	size_t ack_len;
 	int msg_len, buff_len, retval;
 	const char *p;
 
@@ -1212,7 +1237,7 @@
 int kenwood_vfo_op(RIG *rig, vfo_t vfo, vfo_op_t op)
 {
 	unsigned char *cmd, ackbuf[16];
-	int ack_len = 0;
+	size_t ack_len = 0;
 
 	switch(op) {
 		case RIG_OP_UP: cmd="UP;"; break;
@@ -1236,7 +1261,8 @@
 int kenwood_set_mem(RIG *rig, vfo_t vfo, int ch)
 {
 	unsigned char membuf[16], ackbuf[16];
-	int mem_len, ack_len = 0;
+	int mem_len;
+	size_t ack_len = 0;
 
 	/*
 	 * "MCbmm;"
@@ -1255,7 +1281,8 @@
 int kenwood_get_mem(RIG *rig, vfo_t vfo, int *ch)
 {
 	unsigned char membuf[50];
-	int retval, mem_len;
+	int retval;
+	size_t mem_len;
 
 	/*
 	 * "MCbmm;"
@@ -1286,7 +1313,8 @@
 const char* kenwood_get_info(RIG *rig)
 {
 	unsigned char firmbuf[50];
-	int firm_len, retval;
+	int retval;
+	size_t firm_len;
 								 
 	firm_len = 50;
 	retval = kenwood_transaction (rig, "TY;", 3, firmbuf, &firm_len);
