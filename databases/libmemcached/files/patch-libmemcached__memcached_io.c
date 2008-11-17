--- libmemcached/memcached_io.c.orig	2008-11-17 01:19:40.000000000 -0800
+++ libmemcached/memcached_io.c	2008-11-17 01:20:19.000000000 -0800
@@ -135,6 +135,9 @@
 
       difference= (length > ptr->read_buffer_length) ? ptr->read_buffer_length : length;
 
+      if (strlen (ptr->read_ptr) == 0)
+	break;
+
       memcpy(buffer_ptr, ptr->read_ptr, difference);
       length -= difference;
       ptr->read_ptr+= difference;
