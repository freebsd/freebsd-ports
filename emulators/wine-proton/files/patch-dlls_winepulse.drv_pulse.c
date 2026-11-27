--- dlls/winepulse.drv/pulse.c.orig	2026-11-19 14:08:52 UTC
+++ dlls/winepulse.drv/pulse.c
@@ -999,7 +999,7 @@ static NTSTATUS pulse_test_connect(void *args)
 
     pulse_unlock();
 
-    params->priority = Priority_Preferred;
+    params->priority = Priority_Neutral;
     return STATUS_SUCCESS;
 
 fail:
