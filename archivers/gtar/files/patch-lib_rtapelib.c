
$FreeBSD$

--- lib/rtapelib.c.orig
+++ lib/rtapelib.c
@@ -570,7 +570,8 @@
 
   sprintf (command_buffer, "R%lu\n", (unsigned long) length);
   if (do_command (handle, command_buffer) == -1
-      || (status = get_status (handle)) == SAFE_READ_ERROR)
+      || (status = get_status (handle)) == SAFE_READ_ERROR
+      || status > length)
     return SAFE_READ_ERROR;
 
   for (counter = 0; counter < status; counter += rlen, buffer += rlen)
@@ -706,6 +707,12 @@
 	    || (status = get_status (handle), status == -1))
 	  return -1;
 
+	if (status > sizeof (struct mtop))
+	  {
+	    errno = EOVERFLOW;
+	    return -1;
+	  }
+	
 	for (; status > 0; status -= counter, argument += counter)
 	  {
 	    counter = safe_read (READ_SIDE (handle), argument, status);
