--- src/VBox/Devices/Storage/DrvHostBase-freebsd.cpp.orig	2017-10-18 07:11:48 UTC
+++ src/VBox/Devices/Storage/DrvHostBase-freebsd.cpp
@@ -24,6 +24,7 @@
 #include <cam/scsi/scsi_message.h>
 #include <cam/scsi/scsi_pass.h>
 #include <VBox/scsi.h>
+#include <iprt/file.h>
 #include <iprt/log.h>
 
 /** Maximum buffer size supported by the CAM subsystem. */
