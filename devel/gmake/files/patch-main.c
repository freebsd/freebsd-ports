When gmake automatically restart itself because one of its includes is updated,
the "MAKEFLAGS" environment variable is no more honoured.

http://savannah.gnu.org/bugs/?30723

diff -rU3 -N make-3.82.orig/main.c make-3.82/main.c
--- main.c.orig	2010-07-19 07:10:53.000000000 +0000
+++ main.c	2014-01-10 10:55:32.000000000 +0000
@@ -2093,7 +2093,7 @@
             const char *pv = define_makeflags (1, 1);
             char *p = alloca (sizeof ("MAKEFLAGS=") + strlen (pv) + 1);
             sprintf (p, "MAKEFLAGS=%s", pv);
-            putenv (p);
+            putenv (allocated_variable_expand (p));
           }
 
 	  if (ISDB (DB_BASIC))
