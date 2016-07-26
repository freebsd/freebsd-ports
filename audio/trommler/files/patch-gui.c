--- gui.c.orig	2007-11-03 18:20:09 UTC
+++ gui.c
@@ -2425,7 +2425,6 @@ GLOBALFUN int main(int argc, char *argv[
     }
     else
     {
-        getcwd(Global.DrumDir,sizeof(Global.DrumDir));
         strncat(Global.DrumDir,"/Drums",sizeof(Global.DrumDir) );
     }
     
