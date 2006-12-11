diff -u mprof.c.orig mprof.c
--- mprof.c.orig	Fri Apr  7 13:39:45 2006
+++ mprof.c	Fri Apr  7 01:28:45 2006
@@ -186,7 +186,7 @@
 };
 
 
-#define STHASH_SIZE	2047
+#define STHASH_SIZE	(2<<20 -1)
 struct sthash *sthmem[STHASH_SIZE];
 
 #define	STNIL	NULL
@@ -491,7 +491,7 @@
 #define	stab_name(x)	(stab[(x)].name)
 #define	stab_addr(x)	(stab[(x)].addr)
   
-#define	ST_SIZE		5000
+#define	ST_SIZE		500000
 #define	ST_NOT_FOUND	-1
 typedef	int	stindex;
 
@@ -899,7 +899,8 @@
 	if (*(colp+2) == '(') {
 	    char *commap;
 	    commap = index(symp, ',');
-	    *commap = '0';
+	    if (commap)
+	    	*commap = '0';
 	    tnum = atoi((char *) index(symp, '(')+1);
 	} else {
 	    tnum = atoi((char *) (colp+2));
@@ -926,7 +927,8 @@
 	if (*(colp+2) == '(') {
 	    char *commap;
 	    commap = index(symp, ',');
-	    *commap = '0';
+	    if (commap)
+	    	*commap = '0';
 	    tnum = atoi((char *) index(symp, '(')+1);
 	} else {
 	    tnum = atoi((char *) colp+2);
@@ -1275,9 +1277,15 @@
 	    if (d5 != 0) {
 		fx = st_locate(d5);
 		fsym = pc_lookup(stab_addr(fx));
-		fn_name(fsym) = stab_name(fx);
-		lte->path[SHORT_CALLSTACK_SIZE - (i + 1)].func = fn_name(fsym);
-		lte->path[SHORT_CALLSTACK_SIZE - (i + 1)].offset = d5 - stab_addr(fx);
+		if (stab_name(fx) == NULL) {
+			fn_name(fsym) = "";
+			lte->path[SHORT_CALLSTACK_SIZE - (i + 1)].func = "";
+			lte->path[SHORT_CALLSTACK_SIZE - (i + 1)].offset = 0;
+		} else {
+			fn_name(fsym) = stab_name(fx);
+			lte->path[SHORT_CALLSTACK_SIZE - (i + 1)].func = fn_name(fsym);
+			lte->path[SHORT_CALLSTACK_SIZE - (i + 1)].offset = d5 - stab_addr(fx);
+		}
 	    } else {
 		lte->path[SHORT_CALLSTACK_SIZE - (i + 1)].func = "";
 		lte->path[SHORT_CALLSTACK_SIZE - (i + 1)].offset = 0;
@@ -1403,6 +1411,8 @@
 	    fprintf(outfile, "...");
 	}
 	for (j = 0; j < SHORT_CALLSTACK_SIZE; j++) {
+	    if (lte.path[j].func == NULL)
+		lte.path[j].func = "";
 	    if (strcmp(lte.path[j].func, "") != 0) {
 		if (leak_level == LEAK_SHOW) {
 		    fprintf(outfile, "> %s ", lte.path[j].func);
