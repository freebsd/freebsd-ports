--- Src/main.c.orig	2019-10-04 20:09:58 UTC
+++ Src/main.c
@@ -103,7 +103,7 @@ void	explain(int);
 	   can later be truncated at that point
 	*/
  #if 1
-	#define CPP	"gcc -std=gnu99 -E -x c" /* 6.4.0 new default on all systems */
+	#define CPP	"cc -std=gnu99 -E -x c" /* 6.4.0 new default on all systems */
 	/* if gcc-4 is available, this setting is modified below */
  #else
 	#if defined(PC) || defined(MAC)
@@ -579,7 +579,7 @@ void
 preprocess(char *a, char *b, int a_tmp)
 {	char precmd[1024], cmd[2048];
 	int i;
-#ifdef PC
+#if 0
 	/* gcc is sometimes a symbolic link to gcc-4
 	   that does not work well in cygwin, so we try
 	   to use the actual executable that is used.
