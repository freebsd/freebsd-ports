
$FreeBSD$

--- src/buffer.c	2002/06/01 21:08:46	1.1
+++ src/buffer.c	2002/06/01 21:09:16
@@ -1540,7 +1540,7 @@
 		  child = xfork ();
 		  if (child == 0)
 		    {
-		      execlp (shell, "-sh", "-i", 0);
+		      execlp (shell, "-sh", "-i", (char *) 0);
 		      exec_fatal (shell);
 		    }
 		  else
