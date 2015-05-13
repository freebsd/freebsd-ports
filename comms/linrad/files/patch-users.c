--- users.c.orig	2014-11-04 10:25:00 UTC
+++ users.c
@@ -130,6 +130,7 @@ void userdefined_q(void)
 // Leaving the port open the whole time could leave it in an
 // undefined state if Linrad crashes.
 //
+#if 0
 int n;
 int serport_baudrate;
 int serport_stopbits;
@@ -142,6 +143,7 @@ lir_open_serport(SERPORT_NUMBER,        
                  0);                    // RTS mode = 0
 n=lir_write_serport(serport_message,10);
 lir_close_serport();
+#endif
 }
 
 void users_close_devices(void)
