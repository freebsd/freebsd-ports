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
--- mpgraph.c.orig	Fri Apr  7 13:39:45 2006
+++ mpgraph.c	Fri Apr  7 01:45:35 2006
@@ -836,7 +836,15 @@
 	while (!mp_null(chain)) {
 	    vertex	v;
 	    s = (mpsym) mp_car(chain);
-	    v = make_vertex(fn_name(s), count, fn_lcount(s), fn_parents(s));
+	    if ( s == NULL) {
+	        chain = (mpcell) mp_cdr(chain);
+		continue;
+	    }
+	    if (fn_name(s)) 
+	    	v = make_vertex(fn_name(s), count, fn_lcount(s), fn_parents(s));
+	    else
+	    	v = make_vertex("unknown", count, fn_lcount(s), fn_parents(s));
+		
 	    vpush(v, vset);
 	    count += 1;
 	    chain = (mpcell) mp_cdr(chain);
@@ -864,7 +872,11 @@
 	    
 	    parent_name = fn_name((mpsym) mp_car(parent));
 	    parent_data = (mpdata) mp_cdr(parent);
-	    vfrom = hlookup(parent_name);
+	    if (parent_name == NULL) {
+	    	vfrom = hlookup("unknown");
+	    } else {
+	    	vfrom = hlookup(parent_name);
+	    }
 
 	    if (vfrom == vto) {
 		vto->srefs += 1;
