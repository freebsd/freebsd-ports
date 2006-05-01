--- kenwood/ts480.c.orig	Mon Apr 10 01:10:22 2006
+++ kenwood/ts480.c	Mon Apr 10 01:12:55 2006
@@ -50,7 +50,7 @@
 kenwood_ts480_set_ptt (RIG * rig, vfo_t vfo, ptt_t ptt)
 {
   unsigned char ackbuf[16];
-  int ack_len = 0;
+  size_t ack_len = 0;
 
   if (RIG_PTT_ON == ptt)
     return kenwood_transaction (rig, "TX1;", 4, ackbuf, &ack_len);
@@ -68,7 +68,7 @@
 kenwood_ts480_set_ant (RIG * rig, vfo_t vfo, ant_t ant)
 {
   unsigned char ackbuf[16];
-  int ack_len = 0;
+  size_t ack_len = 0;
 
   if (RIG_ANT_1 == ant)
     return kenwood_transaction (rig, "AN1;", 4, ackbuf, &ack_len);
@@ -88,7 +88,7 @@
 kenwood_ts480_get_ant (RIG * rig, vfo_t vfo, ant_t * ant)
 {
   unsigned char ackbuf[16];
-  int ack_len = 16;
+  size_t ack_len = 16;
   int retval;
 
   retval = kenwood_transaction (rig, "AN;", 3, ackbuf, &ack_len);
@@ -120,7 +120,8 @@
 kenwood_ts480_get_info (RIG * rig)
 {
   unsigned char firmbuf[50];
-  int firm_len, retval;
+  int retval;
+  size_t firm_len;
 
   firm_len = 50;
   retval = kenwood_transaction (rig, "TY;", 3, firmbuf, &firm_len);
@@ -160,7 +161,8 @@
 kenwood_ts480_set_level (RIG * rig, vfo_t vfo, setting_t level, value_t val)
 {
   unsigned char levelbuf[16], ackbuf[16];
-  int level_len, ack_len, retval;
+  int level_len, retval;
+  size_t ack_len;
   int kenwood_val;
 
   switch (level)
@@ -227,7 +229,7 @@
 kenwood_ts480_get_level (RIG * rig, vfo_t vfo, setting_t level, value_t * val)
 {
   unsigned char ackbuf[50];
-  int ack_len = 50;
+  size_t ack_len = 50;
   int levelint;
   int retval;
 
@@ -327,7 +329,8 @@
 kenwood_ts480_set_func (RIG * rig, vfo_t vfo, setting_t func, int status)
 {
   unsigned char fctbuf[16], ackbuf[16];
-  int fct_len, ack_len;
+  int fct_len;
+  size_t ack_len;
 
   ack_len = 0;
   switch (func)
