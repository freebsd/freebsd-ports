
$FreeBSD$

--- gadgets/designer/designer_script_utils.cc.orig
+++ gadgets/designer/designer_script_utils.cc
@@ -231,7 +231,7 @@
     if ((pid = fork()) == 0) {
       if (fork() != 0)
         _exit(0);
-      execlp(command, command, file, NULL);
+      execlp(command, command, file, (char*)0);
       DLOG("Failed to exec command: %s", command);
       _exit(-1);
     }
