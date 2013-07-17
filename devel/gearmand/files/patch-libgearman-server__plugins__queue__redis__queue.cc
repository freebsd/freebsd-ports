--- ./libgearman-server/plugins/queue/redis/queue.cc.orig	2013-07-17 10:53:36.000000000 -0400
+++ ./libgearman-server/plugins/queue/redis/queue.cc	2013-07-17 10:53:49.000000000 -0400
@@ -271,14 +271,11 @@
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
