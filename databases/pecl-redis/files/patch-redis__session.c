Patch can be removed in next release
Upstream fix;
https://github.com/phpredis/phpredis/pull/1804

--- redis_session.c.orig	2020-07-03 06:17:19 UTC
+++ redis_session.c
@@ -480,7 +480,8 @@ PS_OPEN_FUNC(redis)
             }
 
             redis_sock = redis_sock_create(addr, addrlen, port, timeout, read_timeout,
-                                           persistent, ZSTR_VAL(persistent_id), retry_interval);
+                                           persistent, persistent_id ? ZSTR_VAL(persistent_id) : NULL,
+                                           retry_interval);
 
             redis_pool_add(pool, redis_sock, weight, db);
             redis_sock->prefix = prefix;
