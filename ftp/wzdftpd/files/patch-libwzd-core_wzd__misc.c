--- libwzd-core/wzd_misc.c.orig	2023-02-11 11:23:37 UTC
+++ libwzd-core/wzd_misc.c
@@ -990,7 +990,7 @@ void win_normalize(char * s, unsigned int length, unsi
 
 
 /* \return 0 if ok, -1 if error, 1 if trying to kill myself */
-int kill_child_signal(unsigned long pid, wzd_context_t * context)
+int kill_child_signal(pthread_t pid, wzd_context_t * context)
 {
   ListElmt * elmnt;
   wzd_context_t * loop_context;
@@ -1022,7 +1022,7 @@ int kill_child_signal(unsigned long pid, wzd_context_t
 }
 
 /* \return 0 if ok, -1 if error, 1 if trying to kill myself */
-int kill_child_new(unsigned long pid, wzd_context_t * context)
+int kill_child_new(pthread_t pid, wzd_context_t * context)
 {
   ListElmt * elmnt;
   int found=0;
