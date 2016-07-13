--- src/hal/drivers/hal_parport.c.orig	2016-06-25 02:19:12 UTC
+++ src/hal/drivers/hal_parport.c
@@ -116,6 +116,8 @@ MODULE_LICENSE("GPL");
 static char *cfg = "0x0278";	/* config string, default 1 output port at 278 */
 RTAPI_MP_STRING(cfg, "config string");
 
+#ifdef __linux__
+
 /***********************************************************************
 *                STRUCTURES AND GLOBAL VARIABLES                       *
 ************************************************************************/
@@ -743,3 +745,11 @@ static int export_output_pin(int portnum
 		"parport.%d.pin-%02d-out-reset", portnum, pin);
     return retval;
 }
+#else
+int rtapi_app_main(void)
+{
+	rtapi_print_msg(RTAPI_MSG_ERR, "PARPORT: !linux\n");
+	return -1;
+}
+
+#endif /* !__linux__ */
