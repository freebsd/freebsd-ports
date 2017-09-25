Remove unreliable and non-portable way to demonstrate memory utilization
with sbrk(2).

https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=221751

--- examples/mountlist.c.orig
+++ examples/mountlist.c
@@ -71,16 +71,12 @@
 
 	printf ("Host = '%s' - %u\n\n", buffer, port);
 
-	printf ("sbrk (0) = %p\n\n", sbrk (0));
-
 	for (c = 0; c < PROFILE_COUNT; c++) {
 		mount_entries = glibtop_get_mountlist (&mount_list, 1);
 
 		g_free (mount_entries);
 	}
 
-	printf ("sbrk (0) = %p\n\n", sbrk (0));
-
 	mount_entries = glibtop_get_mountlist (&mount_list, 1);
 
 	if (mount_entries == NULL)
@@ -108,8 +104,6 @@
 
 	g_free (mount_entries);
 
-	printf ("\nsbrk (0) = %p\n\n", sbrk (0));
-
 	glibtop_close ();
 
 	exit (0);
