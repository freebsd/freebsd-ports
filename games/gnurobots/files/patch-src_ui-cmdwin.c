--- src/ui-cmdwin.c.orig	2008-08-03 14:44:53 UTC
+++ src/ui-cmdwin.c
@@ -19,11 +19,10 @@
 #include "ui-cmdwin.h"
 
 #include <stdlib.h>
-#include <pty.h>
 
 #include <vte/vte.h>
-#include <readline.h>
-#include <history.h>
+#include <readline/readline.h>
+#include <readline/history.h>
 
 struct _UICmdWinPrivate
 {
