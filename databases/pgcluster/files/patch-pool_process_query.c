--- src/pgcluster/pglb/pool_process_query.c.orig.orig	Wed Feb  4 23:35:56 2004
+++ src/pgcluster/pglb/pool_process_query.c	Wed Feb  4 23:37:29 2004
@@ -459,20 +459,31 @@
 
 			pool_write(frontend, &size, sizeof(int));
 			size = htonl(size) - 4;
-			buf = malloc(size);
-			if (buf == NULL)
+
+			/* read and send actual data only when size > 0 */
+			if (size > 0)
 			{
-				show_error("AsciiRow: out of memory");
-				return POOL_END;
+				buf = malloc(size);
+				if (buf == NULL)
+				{
+					show_error("AsciiRow: out of memory");
+					return POOL_END;
+				}
+				/* actual data */
+				if (pool_read(backend, buf, size) < 0)
+				{
+					free(buf);
+					return POOL_END;
+				}
+				pool_write(frontend, buf, size);
+				snprintf(msgbuf, Min(sizeof(msgbuf), size), "%s", buf);
+				free(buf);
+			}
+			else
+			{
+				*msgbuf = '\0';
 			}
-			/* actual data */
-			if (pool_read(backend, buf, size) < 0)
-				return POOL_END;
-
-			pool_write(frontend, buf, size);
-			snprintf(msgbuf, Min(sizeof(msgbuf), size), "%s", buf);
 			show_debug("AsciiRow: len:%d data: %s", size, msgbuf);
-			free(buf);
 		}
 		mask >>= 1;
 	}
@@ -728,10 +739,11 @@
 static POOL_STATUS EmptyQueryResponse(POOL_CONNECTION *frontend,
 									  POOL_CONNECTION *backend)
 {
+	char c;
+
 	/* set function name */
 	set_function("EmptyQueryResponse");
 
-	char c;
 	if (pool_read(backend, &c, sizeof(c)) < 0)
 		return POOL_END;
 
