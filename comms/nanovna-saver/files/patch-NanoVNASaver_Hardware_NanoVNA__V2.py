--- NanoVNASaver/Hardware/NanoVNA_V2.py.orig	2022-01-11 18:46:18 UTC
+++ NanoVNASaver/Hardware/NanoVNA_V2.py
@@ -55,7 +55,8 @@ _ADDR_HARDWARE_REVISION = 0xf2
 _ADDR_FW_MAJOR = 0xf3
 _ADDR_FW_MINOR = 0xf4
 
-WRITE_SLEEP = 0.05
+#WRITE_SLEEP = 0.05
+WRITE_SLEEP = 0.1
 
 _ADF4350_TXPOWER_DESC_MAP = {
     0: '9dB attenuation',
