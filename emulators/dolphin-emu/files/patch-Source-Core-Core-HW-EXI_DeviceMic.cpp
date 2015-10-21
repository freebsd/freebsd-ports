Add missing headers for EXPANSIONINTERFACE definition + memset()/memcpy() functions

--- Source/Core/Core/HW/EXI_DeviceMic.cpp.orig	2015-10-10 12:33:01.119987304 +0000
+++ Source/Core/Core/HW/EXI_DeviceMic.cpp	2015-10-10 12:36:08.152135888 +0000
@@ -12,7 +12,9 @@
 #include "Core/HW/EXI_DeviceMic.h"
 #include "Core/HW/GCPad.h"
 #include "Core/HW/SystemTimers.h"
+#include "Logging/Log.h"
 
+#include <cstring>
 #include <portaudio.h>
 
 void CEXIMic::StreamLog(const char *msg)
