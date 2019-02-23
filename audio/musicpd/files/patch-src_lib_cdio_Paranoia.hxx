--- src/lib/cdio/Paranoia.hxx.orig	2019-02-22 14:23:33 UTC
+++ src/lib/cdio/Paranoia.hxx
@@ -43,6 +43,8 @@
 #include <stdexcept>
 #include <utility>
 
+#include <cstdio>
+
 class CdromDrive {
 	cdrom_drive_t *drv = nullptr;
 
