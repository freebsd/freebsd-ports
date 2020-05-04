--- src/rs232drv/rs232.h.orig	2019-11-21 00:03:29 UTC
+++ src/rs232drv/rs232.h
@@ -78,7 +78,7 @@ extern int rs232_cmdline_options_init(void);
 #define RS232_NUM_DEVICES 4
 
 extern char *rs232_devfile[RS232_NUM_DEVICES];
-int rs232_useip232[RS232_NUM_DEVICES];
+extern int rs232_useip232[RS232_NUM_DEVICES];
 
 /* the "ip232" protocol used by tcpser 
  
