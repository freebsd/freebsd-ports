--- src/fe-gtk/fe-gtk.c.orig	2013-04-02 03:07:55.000000000 +0200
+++ src/fe-gtk/fe-gtk.c	2013-04-04 20:46:15.000000000 +0200
@@ -134,7 +134,7 @@
  {"no-plugins",	'n', 0, G_OPTION_ARG_NONE,	&arg_skip_plugins, N_("Don't auto load any plugins"), NULL},
  {"plugindir",	'p', 0, G_OPTION_ARG_NONE,	&arg_show_autoload, N_("Show plugin/script auto-load directory"), NULL},
  {"configdir",	'u', 0, G_OPTION_ARG_NONE,	&arg_show_config, N_("Show user config directory"), NULL},
- {"url",	 0,  0, G_OPTION_ARG_STRING,	&arg_url, N_("Open an irc://server:port/channel URL"), "URL"},
+ {"url",	 0,  0, G_OPTION_ARG_STRING,	&arg_url, N_("Open an irc://server:port/channel?key URL"), "URL"},
 #ifndef WIN32	/* uses DBUS */
  {"command",	'c', 0, G_OPTION_ARG_STRING,	&arg_command, N_("Execute command:"), "COMMAND"},
  {"existing",	'e', 0, G_OPTION_ARG_NONE,	&arg_existing, N_("Open URL or execute command in an existing HexChat"), NULL},
