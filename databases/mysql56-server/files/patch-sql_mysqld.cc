--- sql/mysqld.cc.orig	2013-02-13 15:18:22.000000000 +0100
+++ sql/mysqld.cc	2013-02-13 15:18:46.000000000 +0100
@@ -6292,7 +6292,7 @@
             The connection was refused by TCP wrappers.
             There are no details (by client IP) available to update the host_cache.
           */
-          statistic_increment(connection_tcpwrap_errors, &LOCK_status);
+          statistic_increment(connection_errors_tcpwrap, &LOCK_status);
           continue;
         }
       }
