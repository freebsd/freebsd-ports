--- man/man.c	2001/07/30 08:49:20
+++ man/man.c	2001/12/13 02:16:57
@@ -222,7 +222,7 @@
       }
       else
 	{
-	  status = man_ml (nextarg);
+	  status = man_ml (nextarg, findall);
 
 	  if (status == 0)
 	    gripe_not_found (nextarg, section);
