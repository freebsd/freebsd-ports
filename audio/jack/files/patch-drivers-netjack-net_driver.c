--- drivers/netjack/net_driver.c.orig	2009-02-06 11:34:50.000000000 +0100
+++ drivers/netjack/net_driver.c	2009-11-13 10:04:27.282082404 +0100
@@ -497,7 +497,7 @@ net_driver_write (net_driver_t* driver, 
     {
 	int r;
 
-#ifdef __APPLE__
+#if !defined(MSG_CONFIRM)
 	static const int flag = 0;
 #else
 	static const int flag = MSG_CONFIRM;
@@ -548,13 +548,13 @@ net_driver_attach (net_driver_t *driver)
 
 	if( driver->bitdepth == 1000 ) {
 #if HAVE_CELT
-	    celt_int32_t lookahead;
+	    celt_int32 lookahead;
 	    // XXX: memory leak
-	    CELTMode *celt_mode = celt_mode_create( driver->sample_rate, 1, driver->period_size, NULL );
+	    CELTMode *celt_mode = celt_mode_create( driver->sample_rate, driver->period_size, NULL );
 	    celt_mode_info( celt_mode, CELT_GET_LOOKAHEAD, &lookahead );
 	    driver->codec_latency = 2*lookahead;
 
-	    driver->capture_srcs = jack_slist_append(driver->capture_srcs, celt_decoder_create( celt_mode ) );
+	    driver->capture_srcs = jack_slist_append(driver->capture_srcs, celt_decoder_create( celt_mode, 1, NULL ) );
 #endif
 	} else {
 #if HAVE_SAMPLERATE 
@@ -596,8 +596,8 @@ net_driver_attach (net_driver_t *driver)
 	if( driver->bitdepth == 1000 ) {
 #if HAVE_CELT
 	    // XXX: memory leak
-	    CELTMode *celt_mode = celt_mode_create( driver->sample_rate, 1, driver->period_size, NULL );
-	    driver->playback_srcs = jack_slist_append(driver->playback_srcs, celt_encoder_create( celt_mode ) );
+	    CELTMode *celt_mode = celt_mode_create( driver->sample_rate, driver->period_size, NULL );
+	    driver->playback_srcs = jack_slist_append(driver->playback_srcs, celt_encoder_create( celt_mode, 1, NULL ) );
 #endif
 	} else {
 #if HAVE_SAMPLERATE
