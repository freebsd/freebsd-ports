--- mk/platform.mk.orig	2014-01-20 12:47:42.902789736 +0800
+++ mk/platform.mk	2014-01-20 12:47:53.647790608 +0800
@@ -522,7 +522,7 @@
 CFG_STATIC_LIB_NAME_x86_64-unknown-freebsd=lib$(1).a
 CFG_LIB_GLOB_x86_64-unknown-freebsd=lib$(1)-*.so
 CFG_LIB_DSYM_GLOB_x86_64-unknown-freebsd=$(1)-*.dylib.dSYM
-CFG_GCCISH_CFLAGS_x86_64-unknown-freebsd := -Wall -Werror -g -fPIC -I/usr/local/include
+CFG_GCCISH_CFLAGS_x86_64-unknown-freebsd := -Wall -g -fPIC -I/usr/local/include
 CFG_GCCISH_LINK_FLAGS_x86_64-unknown-freebsd := -shared -fPIC -g -pthread  -lrt
 CFG_GCCISH_DEF_FLAG_x86_64-unknown-freebsd := -Wl,--export-dynamic,--dynamic-list=
 CFG_GCCISH_PRE_LIB_FLAGS_x86_64-unknown-freebsd := -Wl,-whole-archive
