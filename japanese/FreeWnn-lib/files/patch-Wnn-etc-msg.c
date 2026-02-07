Index: Wnn/etc/msg.c
===================================================================
RCS file: /home/cvs/private/hrs/freewnn/Wnn/etc/msg.c,v
retrieving revision 1.1.1.1
retrieving revision 1.2
diff -u -p -r1.1.1.1 -r1.2
--- Wnn/etc/msg.c	20 Dec 2008 07:13:30 -0000	1.1.1.1
+++ Wnn/etc/msg.c	20 Dec 2008 15:22:40 -0000	1.2
@@ -5,7 +5,7 @@
 /*
  * FreeWnn is a network-extensible Kana-to-Kanji conversion system.
  * This file is part of FreeWnn.
- * 
+ *
  * Copyright Kyoto University Research Institute for Mathematical Sciences
  *                 1987, 1988, 1989, 1990, 1991, 1992
  * Copyright OMRON Corporation. 1987, 1988, 1989, 1990, 1991, 1992, 1999
@@ -69,124 +69,116 @@
 #include "msg.h"
 
 static char *
-getlang (lang)
-     char *lang;
+getlang(char *lang)
 {
-  static char tmp[32];
-  char *p;
-  int i;
+	static char tmp[32];
+	char *p;
+	int i;
 
-  if (lang == NULL || *lang == '\0')
-    {
+	if (lang == NULL || *lang == '\0') {
 #ifdef  HAS_SETLOCALE
-      lang = setlocale (LC_ALL, NULL);
-      if (lang == NULL || *lang == '\0')
+		lang = setlocale(LC_ALL, NULL);
+		if (lang == NULL || *lang == '\0')
 #endif
-        {
-          lang = getenv ("LC_MESSAGES");
-          if (lang == NULL || *lang == '\0')
-            {
-              lang = getenv ("LANG");
-              if (lang == NULL || *lang == '\0')
-                {
-                  lang = DEF_LANG;
-                }
-            }
-        }
-    }
-  for (i = 0, p = lang; *p && *p != '.'; i++, p++)
-    {
-      tmp[i] = *p;
-    }
-  tmp[i] = '\0';
-  return (tmp);
-  /*
-     return(lang);
-   */
+		{
+			lang = getenv("LC_MESSAGES");
+			if (lang == NULL || *lang == '\0') {
+				lang = getenv("LANG");
+
+				if (lang == NULL || *lang == '\0') {
+					lang = DEF_LANG;
+				}
+			}
+		}
+	}
+	for (i = 0, p = lang; *p && *p != '.'; i++, p++)
+		tmp[i] = *p;
+
+	tmp[i] = '\0';
+
+	return (tmp);
+	/*
+	  return(lang);
+	*/
 }
 
 static int
-_search (id, bd)
-    int *id;
-    struct msg_bd *bd;
+_search(int *id,
+	struct msg_bd *bd)
 {
-  return (*id - bd->msg_id);
+	return (*id - bd->msg_id);
 }
 
 static void
-_escape (op, ip)
-     register char *op, *ip;
+_escape(register char *op,
+	register char *ip)
 {
-  for (; *ip != 0; ip++, op++)
-    {
-      if (*ip == '\\')
-        {
-          switch (*++ip)
-            {
-            case 'n':
-              *op = '\n';
-              break;
-            case 't':
-              *op = '\t';
-              break;
-            case 'b':
-              *op = '\b';
-              break;
-            case 'r':
-              *op = '\r';
-              break;
-            case 'f':
-              *op = '\f';
-              break;
-            case 'v':
-              *op = '\v';
-              break;
-            case '0':
-              *op = 0;
-              break;
-              /*
-                 case 'a':
-                 *op = '\a';
-                 break;
-                 case 'e':
-                 case 'E':
-                 case 'o':
-                 case 'd':
-                 case 'x':
-                 break;
-               */
-            default:
-              *op = *ip;
-              break;
-            }
-        }
-      else
-        {
-          if (*ip == '\n')
-            {
-              *op = '\0';
-            }
-          else
-            {
-              *op = *ip;
-            }
-        }
-    }
-  *op = 0;
+	for (; *ip != 0; ip++, op++) {
+		if (*ip == '\\') {
+			switch (*++ip) {
+			case 'n':
+				*op = '\n';
+				break;
+			case 't':
+				*op = '\t';
+				break;
+			case 'b':
+				*op = '\b';
+				break;
+			case 'r':
+				*op = '\r';
+				break;
+			case 'f':
+				*op = '\f';
+				break;
+			case 'v':
+				*op = '\v';
+				break;
+			case '0':
+				*op = 0;
+				break;
+				/*
+				  case 'a':
+				  *op = '\a';
+				  break;
+				  case 'e':
+				  case 'E':
+				  case 'o':
+				  case 'd':
+				  case 'x':
+				  break;
+				*/
+			default:
+				*op = *ip;
+				break;
+			}
+		} else {
+			if (*ip == '\n')
+				*op = '\0';
+			else
+				*op = *ip;
+		}
+	}
+	*op = 0;
 }
 
 static char *
