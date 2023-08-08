--- dlls/wineoss.drv/mmdevdrv.c.orig	2022-08-04 16:21:59.000000000 +0300
+++ dlls/wineoss.drv/mmdevdrv.c	2022-11-10 06:18:31.318170000 +0300
@@ -288,15 +288,6 @@ int WINAPI AUDDRV_GetPriority(void)
 
     close(mixer_fd);
 
-    if(sysinfo.version[0] < '4' || sysinfo.version[0] > '9'){
-        TRACE("Priority_Low: sysinfo.version[0]: %x\n", sysinfo.version[0]);
-        return Priority_Low;
-    }
-    if(sysinfo.versionnum & 0x80000000){
-        TRACE("Priority_Low: sysinfo.versionnum: %x\n", sysinfo.versionnum);
-        return Priority_Low;
-    }
-
     TRACE("Priority_Preferred: Seems like valid OSS!\n");
 
     return Priority_Preferred;
