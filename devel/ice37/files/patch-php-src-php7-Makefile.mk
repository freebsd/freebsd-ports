--- php/src/php7/Makefile.mk.orig	2018-04-20 15:02:08 UTC
+++ php/src/php7/Makefile.mk
@@ -14,8 +14,8 @@ IcePHP_targetname       := ice
 IcePHP_targetdir        := lib
 IcePHP_installdir       := $(install_phplibdir)
 IcePHP_cppflags         := -I$(project) -I$(top_srcdir)/cpp/src $(ice_cpp_cppflags) $(php_cppflags)
-IcePHP_ldflags          := $(php_ldflags)
-IcePHP_dependencies     := IceDiscovery IceLocatorDiscovery IceSSL Ice
+IcePHP_system_libs      := $(php_ldflags) -L/usr/local/lib -lIceDiscovery -lIceLocatorDiscovery -lIceSSL -lIce -lphp7
+#IcePHP_dependencies     := IceDiscovery IceLocatorDiscovery IceSSL Ice
 IcePHP_extra_sources    := $(top_srcdir)/cpp/src/Slice/PHPUtil.cpp
 
 projects += $(project)
