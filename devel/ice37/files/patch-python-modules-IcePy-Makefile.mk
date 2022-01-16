--- python/modules/IcePy/Makefile.mk.orig	2021-06-21 14:44:58 UTC
+++ python/modules/IcePy/Makefile.mk
@@ -9,8 +9,8 @@ IcePy_targetname        := IcePy
 IcePy_targetdir         := $(lang_srcdir)/python
 IcePy_installdir        := $(install_pythondir)
 IcePy_cppflags          := -I$(project) $(ice_cpp_cppflags) -I$(top_srcdir)/cpp/src $(python_cppflags)
-IcePy_system_libs       := $(python_ldflags)
-IcePy_dependencies      := IceDiscovery IceLocatorDiscovery IceSSL Ice
+IcePy_system_libs       := $(python_ldflags) -lIceDiscovery -lIceLocatorDiscovery -lIceSSL -lIce
+#IcePy_dependencies      := IceDiscovery IceLocatorDiscovery IceSSL Ice
 IcePy_libs              := mcpp
 IcePy_extra_sources     := $(filter-out %Util.cpp %Ruby.cpp,\
                            $(wildcard $(top_srcdir)/cpp/src/Slice/*.cpp)) \
