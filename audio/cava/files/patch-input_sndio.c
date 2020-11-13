Stop using uninitialized variable after lazy refactoring upstream

--- input/sndio.c.orig	2020-10-29 12:44:33 UTC
+++ input/sndio.c
@@ -14,7 +14,7 @@ void *input_sndio(void *data) {
     par.bits = 16;
     par.le = 1;
     par.rate = 44100;
-    par.rchan = 2;
+    par.rchan = audio->channels;
     par.appbufsz = sizeof(buf) / par.rchan;
 
     if ((hdl = sio_open(audio->source, SIO_REC, 0)) == NULL) {
@@ -33,7 +33,7 @@ void *input_sndio(void *data) {
         exit(EXIT_FAILURE);
     }
 
-    uint16_t frames = (sizeof(buf) / sizeof(buf[0])) / 2;
+    uint16_t frames = (sizeof(buf) / sizeof(buf[0])) / audio->channels;
     while (audio->terminate != 1) {
         if (sio_read(hdl, buf, sizeof(buf)) == 0) {
             fprintf(stderr, __FILE__ ": sio_read() failed: %s\n", strerror(errno));
