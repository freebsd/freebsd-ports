--- config_manager.c.orig	2021-02-09 17:35:52 UTC
+++ config_manager.c
@@ -68,7 +68,7 @@ cvar_t	cfg_save_sysinfo	=	{"cfg_save_sysinfo", "0"};
 cvar_t	cfg_save_cmdline	=	{"cfg_save_cmdline", "1"};
 cvar_t	cfg_backup			=	{"cfg_backup", "0"};
 cvar_t	cfg_legacy_exec		=	{"cfg_legacy_exec", "1"};
-cvar_t  cfg_use_home		=	{"cfg_use_home", "0"};
+cvar_t  cfg_use_home		=	{"cfg_use_home", "1"};
 cvar_t  cfg_use_gamedir		=	{"cfg_use_gamedir", "0"};
 
 /************************************ DUMP FUNCTIONS ************************************/