-get_msg_bd (cd, id)
-     struct msg_cat *cd;
-     int id;
+get_msg_bd(struct msg_cat *cd,
+	   int id)
 {
-  register struct msg_bd *bd;
-  if (cd->msg_bd == 0 || cd->msg_cnt == 0)
-    return (NULL);
-  bd = (struct msg_bd *) bsearch (&id, cd->msg_bd, cd->msg_cnt, sizeof (struct msg_bd), _search);
-  if (bd == NULL)
-    return (NULL);
-  return (bd->msg);
+	register struct msg_bd *bd;
+
+	if (cd->msg_bd == 0 || cd->msg_cnt == 0)
+		return (NULL);
+
+	bd = (struct msg_bd *)bsearch(&id,
+				      cd->msg_bd,
+				      cd->msg_cnt,
+				      sizeof (struct msg_bd),
+				      _search);
+	if (bd == NULL)
+		return (NULL);
+	return (bd->msg);
 }
 
 /* expand
@@ -195,229 +187,236 @@ get_msg_bd (cd, id)
         %l: the language element from LANG
         %t: the territory element from LANG
         %c: the codeset element from LANG
-        %%: a single % charctor 
+        %%: a single % charctor
 */
 static int
-expand (op, ip, name, lang)
-     register char *op, *ip, *name, *lang;
+expand (register char *op,
+	register char *ip,
+	register char *name,
+	register char *lang)
 {
-  if (!ip || !*ip)
-    return (-1);
-  for (; *ip != 0; ip++)
-    {
-      if (*ip == '%')
-        {
-          switch (*++ip)
-            {
-            case 'N':
-              if (!name || !*name)
-                return (-1);
-              strcpy (op, name);
-              op += strlen (name);
-              break;
-            case 'L':
-              if (!lang || !*lang)
-                return (-1);
-              strcpy (op, lang);
-              op += strlen (lang);
-              break;
-              /*
-                 case 'l':
-                 strcpy(op, language);
-                 op += strlen(language);
-                 break;
-                 case 't':
-                 strcpy(op, terr);
-                 op += strlen(terr);
-                 break;
-                 case 'c':
-                 strcpy(op, code);
-                 op += strlen(code);
-                 break;
-                 case '%':
-                 strcpy(op, "%");
-                 op += strlen("%");
-                 break;
-               */
-            default:
-              break;
-            }
-        }
-      else
-        {
-          *op = *ip;
-          op++;
-        }
-    }
-  *op = '\0';
-  return (0);
+	if (!ip || !*ip)
+		return (-1);
+
+	for (; *ip != 0; ip++) {
+		if (*ip == '%') {
+			switch (*++ip) {
+			case 'N':
+				if (!name || !*name)
+					return (-1);
+				strcpy(op, name);
+				op += strlen(name);
+				break;
+			case 'L':
+				if (!lang || !*lang)
+					return (-1);
+				strcpy(op, lang);
+				op += strlen(lang);
+				break;
+				/*
+				  case 'l':
+				  strcpy(op, language);
+				  op += strlen(language);
+				  break;
+				  case 't':
+				  strcpy(op, terr);
+				  op += strlen(terr);
+				  break;
+				  case 'c':
+				  strcpy(op, code);
+				  op += strlen(code);
+				  break;
+				  case '%':
+				  strcpy(op, "%");
+				  op += strlen("%");
+				  break;
+				*/
+			default:
+				break;
+			}
+		} else {
+			*op = *ip;
+			op++;
+		}
+	}
+	*op = '\0';
+
+	return (0);
 }
 
 
 struct msg_cat *
