--- src/vim.h.orig	2024-07-10 18:45:46 UTC
+++ src/vim.h
@@ -322,8 +322,8 @@ typedef unsigned long	long_u;
 #define STRCHR(s, c)		(char_u *)strchr((char *)(s), c)
 #define STRRCHR(s, c)		(char_u *)strrchr((char *)(s), c)
 #define STRLEN(s)			strlen((char *)(s))
-#define STRCPY(d, s)		strcpy((char *)(d), (char *)(s))
-#define STRNCPY(d, s, n)	strncpy((char *)(d), (char *)(s), n)
+#define STRCPY(d, s)		(memmove((char *)(d), (char *)(s), strlen((char *)(s)) + 1))
+#define STRNCPY(d, s, n)	(memmove((char *)(d), (char *)(s), n))
 #define STRCMP(d, s)		strcmp((char *)(d), (char *)(s))
 #define STRNCMP(d, s, n)	strncmp((char *)(d), (char *)(s), n)
 #define STRCAT(d, s)		strcat((char *)(d), (char *)(s))
