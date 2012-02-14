--- solenv/gbuild/platform/freebsd.mk~	2011-12-24 18:45:27.000000000 +0900
+++ solenv/gbuild/platform/freebsd.mk	2011-12-25 11:01:37.000000000 +0900
@@ -120,6 +120,7 @@
 	-Wl,-z,combreloc \
 	-Wl,-z,defs \
 	$(subst -L../lib , ,$(SOLARLIB)) \
+	%%RPATH%% \
 
 ifeq ($(HAVE_LD_HASH_STYLE),TRUE)
 gb_LinkTarget_LDFLAGS += \
@@ -302,7 +302,7 @@
 	$(foreach lib,$(gb_Library_UNOVERLIBS),$(lib):URELIB) \
 
 define gb_Library_get_rpath
-'-Wl,-rpath,$(call gb_LinkTarget__get_rpath_for_layer,$(call gb_Library_get_layer,$(1)))' \
+-Wl,-z,origin '-Wl,-rpath,$(call gb_LinkTarget__get_rpath_for_layer,$(call gb_Library_get_layer,$(1)))' \
 '-Wl,-rpath-link,$(gb_Library_OUTDIRLOCATION)'
 endef
 
