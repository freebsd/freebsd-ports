Add missing header for sprintf()

--- Source/Core/Core/HW/SI_DeviceAMBaseboard.cpp.orig	2015-10-10 13:10:03.586833708 +0000
+++ Source/Core/Core/HW/SI_DeviceAMBaseboard.cpp	2015-10-10 13:10:33.293832071 +0000
@@ -2,6 +2,7 @@
 // Licensed under GPLv2+
 // Refer to the license.txt file included.
 
+#include <cstdio>
 #include <cstring>
 
 #include "Common/MsgHandler.h"
