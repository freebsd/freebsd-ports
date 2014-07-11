--- mk/platform.mk.orig	2014-07-03 11:11:37.699489136 +0200
+++ mk/platform.mk	2014-07-03 11:13:34.454205727 +0200
@@ -562,7 +562,7 @@
 CFG_LIB_GLOB_x86_64-unknown-freebsd=lib$(1)-*.so
 CFG_LIB_DSYM_GLOB_x86_64-unknown-freebsd=$(1)-*.dylib.dSYM
 CFG_CFLAGS_x86_64-unknown-freebsd := -I/usr/local/include $(CFLAGS)
-CFG_GCCISH_CFLAGS_x86_64-unknown-freebsd := -Wall -Werror -g -fPIC -I/usr/local/include $(CFLAGS)
+CFG_GCCISH_CFLAGS_x86_64-unknown-freebsd := -Wall -g -fPIC -I/usr/local/include $(CFLAGS)
 CFG_GCCISH_LINK_FLAGS_x86_64-unknown-freebsd := -shared -fPIC -g -pthread  -lrt
 CFG_GCCISH_DEF_FLAG_x86_64-unknown-freebsd := -Wl,--export-dynamic,--dynamic-list=
 CFG_GCCISH_PRE_LIB_FLAGS_x86_64-unknown-freebsd := -Wl,-whole-archive
