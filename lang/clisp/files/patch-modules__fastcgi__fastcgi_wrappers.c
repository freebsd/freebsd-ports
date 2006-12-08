--- ./modules/fastcgi/fastcgi_wrappers.c.orig	Fri Dec  8 09:28:45 2006
+++ ./modules/fastcgi/fastcgi_wrappers.c	Fri Dec  8 09:35:23 2006
@@ -41,6 +41,25 @@
 /* Crank this up as needed */
 #define TEMPBUFSIZE 65536
 
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
+
+	return copy_string;
+}
+#endif
+
 /* Local functions */
 static char * read_stdio(FILE *);
 static int    write_stdio(FILE *, char *, int);
@@ -91,7 +110,11 @@
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
