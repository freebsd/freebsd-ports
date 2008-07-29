--- camlibs/ptp2/library.c	2008/07/18 07:26:56	11241
+++ camlibs/ptp2/library.c	2008/07/22 10:01:44	11247
@@ -858,6 +858,8 @@
 
 	/* from Mike Meyer <mwm@mired.org> */
 	{"Apple:iPhone (PTP mode)",		0x05ac, 0x1290, PTPBUG_DCIM_WRONG_PARENT},
+	/* irc reporter */
+	{"Apple:iPhone 3G (PTP mode)",		0x05ac, 0x1292, PTPBUG_DCIM_WRONG_PARENT},
 	/* https://sourceforge.net/tracker/index.php?func=detail&aid=1869653&group_id=158745&atid=809061 */
 	{"Pioneer:DVR-LX60D",			0x08e4, 0x0142, 0},
 };
