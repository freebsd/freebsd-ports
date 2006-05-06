--- sapi/cgi/Makefile.frag.orig	Fri May  5 08:09:42 2006
+++ sapi/cgi/Makefile.frag	Fri May  5 08:10:05 2006
@@ -1,2 +1,5 @@
-$(SAPI_CGI_PATH): $(PHP_GLOBAL_OBJS) $(PHP_SAPI_OBJS)
+$(SAPI_CGI_PATH): $(PHP_GLOBAL_OBJS) $(PHP_CGI_OBJS)
 	$(BUILD_CGI)
+
+install-cgi: $(SAPI_CGI_PATH)
+	@$(INSTALL_CGI)
