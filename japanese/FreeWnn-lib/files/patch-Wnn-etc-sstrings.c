Index: Wnn/etc/sstrings.c
===================================================================
RCS file: /home/cvs/private/hrs/freewnn/Wnn/etc/sstrings.c,v
retrieving revision 1.1.1.1
retrieving revision 1.2
diff -u -p -r1.1.1.1 -r1.2
--- Wnn/etc/sstrings.c	20 Dec 2008 07:13:30 -0000	1.1.1.1
+++ Wnn/etc/sstrings.c	20 Dec 2008 15:22:40 -0000	1.2
@@ -5,7 +5,7 @@
 /*
  * FreeWnn is a network-extensible Kana-to-Kanji conversion system.
  * This file is part of FreeWnn.
- * 
+ *
  * Copyright Kyoto University Research Institute for Mathematical Sciences
  *                 1987, 1988, 1989, 1990, 1991, 1992
  * Copyright OMRON Corporation. 1987, 1988, 1989, 1990, 1991, 1992, 1999
@@ -49,77 +49,75 @@ extern int eeuc_to_ieuc ();
 extern int ieuc_to_eeuc ();
 
 int
-wnn_sStrcpy (c, w)
-     register char *c;
-     register w_char *w;
+wnn_sStrcpy(register char *c,
+	    register w_char *w)
 {
-  register int ret;
+	register int ret;
 
-  ret = ieuc_to_eeuc (c, w, -1);
-  c[ret] = '\0';
-  return (ret);
-}
+	ret = ieuc_to_eeuc(c, w, -1);
+	c[ret] = '\0';
 
+	return (ret);
+}
 
 int
-wnn_Sstrcpy (w, c)
-     w_char *w;
-     unsigned char *c;
+wnn_Sstrcpy(w_char *w,
+	    unsigned char *c)
 {
-  register int ret;
+	register int ret;
 
-  ret = eeuc_to_ieuc (w, c, -1) / sizeof (w_char);
-  w[ret] = (w_char) 0;
-  return (ret);
+	ret = eeuc_to_ieuc(w, c, -1) / sizeof(w_char);
+	w[ret] = (w_char)0;
+
+	return (ret);
 }
 
 #ifdef nodef
 char *
-wnn_Stos (c)
-     w_char *c;
+wnn_Stos(cw_char *c)
 {
-  char *c1 = (char *) c;
-  for (; *c; c++)
-    {
-      if (ASCIIP (*c))
-        {
-          *c1++ = *c;
-        }
-      else
-        {
-          *c1++ = (*c << 8);
-          *c1++ = *c;
-        }
-    }
-  return ((char *) c);
+	char *c1 = (char *)c;
+
+	for (; *c; c++) {
+		if (ASCIIP(*c))
+			*c1++ = *c;
+		else {
+			*c1++ = (*c << 8);
+			*c1++ = *c;
+		}
+	}
+
+	return ((char *) c);
 }
 #endif
 
 char *
-wnn_sStrncpy (s1, s2, n)
-     register char *s1;
-     register w_char *s2;
-     register int n;
+wnn_sStrncpy(register char *s1,
+	     register char *s2,
+	     register int n)
 {
-  eeuc_to_ieuc (s1, s2, n / sizeof (w_char));
-  return s1;
+	eeuc_to_ieuc(s1, s2, n / sizeof(w_char));
+
+	return s1;
 }
 
 #ifdef CHINESE
 int
-wnn_Sstrcat (w, c)
-     w_char *w;
-     unsigned char *c;
+wnn_Sstrcat(w_char *w,
+	    unsigned char *c)
 {
-  w_char *w0 = w;
-  register int ret;
+	w_char *w0 = w;
+	register int ret;
+
+	if (!c || !*c)
+		return (0);
+
+	for (; *w; w++);
+
+	ret = eeuc_to_ieuc(w, c, strlen (c)) / sizeof(w_char);
+	w[ret] = (w_char)0;
+	ret += (w - w0);
 
-  if (!c || !*c)
-    return (0);
-  for (; *w; w++);
-  ret = eeuc_to_ieuc (w, c, strlen (c)) / sizeof (w_char);
-  w[ret] = (w_char) 0;
-  ret += (w - w0);
-  return (ret);
+	return (ret);
 }
 #endif
