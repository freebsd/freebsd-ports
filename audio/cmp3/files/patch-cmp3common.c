--- cmp3common.c.orig	2001-06-13 20:13:13 UTC
+++ cmp3common.c
@@ -102,7 +102,7 @@ int Strncmp(const char *str1,    /* Firs
     return(i);
 }
 
-int getline(char *var,         /* Buffer to copy line into */
+int get_line(char *var,         /* Buffer to copy line into */
             int  maxbuf,       /* MAX to send to fgets */
             FILE *input        /* File descriptor to get line from */)
 {
@@ -142,4 +142,4 @@ void *Malloc(size_t size)
 }
 
 
-/* EOF */
\ No newline at end of file
+/* EOF */
