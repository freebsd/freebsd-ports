--- kenwood/thg71.c.orig	Mon Apr 10 01:13:33 2006
+++ kenwood/thg71.c	Mon Apr 10 01:16:04 2006
@@ -184,7 +184,8 @@
 int thg71_decode_event (RIG *rig)
 {
     char asyncbuf[ACKBUF_LEN];
-    int retval, asyncbuf_len = ACKBUF_LEN-1;
+    int retval;
+    size_t asyncbuf_len = ACKBUF_LEN-1;
     rig_debug(RIG_DEBUG_TRACE, "%s: called\n", __FUNCTION__);
 
     retval = kenwood_transaction(rig, NULL, 0, asyncbuf, &asyncbuf_len);
@@ -291,7 +292,8 @@
 int thg71_get_mode (RIG *rig, vfo_t vfo, rmode_t *mode, pbwidth_t *width)
 {
     char ackbuf[ACKBUF_LEN];
-    int retval,ack_len=ACKBUF_LEN;
+    int retval;
+    size_t ack_len=ACKBUF_LEN;
     int step;
     freq_t freq;
 
@@ -327,7 +329,8 @@
 int thg71_set_vfo (RIG *rig, vfo_t vfo)
 {
     char vfobuf[16], ackbuf[ACKBUF_LEN];
-    int retval,ack_len=ACKBUF_LEN;
+    int retval;
+    size_t ack_len=ACKBUF_LEN;
 
     rig_debug(RIG_DEBUG_TRACE, "%s: called\n", __FUNCTION__);
 
@@ -355,7 +358,8 @@
 int thg71_get_vfo (RIG *rig, vfo_t *vfo)
 {
     char ackbuf[ACKBUF_LEN];
-    int retval,ack_len=ACKBUF_LEN;
+    int retval;
+    size_t ack_len=ACKBUF_LEN;
     int vch;
 
     retval = kenwood_transaction(rig, "VMC 0"EOM , 6, ackbuf, &ack_len);
@@ -382,7 +386,8 @@
 int thg71_set_func(RIG *rig, vfo_t vfo, setting_t func, int status)
 {
     char ackbuf[ACKBUF_LEN];
-    int retval,ack_len=ACKBUF_LEN;
+    int retval;
+    size_t ack_len=ACKBUF_LEN;
 
      if(func != RIG_FUNC_TBURST)
 		return -RIG_EINVAL;
@@ -404,7 +409,8 @@
 int thg71_open(RIG *rig)
 {
     char ackbuf[ACKBUF_LEN],*strl,*stru;
-    int retval,i,ack_len=ACKBUF_LEN;
+    int retval,i;
+    size_t ack_len=ACKBUF_LEN;
     const freq_range_t frend=RIG_FRNG_END;
 
 	/* just to be sure it's a THG-71 */
