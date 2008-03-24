diff -Naur pkg-config-0.23-old/pkg.c pkg-config-0.23-new/pkg.c
--- pkg-config-0.23-old/pkg.c	2008-01-16 13:59:49.000000000 -0800
+++ pkg.c	2008-01-22 15:00:55.000000000 -0800
@@ -483,6 +483,10 @@
 	      g_string_append (str, pcsysrootdir);
 	      g_string_append (str, tmpstr+2);
 	    }
+          else 
+	    {
+	      g_string_append (str, tmpstr);
+	    }
 	}
       else 
 	{
