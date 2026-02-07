--- biniax.c.orig	2009-05-05 16:49:06.000000000 +0200
+++ biniax.c	2010-01-27 23:57:35.000000000 +0100
@@ -47,6 +47,7 @@
 INCLUDES
 ******************************************************************************/
 
+#include <errno.h>
 #include "game.h"
 #include "lev.h"
 #include "inc.h"
@@ -89,6 +90,15 @@
 
 int main( int argc, char *argv[] )
 {
+	if (chdir(getenv("HOME")) != 0)
+		err(1, "cannot chdir to $HOME");
+
+	if (mkdir(".biniax2", 0755) != 0 && errno != EEXIST)
+		err(1, "cannot mkdir $HOME/.biniax2");
+
+	if (chdir(".biniax2") != 0)
+		err(1, "cannot chdir to $HOME/.biniax2");
+
 	BNX_BOOL		bquit		= BNX_FALSE;
 	BNX_INT16		enterState	= cStateMainMenu;
 	BNX_INT16		nmenu		= 0;
