--- hfkernel/mt63/mt63hflink.c.orig	Sat Aug  5 15:52:34 2006
+++ hfkernel/mt63/mt63hflink.c	Sat Aug  5 21:17:42 2006
@@ -112,7 +112,7 @@
 	    % MT63RXBUFLEN );
 	*/
 	if (pthread_mutex_unlock(&mt63_inputmut))
-	    errstr(SEV_FATAL, "pthread_mutex_unlock");
+	    errstr(SEV_FATAL, "pthread_mutex_unlock l1_mt63_input_samples");
 }
 
 /* --------------------------------------------------------------------- */
@@ -150,18 +150,18 @@
 		//printf("%do ",i);
 		mytime += (tinc * nsamples); // nsamples fragments encoded
 		if (pthread_mutex_unlock(&mt63_outputmut))
-		    errstr(SEV_FATAL, "pthread_mutex_unlock");
+		    errstr(SEV_FATAL, "pthread_mutex_unlock l1_mt63_output_samples 1");
 		return 1;
 	    } else {
 		if (pthread_mutex_unlock(&mt63_outputmut))
-		    errstr(SEV_FATAL, "pthread_mutex_unlock");
+		    errstr(SEV_FATAL, "pthread_mutex_unlock l1_mt63_output_samples 2");
 		return 0;
 	    }
 	} 
 	// if it is not yet the time to send sting new
 	printf("mt63 output samples came too early.\n");
 	if (pthread_mutex_unlock(&mt63_outputmut))
-		errstr(SEV_FATAL, "pthread_mutex_unlock");
+		errstr(SEV_FATAL, "pthread_mutex_unlock l1_mt63_output_samples 3");
 	return 0;
 }
 
@@ -170,7 +170,7 @@
 static void mt63_inputcleanup(void *dummy)
 {
 	if (pthread_mutex_unlock(&mt63_inputmut))
-		errstr(SEV_FATAL, "pthread_mutex_unlock");
+		errstr(SEV_FATAL, "pthread_mutex_unlock mt63_inputcleanup");
 	modefamily = 0;
 }
 
@@ -179,21 +179,21 @@
 void l1_mt63_wait_input_request(void)
 {
 	if (pthread_mutex_lock(&mt63_inputmut))
-		errstr(SEV_FATAL, "pthread_mutex_lock");
+		errstr(SEV_FATAL, "pthread_mutex_lock 1");
 
 	pthread_cleanup_push(mt63_inputcleanup, NULL);
 
 	if (pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL))
 		errstr(SEV_FATAL, "pthread_setcancelstate");
 	if (pthread_cond_wait(&mt63_inputcond, &mt63_inputmut))
-		errstr(SEV_FATAL, "pthread_cond_wait");
+		errstr(SEV_FATAL, "pthread_cond_wait l1_mt63_wait_input_request");
 
 	pthread_cleanup_pop(0);
 
 	if (pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL))
 		errstr(SEV_FATAL, "pthread_setcancelstate");
 	if (pthread_mutex_unlock(&mt63_inputmut))
-		errstr(SEV_FATAL, "pthread_mutex_unlock");
+		errstr(SEV_FATAL, "pthread_mutex_unlock l1_mt63_wait_input_request 2");
 	return;
 }
 
@@ -211,8 +211,8 @@
 
 	mt63_finish_tx();
 	//printf("mt63 tx finished ...\n");
-	if (pthread_mutex_unlock(&mt63_outputmut))
-		errstr(SEV_FATAL, "pthread_mutex_unlock");
+//	if (pthread_mutex_unlock(&mt63_outputmut))
+//		errstr(SEV_FATAL, "pthread_mutex_unlock mt63_outputcleanup");
 	printf("mt63 outputmutex unlocked...\n");
 	modefamily = 0;
 
@@ -241,17 +241,17 @@
 void l1_mt63_wait_output_request(void)
 {
 	if (pthread_mutex_lock(&mt63_outputmut))
-		errstr(SEV_FATAL, "pthread_mutex_lock");
+		errstr(SEV_FATAL, "pthread_mutex_lock l1_mt63_wait_output_request 1");
 	pthread_cleanup_push(mt63_outputcleanup, NULL);
 	if (pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL))
 		errstr(SEV_FATAL, "pthread_setcancelstate");
 	if (pthread_cond_wait(&mt63_outputcond, &mt63_outputmut))
-		errstr(SEV_FATAL, "pthread_cond_wait");
+		errstr(SEV_FATAL, "pthread_cond_wait l1_mt63_wait_output_request");
 	pthread_cleanup_pop(0);
 	if (pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL))
 		errstr(SEV_FATAL, "pthread_setcancelstate");
 	if (pthread_mutex_unlock(&mt63_outputmut))
