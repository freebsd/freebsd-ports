--- src/tm.c~	Fri Apr  5 19:59:45 2002
+++ src/tm.c	Wed Jun 26 13:35:52 2002
@@ -19,6 +19,9 @@
 extern char latd;
 extern char lond;
 
+void do_eminit ();
+
+
 void process_message(char *sentence)
 {
     if (checksum(sentence)) {
