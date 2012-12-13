--- svn/VisualMerge.cpp.orig	2006-01-18 05:40:34.000000000 +0900
+++ svn/VisualMerge.cpp	2012-05-10 06:01:16.000000000 +0900
@@ -19,7 +19,7 @@
 
 VisualMerge::VisualMerge( svn_client_ctx_t* context, const sc::String& mergeCmd,
   apr_pool_t* pool )
-: _context(context), _mergeCmd(mergeCmd), _pool(pool)
+: _context(context), _pool(pool), _mergeCmd(mergeCmd)
 {
 }
 
