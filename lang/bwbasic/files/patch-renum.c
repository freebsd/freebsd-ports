Fix various warnings. 

--- renum.c.orig	2018-01-01 11:17:37 UTC
+++ renum.c
@@ -20,7 +20,7 @@ int f2, l2, n, x;
 int sidx[MAX_LINE_COUNT][2];
 char rstr[MAX_LINE_LENGTH];
 
-main(argc, argv)
+int main(argc, argv)
    int argc;
    char *argv[];
 {
@@ -28,7 +28,6 @@ main(argc, argv)
    int c, f1, c1, i, f8, r, l1, l3;
    int v1, f6, l6, b, f9, x9, b1, p8, p9, a, d9;
    char pstr[MAX_LINE_LENGTH];
-   char sstr[MAX_LINE_LENGTH];
    char f9str[MAX_LINE_LENGTH];
    char s9str[MAX_LINE_LENGTH];
    char tempstr[MAX_LINE_LENGTH];
@@ -490,7 +489,7 @@ main(argc, argv)
    fclose(fdin);
    fclose(fdout);
 #if !defined(__MVS__) && !defined(__CMS__)
-   sprintf(tempstr, "mv editfl %s\0", f9str);
+   sprintf(tempstr, "mv editfl %s", f9str);
    system(tempstr);
 #endif
    return (0);
@@ -561,7 +560,7 @@ void binary_search(void)
 
       if (sidx[m][0] == n)
       {
-         sprintf(rstr, "%d\0", sidx[m][1]);
+         sprintf(rstr, "%d", sidx[m][1]);
          x = 0;
          return;
       }
