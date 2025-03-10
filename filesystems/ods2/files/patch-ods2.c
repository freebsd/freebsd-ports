--- ods2.c.orig	2001-09-07 21:17:04 UTC
+++ ods2.c
@@ -1076,10 +1076,17 @@ char *getcmd(char *inp, char *prompt)
 int main(int argc,char *argv[])
 {
     char str[2048];
+    char *ptr;
+    int  iargc, i, ilen, len;
+    int cmdline = 0;
     FILE *atfile = NULL;
+
     printf(" ODS2 %s\n", MODULE_IDENT);
+    if (argc>1) {   /* if exist argument in the command line TRUE */
+        cmdline = 1;
+        iargc = argc - 1;
+    }
     while (1) {
-        char *ptr;
         if (atfile != NULL) {
             if (fgets(str,sizeof(str),atfile) == NULL) {
                 fclose(atfile);
@@ -1090,18 +1097,50 @@ int main(int argc,char *argv[])
                 if (ptr != NULL) *ptr = '\0';
                 printf("$> %s\n",str);
             }
+        }
+        else if (cmdline) {
+            ptr = str;
+            for ( len=0, ilen=0, i=argc-iargc; i<argc; i++ )
+                if ( *argv[i] == '$' ) {
+                    iargc--;
+                    break;
+                } else {
+                    ilen = strlen(argv[i]);
+                    len +=ilen;
+                    if (len < sizeof(str))  {
+                       strcpy(ptr, argv[i]);
+                       ptr += ilen;
+                       *ptr = ' ';
+                       ptr++; *ptr = '\0';
+                       iargc--;
+                    } else {
+                       printf("%%ODS2-CMD-LINE, len of arguments too long.\n");
+                       break;
+                    }
+                }
+            if (iargc == 0) cmdline = 0; /* if all arguments execute */
+            if (ptr != str) printf("$> %s\n",str);
         } else {
 #ifdef VMS
-	    if (getcmd (str, "$> ") == NULL) break;
+	  if (getcmd (str, "$> ") == NULL) break;
 #else
-            printf("$> ");
-            if (gets(str) == NULL) break;
+          printf("$> ");
+          if (fgets(str, sizeof(str), stdin) == NULL)
+              break;
+          str[strlen(str)-1] = '\0'; /* strip newline from str */
 #endif
-        }
+        }     /* if - else if - else  */
         ptr = str;
-        while (*ptr == ' ' || *ptr == '\t') ptr++;
-        if (strlen(ptr) && *ptr != '!') {
+        while (*ptr == ' ' || *ptr == '\t') ptr++; /*  space and tab */
+        len = strlen(ptr);
+        if (len && *ptr != '!') {
             if (*ptr == '@') {
+                len--;
+                /* remove trailing spaces and tabs */
+                while (*(ptr+len) == ' ' || *(ptr+len) == '\t') {
+                    *(ptr+len) = '\0';
+                    len--;
+                }
                 if (atfile != NULL) {
                     printf("%%ODS2-W-INDIRECT, indirect indirection not permitted\n");
                 } else {
@@ -1112,9 +1151,9 @@ int main(int argc,char *argv[])
                 }
             } else {
                 if ((cmdsplit(ptr) & 1) == 0) break;
-            }
-        }
-    }
+            }   /* else */
+        }       /* if   */
+    }   /* while (1) */
     if (atfile != NULL) fclose(atfile);
     return 1;
 }
