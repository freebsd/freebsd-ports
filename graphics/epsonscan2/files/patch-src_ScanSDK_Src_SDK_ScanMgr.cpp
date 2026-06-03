--- src/ScanSDK/Src/SDK/ScanMgr.cpp.orig	2024-09-12 07:10:37 UTC
+++ src/ScanSDK/Src/SDK/ScanMgr.cpp
@@ -298,7 +298,7 @@ BOOL CScanMgr::setSettingParameter(const eSpecifiedPar
  switch (SpecifiedParameter)
  {
  case SP_SLEEP_TIMER:
-  if (m_sv->device_data.SleepTime.capability.minValue <= setparam <= m_sv->device_data.SleepTime.capability.maxValue){
+  if (m_sv->device_data.SleepTime.capability.minValue <= setparam && setparam <= m_sv->device_data.SleepTime.capability.maxValue){
    m_sv->device_data.SleepTime.select = setparam;
    parameter_exist = TRUE;
    SDI_TRACE_LOG("[INFO]setSettingParameter SleepTime set: %d", m_sv->device_data.SleepTime.select);
@@ -316,7 +316,7 @@ BOOL CScanMgr::setSettingParameter(const eSpecifiedPar
     }
    }
   }else{
-   if (m_sv->device_data.AutoPowerOffTime.capability.minValue <= setparam <= m_sv->device_data.AutoPowerOffTime.capability.maxValue){
+   if (m_sv->device_data.AutoPowerOffTime.capability.minValue <= setparam && setparam <= m_sv->device_data.AutoPowerOffTime.capability.maxValue){
     m_sv->device_data.AutoPowerOffTime.select = setparam;
     parameter_exist = TRUE;
     SDI_TRACE_LOG("[INFO]setSettingParameter AutoPowerOffTime set: %d", m_sv->device_data.AutoPowerOffTime.select);
