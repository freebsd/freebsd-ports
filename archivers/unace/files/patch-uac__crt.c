
$FreeBSD$

--- uac_crt.c.orig
+++ uac_crt.c
@@ -33,12 +33,15 @@
 
 /* gets file name from header
  */
-CHAR *ace_fname(CHAR * s, thead * head, INT nopath)
+CHAR *ace_fname(CHAR * s, thead * head, INT nopath, unsigned int size)
 {
-   INT  i;
+   unsigned int i;
    char *cp;
 
-   strncpy(s, (*(tfhead *) head).FNAME, i = (*(tfhead *) head).FNAME_SIZE);
+   i = (*(tfhead *) head).FNAME_SIZE;
+   if (i > (size - 1))
+     i = size - 1;
+   strncpy(s, (*(tfhead *) head).FNAME, i);
    s[i] = 0;
 
    if (nopath)
@@ -56,22 +59,72 @@
    }
 #endif
 
+   cp = s;
+   while (*cp == '/') cp++;
+   if (cp != s)
+     memmove(s, cp, strlen(cp) + 1);
+
    return s;
 }
 
+int is_directory_traversal(char *str)
+{
+  unsigned int mode, countdots;
+  /* mode 0 = fresh, 1 = just dots, 2 = not just dots */
+  char ch;
+
+  mode = countdots = 0;
+
+  while (ch = *str++)
+  {
+    if ((ch == '/') && (mode == 1) && (countdots > 1))
+      return 1;
+
+    if (ch == '/')
+    {
+       mode = countdots = 0;
+       continue;
+    }
+
+    if (ch == '.')
+    {
+      if (mode == 0)
+        mode = 1;
+
+      countdots++;
+    }
+    else
+      mode = 2;
+  }
+
+  if ((mode == 1) && (countdots > 1))
+    return 1;
+
+  return 0;
+}
+
 void check_ext_dir(CHAR * f)        // checks/creates path of file
 {
    CHAR *cp,
         d[PATH_MAX];
-   INT  i;
+   unsigned int i;
 
    d[0] = 0;
 
+   if (is_directory_traversal(f))
+   {
+      f_err = ERR_WRITE;
+      printf("\n    Directory traversal attempt:  %s\n", f);
+      return;
+   }
+
    for (;;)
    {
       if ((cp = (CHAR *) strchr(&f[strlen(d) + 1], DIRSEP))!=NULL)
       {
          i = cp - f;
+         if (i > (PATH_MAX - 1))
+           i = PATH_MAX - 1;
          strncpy(d, f, i);
          d[i] = 0;
       }
