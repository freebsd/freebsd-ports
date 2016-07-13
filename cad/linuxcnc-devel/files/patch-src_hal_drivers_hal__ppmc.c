--- src/hal/drivers/hal_ppmc.c.orig	2016-06-25 02:19:12 UTC
+++ src/hal/drivers/hal_ppmc.c
@@ -81,6 +81,9 @@
 MODULE_AUTHOR("John Kasunich");
 MODULE_DESCRIPTION("HAL driver for Universal PWM Controller");
 MODULE_LICENSE("GPL");
+
+#ifdef __linux__
+
 int port_addr[MAX_BUS] = { 0x378, [1 ... MAX_BUS-1] = -1 };
     /* default, 1 bus at 0x0378 */
 hal_parport_t port_registration[MAX_BUS];
@@ -2428,3 +2431,4 @@ static void WrtMore(unsigned char byte, 
     return;
 }
 
+#endif
