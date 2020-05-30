Stop using uninitialized variable after lazy refactoring upstream

--- input/sndio.c.orig	2020-05-29 23:20:44 UTC
+++ input/sndio.c
@@ -8,14 +8,13 @@ void *input_sndio(void *data) {
     struct sio_par par;
     struct sio_hdl *hdl;
     int16_t buf[256];
-    unsigned int channels;
 
     sio_initpar(&par);
     par.sig = 1;
     par.bits = 16;
     par.le = 1;
     par.rate = 44100;
-    par.rchan = 2;
+    par.rchan = audio->channels;
     par.appbufsz = sizeof(buf) / par.rchan;
 
     if ((hdl = sio_open(audio->source, SIO_REC, 0)) == NULL) {
@@ -34,7 +33,7 @@ void *input_sndio(void *data) {
         exit(EXIT_FAILURE);
     }
 
-    uint16_t frames = (sizeof(buf) / sizeof(buf[0])) / channels;
+    uint16_t frames = (sizeof(buf) / sizeof(buf[0])) / audio->channels;
     while (audio->terminate != 1) {
         if (sio_read(hdl, buf, sizeof(buf)) == 0) {
             fprintf(stderr, __FILE__ ": sio_read() failed: %s\n", strerror(errno));
