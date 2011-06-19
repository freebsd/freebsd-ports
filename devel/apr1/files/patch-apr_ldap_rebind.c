--- apr-util-1.3.12/ldap/apr_ldap_rebind.c.orig	2011-06-18 14:42:15.000000000 +0000
+++ apr-util-1.3.12/ldap/apr_ldap_rebind.c	2011-06-18 14:42:28.000000000 +0000
@@ -81,11 +81,11 @@
     get_apd
 #endif
 
+#if APR_HAS_THREADS
     /* run after apr_thread_mutex_create cleanup */
     apr_pool_cleanup_register(pool, &apr_ldap_xref_lock, apr_ldap_pool_cleanup_set_null,
                               apr_pool_cleanup_null);
 
-#if APR_HAS_THREADS
     if (apr_ldap_xref_lock == NULL) {
         retcode = apr_thread_mutex_create(&apr_ldap_xref_lock, APR_THREAD_MUTEX_DEFAULT, pool);
     }
