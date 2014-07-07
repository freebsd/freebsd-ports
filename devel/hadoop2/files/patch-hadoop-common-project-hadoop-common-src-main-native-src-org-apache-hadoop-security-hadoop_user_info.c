--- hadoop-common-project/hadoop-common/src/main/native/src/org/apache/hadoop/security/hadoop_user_info.c.bak	2014-06-21 09:40:12.000000000 +0400
+++ hadoop-common-project/hadoop-common/src/main/native/src/org/apache/hadoop/security/hadoop_user_info.c	2014-07-04 10:53:05.000000000 +0400
@@ -36,7 +36,7 @@
 struct hadoop_user_info *hadoop_user_info_alloc(void)
 {
   struct hadoop_user_info *uinfo;
-  size_t buf_sz;
+  long buf_sz;
   char *buf;
 
   uinfo = calloc(1, sizeof(struct hadoop_user_info));
@@ -193,7 +193,7 @@
   ngroups = uinfo->gids_size;
   ret = getgrouplist(uinfo->pwd.pw_name, uinfo->pwd.pw_gid, 
                          uinfo->gids, &ngroups);
-  if (ret > 0) {
+  if (ret > 0 /* Linux */ || ret == 0 /* FreeBSD */) {
     uinfo->num_gids = ngroups;
     ret = put_primary_gid_first(uinfo);
     if (ret) {
