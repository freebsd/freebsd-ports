--- common/UCvsApp.cpp.orig	2007-11-22 20:23:41.000000000 +0100
+++ common/UCvsApp.cpp	2007-11-22 20:24:43.000000000 +0100
@@ -364,7 +364,7 @@
 	res = read (parent_comm_pipes[0], &child_pid, sizeof (child_pid));
 	if (res != sizeof (child_pid))
 	{
-		g_message ("res is %d instead of %d", res,
+		g_message ("res is %d instead of %ld", res,
 			   sizeof (child_pid));
 		child_pid = -1;	/* really weird things happened */
 	}
