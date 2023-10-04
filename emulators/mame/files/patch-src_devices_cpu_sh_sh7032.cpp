--- src/devices/cpu/sh/sh7032.cpp.orig	2023-10-03 07:41:18 UTC
+++ src/devices/cpu/sh/sh7032.cpp
@@ -1,6 +1,7 @@
 // license:BSD-3-Clause
 // copyright-holders:Angelo Salese
 
+#include "emu.h"
 #include "sh7032.h"
 
 DEFINE_DEVICE_TYPE(SH1_SH7032,  sh1_sh7032_device,  "sh1_sh7032",  "Hitachi SH-1 (SH7032)")
