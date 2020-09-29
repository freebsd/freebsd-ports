--- lldb/source/Plugins/Process/FreeBSD/RegisterContextPOSIXProcessMonitor_arm.h.orig
+++ lldb/source/Plugins/Process/FreeBSD/RegisterContextPOSIXProcessMonitor_arm.h
@@ -70,6 +70,10 @@
   uint32_t NumSupportedHardwareWatchpoints();
 
 private:
+  RegisterInfoPOSIX_arm::GPR m_gpr_arm;
+
+  RegisterInfoPOSIX_arm::FPU m_fpr;
+
   ProcessMonitor &GetMonitor();
 };
 
