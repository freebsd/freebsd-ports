--- vb2c.c.orig	Mon Feb 12 07:33:50 2001
+++ vb2c.c	Wed Oct 15 18:40:32 2003
@@ -472,7 +472,7 @@
       if (strcmp(token,"=")!=0)
       { printf("Damnit.. I expected an '=' and got %s\n",token); }
       tokentype=gettoken(token);
-      fprintf(tmp,"  gtk_text_insert(GTK_TEXT(%s),NULL,
+      fprintf(tmp,"  gtk_text_insert(GTK_TEXT(%s),NULL,\n\
                      &%s->style->black,NULL,%s,-1);\n",name,name,token);
     }
       else
@@ -538,7 +538,7 @@
       if (strcmp(token,"=")!=0)
       { printf("Damnit.. I expected an '=' and got %s\n",token); }
       tokentype=gettoken(token);
-      fprintf(tmp,"  gtk_text_insert(GTK_TEXT(%s),NULL,
+      fprintf(tmp,"  gtk_text_insert(GTK_TEXT(%s),NULL,\n\
                      &%s->style->black,NULL,%s,-1);\n",name,name,token);
     }
       else
@@ -604,7 +604,7 @@
       if (strcmp(token,"=")!=0)
       { printf("Damnit.. I expected an '=' and got %s\n",token); }
       tokentype=gettoken(token);
-      fprintf(tmp,"  gtk_text_insert(GTK_TEXT(%s),NULL,
+      fprintf(tmp,"  gtk_text_insert(GTK_TEXT(%s),NULL,\n\
                      &%s->style->black,NULL,%s,-1);\n",name,name,token);
     }
       else
