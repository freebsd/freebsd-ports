--- src/conf.c.orig	Tue Mar 15 02:40:04 2004
+++ src/conf.c	Tue Mar 15 02:40:07 2004
@@ -183,6 +183,7 @@
   t_conf	conf;
   gint		ret_val;
 
+  bzero( &conf, sizeof(conf) );
   if (get_conf(key, &conf))
     {
       free_conf(&conf);
@@ -198,6 +199,7 @@
   t_conf	conf;
   gint		ret_val;
 
+  bzero( &conf, sizeof(conf) );
   if (get_conf(key, &conf))
     {
       free_conf(&conf);
@@ -213,6 +215,7 @@
   t_conf	conf;
   gboolean	ret_val;
 
+  bzero( &conf, sizeof(conf) );
   if (get_conf(key, &conf))
     {
       free_conf(&conf);
@@ -231,6 +234,7 @@
   t_conf	conf;
   gboolean	ret_val;
 
+  bzero( &conf, sizeof(conf) );
   if (get_conf(key, &conf))
     {
       free_conf(&conf);
@@ -249,6 +253,7 @@
   t_conf	conf;
   gchar		*ret_val;
 
+  bzero( &conf, sizeof(conf) );
   if (get_conf(key, &conf))
     {
       free_conf(&conf);
@@ -266,6 +271,7 @@
   t_conf	conf;
   gchar		*ret_val;
 
+  bzero( &conf, sizeof(conf) );
   if (get_conf(key, &conf))
     {
       free_conf(&conf);
@@ -386,6 +392,7 @@
 {
   t_conf	conf;
 
+  bzero( &conf, sizeof(conf) );
   conf.line = g_strdup_printf("%d", value);
   if (set_conf(key, &conf))
     {
@@ -400,6 +407,7 @@
 {
   t_conf	conf;
 
+  bzero( &conf, sizeof(conf) );
   if (value)
     conf.line = g_strdup("TRUE");
   else
@@ -417,6 +425,7 @@
 {
   t_conf	conf;
 
+  bzero( &conf, sizeof(conf) );
   conf.line = g_strdup(value);
   if (set_conf(key, &conf))
     {
