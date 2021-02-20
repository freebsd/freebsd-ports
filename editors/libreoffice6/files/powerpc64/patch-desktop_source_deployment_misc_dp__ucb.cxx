--- desktop/source/deployment/misc/dp_ucb.cxx.orig	2020-10-21 20:09:11 UTC
+++ desktop/source/deployment/misc/dp_ucb.cxx
@@ -45,7 +45,7 @@ namespace dp_misc
 bool create_ucb_content(
     ::ucbhelper::Content * ret_ucbContent, OUString const & url,
     Reference<XCommandEnvironment> const & xCmdEnv,
-    bool throw_exc )
+    bool throw_exc ) __attribute__ ((optnone))
 {
     try {
         // Existence check...
@@ -81,7 +81,7 @@ bool create_ucb_content(
 
 bool create_folder(
     ::ucbhelper::Content * ret_ucb_content, OUString const & url_,
-    Reference<XCommandEnvironment> const & xCmdEnv, bool throw_exc )
+    Reference<XCommandEnvironment> const & xCmdEnv, bool throw_exc ) __attribute__ ((optnone))
 {
     ::ucbhelper::Content ucb_content;
     if (create_ucb_content(
