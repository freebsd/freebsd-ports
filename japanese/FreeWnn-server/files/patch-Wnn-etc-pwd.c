Index: Wnn/etc/pwd.c
===================================================================
RCS file: /home/cvs/private/hrs/freewnn/Wnn/etc/pwd.c,v
retrieving revision 1.1.1.1
retrieving revision 1.2
diff -u -p -r1.1.1.1 -r1.2
--- Wnn/etc/pwd.c	20 Dec 2008 07:13:30 -0000	1.1.1.1
+++ Wnn/etc/pwd.c	20 Dec 2008 15:22:40 -0000	1.2
@@ -5,7 +5,7 @@
 /*
  * FreeWnn is a network-extensible Kana-to-Kanji conversion system.
  * This file is part of FreeWnn.
- * 
+ *
  * Copyright Kyoto University Research Institute for Mathematical Sciences
  *                 1987, 1988, 1989, 1990, 1991, 1992
  * Copyright OMRON Corporation. 1987, 1988, 1989, 1990, 1991, 1992, 1999
@@ -62,41 +62,47 @@ JS_STATIC void new_pwd (char* src, char*
 JS_STATIC int check_pwd (char* src, char* encd);
 
 JS_STATIC void
-new_pwd (char* src, char* encd)
+new_pwd(char *src, char *encd)
 {
-  int i, x, c;
-  char xx[3];
-  char *cr;
-
-  if (encd == NULL)
-    encd = src;
-  if (strcmp (src, "") == 0)
-    {
-      bzero (encd, WNN_PASSWD_LEN);
-      return;
-    }
-  x = time (NULL);
-  xx[0] = x & 0x3f;
-  xx[1] = (x & 0x3f00) >> 8;
-  xx[2] = '\0';                 /* for MD5 (that requires terminator) */
-  for (i = 0; i < 2; i++)
-    {
-      c = xx[i] + '.';
-      if (c > '9')
-        c += 7;
-      if (c > 'Z')
-        c += 6;
-      xx[i] = c;
-    }
-  cr = crypt (src, xx);
-  bzero (encd, WNN_PASSWD_LEN);
-  strncpy (encd, cr, WNN_PASSWD_LEN);
+	int i, x, c;
+	char xx[3];
+	char *cr;
+
+	if (encd == NULL)
+		encd = src;
+
+	if (strcmp (src, "") == 0) {
+		bzero (encd, WNN_PASSWD_LEN);
+		return;
+	}
+
+	x = time (NULL);
+	xx[0] = x & 0x3f;
+	xx[1] = (x & 0x3f00) >> 8;
+
+	/* for MD5 (that requires terminator) */
+	xx[2] = '\0';
+
+	for (i = 0; i < 2; i++) {
+		c = xx[i] + '.';
+		if (c > '9')
+			c += 7;
+		if (c > 'Z')
+			c += 6;
+		xx[i] = c;
+	}
+
+	cr = crypt(src, xx);
+	bzero(encd, WNN_PASSWD_LEN);
+	strncpy(encd, cr, WNN_PASSWD_LEN);
 }
 
 JS_STATIC int
-check_pwd (char* src, char* encd)
+check_pwd(char* src, char* encd)
 {
-  if (strcmp (encd, "") == 0)
-    return (1);                 /* No passwd */
-  return (!strncmp (encd, crypt (src, encd), WNN_PASSWD_LEN));
+	if (strcmp (encd, "") == 0)
+		/* No passwd */
+		return (1);
+
+	return (!strncmp(encd, crypt(src, encd), WNN_PASSWD_LEN));
 }
