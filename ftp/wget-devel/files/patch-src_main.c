Index: src/main.c
===================================================================
RCS file: /pack/anoncvs/wget/src/main.c,v
retrieving revision 1.66
retrieving revision 1.67
diff -u -r1.66 -r1.67
--- src/main.c	2001/12/06 07:14:35	1.66
+++ src/main.c	2001/12/09 19:44:20	1.67
@@ -738,10 +738,7 @@
     {
       char *rewritten = rewrite_shorthand_url (argv[optind]);
       if (rewritten)
-	{
-	  printf ("Converted %s to %s\n", argv[optind], rewritten);
-	  url[i] = rewritten;
-	}
+	url[i] = rewritten;
       else
 	url[i] = xstrdup (argv[optind]);
     }
