--- src/proc.c.bak	Sun May 19 02:11:05 2002
+++ src/proc.c	Thu Jul 27 22:45:32 2006
@@ -92,7 +92,7 @@
 	  /*g_critical*/
 	  printf("procedure \"%s\" contexts list not empty !\n", 
 		 PROC(myproc)->name);
-	  exit();
+	  exit(0);
 	  //g_slist_foreach(PROC(myproc)->contexts, context_free_from_list, NULL);
 	  //g_slist_free(PROC(myproc)->contexts);
 	}
