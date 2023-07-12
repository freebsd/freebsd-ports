--- redis.c.orig	2022-02-15 18:25:22 UTC
+++ redis.c
@@ -154,6 +154,9 @@ ZEND_BEGIN_ARG_INFO_EX(arginfo_pconnect, 0, 0, 1)
     ZEND_ARG_INFO(0, host)
     ZEND_ARG_INFO(0, port)
     ZEND_ARG_INFO(0, timeout)
+    ZEND_ARG_INFO(0, persistent_id)
+    ZEND_ARG_INFO(0, retry_interval)
+    ZEND_ARG_INFO(0, read_timeout)
 ZEND_END_ARG_INFO()
 
 ZEND_BEGIN_ARG_INFO_EX(arginfo_mget, 0, 0, 1)
