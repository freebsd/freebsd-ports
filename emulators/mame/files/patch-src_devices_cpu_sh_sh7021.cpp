--- src/devices/cpu/sh/sh7021.cpp.orig	2023-10-03 07:41:10 UTC
+++ src/devices/cpu/sh/sh7021.cpp
@@ -1,6 +1,7 @@
 // license:BSD-3-Clause
 // copyright-holders:Angelo Salese
 
+#include "emu.h"
 #include "sh7021.h"
 
 DEFINE_DEVICE_TYPE(SH2A_SH7021, sh2a_sh7021_device, "sh2a_sh7021", "Hitachi SH-2A (SH7021)")
