--- parse.y.orig	Tue Jan 22 22:35:17 2002
+++ parse.y	Sun Dec  1 23:59:12 2002
@@ -831,7 +831,7 @@
 		  tmp->set_file(@1.text);
 		  tmp->set_lineno(@1.first_line);
 		  $$ = tmp;
-		  delete $1
+		  delete $1;
 		}
 	| identifier '[' expression ']'
 		{ PEIdent*tmp = new PEIdent(*$1);
@@ -1046,6 +1046,7 @@
 		  delete $3;
 		  $$ = tmp;
 		}
+		;
 
 list_of_ports
 	: port_opt
