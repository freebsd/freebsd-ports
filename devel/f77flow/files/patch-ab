--- flow.c.orig	Wed Feb 19 08:45:20 1997
+++ flow.c	Sun May 11 22:14:03 2003
@@ -20,6 +20,7 @@
 /*  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.            */
 /*************************************************************************/
 
+#include <stdlib.h>
 #include <stdio.h>
 #include <ctype.h>
 #include <string.h>
@@ -66,7 +67,7 @@
 
 FILE *CallFile=NULL;
 FILE *SubFile=NULL;
-FILE *OUTFILE=stdout;
+FILE *OUTFILE=NULL;
 
 char S_OUT[]="FLOW.SUBS"; /* file name where to print subroutines */
 char C_OUT[]="FLOW.CALL"; /* file name where to print call's */
@@ -89,7 +90,7 @@
 
 /* begin of main */
 
-void main(int argc, char *argv[]) 
+int main(int argc, char *argv[]) 
 
 {
 int k,d,i;
@@ -100,6 +101,8 @@
 long int Count_Lines=0;
 char PRG_Name[60];
 
+OUTFILE=stdout;
+
 for (k=0; k<NO_SUB+1; k++) Subroutine[k].Call=0;
 for (k=0; k<NO_CALL; k++) Call[k].Call=0;
    Program.Call=0;
@@ -181,7 +184,7 @@
                       /* An Error occured */
                       printf("\nError with option -r");
                       printf("\nMissing Name for starting SUBROUTINE");
-                      exit;
+                      exit(2);
                         }
 
                      O_NEWSTART=1;
@@ -303,6 +306,8 @@
    if (No_Main==0) Output_Result();
 
    if (O_OutFile) fclose(OUTFILE);
+
+   exit(0);
  
 }
 
@@ -584,7 +589,7 @@
       printf("  -W: A warning is given if a code line exceeds the\n");
       printf("      length of 72 characters\n");
       printf("\nFor further information see manual page flow(1).\n\n");
-      exit();
+      exit(2);
      }
 
 
