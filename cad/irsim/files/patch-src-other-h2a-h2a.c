--- src/other/h2a/h2a.c.orig	Sun Oct  8 13:26:06 2006
+++ src/other/h2a/h2a.c	Sun Oct  8 13:26:09 2006
@@ -32,6 +32,7 @@
 public	void	make_stacks( n ) nptr n;		{}
 public	void	pStackedTxtors()			{}
 
+private Usage();
 
 private	char   *sim_file = NULL;
 private	char   *hist_file = NULL;
