--- ./src/modules/m_nationalchars.cpp.orig	2010-07-05 11:21:26.000000000 +0300
+++ ./src/modules/m_nationalchars.cpp	2010-07-05 11:23:29.000000000 +0300
@@ -255,7 +255,10 @@
 		ConfigReader* conf = new ConfigReader(ServerInstance);
 		charset = conf->ReadValue("nationalchars", "file", 0);
 		casemapping = conf->ReadValue("nationalchars", "casemapping", charset, 0, false);
-		charset.insert(0, "../locales/");
+		if (charset[0] != '/')
+		{
+			charset.insert(0, "../share/inspircd/locales/");
+		}
 		unsigned char * tables[8] = { m_additional, m_additionalMB, m_additionalUp, m_lower, m_upper, m_additionalUtf8, m_additionalUtf8range, m_additionalUtf8interval };
 		loadtables(charset, tables, 8, 5);
 		forcequit = conf->ReadFlag("nationalchars", "forcequit", 0);
