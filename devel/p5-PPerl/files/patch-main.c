--- main.c.orig	Wed Mar  3 01:06:15 2004
+++ main.c	Mon Dec 13 18:22:53 2004
@@ -223,6 +223,8 @@
     /* strict C compilers can't/won't do char foo[variant]; */
     char *fullpath = my_malloc(path_max);
     int i = 0;
+    char euid[sizeof(uid_t)+2];
+    sprintf(euid, "_%d", geteuid());
 
     if (realpath(scriptname, fullpath) == NULL) {
         perror("pperl: resolving full pathname to script failed");
@@ -230,7 +232,7 @@
     }
     Dx(Debug("realpath returned: %s\n", fullpath));
     /* Ugh. I am a terrible C programmer! */
-    sockname = my_malloc(strlen(P_tmpdir) + strlen(fullpath) + 3);
+    sockname = my_malloc(strlen(P_tmpdir) + strlen(fullpath) + 3 + strlen(euid));
     save = sockname;
     sprintf(sockname, "%s/", P_tmpdir);
     sockname += strlen(P_tmpdir) + 1;
@@ -246,7 +248,7 @@
         }
         sockname++; i++;
     }
-    *sockname = '\0';
+    strcat(sockname, euid);
     free(fullpath);
     return save;
 }
