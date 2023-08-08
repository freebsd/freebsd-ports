--- src/io.c.orig	2023-05-07 20:50:29 UTC
+++ src/io.c
@@ -1157,7 +1157,7 @@ void Get_Nexus_Data(FILE *fp, option *io)
 
 int Get_Token(FILE *fp, char *token)
 {
-  char c;
+  int c;
 
   c = ' ';
 
@@ -1518,7 +1518,8 @@ align **Read_Seq_Interleaved(option *io)
 
 int Read_One_Line_Seq(align ***data, int num_otu, FILE *in)
 {
-  char c = ' ';
+  char c_;
+  int c = ' ';
   int nchar = 0;
 
   while(1)
@@ -1552,7 +1553,9 @@ int Read_One_Line_Seq(align ***data, int num_otu, FILE
         }
       
       nchar++;
-      Uppercase(&c);
+      c_ = c;
+      Uppercase(&c_);
+      c = c_;
 
       if(c == '.')
         {
@@ -1617,7 +1620,7 @@ char *Return_Tree_String_Phylip(FILE *fp_input_tree)
 {
   char *line;
   int i;
-  char c;
+  int c;
   int open,maxopen;
 
   if(fp_input_tree == NULL)
