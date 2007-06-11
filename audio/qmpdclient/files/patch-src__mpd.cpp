--- src/mpd.cpp.orig	Wed Dec  6 18:49:57 2006
+++ src/mpd.cpp		Fri Jun  1 23:52:14 2007
@@ -578,6 +578,9 @@
 	if (!m_connected)
 		return;
 
+	m_status.setVolume(v);
+	emit volumeUpdated(v);
+	
 	QMutexLocker lock(&m_mutex);
 	mpd_sendSetvolCommand(m_connection, v);
 	finishCommand();
