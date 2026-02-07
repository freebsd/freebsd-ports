--- api/logic/minecraft/launch/PrintInstanceInfo.cpp.orig	2019-03-07 21:42:07 UTC
+++ api/logic/minecraft/launch/PrintInstanceInfo.cpp
@@ -19,8 +19,9 @@
 #include "PrintInstanceInfo.h"
 #include <launch/LaunchTask.h>
 
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
 namespace {
+#if defined(Q_OS_LINUX)
 void probeProcCpuinfo(QStringList &log)
 {
     std::ifstream cpuin("/proc/cpuinfo");
@@ -66,7 +67,44 @@ void runLspci(QStringList &log)
     }
     pclose(lspci);
 }
+#elif defined(Q_OS_FREEBSD)
+void runSysctlHwModel(QStringList &log)
+{
+	char buff[512];
+	FILE *hwmodel = popen("sysctl hw.model", "r");
+	while (fgets(buff, 512, hwmodel) != NULL)
+	{
+		log << QString::fromUtf8(buff);
+		break;
+	}
+	pclose(hwmodel);
+}
 
+void runPciconf(QStringList &log)
+{
+	char buff[512];
+	std::string strcard;
+	FILE *pciconf = popen("pciconf -lv -a vgapci0", "r");
+	while (fgets(buff, 512, pciconf) != NULL)
+	{
+		if (strncmp(buff, "    vendor", 10) == 0)
+		{
+			std::string str(buff);
+			strcard.append(str.substr(str.find_first_of("'") + 1, str.find_last_not_of("'") - (str.find_first_of("'") + 2)));
+			strcard.append(" ");
+		}
+		else if (strncmp(buff, "    device", 10) == 0)
+		{
+			std::string str2(buff);
+			strcard.append(str2.substr(str2.find_first_of("'") + 1, str2.find_last_not_of("'") - (str2.find_first_of("'") + 2)));
+		}
+		log << QString::fromStdString(strcard);
+		break;
+	}
+	pclose(pciconf);
+}
+#endif
+
 void runGlxinfo(QStringList & log)
 {
     // FIXME: fixed size buffers...
@@ -94,10 +132,14 @@ void PrintInstanceInfo::executeTask()
     auto instance = m_parent->instance();
     QStringList log;
 
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX)
     ::probeProcCpuinfo(log);
     ::runLspci(log);
     ::runGlxinfo(log);
+#elif defined(Q_OS_FREEBSD)
+	::runSysctlHwModel(log);
+	::runPciconf(log);
+	::runGlxinfo(log);
 #endif
 
     logLines(log, MessageLevel::MultiMC);
