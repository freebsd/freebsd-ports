--- src/forward.c.orig	2024-12-20 21:57:21 UTC
+++ src/forward.c
@@ -3054,7 +3054,7 @@ static struct frec *lookup_frec(char *target, int clas
 }
 
 /* Send query packet again, if we can. */
-void resend_query()
+void resend_query(void)
 {
   if (daemon->srv_save)
     server_send(daemon->srv_save, daemon->fd_save,
