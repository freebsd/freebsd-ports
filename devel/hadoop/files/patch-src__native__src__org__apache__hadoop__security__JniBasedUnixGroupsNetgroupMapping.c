--- src/native/src/org/apache/hadoop/security/JniBasedUnixGroupsNetgroupMapping.c.orig	2011-08-07 16:43:00.000000000 +0200
+++ src/native/src/org/apache/hadoop/security/JniBasedUnixGroupsNetgroupMapping.c	2011-08-07 16:43:30.000000000 +0200
@@ -73,7 +73,7 @@
   // was successfull or not (as long as it was called we need to call
   // endnetgrent)
   setnetgrentCalledFlag = 1;
-  if(setnetgrent(cgroup) == 1) {
+  if(setnetgrent(cgroup) >= 1) {
     UserList *current = NULL;
     // three pointers are for host, user, domain, we only care
     // about user now
