--- src/oss_backend.c.orig	2015-03-02 23:54:36.000000000 +0100
+++ src/oss_backend.c	2017-12-18 17:23:45.230183000 +0100
@@ -292,3 +292,13 @@ void oss_set_volume(int volume)
 	if(volume == 100)
 		m_actual_maxvalue = get_raw_value();
 }
+
+const gchar * oss_get_device()
+{
+	return NULL;
+}
+
+const GList * oss_get_device_names()
+{
+	return NULL;
+}