-		errstr(SEV_FATAL, "pthread_mutex_unlock");
+		errstr(SEV_FATAL, "pthread_mutex_unlock l1_mt63_wait_output_request 2");
 	return;
 }
 
@@ -394,10 +394,10 @@
 	 * this long hangover because otherwise receiver's squelch will
 	 * cut off tail of the data !
 	 */
+	if (pthread_cond_wait(&mt63_outputcond, &mt63_outputmut))
+		errstr(SEV_FATAL, "pthread_cond_wait mt63_finish_tx");
 	for(i=0; i< tx_hangover; i++) { 
 	    //l1_mt63_wait_output_request(); this causes hang while cleanup!!
-	    if (pthread_cond_wait(&mt63_outputcond, &mt63_outputmut))
-		errstr(SEV_FATAL, "pthread_cond_wait");
 	    bufprintf(HFAPP_MSG_DATA_MONITOR, 
 		//"%02d ", (int)((txchar >> 1) & 0x1f));
 		".");
@@ -410,9 +410,9 @@
 		    mt63txbuf_written -= MT63TXBUFLEN;
 	    }
 	    //printf("written %d rest-samples from encodebuf to outbuf...\n", j);
-	    if (pthread_mutex_unlock(&mt63_outputmut))
-		errstr(SEV_FATAL, "mt63 tx: pthread_mutex_unlock");
 	}
+	if (pthread_mutex_unlock(&mt63_outputmut))
+		errstr(SEV_FATAL, "mt63 tx: pthread_mutex_unlock");
 	printf("o.k., flushed encodebuf, %d cycles...\n", i);
 	
 	errprintf(SEV_INFO, "mt63 tx: Sending jamming waveform ...\n");
@@ -420,10 +420,12 @@
 	bufprintf(HFAPP_MSG_DATA_STATUS, 
 	    "MT63 TX: Sending jamming waveform ...");
 */
+//	if (pthread_mutex_lock(&mt63_outputmut))
+//		errstr(SEV_FATAL, "mt63 tx: pthread_mutex_lock");
 	for ( i = 0; i < 20; i++) { 
-	    l1_mt63_wait_output_request();
-	    if (pthread_mutex_lock(&mt63_outputmut))
-		errstr(SEV_FATAL, "mt63 tx: pthread_mutex_lock");
+	    l1_mt63_wait_output_request(); /* locks and unlocks mt63_outputmut*/
+//	    if (pthread_mutex_unlock(&mt63_outputmut)) 
+//		errstr(SEV_FATAL, "mt63 tx: pthread_mutex_unlock");
 	    memset(encodebuf, 0, sizeof(encodebuf));
 	    mt63_tx_send_jam();
 	    for(j = 0; j < encodelen; j++) {
@@ -432,8 +434,6 @@
 		if (mt63txbuf_written >= MT63TXBUFLEN)
 		    mt63txbuf_written -= MT63TXBUFLEN;
 	    }
-	    if (pthread_mutex_unlock(&mt63_outputmut))
-		errstr(SEV_FATAL, "mt63 tx: pthread_mutex_unlock");
 	}
 	printf("sent %d cycles of jam ...\n", i);
 } 
@@ -488,10 +488,10 @@
 	if (pthread_mutex_unlock(&mt63_outputmut))
 	    errstr(SEV_FATAL, "mt63 tx: pthread_mutex_unlock");
 	//for(j = 0; j < 24; j++) {   
+//	if (pthread_mutex_lock(&mt63_outputmut))
+//		errstr(SEV_FATAL, "mt63 tx: pthread_mutex_lock");
 	for(;;) {
-	    l1_mt63_wait_output_request();
-	    if (pthread_mutex_lock(&mt63_outputmut))
-		errstr(SEV_FATAL, "mt63 tx: pthread_mutex_lock");
+	    l1_mt63_wait_output_request(); /* locks and unlocks mt63_outputmut */
 	    txchar = mt63_getcharbits();
 	    //txchar = 'f';
 	    bufprintf(HFAPP_MSG_DATA_MONITOR, 
@@ -505,9 +505,9 @@
 		    mt63txbuf_written -= MT63TXBUFLEN;
 	    }
 	    //printf("written %d samples from encodebuf to outbuf...\n",i);
-	    if (pthread_mutex_unlock(&mt63_outputmut))
-		errstr(SEV_FATAL, "mt63 tx: pthread_mutex_unlock");
 	}
+	if (pthread_mutex_unlock(&mt63_outputmut))
+		errstr(SEV_FATAL, "mt63 tx: pthread_mutex_unlock");
 	// mt63_outputcleanup(NULL);
 	// pthread_exit(NULL);
 }
