
$FreeBSD$

--- gettext.c.orig	Wed Feb  9 08:02:18 2000
+++ gettext.c	Sun Jul 28 04:22:31 2002
@@ -22,6 +22,10 @@
 # include <config.h>
 #endif
 
+#if defined HAVE_LOCALE_H || defined _LIBC
+# include <locale.h>
+#endif
+
 #ifdef __GNUC__
 # define alloca __builtin_alloca
 # define HAVE_ALLOCA 1
@@ -1294,6 +1298,15 @@
 		    {
 		      FREE_BLOCKS (block_list);
 		      return added;
+		    }
+		  if (string_space != new_pool)
+		    {
+		      size_t i;
+		      for (i = 0; i < nmap; i++)
+			{
+			  map[i].alias += new_pool - string_space;
+			  map[i].value += new_pool - string_space;
+			}
 		    }
 		  string_space = new_pool;
 		  string_space_max = new_size;
