--- uartlirc_subr.c.orig
+++ uartlirc_subr.c
@@ -210,9 +210,17 @@ uartlirc_getenv(int devtype, struct uart
 	 * port (resp).
 	 */
 	if (devtype == UARTLIRC_DEV_CONSOLE)
+#if __FreeBSD_version >= 1100039
+		spec = kern_getenv("hw.uart.console");
+#else
 		spec = getenv("hw.uart.console");
+#endif
 	else if (devtype == UARTLIRC_DEV_DBGPORT)
+#if __FreeBSD_version >= 1100039
+		spec = kern_getenv("hw.uart.dbgport");
+#else
 		spec = getenv("hw.uart.dbgport");
+#endif
 	else
 		spec = NULL;
 	if (spec == NULL)
