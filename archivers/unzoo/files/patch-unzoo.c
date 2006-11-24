--- unzoo.c.orig       Sat Nov 25 00:53:57 2006
+++ unzoo.c    Sat Nov 25 01:00:42 2006
@@ -2590,20 +2590,20 @@
             /* but only if the user did not request otherwise              */

             /* building the universal path of this member                  */
+            int found_trav = 0;
             char patu [sizeof(Entry.diru) + sizeof(Entry.namu) + 2];
             strcpy( patu, Entry.diru );
             if ( strlen(patu) && patu[strlen(patu)-1] != '/') strcat( patu, "/" );
             strcat( patu, (Entry.lnamu ? Entry.namu : Entry.nams) );

-            int found_trav = 0;

             if ( strstr( patu, "/../" )) {
-                found_trav = 1;

                 /* remove "/../" from the path                             */
                 char tmp [sizeof(patu)];
                 char *p;
                 char *q;
+                found_trav = 1;
                 memset(tmp, 0, sizeof(tmp));
                 q = patu;

@@ -2625,10 +2625,10 @@
                 printf("unzoo: skipped \"/../\" path component(s) in '%s'\n", Entry.patl);
             }
             if ( *patu == '/' && !strlen( pre ) ) {
-                found_trav = 1;

                 char *p = malloc(sizeof(patu));
                 char *q = p;
+                found_trav = 1;
                 memset(p, 0, sizeof(patu));
                 strcpy(p, patu);
                 while ( q[0] == '/' ) q++;
@@ -2638,9 +2638,9 @@
                 printf("unzoo: skipped root directory path component in '%s'\n", patl);
             }
             if ( !strncmp( patu, "../", 3 )) {
-                found_trav = 1;

                 char tmp [sizeof(patu)];
+                found_trav = 1;
                 memset(tmp, 0, sizeof(tmp));
                 strcpy(tmp, patu + 3);
                 strcpy(patu, tmp);
