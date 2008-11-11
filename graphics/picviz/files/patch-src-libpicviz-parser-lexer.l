--- src/libpicviz/parser/lexer.l.orig	2008-10-27 12:39:31.000000000 +0100
+++ src/libpicviz/parser/lexer.l	2008-11-08 17:11:55.000000000 +0100
@@ -19,7 +19,27 @@
 static char *realfile;
 
 void yyerror (char *s);
+
+#ifdef __FreeBSD__
+char* strndup(const char* string, size_t n)
+{
+        char* copy_string = 0;
+
+        if(0 == string || 0 == n)
+                return 0;
+
+        copy_string = (char*) malloc(n + 1);
+        if(0 == copy_string)
+                return 0;
+
+        memcpy(copy_string, string, n);
+        *(copy_string + n) = '\0';
+
+        return copy_string;
+}
+#else
 char * strndup (const char *s, size_t n);
+#endif
 
 #define MAX_INCLUDE_DEPTH 10
 YY_BUFFER_STATE includes[MAX_INCLUDE_DEPTH];
@@ -48,7 +68,20 @@
         return str;
 }
 
+void yyset_lineno(int line_number) {
+	yylineno = line_number;
+}
+
+int yyget_lineno() {
+	return yylineno;
+}
+
+char * yyget_text() {
+	return yytext;
+}
+
 %}
+%option yylineno
 %option noyywrap
 
 SECTION		(header|engine|axes|data)