-msg_open (name, nlspath, lang)
-     char *name;
-     char *nlspath;
-     char *lang;
+msg_open (char *name,
+	  char *nlspath,
+	  char *lang)
 {
-  struct msg_cat *cd;
+	struct msg_cat *cd;
 
-  char fn[MAXPATHLEN];
-  FILE *fp;
-  char data[1024];
-  char save[1024];
-  int msg_cnt = 0;
-  int msg_byte = 0;
-  register char *dp;
-  register struct msg_bd *bd;
-  register char *msg, *l;
-
-  l = getlang (lang);
-  if (name && *name == '/')
-    {
-      strcpy (fn, name);
-    }
-  else
-    {
-      if (expand (fn, nlspath, name, l) == -1)
-        {
-          return (NULL);
+	char fn[MAXPATHLEN];
+	FILE *fp;
+	char data[1024];
+	char save[1024];
+	int msg_cnt = 0;
+	int msg_byte = 0;
+	register char *dp;
+	register struct msg_bd *bd;
+	register char *msg, *l;
+
+	l = getlang(lang);
+
+	if (name && *name == '/')
+		strcpy (fn, name);
+	else {
+		if (expand (fn, nlspath, name, l) == -1)
+			return (NULL);
         }
-    }
 
-  if (!(cd = (struct msg_cat *) malloc (sizeof (struct msg_cat))))
-    return (NULL);
+	if (!(cd = (struct msg_cat *) malloc (sizeof (struct msg_cat))))
+		return (NULL);
+
+	strcpy (cd->name, name);
+	strcpy (cd->lang, l);
+	strcpy (cd->nlspath, nlspath);
+	cd->nextp = NULL;
+	cd->msg_cnt = 0;
+
+	if ((fp = fopen (fn, "r")) == NULL) {
+		/* message file not found */
+		cd->msg_bd = 0;
+		return (cd);
+	}
+
+	for (;;) {
+		/* first: count bytes */
+		if (fgets (data, 1024, fp) == NULL)
+			break;
+
+		/* comment */
+		if (*data == '#')
+			continue;
+
+		for (dp = data; *dp && *dp != '\t'; dp++);
+		/* msg_id:message\n */
+
+		if (*dp == '\0')
+			continue;
+
+		dp++;
+		msg_byte += strlen (dp);
+		msg_cnt++;
+	}
+
+	rewind(fp);
+
+	cd->msg_cnt = msg_cnt;
+
+	if (!(bd = cd->msg_bd =
+	      (struct msg_bd *)malloc((sizeof (struct msg_bd)) * msg_cnt + msg_byte + 1))) {
+		fclose(fp);
+		free(cd);
+		return (NULL);
+	}
+
+	msg = (char *) bd + (sizeof (struct msg_bd)) * msg_cnt;
+
+	for (;;) {
+		/* second : get message */
+		if (fgets(data, 1024, fp) == NULL)
+			break;
+
+		if (*data == '#')
+			/* comment */
+			continue;
+
+		for (dp = data; *dp && *dp != '\t'; dp++);
+		/* msg_id:message\n */
+
+		if (*dp == '\0')
+			continue;
+
+		*dp = 0;
+		dp++;
+		bd->msg_id = atoi(data);
+		bd->msg = msg;
+		bd++;
+		_escape(save, dp);
+		strcpy(msg, save);
+		msg += strlen(save);
+		*msg = 0;
+		msg++;
+	}
 
-  strcpy (cd->name, name);
-  strcpy (cd->lang, l);
-  strcpy (cd->nlspath, nlspath);
-  cd->nextp = NULL;
-  cd->msg_cnt = 0;
-
-  if ((fp = fopen (fn, "r")) == NULL)
-    {
-      /* message file not found */
-      cd->msg_bd = 0;
-      return (cd);
-    }
-  for (;;)
-    {
-      /* first: count bytes */
-      if (fgets (data, 1024, fp) == NULL)
-        break;
-      if (*data == '#')
-        continue;               /* comment */
-      for (dp = data; *dp && *dp != '\t'; dp++);        /* msg_id:message\n */
-      if (*dp == '\0')
-        continue;
-      dp++;
-      msg_byte += strlen (dp);
-      msg_cnt++;
-    }
-  rewind (fp);
-
-  cd->msg_cnt = msg_cnt;
-  if (!(bd = cd->msg_bd = (struct msg_bd *) malloc ((sizeof (struct msg_bd)) * msg_cnt + msg_byte + 1)))
-    {
-      fclose (fp);
-      free (cd);
-      return (NULL);
-    }
-  msg = (char *) bd + (sizeof (struct msg_bd)) * msg_cnt;
-
-  for (;;)
-    {
-      /* second : get message */
-      if (fgets (data, 1024, fp) == NULL)
-        break;
-      if (*data == '#')
-        continue;               /* comment */
-      for (dp = data; *dp && *dp != '\t'; dp++);        /* msg_id:message\n */
-      if (*dp == '\0')
-        continue;
-      *dp = 0;
-      dp++;
-      bd->msg_id = atoi (data);
-      bd->msg = msg;
-      bd++;
-      _escape (save, dp);
-      strcpy (msg, save);
-      msg += strlen (save);
-      *msg = 0;
-      msg++;
-    }
-  fclose (fp);
-  return (cd);
+	fclose(fp);
+	return (cd);
 }
 
 char *
-msg_get (catd, id, msg, lang)
-     struct msg_cat *catd;
-     int id;
-     char *msg;
-     register char *lang;
+msg_get(struct msg_cat *catd,
+	int id,
+	char *msg,
+	register char *lang)
 {
-  register struct msg_cat *cd;
-  register char *msg_bd;
+	register struct msg_cat *cd;
+	register char *msg_bd;
 
-  if (catd == 0)
-    goto error;
-  cd = catd;
-  if (lang == 0 || *lang == '\0')
-    {
-      lang = cd->lang;
-    }
-  else
-    {
-      for (;; cd = cd->nextp)
-        {
-          if (strcmp (lang, cd->lang) == 0)
-            break;
-          if (cd->nextp == 0)
-            {
-              cd->nextp = msg_open (cd->name, cd->nlspath, lang);
-              cd = cd->nextp;
-              break;
-            }
-        }
-    }
+	if (catd == 0)
+		goto error;
+
+	cd = catd;
+
+	if (lang == 0 || *lang == '\0')
+		lang = cd->lang;
+	else {
+		for (;; cd = cd->nextp) {
+			if (strcmp(lang, cd->lang) == 0)
+				break;
+			if (cd->nextp == 0) {
+				cd->nextp = msg_open(cd->name, cd->nlspath, lang);
+				cd = cd->nextp;
+				break;
+			}
+		}
+	}
 
-  if (msg_bd = get_msg_bd (cd, id))
-    return (msg_bd);
+	if (msg_bd = get_msg_bd(cd, id))
+		return (msg_bd);
 error:
-  if (msg != 0 && *msg != '\0')
-    return (msg);
-  {
-    static char ret[128];
-    sprintf (ret, "mes_id = %d: %s", id, DEF_MSG);
-    return (ret);
-  }
+
+	if (msg != 0 && *msg != '\0')
+		return (msg);
+
+	{
+		static char ret[128];
+		sprintf(ret, "mes_id = %d: %s", id, DEF_MSG);
+		return (ret);
+	}
 }
 
 void
-msg_close (cd)
-     register struct msg_cat *cd;
+msg_close(register struct msg_cat *cd)
 {
-  if (cd->nextp)
-    msg_close (cd->nextp);
-  if (cd->msg_bd)
-    free (cd->msg_bd);
-  if (cd)
-    free (cd);
+	if (cd->nextp)
+		msg_close(cd->nextp);
+
+	if (cd->msg_bd)
+		free(cd->msg_bd);
+
+	if (cd)
+		free(cd);
 }
 
 #ifdef  not_use
 /* test */
-main ()
+main()
 {
-  struct msg_cat *cd;
+	struct msg_cat *cd;
 
-  cd = msg_open ("msg", "%L", "ja_JP");
+	cd = msg_open("msg", "%L", "ja_JP");
 
-  printf (msg_get (cd, 5, "message not found\n", "ja_JP"), 555);
-  printf (msg_get (cd, 6, "message not found\n", "zh_CN"));
-  printf (msg_get (cd, -1, "", "ja_JP"), 555);
-  printf (msg_get (cd, 2, "message not found\n", "ja_JP"), "abc");
-  printf (msg_get (cd, 100, "message not found\n", "zh_CN"), "abc");
+	printf (msg_get(cd, 5, "message not found\n", "ja_JP"), 555);
+	printf (msg_get(cd, 6, "message not found\n", "zh_CN"));
+	printf (msg_get(cd, -1, "", "ja_JP"), 555);
+	printf (msg_get(cd, 2, "message not found\n", "ja_JP"), "abc");
+	printf (msg_get(cd, 100, "message not found\n", "zh_CN"), "abc");
 }
 #endif /* not_use */
