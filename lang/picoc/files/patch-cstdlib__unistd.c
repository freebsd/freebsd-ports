--- ./cstdlib/unistd.c.orig	2011-02-21 06:22:13.000000000 +0100
+++ ./cstdlib/unistd.c	2011-03-11 08:09:48.884688383 +0100
@@ -80,10 +80,10 @@
     ReturnValue->Val->Integer = fchdir(Param[0]->Val->Integer);
 }
 
-void UnistdFdatasync(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
+/*void UnistdFdatasync(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
 {
     ReturnValue->Val->Integer = fdatasync(Param[0]->Val->Integer);
-}
+}*/
 
 void UnistdFork(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
 {
@@ -278,7 +278,7 @@
 
 void UnistdSetpgrp(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
 {
-    ReturnValue->Val->Integer = setpgrp();
+    ReturnValue->Val->Integer = setpgrp(Param[0]->Val->Integer, Param[1]->Val->Integer);
 }
 
 void UnistdSetregid(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
@@ -416,7 +416,7 @@
     { Unistd_Exit,         "void _exit(int);" },
     { UnistdFchown,        "int fchown(int, uid_t, gid_t);" },
     { UnistdFchdir,        "int fchdir(int);" },
-    { UnistdFdatasync,     "int fdatasync(int);" },
+/*    { UnistdFdatasync,     "int fdatasync(int);" },*/
     { UnistdFork,          "pid_t fork(void);" },
     { UnistdFpathconf,     "long fpathconf(int, int);" },
     { UnistdFsync,         "int fsync(int);" },
@@ -458,7 +458,7 @@
     { UnistdSbrk,          "void *sbrk(intptr_t);" },
     { UnistdSetgid,        "int setgid(gid_t);" },
     { UnistdSetpgid,       "int setpgid(pid_t, pid_t);" },
-    { UnistdSetpgrp,       "pid_t setpgrp(void);" },
+    { UnistdSetpgrp,       "pid_t setpgrp(pid_t, pid_t);" },
     { UnistdSetregid,      "int setregid(gid_t, gid_t);" },
     { UnistdSetreuid,      "int setreuid(uid_t, uid_t);" },
     { UnistdSetsid,        "pid_t setsid(void);" },
