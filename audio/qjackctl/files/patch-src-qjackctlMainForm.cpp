

Patch attached with submission follows:

--- src/qjackctlMainForm.cpp.orig	2010-04-23 14:36:05.000000000 +0300
+++ src/qjackctlMainForm.cpp	2010-04-23 14:36:32.000000000 +0300
@@ -805,6 +805,8 @@
 		if (m_preset.iPriority > 0 && !bCoreaudio)
 			args.append("-P" + QString::number(m_preset.iPriority));
 	}
+	else
+		args.append("-r");
 	if (m_preset.iPortMax > 0 && m_preset.iPortMax != 256)
 		args.append("-p" + QString::number(m_preset.iPortMax));
 	if (m_preset.iTimeout > 0 && m_preset.iTimeout != 500)


