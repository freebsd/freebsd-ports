--- par-ch3.adb.orig	Fri Sep  1 10:13:57 2000
+++ par-ch3.adb	Fri Feb  8 21:14:11 2002
@@ -2587,7 +2587,7 @@
                P_Component_Items (Decls_List);
                P_Pragmas_Opt (Decls_List);
 
-               exit when Token = Tok_End
+               exit Component_Scan_Loop when Token = Tok_End
                  or else Token = Tok_Case
                  or else Token = Tok_When;
 
