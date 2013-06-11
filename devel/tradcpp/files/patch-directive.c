--- ./directive.c.orig	2013-06-11 06:14:31.000000000 +0200
+++ ./directive.c	2013-06-11 14:19:53.281451337 +0200
@@ -238,7 +238,7 @@
 
 static
 void
-d_else(struct place *p, struct place *p2, char *line)
+d_else(struct place *p, struct place *p2 __unused, char *line __unused)
 {
 	if (ifstate->seenelse) {
 		complain(p, "Multiple #else directives in one conditional");
@@ -252,7 +252,7 @@
 
 static
 void
-d_endif(struct place *p, struct place *p2, char *line)
+d_endif(struct place *p, struct place *p2 __unused, char *line __unused)
 {
 	if (ifstate->prev == NULL) {
 		complain(p, "Unmatched #endif");
@@ -267,7 +267,7 @@
 
 static
 void
-d_define(struct place *p, struct place *p2, char *line)
+d_define(struct place *p __unused, struct place *p2, char *line)
 {
 	size_t pos, argpos;
 	struct place p3, p4;
@@ -330,7 +330,7 @@
 
 static
 void
-d_undef(struct place *p, struct place *p2, char *line)
+d_undef(struct place *p __unused, struct place *p2, char *line)
 {
 	uncomment(line);
 	oneword("#undef", p2, line);
@@ -393,7 +393,7 @@
 
 static
 void
-d_line(struct place *p, struct place *p2, char *line)
+d_line(struct place *p, struct place *p2 __unused, char *line __unused)
 {
 	/* XXX */
 	complain(p, "Sorry, no #line yet");
@@ -433,7 +433,7 @@
 
 static
 void
-d_pragma(struct place *p, struct place *p2, char *line)
+d_pragma(struct place *p, struct place *p2 __unused, char *line)
 {
 	complain(p, "#pragma %s", line);
 	complain_fail();
