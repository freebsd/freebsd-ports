--- config_manager.c.orig	Tue Apr 18 17:59:55 2006
+++ config_manager.c	Wed Aug 30 19:01:17 2006
@@ -67,7 +67,7 @@
 cvar_t	cfg_save_unchanged	=	{"cfg_save_unchanged", "0"};
 cvar_t	cfg_save_userinfo	=	{"cfg_save_userinfo", "2"};
 cvar_t	cfg_legacy_exec		=	{"cfg_legacy_exec", "1"};
-cvar_t	cfg_legacy_write	=	{"cfg_legacy_write", "0"};
+cvar_t	cfg_legacy_write	=	{"cfg_legacy_write", "1"};
 
 cvar_t	cfg_save_cvars		=	{"cfg_save_cvars", "1"};
 cvar_t	cfg_save_aliases	=	{"cfg_save_aliases", "1"};
