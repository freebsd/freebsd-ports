Index: src/recur.c
===================================================================
RCS file: /pack/anoncvs/wget/src/recur.c,v
retrieving revision 1.37
retrieving revision 1.38
diff -u -r1.37 -r1.38
--- src/recur.c	2001/12/13 19:18:31	1.37
+++ src/recur.c	2001/12/18 15:22:03	1.38
@@ -237,7 +237,7 @@
 	  int oldrec = opt.recursive;
 
 	  opt.recursive = 0;
-	  status = retrieve_url (url, &file, &redirected, NULL, &dt);
+	  status = retrieve_url (url, &file, &redirected, referer, &dt);
 	  opt.recursive = oldrec;
 
 	  if (file && status == RETROK
