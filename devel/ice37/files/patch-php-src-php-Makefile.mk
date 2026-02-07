--- php/src/php/Makefile.mk.orig	2021-06-21 14:44:58 UTC
+++ php/src/php/Makefile.mk
@@ -9,8 +9,13 @@ IcePHP_targetname       := ice
 IcePHP_targetdir        := lib
 IcePHP_installdir       := $(install_phplibdir)
 IcePHP_cppflags         := -I$(project) -I$(top_srcdir)/cpp/src $(ice_cpp_cppflags) $(php_cppflags)
-IcePHP_ldflags          := $(php_ldflags)
-IcePHP_dependencies     := IceDiscovery IceLocatorDiscovery IceSSL Ice
+IcePHP_system_libs      := $(php_ldflags) -L/usr/local/lib -lIceDiscovery -lIceLocatorDiscovery -lIceSSL -lIce
+ifeq ($(shell [ $$($(PHP_CONFIG) --vernum) -lt 80000 ] && echo 0),0)
+    IcePHP_system_libs += -lphp7
+else
+    IcePHP_system_libs += -lphp
+endif
+#IcePHP_dependencies     := IceDiscovery IceLocatorDiscovery IceSSL Ice
 IcePHP_extra_sources    := $(top_srcdir)/cpp/src/Slice/PHPUtil.cpp
 
 projects += $(project)
