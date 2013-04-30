--- src/lib/fte/dotcards.c.orig	1993-07-30 13:44:28.000000000 +0900
+++ src/lib/fte/dotcards.c	2013-05-01 05:07:55.000000000 +0900
@@ -405,11 +405,17 @@
     char *string;
 {
     char buf[BSIZE_SP], *s, *t, *ss = string;
+    char *e;
 
+    e = string + strlen(string);
     if (ciprefix("v(", string) && index(string, ',')) {
         for (s = string; *s && (*s != ','); s++)
             ;
         *s++ = '\0';
+	while (s + 1 < e && isspace(*(s + 1))) {
+		*(s + 1) = '\0';
+		s++;
+	}
         for (t = s; *t && (*t != ')'); t++)
             ;
         *t = '\0';
@@ -589,6 +595,10 @@
 
 	if (c)
 	    *c = 0;
+	while (c + 1 < r && isspace(*(c + 1))) {
+		c++;
+		*c = '\0';
+	}
 
 	wl = alloc(struct wordlist);
 
