--- libwzd-core/wzd_site_user.c.orig	2023-02-11 11:29:18 UTC
+++ libwzd-core/wzd_site_user.c
@@ -1224,9 +1224,9 @@ int do_site_kill(UNUSED wzd_string_t *ignored, wzd_str
 {
   char *ptr;
   int ret;
-  unsigned long pid;
+  pthread_t pid;
 
-  pid = strtoul(str_tochar(param),&ptr,0);
+  pid = (pthread_t)strtoul(str_tochar(param),&ptr,0);
   if (*ptr!='\0') {
     ret = send_message_with_args(501,context,"Usage: site kill <pid>");
     return 0;
