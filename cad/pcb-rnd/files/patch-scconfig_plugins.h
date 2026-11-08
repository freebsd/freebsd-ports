--- scconfig/plugins.h.orig	2026-10-02 12:19:32 UTC
+++ scconfig/plugins.h
@@ -175,6 +175,7 @@ plugin_dep("io_diptrace", "lib_compat_help")
 plugin_dep("io_altium", "lib_compat_help")
 plugin_dep("io_autotrax", "lib_polyhelp")
 plugin_dep("io_diptrace", "lib_compat_help")
+plugin_dep("io_diptrace", "lib_gensexpr")
 plugin_dep("io_dsn", "lib_compat_help")
 plugin_dep("io_dsn", "lib_gensexpr")
 plugin_dep("io_dsn", "lib_netmap")
