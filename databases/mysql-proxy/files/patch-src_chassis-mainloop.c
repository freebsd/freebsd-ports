Switch away from deprecated libevent macros.

--- src/chassis-mainloop.c.orig	2013-12-23 22:57:16 UTC
+++ src/chassis-mainloop.c
@@ -99,9 +99,9 @@ int chassis_check_version(const char *li
 chassis *chassis_new() {
 	chassis *chas;
 
-	if (0 != chassis_check_version(event_get_version(), _EVENT_VERSION)) {
+	if (0 != chassis_check_version(event_get_version(), LIBEVENT_VERSION)) {
 		g_critical("%s: chassis is build against libevent %s, but now runs against %s",
-				G_STRLOC, _EVENT_VERSION, event_get_version());
+				G_STRLOC, LIBEVENT_VERSION, event_get_version());
 		return NULL;
 	}
 
@@ -116,7 +116,7 @@ chassis *chassis_new() {
 
 	chas->threads = chassis_event_threads_new();
 
-	chas->event_hdr_version = g_strdup(_EVENT_VERSION);
+	chas->event_hdr_version = g_strdup(LIBEVENT_VERSION);
 
 	chas->shutdown_hooks = chassis_shutdown_hooks_new();
 
@@ -225,10 +225,10 @@ static void event_log_use_glib(int libev
 
 	GLogLevelFlags glib_log_level = G_LOG_LEVEL_DEBUG;
 
-	if (libevent_log_level == _EVENT_LOG_DEBUG) glib_log_level = G_LOG_LEVEL_DEBUG;
-	else if (libevent_log_level == _EVENT_LOG_MSG) glib_log_level = G_LOG_LEVEL_MESSAGE;
-	else if (libevent_log_level == _EVENT_LOG_WARN) glib_log_level = G_LOG_LEVEL_WARNING;
-	else if (libevent_log_level == _EVENT_LOG_ERR) glib_log_level = G_LOG_LEVEL_CRITICAL;
+	if (libevent_log_level == EVENT_LOG_DEBUG) glib_log_level = G_LOG_LEVEL_DEBUG;
+	else if (libevent_log_level == EVENT_LOG_MSG) glib_log_level = G_LOG_LEVEL_MESSAGE;
+	else if (libevent_log_level == EVENT_LOG_WARN) glib_log_level = G_LOG_LEVEL_WARNING;
+	else if (libevent_log_level == EVENT_LOG_ERR) glib_log_level = G_LOG_LEVEL_CRITICAL;
 
 	g_log(G_LOG_DOMAIN, glib_log_level, "(libevent) %s", msg);
 }
