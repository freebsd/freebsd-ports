--- readline.c.orig	2006-11-24 17:52:04.000000000 +0100
+++ readline.c	2007-09-25 17:59:54.000000000 +0200
@@ -61,7 +61,7 @@
 #include "el.h"
 #include "fcns.h"		/* for EL_NUM_FCNS */
 #include "histedit.h"
-#include "readline/readline.h"
+#include "editline/readline.h"
 #include "filecomplete.h"
 
 void rl_prep_terminal(int);
