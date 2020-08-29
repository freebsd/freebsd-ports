--- src/io.c.orig	2020-07-09 11:49:16 UTC
+++ src/io.c
@@ -39,8 +39,6 @@ t_tree *Read_Tree(char **s_tree)
       if((*s_tree)[i] == ',') n_otu++;
     }
   n_otu+=1;
-
-
   
   tree = Make_Tree_From_Scratch(n_otu,NULL);
   subs = Sub_Trees((*s_tree),&degree);
@@ -2312,7 +2310,7 @@ void Print_Fp_Out(FILE *fp_out, time_t t_beg, time_t t
   div_t hour,min;
   int i, j;
   
-  if (precision > 0) snprintf (format, 8, "%%.%df", precision);
+  if (precision > 0) snprintf(format,8,"%%.%huf",(unsigned short)precision);
   
   if(n_data_set == 1)
     {
