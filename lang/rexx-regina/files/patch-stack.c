--- stack.c.orig	2021-01-14 22:35:55 UTC
+++ stack.c
@@ -1314,7 +1314,7 @@ int create_queue( tsd_t *TSD, const streng *queue_name
          /*
           * Create a unique queue name
           */
-         sprintf(buf,"S%d-%ld-%d", getpid(), clock(), st->runner++ );
+         sprintf(buf,"S%d-%d-%d", getpid(), clock(), st->runner++ );
          new_queue = Str_cre_TSD( TSD, buf ) ;
       }
       else
@@ -1344,7 +1344,7 @@ int create_queue( tsd_t *TSD, const streng *queue_name
                /*
                 * Create a unique queue name
                 */
-               sprintf(buf,"S%d-%ld-%d", getpid(), clock(), st->runner++ );
+               sprintf(buf,"S%d-%d-%d", getpid(), clock(), st->runner++ );
                new_queue = Str_cre_TSD( TSD, buf ) ;
                rc = 1;
             }
