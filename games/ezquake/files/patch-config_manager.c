--- config_manager.c.orig	2008-04-27 17:51:52.000000000 -0300
+++ config_manager.c	2008-05-06 15:02:46.000000000 -0300
@@ -68,7 +68,7 @@
 cvar_t	cfg_save_userinfo	=	{"cfg_save_userinfo", "2"};
 cvar_t	cfg_save_onquit		=	{"cfg_save_onquit", "0"};
 cvar_t	cfg_legacy_exec		=	{"cfg_legacy_exec", "1"};
-cvar_t	cfg_legacy_write	=	{"cfg_legacy_write", "0"};
+cvar_t	cfg_legacy_write	=	{"cfg_legacy_write", "1"};
 
 cvar_t	cfg_save_cvars		=	{"cfg_save_cvars", "1"};
 cvar_t	cfg_save_aliases	=	{"cfg_save_aliases", "1"};
