--- src/retr.c.orig	Wed Feb  9 00:18:45 2000
+++ src/retr.c	Wed Feb  9 00:18:51 2000
@@ -445,7 +445,7 @@
   recursive_reset ();
   for (cur_url = url_list; cur_url; cur_url = cur_url->next, ++*count)
     {
-      char *filename, *new_file;
+      char *filename, *new_file, *referer;
       int dt;
 
       if (opt.quota && opt.downloaded > opt.quota)
@@ -453,7 +453,8 @@
 	  status = QUOTEXC;
 	  break;
 	}
-      status = retrieve_url (cur_url->url, &filename, &new_file, NULL, &dt);
+      referer = getenv("referer");
+      status = retrieve_url (cur_url->url, &filename, &new_file, referer, &dt);
       if (opt.recursive && status == RETROK && (dt & TEXTHTML))
 	status = recursive_retrieve (filename, new_file ? new_file : cur_url->url);
 
