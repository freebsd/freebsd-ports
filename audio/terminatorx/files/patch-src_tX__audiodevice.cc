--- src/tX_audiodevice.cc.orig	2018-11-07 17:14:34 UTC
+++ src/tX_audiodevice.cc
@@ -594,7 +594,7 @@ tX_jack_client tX_jack_client::instance;
 bool tX_jack_client::init()
 {
 	if (!client_initialized) {
-		if ((client=jack_client_open("terminatorX", (jack_options_t) NULL, NULL))==0) {
+		if ((client=jack_client_open("terminatorX", (jack_options_t) '\0', NULL))==0) {
 			tX_error("tX_jack_client() -> failed to connect to jackd.");
 		} else {
 			client_initialized = true;
