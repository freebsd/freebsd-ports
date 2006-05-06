--- sapi/cgi/Makefile.frag.orig	Wed May  3 10:09:02 2006
+++ sapi/cgi/Makefile.frag	Wed May  3 10:08:54 2006
@@ -1,2 +1,5 @@
-$(SAPI_CGI_PATH): $(PHP_GLOBAL_OBJS) $(PHP_SAPI_OBJS)
+$(SAPI_CGI_PATH): $(PHP_GLOBAL_OBJS) $(PHP_CGI_OBJS)
 	$(BUILD_CGI)
+
+install-cgi: $(SAPI_CGI_PATH)
+	@$(INSTALL_CGI)
