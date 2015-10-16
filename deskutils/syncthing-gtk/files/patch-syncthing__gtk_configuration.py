--- syncthing_gtk/configuration.py.orig	2015-10-06 17:40:00 UTC
+++ syncthing_gtk/configuration.py
@@ -30,7 +30,7 @@ class _Configuration(object):
 		"autokill_daemon"			: (int, 2),	# 0 - never kill, 1 - always kill, 2 - ask
 		"daemon_priority"			: (int, 0), # uses nice values
 		"max_cpus"					: (int, 0), # 0 for all cpus
-		"syncthing_binary"			: (str, "/usr/bin/syncthing"),
+		"syncthing_binary"			: (str, "%%LOCALBASE%%/bin/syncthing"),
 		"minimize_on_start"			: (bool, False),
 		"folder_as_path"			: (bool, True),
 		"use_inotify"				: (list, []),
