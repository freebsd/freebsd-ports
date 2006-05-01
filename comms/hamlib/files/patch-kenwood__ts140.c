--- kenwood/ts140.c.orig	Sun Apr  9 23:07:44 2006
+++ kenwood/ts140.c	Sun Apr  9 23:08:10 2006
@@ -63,7 +63,8 @@
 static int ts140_get_mode(RIG *rig, vfo_t vfo, rmode_t *mode, pbwidth_t *width)
 {
                 unsigned char modebuf[50];
-                int mode_len, retval;
+                size_t mode_len;
+		int retval;
 
                 mode_len = 50;
                 retval = kenwood_transaction (rig, "IF;", 3, modebuf, &mode_len);
@@ -98,7 +99,8 @@
 static int ts140_set_vfo(RIG *rig, vfo_t vfo)
 {
                 unsigned char cmdbuf[16], ackbuf[16];
-                int cmd_len, ack_len, retval;
+                int cmd_len, retval;
+		size_t ack_len;
                 char vfo_function;
 
                 switch (vfo) {
@@ -118,13 +120,14 @@
                 retval = kenwood_transaction (rig, cmdbuf, cmd_len, ackbuf, &ack_len);
                 if (retval != RIG_OK)
                         return retval;
-				return RIG_OK;
+                return RIG_OK;
 }
 
 static int ts140_get_freq(RIG *rig, vfo_t vfo, freq_t *freq)
 {
                 unsigned char freqbuf[50];
-                int freq_len, retval;
+                size_t freq_len;
+		int retval;
                 long long f;
 
 /* We're using IF; here because the TS-140S is incapable of supplying
@@ -143,16 +146,47 @@
                	}
 
                	freqbuf[14] = '\0';
-                sscanf(freqbuf+2, "%lld", &f);
+                sscanf(freqbuf+2, "%lld", &f); /* Is a long long int really necessary here? */
                 *freq = (freq_t)f;
 
                 return RIG_OK;
 }
 
+static int ts140_get_mem(RIG *rig, vfo_t vfo, int *ch)
+{
+                unsigned char membuf[50];
+                int m, retval;
+                size_t mem_len;
+
+                mem_len = 50;
+
+/* Again, the TS-140S is incapable of supplying the memory location
+* from MC; so we use IF;. Another awful hack, but it's what the radio
+* forces us to use. Furthermore, the radio will not return the value
+* of an empty memory. */
+
+                retval = kenwood_transaction (rig, "IF;", 3, membuf, &mem_len);
+                if (retval != RIG_OK)
+                                return retval;
+
+                if (mem_len != 38 || membuf[1] != 'F') {
+                                rig_debug(RIG_DEBUG_ERR,"ts140_get_mem: wrong answer "
+                                                                "len=%d\n", mem_len);
+                                return -RIG_ERJCTED;
+                }
+
+                membuf[28] = '\0';
+                sscanf(membuf+25, "%d", &m);
+                *ch = m;
+
+                return RIG_OK;
+}
+
 static int ts140_set_func(RIG *rig, vfo_t vfo, setting_t func, int status)
 {
                 unsigned char fctbuf[16], ackbuf[16];
-                int fct_len, ack_len;
+                int fct_len;
+		size_t ack_len;
                 ack_len = 0;
                 switch (func) {
                 case RIG_FUNC_LOCK:
@@ -170,7 +204,7 @@
 
 /*
  * ts140 rig capabilities.
- * 	MattD.. 2005-01-29
+ * 	GW0VNR 09042006
  */
 
 const struct rig_caps ts140_caps = {
@@ -275,7 +309,7 @@
 .get_func =  kenwood_get_func,
 .vfo_op =  kenwood_vfo_op,
 .set_mem =  kenwood_set_mem,
-.get_mem =  kenwood_get_mem,
+.get_mem =  ts140_get_mem,
 .reset =  kenwood_reset,
 
 };
