--- src/io.h.orig	2020-08-06 17:06:40 UTC
+++ src/io.h
@@ -90,9 +90,9 @@ uint8_t io_backend(void);
 
 /* prototypes */
 uint8_t io_backend(void);
-void io_signal();
-void io_signal_on();
-void io_signal_off();
+void io_signal(int);
+void io_signal_on(void);
+void io_signal_off(void);
 void io_config(void);
 int io_open(void);
 void io_close(int);
