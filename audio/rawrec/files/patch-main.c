--- main.c.orig	2006-01-22 02:40:17 UTC
+++ main.c
@@ -119,6 +119,8 @@ int main(int argc, char *argv[])
 
   /* at the moment, this application goes with the default for most signals */
   ignorer_act.sa_handler = SIG_IGN;
+  ignorer_act.sa_flags = 0;
+  sigemptyset(&ignorer_act.sa_mask);
   /* because I'm unclear on how SIGIO is supposed to work, it's not 
      applicable here, and I'm paranoid */
   if ( sigaction(SIGIO, &ignorer_act, NULL) == -1 )
