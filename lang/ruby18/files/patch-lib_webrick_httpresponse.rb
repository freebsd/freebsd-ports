--- lib/webrick/httpresponse.rb.orig	2010-08-17 18:54:44.000000000 -0700
+++ lib/webrick/httpresponse.rb	2010-08-17 18:54:58.000000000 -0700
@@ -209,7 +209,7 @@
         @keep_alive = false
         self.status = HTTPStatus::RC_INTERNAL_SERVER_ERROR
       end
-      @header['content-type'] = "text/html"
+      @header['content-type'] = "text/html; charset=ISO-8859-1"
 
       if respond_to?(:create_error_page)
         create_error_page()
