--- src/librtlsdr.c.orig	2015-02-02 14:14:20 UTC
+++ src/librtlsdr.c
@@ -314,6 +314,7 @@ static rtlsdr_dongle_t known_devices[] =
 	{ 0x0ccd, 0x00e0, "Terratec NOXON DAB/DAB+ USB dongle (rev 2)" },
 	{ 0x1554, 0x5020, "PixelView PV-DT235U(RN)" },
 	{ 0x15f4, 0x0131, "Astrometa DVB-T/DVB-T2" },
+	{ 0x15f4, 0x0133, "HanfTek DVB-T" },
 	{ 0x185b, 0x0620, "Compro Videomate U620F"},
 	{ 0x185b, 0x0650, "Compro Videomate U650F"},
 	{ 0x185b, 0x0680, "Compro Videomate U680F"},
