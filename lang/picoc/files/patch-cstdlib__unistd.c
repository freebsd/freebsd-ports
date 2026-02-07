--- cstdlib/unistd.c.orig	2017-03-22 14:01:43.750834000 -0700
+++ cstdlib/unistd.c	2017-03-22 14:08:17.778456000 -0700
@@ -81,16 +81,6 @@
     ReturnValue->Val->Integer = fchdir(Param[0]->Val->Integer);
 }
 
-void UnistdFdatasync(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
-{
-#ifndef F_FULLSYNC
-    ReturnValue->Val->Integer = fdatasync(Param[0]->Val->Integer);
-#else
-    /* Mac OS X equivalent */
-    ReturnValue->Val->Integer = fcntl(Param[0]->Val->Integer, F_FULLFSYNC);
-#endif
-}
-
 void UnistdFork(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
 {
     ReturnValue->Val->Integer = fork();
@@ -284,7 +274,7 @@
 
 void UnistdSetpgrp(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
 {
-    ReturnValue->Val->Integer = setpgrp();
+    ReturnValue->Val->Integer = setpgrp(Param[0]->Val->Integer, Param[1]->Val->Integer);
 }
 
 void UnistdSetregid(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
@@ -422,7 +412,6 @@
     { Unistd_Exit,         "void _exit(int);" },
     { UnistdFchown,        "int fchown(int, uid_t, gid_t);" },
     { UnistdFchdir,        "int fchdir(int);" },
-    { UnistdFdatasync,     "int fdatasync(int);" },
     { UnistdFork,          "pid_t fork(void);" },
     { UnistdFpathconf,     "long fpathconf(int, int);" },
     { UnistdFsync,         "int fsync(int);" },
