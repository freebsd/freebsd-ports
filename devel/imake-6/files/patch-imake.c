--- imake/imake.c.orig	Tue Jan 30 14:57:37 2007
+++ imake/imake.c	Tue Jan 30 14:55:59 2007
@@ -1153,29 +1153,17 @@
   int mib[2];
   size_t len;
   int osrel = 0;
-  FILE *objprog = NULL;
   int iself = 0;
-  char buf[10];
-  char cmd[PATH_MAX];
 
   mib[0] = CTL_KERN;
   mib[1] = KERN_OSRELDATE;
   len = sizeof(osrel);
   sysctl(mib, 2, &osrel, &len, NULL, 0);
-  if (CrossCompiling) {
-      strcpy (cmd, CrossCompileDir);
-      strcat (cmd, "/");
-      strcat (cmd,"objformat");
-  } else
-      strcpy (cmd, "objformat");
 
-  if (osrel >= 300004 &&
-      (objprog = popen(cmd, "r")) != NULL &&
-      fgets(buf, sizeof(buf), objprog) != NULL &&
-      strncmp(buf, "elf", 3) == 0)
+  if (osrel < 300004)
+    iself = 0;
+  else
     iself = 1;
-  if (objprog)
-    pclose(objprog);
 
   fprintf(inFile, "#define DefaultToElfFormat %s\n", iself ? "YES" : "NO");
 }
