--- festival.c.orig	Thu Aug 18 20:02:32 2005
+++ festival.c	Thu Aug 18 20:11:48 2005
@@ -435,10 +435,11 @@
 {
   char *stripped;
   const char *alias = get_best_name(account, who);
-  silent_joins = NULL;
 
   GString *buffer= g_string_new("");
   GString *ascii;
+
+  silent_joins = NULL;
   ascii = g_string_new(g_convert (what, strlen (what),
 				  "ISO-8859-1", "UTF-8",
 				  NULL, NULL, NULL));
@@ -613,7 +614,12 @@
 plugin_load(GaimPlugin *plugin) {
 
   FILE *which_pf;
-  char line[1024];
+  char line[1024], proc[1024];
+  int errno=0;
+  void *conv_handle;
+  void *blist_handle;
+  void *accounts_handle;
+
   which_pf= popen("which festival 2>/dev/null","r");
   fscanf(which_pf,"%1023s",line);
   pclose(which_pf);
@@ -621,10 +627,8 @@
   if( *line != '/')
     return FALSE;
 
-  char proc[1024];
   sprintf(proc, "%s %s", snd((char *)gaim_prefs_get_string("/gaim/gtk/sound/method")), line);
 
-  int errno=0;
   festival_pf= popen(proc,"w");
 
   if(errno) {
@@ -634,9 +638,9 @@
 
   load_conf();
 
-  void *conv_handle = gaim_conversations_get_handle();
-  void *blist_handle = gaim_blist_get_handle();
-  void *accounts_handle = gaim_accounts_get_handle();
+  conv_handle = gaim_conversations_get_handle();
+  blist_handle = gaim_blist_get_handle();
+  accounts_handle = gaim_accounts_get_handle();
 
   gaim_signal_connect(conv_handle, "received-im-msg",
 		      plugin, GAIM_CALLBACK(im_recv_im), NULL);
