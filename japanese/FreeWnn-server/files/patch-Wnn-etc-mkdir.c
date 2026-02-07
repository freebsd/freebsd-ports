Index: Wnn/etc/mkdir.c
===================================================================
RCS file: /home/cvs/private/hrs/freewnn/Wnn/etc/mkdir.c,v
retrieving revision 1.1.1.1
retrieving revision 1.2
diff -u -p -r1.1.1.1 -r1.2
--- Wnn/etc/mkdir.c	20 Dec 2008 07:13:30 -0000	1.1.1.1
+++ Wnn/etc/mkdir.c	20 Dec 2008 15:22:40 -0000	1.2
@@ -5,7 +5,7 @@
 /*
  * FreeWnn is a network-extensible Kana-to-Kanji conversion system.
  * This file is part of FreeWnn.
- * 
+ *
  * Copyright Kyoto University Research Institute for Mathematical Sciences
  *                 1987, 1988, 1989, 1990, 1991, 1992
  * Copyright OMRON Corporation. 1987, 1988, 1989, 1990, 1991, 1992, 1999
@@ -57,25 +57,24 @@
 #endif /* !WIFEXITED */
 
 int
-mkdir (path, mode)
-     const char *path;
-     mode_t mode;
+mkdir(const char *path,
+      mode_t mode)
 {
-  const char *args[3];
-  int status;
+	const char *args[3];
+	int status;
 
-  if (!path)
-    return -1;
+	if (!path)
+		return -1;
 
-  args[0] = "/bin/mkdir";
-  args[1] = path;
-  args[2] = NULL;
-
-  if (!fork ())
-    execv (args[0], args);
-  else
-    wait (&status);
+	args[0] = "/bin/mkdir";
+	args[1] = path;
+	args[2] = NULL;
+
+	if (!fork())
+		execv(args[0], args);
+	else
+		wait(&status);
 
-  return !(WIFEXITED (status));
+	return !(WIFEXITED(status));
 }
 #endif
