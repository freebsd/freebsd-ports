--- biniax.c.orig	2008-04-08 09:25:14.000000000 +0400
+++ biniax.c	2008-04-16 22:33:02.000000000 +0400
@@ -89,6 +89,15 @@
 
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
