--- kenwood/ts450s.c.orig	Mon Apr 10 01:05:26 2006
+++ kenwood/ts450s.c	Mon Apr 10 01:07:44 2006
@@ -78,7 +78,8 @@
 ts450s_get_mode(RIG *rig, vfo_t vfo, rmode_t *mode, pbwidth_t *width)
 {
   unsigned char infobuf[50];
-  int info_len, retval;
+  int retval;
+  size_t info_len;
 
   retval = kenwood_transaction (rig, "IF;", 3, infobuf, &info_len);
   if (retval != RIG_OK)
@@ -116,7 +117,8 @@
 ts450s_get_vfo(RIG *rig, vfo_t *vfo)
 {
   unsigned char infobuf[50];
-  int info_len, retval;
+  int retval;
+  size_t info_len;
 
   retval = kenwood_transaction (rig, "IF;", 3, infobuf, &info_len);
   if (retval != RIG_OK)
@@ -145,7 +147,8 @@
 ts450s_get_level(RIG *rig, vfo_t vfo, setting_t level, value_t *val)
 {
   unsigned char lvlbuf[50];
-  int lvl_len, retval;
+  int retval;
+  size_t lvl_len;
 
   lvl_len = 50;
   switch (level) 
@@ -205,7 +208,8 @@
 ts450s_set_level(RIG *rig, vfo_t vfo, setting_t level, value_t val)
 {
   unsigned char levelbuf[16], ackbuf[16];
-  int level_len, ack_len, retval;
+  int level_len, retval;
+  size_t ack_len;
   int kenwood_val;
 
   if (RIG_LEVEL_IS_FLOAT(level))
