--- src/VBox/Devices/PC/DevFwCommon.cpp.orig
+++ src/VBox/Devices/PC/DevFwCommon.cpp
@@ -40,6 +40,11 @@
 #include "VBoxDD2.h"
 #include "DevFwCommon.h"
 
+static inline void *
+mempcpy(void *__restrict dst, const void *__restrict src, size_t len)
+{
+	return ((char *)memcpy(dst, src, len) + len);
+}
 
 /*********************************************************************************************************************************
 *   Defined Constants And Macros                                                                                                 *
