--- client/mysql.cc.orig	2007-11-13 13:29:42 +0000
+++ client/mysql.cc	2008-05-01 19:16:09 +0000
@@ -2636,9 +2636,12 @@
   {
     while((field = mysql_fetch_field(result)))
     {
-      tee_fprintf(PAGER, "<TH>%s</TH>", (field->name ? 
-					 (field->name[0] ? field->name : 
-					  " &nbsp; ") : "NULL"));
+      tee_fputs("<TH>", PAGER);
+      if (field->name && field->name[0])
+        xmlencode_print(field->name, field->name_length);
+      else
+        tee_fputs(field->name ? " &nbsp; " : "NULL", PAGER);
+      tee_fputs("</TH>", PAGER);
     }
     (void) tee_fputs("</TR>", PAGER);
   }
@@ -2651,7 +2654,7 @@
     for (uint i=0; i < mysql_num_fields(result); i++)
     {
       (void) tee_fputs("<TD>", PAGER);
-      safe_put_field(cur[i],lengths[i]);
+      xmlencode_print(cur[i], lengths[i]);
       (void) tee_fputs("</TD>", PAGER);
     }
     (void) tee_fputs("</TR>", PAGER);
