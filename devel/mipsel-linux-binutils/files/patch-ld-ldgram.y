--- ld/ldgram.y.orig	Tue Jul 11 05:42:41 2000
+++ ld/ldgram.y	Sun Feb  2 10:49:25 2003
@@ -168,6 +168,7 @@
 		  ldlex_popstate();
 		  lang_add_assignment(exp_assop($3,$2,$4));
 		}
+	;
 
 /* SYNTAX WITHIN AN MRI SCRIPT FILE */  
 mri_script_file:
