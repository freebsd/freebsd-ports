--- src/System_Info.cpp.orig	2026-11-07 08:39:49 UTC
+++ src/System_Info.cpp
@@ -21,6 +21,8 @@
 **
 ****************************************************************************/
 
+#include <unistd.h>
+
 #include <QDir>
 #include <QFile>
 #include <QProcess>
@@ -2725,7 +2727,7 @@ QStringList System_Info::Get_Host_CDROM_
 #include <QDir>
 #include <QFileInfoList>
 
-void System_Info::Get_Free_Memory_Size(int& allRAM, int& freeRAM)
+void System_Info::Get_Free_Memory_Size(size_t& allRAM, size_t& freeRAM)
 {
   size_t all_ram = 0, free_ram = 0, cached_mem = 0;
   size_t len = sizeof(all_ram);
