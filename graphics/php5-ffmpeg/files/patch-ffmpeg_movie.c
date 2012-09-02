--- ffmpeg_movie.c.orig	2012-09-01 22:21:08.000000000 -0500
+++ ffmpeg_movie.c	2012-09-01 22:25:06.000000000 -0500
@@ -308,7 +308,7 @@
     } 
 
     if (persistent) {
-        list_entry *le;
+	zend_rsrc_list_entry *le;
         /* resolve the fully-qualified path name to use as the hash key */
         fullpath = expand_filepath(filename, NULL TSRMLS_CC);
 
@@ -343,7 +343,7 @@
             }
             
         } else { /* no existing persistant movie, create one */
-            list_entry new_le;
+	    zend_rsrc_list_entry new_le;
             ffmovie_ctx = _php_alloc_ffmovie_ctx(1);
 
             if (_php_open_movie_file(ffmovie_ctx, filename)) {
@@ -357,7 +357,7 @@
             new_le.ptr = ffmovie_ctx;
 
             if (FAILURE == zend_hash_update(&EG(persistent_list), hashkey, 
-                        hashkey_length+1, (void *)&new_le, sizeof(list_entry),
+                        hashkey_length+1, (void *)&new_le, sizeof(zend_rsrc_list_entry),
                         NULL)) {
                 php_error_docref(NULL TSRMLS_CC, E_WARNING, 
                         "Failed to register persistent resource");
@@ -501,7 +501,7 @@
                     codec_id));
 
         if (!decoder) {
-            zend_error(E_ERROR, "Could not find decoder for %s", 
+            zend_error(E_WARNING, "Could not find decoder for %s", 
                     _php_get_filename(ffmovie_ctx));
             return NULL;
         }
