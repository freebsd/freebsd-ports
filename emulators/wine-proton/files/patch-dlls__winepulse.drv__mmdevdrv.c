--- dlls/winepulse.drv/mmdevdrv.c.orig	2022-08-04 16:21:59.000000000 +0300
+++ dlls/winepulse.drv/mmdevdrv.c	2022-11-10 05:43:39.850396000 +0300
@@ -499,7 +499,7 @@ int WINAPI AUDDRV_GetPriority(void)
     params.config = &pulse_config;
     pulse_call(test_connect, &params);
     free(name);
-    return SUCCEEDED(params.result) ? Priority_Preferred : Priority_Unavailable;
+    return SUCCEEDED(params.result) ? Priority_Neutral : Priority_Unavailable;
 }
 
 static BOOL get_pulse_name_by_guid(const GUID *guid, char pulse_name[MAX_PULSE_NAME_LEN], EDataFlow *flow)
