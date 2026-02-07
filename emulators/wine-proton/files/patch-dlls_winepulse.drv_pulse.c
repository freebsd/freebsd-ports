--- dlls/winepulse.drv/pulse.c.orig	2023-07-17 16:05:30.000000000 +0300
+++ dlls/winepulse.drv/pulse.c	2023-09-02 22:49:43.373385000 +0300
@@ -840,7 +840,7 @@ static NTSTATUS pulse_test_connect(void *args)
 
     pulse_unlock();
 
-    params->priority = Priority_Preferred;
+    params->priority = Priority_Neutral;
     return STATUS_SUCCESS;
 
 fail:
