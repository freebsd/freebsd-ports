--- configure.mk.orig	Mon Dec  9 14:41:01 2002
+++ configure.mk	Fri Dec 27 05:09:39 2002
@@ -13,8 +13,13 @@
 # install make+ separately.
 
 # Configuration scripts.
-MP_CONFIGURE_START = $(MAKEPLUS_HOME)/configure_start.sh > config.h
-MP_CONFIGURE_END = $(MAKEPLUS_HOME)/configure_end.sh >> config.h
-MP_CHECK_HEADERS = $(MAKEPLUS_HOME)/check_headers.sh >> config.h
-MP_CHECK_FUNCS	= $(MAKEPLUS_HOME)/check_funcs.sh >> config.h
-MP_CHECK_LIB	= $(MAKEPLUS_HOME)/check_lib.sh >> config.h
\ No newline at end of file
+MP_CONFIGURE_START = $(SETENV) $(CONF_ENV) \
+	$(MAKEPLUS_HOME)/configure_start.sh > config.h
+MP_CONFIGURE_END = $(SETENV) $(CONF_ENV) \
+	$(MAKEPLUS_HOME)/configure_end.sh >> config.h
+MP_CHECK_HEADERS = $(SETENV) $(CONF_ENV) \
+	$(MAKEPLUS_HOME)/check_headers.sh >> config.h
+MP_CHECK_FUNCS	=  $(SETENV) $(CONF_ENV) \
+	$(MAKEPLUS_HOME)/check_funcs.sh >> config.h
+MP_CHECK_LIB	=  $(SETENV) $(CONF_ENV) \
+	$(MAKEPLUS_HOME)/check_lib.sh >> config.h
