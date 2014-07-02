--- users.c.orig	2014-06-28 18:33:12.000000000 -0700
+++ users.c	2014-06-28 18:33:19.000000000 -0700
@@ -130,6 +130,7 @@
 // Leaving the port open the whole time could leave it in an
 // undefined state if Linrad crashes.
 //
+#if 0
 int n;
 int serport_baudrate;
 int serport_stopbits;
@@ -142,6 +143,7 @@
                  0);                    // RTS mode = 0
 n=lir_write_serport(serport_message,10);
 lir_close_serport();
+#endif
 }
 
 void users_close_devices(void)
