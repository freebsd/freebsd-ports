--- mono/io-layer/handles.c.orig	2015-02-19 17:31:13.622684000 -0500
+++ mono/io-layer/handles.c	2015-02-19 17:33:50.793866000 -0500
@@ -226,9 +226,16 @@
 
 	res = getrlimit (RLIMIT_NOFILE, &limit);
 	g_assert (res == 0);
-	return limit.rlim_cur;
+	/* Fixes a weird bug on systems with large mem - 196GB on my server*/
+	if ( limit.rlim_cur > 1000000 )
+		return 1000000;
+        else
+		return limit.rlim_cur;
 #else
-	return getdtablesize ();
+	if ( getdtablesize() > 1000000 )
+		return 1000000;
+        else
+		return getdtablesize ();
 #endif
 }
 
