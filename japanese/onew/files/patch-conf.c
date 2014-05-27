--- conf.c.orig	1994-06-23 11:42:33.000000000 +0900
+++ conf.c	2014-05-25 11:51:12.000000000 +0900
@@ -119,6 +119,7 @@
 			}
 	return name;
 }
+void
 switch_rkserv(){
 	char help[128];
 	char *romkan;
@@ -137,6 +138,7 @@
 		Onew_putmsg_retain(1,"%s %s",Onew_RK_smode(),help);
 	}
 }
+void
 switch_kkserv(){
 	char mode[64],help[128],*kanakan;
 
@@ -220,7 +222,8 @@
 #define IR(func)			(romkan_select() ? func : 0)
 #define ONEWromkan_ready(rkpath)	IR((*RP->rk_ready)(rkpath))
 #define ONEWromkan_modesw(mode)		IR((*RP->rk_modesw)(mode))
-#define ONEWromkan_clear()		IR((*RP->rk_gotch)())
+/*#define ONEWromkan_clear()		IR((*RP->rk_gotch)())*/
+#define ONEWromkan_clear()		IR((*RP->rk_clear)())
 #define ONEWromkan_getc()		IR((*RP->rk_getc)())
 #define ONEWromkan_next()		IR((*RP->rk_next)())
 #define ONEWromkan_dispmode()		IR((*RP->rk_dispmode)())
