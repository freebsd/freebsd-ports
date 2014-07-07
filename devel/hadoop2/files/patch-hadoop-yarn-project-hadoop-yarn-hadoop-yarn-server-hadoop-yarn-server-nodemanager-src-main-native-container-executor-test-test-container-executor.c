# Patch from https://issues.apache.org/jira/browse/YARN-1327
--- hadoop-yarn-project/hadoop-yarn/hadoop-yarn-server/hadoop-yarn-server-nodemanager/src/main/native/container-executor/test/test-container-executor.c
+++ hadoop-yarn-project/hadoop-yarn/hadoop-yarn-server/hadoop-yarn-server-nodemanager/src/main/native/container-executor/test/test-container-executor.c
@@ -476,7 +476,7 @@ void test_signal_container_group() {
     printf("FAIL: fork failed\n");
     exit(1);
   } else if (child == 0) {
-    setpgrp();
+    setpgid(0,0);
     if (change_user(user_detail->pw_uid, user_detail->pw_gid) != 0) {
       exit(1);
     }
