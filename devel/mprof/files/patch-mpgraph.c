--- mpgraph.c.orig	Tue Apr 20 16:36:18 1993
+++ mpgraph.c	Mon Jun  3 18:26:17 2002
@@ -23,8 +23,8 @@
 #define	UNUSED		-1
 #define	USED		0
 
-FILE	*stout = stdout;
-FILE	*sterr = stderr;
+/* FILE	*stout = stdout; */
+/* FILE	*sterr = stderr; */
 
 extern	mpcell	hmem[];
 extern	char	*strdup();
@@ -114,7 +114,7 @@
     vertex	from, to;
     mpdata	data;
     int		mark;
-    struct edge_struct *save
+    struct edge_struct *save;
 } *edge, edge_item;
 
 edge
