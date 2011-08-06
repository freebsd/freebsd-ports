--- hfkernel/fsk/pactor.c.orig	2011-08-05 09:15:15.000000000 -0400
+++ hfkernel/fsk/pactor.c	2011-08-05 09:15:55.000000000 -0400
@@ -256,7 +256,7 @@
 
 /* --------------------------------------------------------------------- */
 
-extern __inline__ unsigned int get_crc_preset(int pktlen)
+__inline__ unsigned int get_crc_preset(int pktlen)
 {
 	switch (pktlen) {
 	case 23:
@@ -280,7 +280,7 @@
 #define PKT_QRT   (1<<2)
 #define PKT_IDLE  (1<<3)
 
-extern __inline__ void decode_qrt_packet(unsigned char *data, int pktlen)
+__inline__ void decode_qrt_packet(unsigned char *data, int pktlen)
 {
 	unsigned char buf[8];
 	unsigned char *bp2;
@@ -456,7 +456,7 @@
 };
 
 
-extern __inline__ void encode_qrt_packet(int pktlen)
+__inline__ void encode_qrt_packet(int pktlen)
 {
         unsigned char *p1, *p2;
         unsigned int crc;
@@ -611,7 +611,7 @@
 
 #define TMSIZE (sizeof(ps.tm.devflt)/sizeof(ps.tm.devflt[0]))
 
-extern __inline__ void tmg_clear(void)
+__inline__ void tmg_clear(void)
 {
 	memset(ps.tm.devflt, 0, sizeof(ps.tm.devflt));
 	ps.tm.ptr = 0;
@@ -646,7 +646,7 @@
 
 /* --------------------------------------------------------------------- */
 
-extern __inline__ void marq_clear(void)
+__inline__ void marq_clear(void)
 {
 	memset(ps.marq.acc, 0, sizeof(ps.marq.acc));
 	ps.marq.hdr = 0xff;
@@ -657,7 +657,7 @@
  * misc utility functions
  */
 
-extern __inline__ void cycle_end(void)
+__inline__ void cycle_end(void)
 {
 	ps.rxtime += PACTOR_CYCLE_ARQ;
 	ps.txtime += PACTOR_CYCLE_ARQ;
@@ -665,14 +665,14 @@
 	ps.txinv = !ps.txinv;
 }
 
-extern __inline__ void ack_transmit(void)
+__inline__ void ack_transmit(void)
 {
 	kbd_ack();
 	ps.pkt_counter = (ps.pkt_counter + 1) & 3;
 	ps.cur_hdr ^= 0xff;
 }
 
-extern __inline__ int retry(void)
+__inline__ int retry(void)
 {
 	if ((--ps.retry) <= 0)
 		return 1;
@@ -680,7 +680,7 @@
 }
 
 #ifdef FREQ_TRACKING
-extern __inline__ void pct_freq_tracking(int trk, l1_soft_t trkl, l1_soft_t trkm, l1_soft_t trkh)
+__inline__ void pct_freq_tracking(int trk, l1_soft_t trkl, l1_soft_t trkm, l1_soft_t trkh)
 {
 	ps.rxfreqdev += trk;
 	if (!ps.is_master)
@@ -1534,7 +1534,7 @@
 
 /* --------------------------------------------------------------------- */
 
-extern __inline__ void guess_crc(unsigned char *pkt, unsigned int len)
+__inline__ void guess_crc(unsigned char *pkt, unsigned int len)
 {
 #ifdef STANDBY_CRC_PRINT
 	unsigned char buf[24];
