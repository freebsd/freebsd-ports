# Patch from https://issues.apache.org/jira/browse/YARN-1327
--- hadoop-yarn-project/hadoop-yarn/hadoop-yarn-server/hadoop-yarn-server-nodemanager/src/main/native/container-executor/impl/container-executor.c
+++ hadoop-yarn-project/hadoop-yarn/hadoop-yarn-server/hadoop-yarn-server-nodemanager/src/main/native/container-executor/impl/container-executor.c
@@ -19,6 +19,7 @@
 #include "configuration.h"
 #include "container-executor.h"
 
+#include <libgen.h>
 #include <dirent.h>
 #include <fcntl.h>
 #include <fts.h>
@@ -496,9 +497,10 @@ static struct passwd* get_user_info(const char* user) {
 int is_whitelisted(const char *user) {
   char **whitelist = get_values(ALLOWED_SYSTEM_USERS_KEY);
   char **users = whitelist;
+  int logname_size = sysconf(_SC_LOGIN_NAME_MAX);
   if (whitelist != NULL) {
     for(; *users; ++users) {
-      if (strncmp(*users, user, LOGIN_NAME_MAX) == 0) {
+      if (strncmp(*users, user, logname_size) == 0) {
         free_values(whitelist);
         return 1;
       }
@@ -1236,6 +1238,10 @@ void chown_dir_contents(const char *dir_path, uid_t uid, gid_t gid) {
  * hierarchy: the top directory of the hierarchy for the NM
  */
 int mount_cgroup(const char *pair, const char *hierarchy) {
+#ifndef __linux
+  fprintf(LOGFILE, "cgroups are supported only on Linux OS\n");
+  return -1;
+#else
   char *controller = malloc(strlen(pair));
   char *mount_path = malloc(strlen(pair));
   char hier_path[PATH_MAX];
@@ -1270,7 +1276,7 @@ int mount_cgroup(const char *pair, const char *hierarchy) {
 
   free(controller);
   free(mount_path);
-
   return result;
+#endif
 }
 
