--- ./libgearman-server/plugins/queue/redis/queue.cc.orig	2012-10-03 15:55:58.000000000 -0400
+++ ./libgearman-server/plugins/queue/redis/queue.cc	2012-10-03 15:56:31.000000000 -0400
@@ -269,14 +269,11 @@
       assert(fmt_str_length != 1);
       return gearmand_gerror("snprintf() failed to produce a valud fmt_str for redis key", GEARMAN_QUEUE_ERROR);
     }
-#pragma GCC diagnostic push
-#pragma GCC diagnostic ignored "-Wformat-nonliteral"
     int ret= sscanf(reply->element[x]->str,
                     fmt_str,
                     prefix,
                     function_name,
                     unique);
-#pragma GCC diagnostic pop
     if (ret == 0)
     {
       continue;
