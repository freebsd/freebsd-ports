--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/c/ratc.h	Tue Feb 15 14:26:43 1994
+++ ./reuse/c/ratc.h	Fri Sep 10 13:35:03 2004
@@ -38,4 +38,12 @@
 
 typedef char * tString;
 
+# ifdef __STDC__
+# define ARGS(parameters)       parameters
+# define NOARGS                 void
+# else
+# define ARGS(parameters)       ()
+# define NOARGS
+# endif
+
 # endif
