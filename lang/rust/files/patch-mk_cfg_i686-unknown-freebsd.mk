--- mk/cfg/i686-unknown-freebsd.mk.orig	2016-03-01 19:18:54 UTC
+++ mk/cfg/i686-unknown-freebsd.mk
@@ -7,9 +7,9 @@ CFG_LIB_NAME_i686-unknown-freebsd=lib$(1
 CFG_STATIC_LIB_NAME_i686-unknown-freebsd=lib$(1).a
 CFG_LIB_GLOB_i686-unknown-freebsd=lib$(1)-*.so
 CFG_LIB_DSYM_GLOB_i686-unknown-freebsd=$(1)-*.dylib.dSYM
-CFG_JEMALLOC_CFLAGS_i686-unknown-freebsd := -m32 -I/usr/local/include $(CFLAGS)
-CFG_GCCISH_CFLAGS_i686-unknown-freebsd := -Wall -Werror -g -fPIC -m32 -arch i386 -I/usr/local/include $(CFLAGS)
-CFG_GCCISH_LINK_FLAGS_i686-unknown-freebsd := -m32 -shared -fPIC -g -pthread -lrt
+CFG_JEMALLOC_CFLAGS_i686-unknown-freebsd := -I/usr/local/include $(CFLAGS)
+CFG_GCCISH_CFLAGS_i686-unknown-freebsd := -Wall -Werror -g -fPIC -I/usr/local/include $(CFLAGS)
+CFG_GCCISH_LINK_FLAGS_i686-unknown-freebsd := -shared -fPIC -g -pthread -lrt
 CFG_GCCISH_DEF_FLAG_i686-unknown-freebsd := -Wl,--export-dynamic,--dynamic-list=
 CFG_LLC_FLAGS_i686-unknown-freebsd :=
 CFG_INSTALL_NAME_i686-unknown-freebsd =
