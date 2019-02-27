--- imake.c.orig	2013-08-17 10:11:50 UTC
+++ imake.c
@@ -531,6 +531,14 @@ init(void)
 				AddCppArg(p);
 			}
 	}
+	if ((p = getenv("IMAKECPPFLAGS"))) {
+		AddCppArg(p);
+		for (; *p; p++)
+			if (*p == ' ') {
+				*p++ = '\0';
+				AddCppArg(p);
+			}
+	}
 	if ((p = getenv("IMAKECPP")))
 		cpp = p;
 	if ((p = getenv("IMAKEMAKE")))
@@ -1142,29 +1150,17 @@ get_binary_format(FILE *inFile)
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
