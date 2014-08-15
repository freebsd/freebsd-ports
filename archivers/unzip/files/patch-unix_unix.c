--- unix/unix.c.orig	2009-01-23 23:31:26 UTC
+++ unix/unix.c
@@ -610,7 +610,7 @@ int mapname(__G__ renamed)
                  * else allow 8-bit characters (e.g. UTF-8) in filenames:
                  */
                 if (uO.cflxflag ||
-                    (isprint(workch) || (128 <= workch && workch <= 254)))
+		    (isprint(workch) || (128 <= workch && workch <= 255)))
                     *pp++ = (char)workch;
         } /* end switch */
 
