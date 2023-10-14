--- dlls/wineoss.drv/oss.c.orig	2023-07-17 16:05:30.000000000 +0300
+++ dlls/wineoss.drv/oss.c	2023-09-02 22:43:48.312607000 +0300
@@ -145,17 +145,6 @@ static NTSTATUS oss_test_connect(void *args)
 
     close(mixer_fd);
 
-    if(sysinfo.version[0] < '4' || sysinfo.version[0] > '9'){
-        TRACE("Priority_Low: sysinfo.version[0]: %x\n", sysinfo.version[0]);
-        params->priority = Priority_Low;
-        return STATUS_SUCCESS;
-    }
-    if(sysinfo.versionnum & 0x80000000){
-        TRACE("Priority_Low: sysinfo.versionnum: %x\n", sysinfo.versionnum);
-        params->priority = Priority_Low;
-        return STATUS_SUCCESS;
-    }
-
     TRACE("Priority_Preferred: Seems like valid OSS!\n");
 
     params->priority = Priority_Preferred;
