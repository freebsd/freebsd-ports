--- src/mpdstatus.cpp.orig	Wed Dec  6 18:23:51 2006
+++ src/mpdstatus.cpp		Fri Jun  1 23:08:56 2007
@@ -88,6 +88,10 @@
 	return d->m_volume;
 }
 
+void MPDStatus::MPDStatus::setVolume(int vol) const {
+	d->m_volume = vol;
+}
+
 int MPDStatus::repeat() const {
 	return d->m_repeat;
 }
