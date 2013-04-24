--- mk/platform.mk.orig	2013-04-06 12:47:35.924036199 +0800
+++ mk/platform.mk	2013-04-06 12:48:04.696038055 +0800
@@ -299,7 +299,7 @@
 CFG_LIB_NAME_x86_64-unknown-freebsd=lib$(1).so
 CFG_LIB_GLOB_x86_64-unknown-freebsd=lib$(1)-*.so
 CFG_LIB_DSYM_GLOB_x86_64-unknown-freebsd=$(1)-*.dylib.dSYM
-CFG_GCCISH_CFLAGS_x86_64-unknown-freebsd := -Wall -Werror -g -fPIC -I/usr/local/include
+CFG_GCCISH_CFLAGS_x86_64-unknown-freebsd := -Wall -g -fPIC -I/usr/local/include
 CFG_GCCISH_LINK_FLAGS_x86_64-unknown-freebsd := -shared -fPIC -g -lpthread -lrt
 CFG_GCCISH_DEF_FLAG_x86_64-unknown-freebsd := -Wl,--export-dynamic,--dynamic-list=
 CFG_GCCISH_PRE_LIB_FLAGS_x86_64-unknown-freebsd := -Wl,-whole-archive
