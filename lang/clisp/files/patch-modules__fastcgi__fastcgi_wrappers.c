--- modules/fastcgi/fastcgi_wrappers.c.orig	2018-11-12 00:05:07 UTC
+++ modules/fastcgi/fastcgi_wrappers.c
@@ -41,7 +41,26 @@ extern char **environ;
 
 /* Crank this up as needed */
 #define TEMPBUFSIZE 65536
+ 
+#ifdef __FreeBSD__
+char* t_strndup(const char* string, size_t n)
+{
+	char* copy_string = 0;
+ 
+	if(0 == string || 0 == n)
+		return 0;
+	
+	copy_string = (char*) malloc(n + 1);	
+	if(0 == copy_string)
+		return 0;
+	
+	memcpy(copy_string, string, n);
+	*(copy_string + n) = '\0';		
 
+	return copy_string;
+}
+#endif
+
 /* Local functions */
 static char * read_stdio(FILE *);
 static int    write_stdio(FILE *, char *, int);
@@ -93,7 +112,11 @@ char ** fcgi_env() {
       result[i+1] = NULL;
     }
     else {
+#ifdef __FreeBSD__
+		result[i] = t_strndup(*envp, equ - *envp);
+#else
       result[i] = strndup(*envp, equ - *envp);
+#endif
       result[i+1] = strdup(equ + 1);
     }
   }
