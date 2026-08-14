From: Santiago Vila <sanvila@debian.org>
Subject: Use format specifier %s to print strings, not the string itself
Bug-Debian: https://bugs.debian.org/673476
X-Debian-version: 3.0-5

From: Florent 'Skia' Jacquet <florent.jacquet@canonical.com>
Subject: Fix buffer overflow when using '-T -TT'
Bug-Debian: https://bugs.debian.org/1093629
Bug-Ubuntu: https://launchpad.net/bugs/2093024
Forwarded: https://sourceforge.net/p/infozip/bugs/81/

strlen(unzip_path) + strlen(zipname) + " " + "'" + "'" + '\0'
The additional space required in the `cmd` buffer is 4, not 3.

From: Paul Marquess <pmqs@outlook.com>
Subject: Fix command injection issue
Bug-Debian: https://bugs.debian.org/1143866
X-Debian-version: 3.0-16

--- zip.c.orig	2008-07-05 16:34:06 UTC
+++ zip.c
@@ -122,6 +122,7 @@ local int  finish  OF((int));
 
 local void freeup  OF((void));
 local int  finish  OF((int));
+local char *quote_arg(char *instring);
 #if (!defined(MACOS) && !defined(WINDLL))
 local void handler OF((int));
 local void license OF((void));
@@ -1028,7 +1029,7 @@ local void help_extended()
 
   for (i = 0; i < sizeof(text)/sizeof(char *); i++)
   {
-    printf(text[i]);
+    printf("%s", text[i]);
     putchar('\n');
   }
 #ifdef DOS
@@ -1225,7 +1226,7 @@ local void version_info()
             CR_MAJORVER, CR_MINORVER, CR_BETA_VER, CR_VERSION_DATE);
   for (i = 0; i < sizeof(cryptnote)/sizeof(char *); i++)
   {
-    printf(cryptnote[i]);
+    printf("%s", cryptnote[i]);
     putchar('\n');
   }
   ++i;  /* crypt support means there IS at least one compilation option */
@@ -1323,6 +1324,134 @@ local int check_unzip_version(unzippath)
   return 1;
 }
 
+
+/* quote_arg()
+ *
+ * Add quotation and/or escapes to a shell (VMS: DCL) argument string
+ * appropriate to the local operating system or shell  (Unix, Windows,
+ * etc.).  This is mainly used to build the command line to pass to
+ * UnZip (or other application when -TT used) to test an archive.
+ * Return malloc()'d result.
+ *
+ *    All:     Add " at beginning and end.
+ *    MSDOS:   % -> "^%"
+ *             " -> \""
+ *    Unix:    ! -> "'!'"
+ *             $ -> \$
+ *             \ -> \\
+ *             ` -> \`
+ *    Non-VMS: " -> \"
+ *    VMS:     " -> """
+ *
+ * On VMS, quoted double apostrophes are also special.  Currently not
+ * handled.  (How?  Quotation marks are needed for (upper-)case
+ * preservation.  Double apostrophes in quotation marks are interpreted
+ * (symbol evaluation).  SMS sees no way to handle "fr''ed".  "fr'""'ed"
+ * becomes >fr'"'ed<, for example.)  Not a problem for file specs, but
+ * imposes a restriction on passwords.
+ */
+#ifndef NO_PROTO
+local char *quote_arg(char *instring)
+#else
+local char *quote_arg(instring)
+  char *instring;
+#endif
+{
+  int i;
+  int j;
+  char *tempstring;
+  char *outstring;
+  char c;
+
+  if (instring == NULL)
+    return NULL;
+
+# ifdef MSDOS
+#  define QA_FACTOR 4            /* Worst case (MSDOS): % -> "^%"  */
+
+# else /* not MSDOS */
+#  ifdef VMS
+#   define QA_FACTOR 3           /* Worst case (VMS): " -> """  */
+
+#  else /* not MSDOS or VMS */
+#   define QA_FACTOR 5           /* Worst case (Unix): ! -> "'!'"  */
+#  endif /* VMS [else] */
+# endif /* MSDOS [else] */
+
+# define QA_INCR 2               /* Surrounding quotation marks. */
+
+  i = QA_FACTOR * (int)strlen(instring) + QA_INCR + 1;
+  if ((tempstring = (char *)malloc(i)) == NULL) {
+    ZIPERR(ZE_MEM, "quote_arg");
+  }
+
+  j = 0;
+
+  tempstring[j++] = '\"';       /* Surrounding quotation mark (start). */
+
+  for (i = 0; instring[i]; i++) {
+    c = instring[i];
+
+# ifdef MSDOS /* or Windows */
+    if (c == '%')               /* Percent. */
+    {
+      tempstring[j++] = '"';    /* Add (closing) quotation mark. */
+      tempstring[j++] = '^';    /* Add caret escape. */
+      tempstring[j++] = '%';    /* Original character (%). */
+      c = '"';                  /* Prepare (re-opening) quotation mark. */
+    }
+    else if (c == '"')          /* Quotation mark. */
+    {
+      tempstring[j++] = '\\';   /* Add backslash (escape). */
+      tempstring[j++] = '"';    /* Add quote (acts as closing and literal). */
+    }
+# else /* not def MSDOS */
+
+#  ifdef VMS
+    if (c == '"')               /* Quotation mark. */
+    {
+      tempstring[j++] = '"';    /* Add two quotation marks. */
+      tempstring[j++] = '"';
+    }
+#  else /* not def VMS */
+
+    /* UNIX is default for others */
+
+    if (c == '"')               /* Quotation mark. */
+    {
+      tempstring[j++] = '\\';   /* Add backslash (escape). */
+    }
+    else if (c == '!')          /* Exclamation.  (Inefficient.) */
+    {
+      tempstring[j++] = '"';    /* Add (closing) quotation mark. */
+      tempstring[j++] = '\'';   /* Add (opening) apostrophe. */
+      tempstring[j++] = '!';    /* Original character (!). */
+      tempstring[j++] = '\'';   /* Add (closing) apostrophe. */
+      c = '"';                  /* Prepare (re-opening) quotation mark. */
+    }
+    else if ((c == '$') ||      /* Dollar sign. */
+             (c == '`') ||      /* Grave accent (backtick). */
+             (c == '\\'))       /* Backslash. */
+    {
+      tempstring[j++] = '\\';   /* Add backslash (escape). */
+    }
+
+#  endif /* def VMS [else] */
+# endif /* def MSDOS [else] */
+
+    tempstring[j++] = c;        /* Original (or other last) character. */
+  }
+
+  tempstring[j++] = '\"';       /* Surrounding quotation mark (end). */
+
+  tempstring[j] = '\0';
+  /* outstring = string_dup(tempstring, "quote_arg", NO_FLUFF); */
+  outstring = strdup(tempstring);
+  free(tempstring);
+
+  return outstring;
+}
+
 local void check_zipfile(zipname, zippath)
   char *zipname;
   char *zippath;
