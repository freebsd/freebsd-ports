--- src/http.c
+++ src/http.c
@@ -327,7 +327,60 @@
 }
 
 char * 
-url_encode (const char *str, char **result_p)
+html_escape (const char *str)
+{
+  const char *p;
+  char *q;
+  char *result;
+  int toescape= 0;
+
+  if (!str) {
+	  xa_debug (1, "WARNING: html_escape() called with NULL string");
+	  return NULL;
+  }
+
+  for (p = str; *p; p++) {
+    if ((unsigned char) (*p) == '&') toescape+=4;
+    if ((unsigned char) (*p) == '"') toescape+=5;
+    if ((unsigned char) (*p) == '<') toescape+=3;
+    if ((unsigned char) (*p) == '>') toescape+=3;
+  }
+  
+  result = (char  *) nmalloc (p - str + toescape + 1);
+
+  for (q = result, p = str; *p; p++) {
+      unsigned char a = *p;
+      if (a == '&') {
+      	  *q++ = '&';
+      	  *q++ = 'a';
+      	  *q++ = 'm';
+      	  *q++ = 'p';
+      	  *q++ = ';';
+      } else if (a == '"') {
+      	  *q++ = '&';
+      	  *q++ = 'q';
+      	  *q++ = 'u';
+      	  *q++ = 'o';
+      	  *q++ = 't';
+      	  *q++ = ';';
+      } else if (a == '<') {
+      	  *q++ = '&';
+      	  *q++ = 'l';
+      	  *q++ = 't';
+      	  *q++ = ';';
+      } else if (a == '>') {
+      	  *q++ = '&';
+      	  *q++ = 'g';
+      	  *q++ = 't';
+      	  *q++ = ';';
+      } else *q++ = *p;
+    }
+  *q++ = 0; 
+  return result;
+}
+
+char * 
+url_encode (const char *str, char** result_p)
 {
   const char *p;
   char *q;
@@ -345,7 +398,6 @@
       unacceptable++;
 
   result = (char  *) nmalloc (p - str + unacceptable + unacceptable + 1);
-
   *result_p = result;
 
   for (q = result, p = str; *p; p++) 
@@ -1336,7 +1388,7 @@
 	  add_varpair2 (variables, nstrdup (ident), ice_itoa (i));
 	  add_varpair2 (variables, ice_cat (ident, ".id"), ice_itoa (travclients->id));
 	  add_varpair2 (variables, ice_cat (ident, ".host"), nstrdup (con_host (travclients)));
-	  add_varpair2 (variables, ice_cat (ident, ".user_agent"), nstrdup (get_user_agent (travclients)));
+	  add_varpair2 (variables, ice_cat (ident, ".user_agent"), nstrdup (html_escape(get_user_agent (travclients))));
 	  add_varpair2 (variables, ice_cat (ident, ".writebytes"), ice_utoa (travclients->food.client->write_bytes));
 	  add_varpair2 (variables, ice_cat (ident, ".connecttime"), nstrdup (nice_time (get_time() - travclients->connect_time, buf)));
 	  endptr = parse_template_file (clicon, NULL, runptr, fd, variables);
