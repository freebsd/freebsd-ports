--- source/ctcp.c.orig  Tue Dec  5 01:11:56 2000
+++ source/ctcp.c       Tue May 27 16:55:04 2003
@@ -897,7 +897,8 @@
	int	len;

 	/* Make sure that the final \001 doesnt get truncated */
-	len = IRCD_BUFFER_SIZE - (12 + strlen(to));
+	if ((len = IRCD_BUFFER_SIZE - (12 + strlen(to))) < 0)
+		return;
 	putbuf2 = alloca(len);
 
 	if (format)
