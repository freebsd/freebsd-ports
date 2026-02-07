--- main.cxx.orig	2002-10-24 15:38:50 UTC
+++ main.cxx
@@ -345,8 +345,8 @@ int main(int argc, char* argv[]) 
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
