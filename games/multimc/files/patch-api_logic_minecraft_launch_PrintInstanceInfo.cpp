--- api/logic/minecraft/launch/PrintInstanceInfo.cpp.orig	2017-12-18 00:19:43 UTC
+++ api/logic/minecraft/launch/PrintInstanceInfo.cpp
@@ -24,6 +24,10 @@ void PrintInstanceInfo::executeTask()
     auto instance = m_parent->instance();
     auto lines = instance->verboseDescription(m_session);
     
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
+
+	char buff[512];
+
 #ifdef Q_OS_LINUX
     std::ifstream cpuin("/proc/cpuinfo");
     for (std::string line; std::getline(cpuin, line);)
@@ -36,7 +40,6 @@ void PrintInstanceInfo::executeTask()
         }
     }
 
-    char buff[512];
     int gpuline = -1;
     int cline = 0;
     FILE *fp = popen("lspci -k", "r");
@@ -64,6 +67,40 @@ void PrintInstanceInfo::executeTask()
             cline++;
         }
     }
+#elif defined(Q_OS_FREEBSD)
+
+	std::string strcard;
+
+	FILE *fp3 = popen("sysctl hw.model", "r");
+	if (fp3 != NULL)
+	{
+		fgets(buff, 512, fp3);
+		std::string str(buff);
+		QStringList clines = (QStringList() << QString::fromStdString(str.substr(10, std::string::npos)));
+		logLines(clines, MessageLevel::MultiMC);
+	}
+
+	FILE *fp4 = popen("pciconf -lv -a vgapci0", "r");
+	if (fp4 != NULL)
+	{
+		while (fgets(buff, 512, fp4) != NULL)
+		{
+			if (strncmp(buff, "    vendor", 10) == 0)
+			{
+				std::string str(buff);
+				strcard.append(str.substr(str.find_first_of("'") + 1, str.find_last_not_of("'") - (str.find_first_of("'") + 2)));
+				strcard.append(" ");
+			}
+			else if (strncmp(buff, "    device", 10) == 0)
+			{
+				std::string str2(buff);
+				strcard.append(str2.substr(str2.find_first_of("'") + 1, str2.find_last_not_of("'") - (str2.find_first_of("'") + 2)));
+				QStringList glines = (QStringList() << QString::fromStdString(strcard));
+				logLines(glines, MessageLevel::MultiMC);
+			}
+		}
+	}
+#endif
     
     FILE *fp2 = popen("glxinfo", "r");
     if (fp2 != NULL)
