--- main.cxx.orig	Thu Sep 23 23:35:38 1999
+++ main.cxx	Sat Oct 21 04:11:00 2000
@@ -326,8 +326,8 @@
     compile_system_library = TRUE;
 #ifdef PREFIX
     token::input(turbo_pascal 
-		 ? PREFIX "/share/ptoc/tptoc.pas" 
-		 : PREFIX "/share/ptoc/ptoc.pas")); 
+		 ? (char *) PREFIX "/share/ptoc/tptoc.pas" 
+		 : (char *) PREFIX "/share/ptoc/ptoc.pas"); 
 #else
     token::input(dprintf("%s%s", prog_path, 
  			 turbo_pascal ? "tptoc.pas" : "ptoc.pas")); 
