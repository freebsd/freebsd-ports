--- src/Standalone/networkdeviceselectdialog.cpp.orig	2021-11-25 00:56:56 UTC
+++ src/Standalone/networkdeviceselectdialog.cpp
@@ -183,7 +183,7 @@ bool NetworkDeviceSelectDialog::UpdateNetworkSettingFi
         ES_Trace_Log(this, "Exist network setting file");
 #else
         ES_Trace_Log(this, "Exist file : .epsonscan2/Network/epsonscan2.conf");
-#endif*/
+#endif
        std::string work_path = ES_CMN_FUNCS::PATH::ES_GetWorkTempPath();
        QDir tmpdir("/tmp");
        if (!tmpdir.exists(work_path.c_str())) tmpdir.mkdir(work_path.c_str());
