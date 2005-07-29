--- subversion/bindings/swig/core.i.orig	Wed Jul 13 14:25:06 2005
+++ subversion/bindings/swig/core.i	Wed Jul 13 14:25:24 2005
@@ -425,13 +425,13 @@
 
 static apr_pool_t *current_pool = 0;
 
-SWIGEXPORT(apr_pool_t *)
+SWIGEXPORT apr_pool_t *
 svn_swig_pl_get_current_pool (void)
 {
   return current_pool;
 }
 
-SWIGEXPORT(void)
+SWIGEXPORT void
 svn_swig_pl_set_current_pool (apr_pool_t *pool)
 {
   current_pool = pool;
