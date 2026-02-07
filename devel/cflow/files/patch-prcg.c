--- prcg.c.orig	1995-02-16 13:36:48.000000000 +0800
+++ prcg.c	2011-09-16 09:28:07.000000000 +0800
@@ -14,6 +14,7 @@
 #include <stdlib.h>
 #include <ctype.h>
 #include <string.h>
+#include <unistd.h>
 
 #include "prcg.prototypes.h"
 #ifndef PATH_MAX
@@ -100,6 +101,7 @@ static void usage(void)
 	exit(1);
 }
 
+int
 main(int argc, char **argv)
 {
 
@@ -198,6 +200,7 @@ char tail_name[NAME_MAX] = "";	/* previo
  * `name1<tab>name2<tab>reference<newline>.' Return 1 if the tail of arc
  * name1 --> name2 (i.e., name1) is the tail the previous arc,
  * otherwise 0. */
+int
 get_arc(char *buf, char **ip, char **rp)
 {
 
@@ -244,7 +247,7 @@ struct imm_node *
 	struct imm_node *ip;
 
 	/* name already on name list */
-	if (np = nlist_contains(s)) {
+	if ((np = nlist_contains(s))) {
 		/* arc tail node installed && arc reference realloc'd */
 		if ((ip = node_to_arc(np, (struct imm_node *) 0)) != 0
 		    && (np->imm_ref = realloc(np->imm_ref, strlen(t) + 1)) != NULL) {
@@ -352,6 +355,7 @@ static struct imm_node *
 
 /* Preorder traverse the DCG, printing the names of nodes as they
  * are visited. */
+void
 print_dcg(int argc, char **argv)
 {
 	register int c;
@@ -362,7 +366,7 @@ print_dcg(int argc, char **argv)
 		/* restart argument list; print only specified names */
 		for (optind = 1; (c = getopt(argc, argv, arglist)) != EOF;) {
 			if (c == 'r')
-				if (root_p = nlist_contains(optarg))
+				if ((root_p = nlist_contains(optarg)))
 					print_name(root_p, 1);
 				else
 					(void) fprintf(stderr, "%s: not found: %s\n", progname, optarg);
@@ -383,6 +387,7 @@ print_dcg(int argc, char **argv)
  * While travering the DCG, maintain an active list of nodes in the current
  * path.  If an active node is revisited, terminate the path and print a
  * `cycle' mark. */
+void
 print_name(struct name_node *node, int tabc)
 {
 	static long line = 0;	/* line number */
@@ -457,6 +462,7 @@ int active_p = 0;		/* current path size 
 /* makeactive simply puts a pointer to the nameblock into a stack with
  * maximum depth DEPTH_MAX. the error return only happens for stack
  * overflow. */
+int
 makeactive(struct name_node *node)
 {
 	if (active_p < DEPTH_MAX) {
@@ -468,6 +474,7 @@ makeactive(struct name_node *node)
 }
 
 /* backup removes an item from the active stack */
+void
 backup(void)
 {
 	if (active_p)
@@ -476,6 +483,7 @@ backup(void)
 
 /* active checks whether the pointer which is its argument has already
  * occurred on the active list, and returns 1 if so.  */
+int
 active(struct name_node *node)
 {
 	register int i;
