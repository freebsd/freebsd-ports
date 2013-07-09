--- mk/platform.mk.orig	2013-07-09 00:57:39.009593612 +0800
+++ mk/platform.mk	2013-07-09 00:57:55.526200080 +0800
@@ -375,7 +375,7 @@
 CFG_LIB_NAME_x86_64-unknown-freebsd=lib$(1).so
 CFG_LIB_GLOB_x86_64-unknown-freebsd=lib$(1)-*.so
 CFG_LIB_DSYM_GLOB_x86_64-unknown-freebsd=$(1)-*.dylib.dSYM
-CFG_GCCISH_CFLAGS_x86_64-unknown-freebsd := -Wall -Werror -g -fPIC -I/usr/local/include
+CFG_GCCISH_CFLAGS_x86_64-unknown-freebsd := -Wall -g -fPIC -I/usr/local/include
 CFG_GCCISH_LINK_FLAGS_x86_64-unknown-freebsd := -shared -fPIC -g -pthread  -lrt
 CFG_GCCISH_DEF_FLAG_x86_64-unknown-freebsd := -Wl,--export-dynamic,--dynamic-list=
 CFG_GCCISH_PRE_LIB_FLAGS_x86_64-unknown-freebsd := -Wl,-whole-archive
