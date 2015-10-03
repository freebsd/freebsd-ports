--- src/fsq/fsq.cxx.orig	2015-09-28 18:24:41 UTC
+++ src/fsq/fsq.cxx
@@ -1193,9 +1193,12 @@ int fsq::rx_process(const double *buf, i
 						&rx_stream[SHIFT_SIZE],				// from
 						BLOCK_SIZE*sizeof(*rx_stream));	// # bytes
 				memset(fft_data, 0, sizeof(fft_data));
-				for (int i = 0; i < BLOCK_SIZE; i++)
-					fft_data[i].real() = fft_data[i].imag() =
-						rx_stream[i] * a_blackman[i];
+				for (int i = 0; i < BLOCK_SIZE; i++) {
+					fft_data[i].real(
+							 rx_stream[i] * a_blackman[i]);
+					fft_data[i].imag(
+							 rx_stream[i] * a_blackman[i]);
+				}
 				fft->ComplexFFT(fft_data);
 				process_tones();
 			}
@@ -1423,7 +1426,7 @@ static string tx_text_queue = "";
 
 static vector<string> commands;
 #define NUMCOMMANDS 10
-static size_t next = 0;
+static size_t nexti = 0;
 
 double fsq_xmtdelay() // in seconds
 {
@@ -1440,9 +1443,9 @@ double fsq_xmtdelay() // in seconds
 void fsq_repeat_last_command()
 {
 	fsq_tx_text->clear();
-	fsq_tx_text->addstr(sz2utf8(commands[next].c_str()));
-	next++;
-	if (next == commands.size()) next = 0;
+	fsq_tx_text->addstr(sz2utf8(commands[nexti].c_str()));
+	nexti++;
+	if (nexti == commands.size()) nexti = 0;
 }
 
 int get_fsq_tx_char(void)
@@ -1484,7 +1487,7 @@ void try_transmit(void *)
 	if (active_modem != fsq_modem) return;
 
 	if (!active_modem->fsq_squelch_open() && trx_state == STATE_RX) {
-		next = 0;
+		nexti = 0;
 		fsq_que_clear();
 //LOG_WARN("%s", "start_tx()");
 		start_tx();