@@ -1424,11 +1553,15 @@ local void check_zipfile(zipname, zippath)
 
 #else /* (MSDOS && !__GO32__) || __human68k__ */
   char *cmd;
+  char *qzipname;
   int result;
 
   /* Tell picky compilers to shut up about unused variables */
   zippath = zippath;
 
+  /* Quote each arg (and add appropriate escapes). */
+  qzipname = quote_arg(zipname);
+
   if (unzip_path) {
     /* user gave us a path to some unzip (may not be UnZip) */
     char *here;
@@ -1437,7 +1570,7 @@ local void check_zipfile(zipname, zippath)
     /* Replace first {} with archive name.  If no {} append name to string. */
     here = strstr(unzip_path, "{}");
 
-    if ((cmd = malloc(strlen(unzip_path) + strlen(zipname) + 3)) == NULL) {
+    if ((cmd = malloc(strlen(unzip_path) + strlen(qzipname) + 4)) == NULL) {
       ziperr(ZE_MEM, "building command string for testing archive");
     }
 
@@ -1447,32 +1580,20 @@ local void check_zipfile(zipname, zippath)
       strcpy(cmd, unzip_path);
       cmd[len] = '\0';
       strcat(cmd, " ");
-# ifdef UNIX
-      strcat(cmd, "'");    /* accept space or $ in name */
-      strcat(cmd, zipname);
-      strcat(cmd, "'");
-# else
-      strcat(cmd, zipname);
-# endif
+      strcat(cmd, qzipname);
       strcat(cmd, " ");
       strcat(cmd, here + 2);
     } else {
       /* No {} so append temp name to end */
       strcpy(cmd, unzip_path);
       strcat(cmd, " ");
-# ifdef UNIX
-      strcat(cmd, "'");    /* accept space or $ in name */
-      strcat(cmd, zipname);
-      strcat(cmd, "'");
-# else
-      strcat(cmd, zipname);
-# endif
+      strcat(cmd, qzipname);
     }
     free(unzip_path);
     unzip_path = NULL;
 
   } else {
-    if ((cmd = malloc(20 + strlen(zipname))) == NULL) {
+    if ((cmd = malloc(20 + strlen(qzipname))) == NULL) {
       ziperr(ZE_MEM, "building command string for testing archive");
     }
 
@@ -1484,14 +1605,11 @@ local void check_zipfile(zipname, zippath)
     if (check_unzip_version("unzip") == 0)
       ZIPERR(ZE_TEST, zipfile);
 
-# ifdef UNIX
-    strcat(cmd, "'");    /* accept space or $ in name */
-    strcat(cmd, zipname);
-    strcat(cmd, "'");
-# else
-    strcat(cmd, zipname);
-# endif
+    strcat(cmd, qzipname);
   }
+
+  if (qzipname)
+    free(qzipname);
 
   result = system(cmd);
 # ifdef VMS
