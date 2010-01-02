Index: Wnn/etc/server_env.c
===================================================================
RCS file: /home/cvs/private/hrs/freewnn/Wnn/etc/server_env.c,v
retrieving revision 1.1.1.1
retrieving revision 1.2
diff -u -p -r1.1.1.1 -r1.2
--- Wnn/etc/server_env.c	20 Dec 2008 07:13:30 -0000	1.1.1.1
+++ Wnn/etc/server_env.c	20 Dec 2008 15:22:40 -0000	1.2
@@ -5,7 +5,7 @@
 /*
  * FreeWnn is a network-extensible Kana-to-Kanji conversion system.
  * This file is part of FreeWnn.
- * 
+ *
  * Copyright Kyoto University Research Institute for Mathematical Sciences
  *                 1987, 1988, 1989, 1990, 1991, 1992
  * Copyright OMRON Corporation. 1987, 1988, 1989, 1990, 1991, 1992, 1999
@@ -44,36 +44,31 @@
 #include "wnn_config.h"
 #include "wnn_os.h"
 
-typedef struct _server_env_struct
-{
-  char *lang;
-  char *env;
-}
-server_env_struct;
+typedef struct _server_env_struct {
+	char *lang;
+	char *env;
+} server_env_struct;
 
 static server_env_struct server_env[] = {
-  {WNN_J_LANG, WNN_JSERVER_ENV},
-  {WNN_C_LANG, WNN_CSERVER_ENV},
-  {WNN_K_LANG, WNN_KSERVER_ENV},
-  {WNN_T_LANG, WNN_TSERVER_ENV},
-  {NULL, NULL}
+	{WNN_J_LANG, WNN_JSERVER_ENV},
+	{WNN_C_LANG, WNN_CSERVER_ENV},
+	{WNN_K_LANG, WNN_KSERVER_ENV},
+	{WNN_T_LANG, WNN_TSERVER_ENV},
+	{NULL, NULL}
 };
 
 char *
-get_server_env (lang)
-     register char *lang;
+get_server_env(register char *lang)
 {
-  register server_env_struct *p;
+	register server_env_struct *p;
+
+	if (!lang || !*lang)
+		return (NULL);
 
-  if (!lang || !*lang)
-    return (NULL);
+	for (p = server_env; p->lang; p++) {
+		if (!strncmp(lang, p->lang, strlen(lang)))
+			return (p->env);
+	}
 
-  for (p = server_env; p->lang; p++)
-    {
-      if (!strncmp (lang, p->lang, strlen (lang)))
-        {
-          return (p->env);
-        }
-    }
-  return (NULL);
+	return (NULL);
 }
