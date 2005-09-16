--- config.m4:1.1 Fri Apr 29 19:54:33 2005
+++ config.m4 Sat Jul 16 12:46:31 2005
@@ -1,4 +1,4 @@
-dnl $Id: config.m4,v 1.1 2005/04/29 23:54:33 pollita Exp $
+dnl $Id: config.m4,v 1.2 2005/07/16 16:46:31 pollita Exp $
 dnl config.m4 for extension runkit

 PHP_ARG_ENABLE(runkit, whether to enable runkit support,
@@ -8,8 +8,5 @@
   if test "$PHP_RUNKIT" = "classkit"; then
     AC_DEFINE(PHP_RUNKIT_CLASSKIT_COMPAT, 1, [Whether to export classkit compatable function aliases])
   fi
-  PHP_ADD_LIBRARY(dl,,RUNKIT_SHARED_LIBADD)
-  PHP_SUBST(RUNKIT_SHARED_LIBADD)
-
   PHP_NEW_EXTENSION(runkit, runkit.c runkit_functions.c runkit_methods.c runkit_constants.c runkit_import.c runkit_classes.c runkit_sandbox.c, $ext_shared)
 fi

