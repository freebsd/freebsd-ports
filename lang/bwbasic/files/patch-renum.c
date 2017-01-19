Fix various warnings. Don't use unsafe gets().

--- renum.c.orig	2017-01-19 00:10:01 UTC
+++ renum.c
@@ -7,6 +7,7 @@
 
 #include <stdio.h>
 #include <string.h>
+#include <stdlib.h>
 
 int instr();
 char *midstr1();
@@ -17,14 +18,14 @@ int f2, l2, n, x;
 int sidx[1500][2];
 char rstr[255];
 
-main(argc, argv)
+int main(argc, argv)
    int argc;
    char *argv[];
 {
    int f, d, s, p, s1, t, l, g;
    int c, f1, c1, i, f8, r, l1, l3;
    int v1, f6, l6, b, f9, x9, b1, p8, p9, a, d9;
-   char pstr[255], sstr[255], f9str[255], s9str[255], tempstr[255];
+   char pstr[255], f9str[255], s9str[255], tempstr[255];
    FILE *fdin, *fdout;
    int skip, bp, temp, getout, disp_msg;
 
@@ -34,7 +35,10 @@ main(argc, argv)
    else
    {
       printf("Program in file? ");
-      gets(pstr);
+      fgets(pstr, 255, stdin);
+      if (pstr[0] != '\n' || pstr[0] != '\0') {
+	pstr[strlen(pstr) - 1] = '\0';
+      }
    }
    if (strlen(pstr) == 0) strcpy(pstr, "0.doc");
 
@@ -124,7 +128,7 @@ main(argc, argv)
       skip = 0;
       bp = 0;
       printf("RENUMBER-");
-      gets(pstr);
+      fgets(pstr, 255, stdin);
       p = strlen(pstr);
 
       if (g == 0)
@@ -268,7 +272,7 @@ main(argc, argv)
       printf("%d -> %d\n", sidx[r][0], sidx[r][1]); */
 
    printf("VERIFY? ");
-   gets(pstr);
+   fgets(pstr, 255, stdin);
    v1 = 0;
    if (strcmp(midstr2(pstr, 1, 1), "N") == 0) v1 = 1;
 
@@ -473,7 +477,7 @@ main(argc, argv)
    fclose(fdin);
    fclose(fdout);
 #if !defined(__MVS__) && !defined(__CMS__)
-   sprintf(tempstr, "mv editfl %s\0", f9str);
+   sprintf(tempstr, "mv editfl %s", f9str);
    system(tempstr);
 #endif
    return (0);
@@ -542,7 +546,7 @@ void binary_search(void)
 
       if (sidx[m][0] == n)
       {
-         sprintf(rstr, "%d\0", sidx[m][1]);
+         sprintf(rstr, "%d", sidx[m][1]);
          x = 0;
          return;
       }
