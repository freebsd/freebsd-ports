--- src/lib/Epsilon.c.orig	2007-11-30 06:33:18.000000000 +0100
+++ src/lib/Epsilon.c	2010-03-29 08:52:04.000000000 +0200
@@ -773,7 +773,7 @@
 	}
       else
 	{
-	  if ((ret = png_check_sig ((png_bytep)buf, bytes)))
+	  if ((ret = !png_sig_cmp ((png_bytep)buf, 0, bytes)))
 	    rewind (fp);
 	  else
 	    {
