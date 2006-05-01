--- kenwood/ts870s.c.orig	Mon Apr 10 00:08:29 2006
+++ kenwood/ts870s.c	Mon Apr 10 00:08:39 2006
@@ -74,7 +74,8 @@
 static int ts870s_get_vfo(RIG *rig, vfo_t *vfo)
 {
 		unsigned char vfobuf[50];
-		int vfo_len, retval;
+		int retval;
+		size_t vfo_len;
 
 
 		/* query RX VFO */
@@ -104,98 +105,100 @@
 
 static int ts870s_get_mode(RIG *rig, vfo_t vfo, rmode_t *mode, pbwidth_t *width)
 {
-  unsigned char buf[50];
-  int buf_len, retval;
-
-
-  buf_len = 50;
-  retval = kenwood_transaction (rig, "MD;", 3, buf, &buf_len);
-  if (retval != RIG_OK)
-    return retval;
-
-  if (buf_len != 4 || buf[1] != 'D')
-  {
-    rig_debug(RIG_DEBUG_ERR,"%s: unexpected MD answer, len=%d\n",
-      __FUNCTION__,buf_len);
-    return -RIG_ERJCTED;
-  }
-
-  switch (buf[2]) 
-  {
-    case MD_CW:         *mode = RIG_MODE_CW; break;
-    case MD_CWR:	*mode = RIG_MODE_CWR; break;
-    case MD_USB:	*mode = RIG_MODE_USB; break;
-    case MD_LSB:	*mode = RIG_MODE_LSB; break;
-    case MD_FM:	        *mode = RIG_MODE_FM; break;
-    case MD_AM:	        *mode = RIG_MODE_AM; break;
-    case MD_FSK:	*mode = RIG_MODE_RTTY; break;
-    case MD_FSKR:	*mode = RIG_MODE_RTTYR; break;
-    case MD_NONE:	*mode = RIG_MODE_NONE; break;
-    default:
-      rig_debug(RIG_DEBUG_ERR,"%s: unsupported mode '%c'\n",
-		      __FUNCTION__,buf[2]);
-      return -RIG_EINVAL;
-  }
-
-  buf_len = 50;
-  retval = kenwood_transaction (rig, "FW;", 3, buf, &buf_len);
-  if (retval != RIG_OK)
-    return retval;
-
-  if (buf_len != 7 || buf[1] != 'W')
-  {
-    rig_debug(RIG_DEBUG_ERR,"%s: unexpected FW answer, len=%d\n",
+  		unsigned char buf[50];
+		int retval;
+		size_t buf_len;
+
+  		buf_len = 50;
+  		retval = kenwood_transaction (rig, "MD;", 3, buf, &buf_len);
+  		if (retval != RIG_OK)
+    			return retval;
+
+  		if (buf_len != 4 || buf[1] != 'D')
+  		{
+    			rig_debug(RIG_DEBUG_ERR,"%s: unexpected MD answer, len=%d\n",
+      			__FUNCTION__,buf_len);
+    			return -RIG_ERJCTED;
+  		}
+
+  		switch (buf[2]) 
+  		{
+    			case MD_CW:         *mode = RIG_MODE_CW; break;
+    			case MD_CWR:	*mode = RIG_MODE_CWR; break;
+    			case MD_USB:	*mode = RIG_MODE_USB; break;
+    			case MD_LSB:	*mode = RIG_MODE_LSB; break;
+    			case MD_FM:	        *mode = RIG_MODE_FM; break;
+    			case MD_AM:	        *mode = RIG_MODE_AM; break;
+    			case MD_FSK:	*mode = RIG_MODE_RTTY; break;
+    			case MD_FSKR:	*mode = RIG_MODE_RTTYR; break;
+    			case MD_NONE:	*mode = RIG_MODE_NONE; break;
+    			default:
+      			rig_debug(RIG_DEBUG_ERR,"%s: unsupported mode '%c'\n",
+		      	__FUNCTION__,buf[2]);
+      			return -RIG_EINVAL;
+  		}
+
+  		buf_len = 50;
+  		retval = kenwood_transaction (rig, "FW;", 3, buf, &buf_len);
+  		if (retval != RIG_OK)
+    		return retval;
+
+  		if (buf_len != 7 || buf[1] != 'W')
+  		{
+    			rig_debug(RIG_DEBUG_ERR,"%s: unexpected FW answer, len=%d\n",
 			__FUNCTION__,buf_len);
-    return -RIG_ERJCTED;
-  }
+    			return -RIG_ERJCTED;
+  		}
   
-  *width = 10 * atoi(&buf[2]);
+ 		*width = 10 * atoi(&buf[2]);
 
-  return RIG_OK;
+  		return RIG_OK;
 }
 
 static int ts870s_set_mode(RIG *rig, vfo_t vfo, rmode_t mode, pbwidth_t width)
 {
-  unsigned char buf[16],ackbuf[16];
-  int buf_len, ack_len, kmode, retval;
-
-  switch (mode) 
-  {
-    case RIG_MODE_CW:       kmode = MD_CW; break;
-    case RIG_MODE_CWR:      kmode = MD_CWR; break;
-    case RIG_MODE_USB:      kmode = MD_USB; break;
-    case RIG_MODE_LSB:      kmode = MD_LSB; break;
-    case RIG_MODE_FM:       kmode = MD_FM; break;
-    case RIG_MODE_AM:       kmode = MD_AM; break;
-    case RIG_MODE_RTTY:     kmode = MD_FSK; break;
-    case RIG_MODE_RTTYR:    kmode = MD_FSKR; break;
-    default:
-      rig_debug(RIG_DEBUG_ERR,"%s: unsupported mode %d\n",
-		      __FUNCTION__,mode);
-      return -RIG_EINVAL;
-  }
-
-  buf_len = sprintf(buf, "MD%c;", kmode);
-  ack_len = 0;
-  retval = kenwood_transaction (rig, buf, buf_len, ackbuf, &ack_len);
-  if (retval != RIG_OK) return retval;
-
-/* 
- * This rig will simply use an IF bandpass which is closest to width, 
- * so we don't need to check the value...
- */
-  buf_len = sprintf(buf, "FW%04d;", (int)width/10);
-  ack_len = 0;
-  retval = kenwood_transaction (rig, buf, buf_len, ackbuf, &ack_len);
-  if (retval != RIG_OK) return retval;
+  		unsigned char buf[16],ackbuf[16];
+  		int buf_len, kmode, retval;
+		size_t ack_len;
+
+  		switch (mode) 
+  		{
+    			case RIG_MODE_CW:       kmode = MD_CW; break;
+    			case RIG_MODE_CWR:      kmode = MD_CWR; break;
+    			case RIG_MODE_USB:      kmode = MD_USB; break;
+    			case RIG_MODE_LSB:      kmode = MD_LSB; break;
+    			case RIG_MODE_FM:       kmode = MD_FM; break;
+    			case RIG_MODE_AM:       kmode = MD_AM; break;
+    			case RIG_MODE_RTTY:     kmode = MD_FSK; break;
+    			case RIG_MODE_RTTYR:    kmode = MD_FSKR; break;
+    			default:
+      			rig_debug(RIG_DEBUG_ERR,"%s: unsupported mode %d\n",
+		      	__FUNCTION__,mode);
+      			return -RIG_EINVAL;
+  		}
+
+  		buf_len = sprintf(buf, "MD%c;", kmode);
+  		ack_len = 0;
+  		retval = kenwood_transaction (rig, buf, buf_len, ackbuf, &ack_len);
+  		if (retval != RIG_OK) return retval;
+
+	/* 
+ 	* This rig will simply use an IF bandpass which is closest to width, 
+ 	* so we don't need to check the value...
+ 	*/
+  		buf_len = sprintf(buf, "FW%04d;", (int)width/10);
+  		ack_len = 0;
+  		retval = kenwood_transaction (rig, buf, buf_len, ackbuf, &ack_len);
+  		if (retval != RIG_OK) return retval;
 
-  return RIG_OK;
+  		return RIG_OK;
 }
 
 static int ts870s_get_level(RIG *rig, vfo_t vfo, setting_t level, value_t *val)
 {
 		unsigned char lvlbuf[50];
-		int lvl_len, retval;
+		int retval;
+		size_t lvl_len;
 		int lvl;
 		int i, ret, agclevel;
 
