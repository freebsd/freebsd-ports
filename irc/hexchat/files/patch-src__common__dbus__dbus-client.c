--- ./src/common/dbus/dbus-client.c.orig	2013-04-02 01:07:55.000000000 +0000
+++ ./src/common/dbus/dbus-client.c	2013-04-13 13:50:32.000000000 +0000
@@ -53,11 +53,13 @@
 	GError *error = NULL;
 	char *command = NULL;
 
+#if !GLIB_CHECK_VERSION (2, 32, 0)
 	/* GnomeVFS >=2.15 uses D-Bus and threads, so threads should be
 	 * initialised before opening for the first time a D-Bus connection */
 	if (!g_thread_supported ()) {
 		g_thread_init (NULL);
 	}
+#endif
 	dbus_g_thread_init ();
 
 	/* if there is nothing to do, return now. */
