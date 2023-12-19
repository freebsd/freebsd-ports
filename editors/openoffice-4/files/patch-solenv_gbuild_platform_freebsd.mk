--- solenv/gbuild/platform/freebsd.mk.orig	2021-04-02 12:58:22 UTC
+++ solenv/gbuild/platform/freebsd.mk
@@ -137,6 +137,7 @@ gb_LinkTarget_LDFLAGS += \
 	-Wl,-rpath-link,$(SYSBASE)/lib:$(SYSBASE)/usr/lib \
 	-Wl,-z,combreloc \
 	-Wl,-z,defs \
+	-Wl,--undefined-version \
 	$(subst -L../lib , ,$(SOLARLIB)) \
 	${FBSD_GCC_RPATH} \
 	 \
@@ -188,13 +189,13 @@ $(call gb_Helper_abbreviate_dirs,\
 	mkdir -p $(dir $(1)) && \
 	mkdir -p $(dir $(call gb_CObject_get_dep_target,$(2))) && \
 	$(gb_CC) \
-		$(DEFS) $(CFLAGS) \
+		$(DEFS) \
 		-c $(3) \
 		-o $(1) \
 		-MMD -MT $(call gb_CObject_get_target,$(2)) \
 		-MF $(call gb_CObject_get_dep_target,$(2)) \
 		-I$(dir $(3)) \
-		$(INCLUDE))
+		$(INCLUDE) $(CFLAGS))
 endef
 
 # convert parametters filesystem root to native notation
@@ -212,13 +213,13 @@ $(call gb_Helper_abbreviate_dirs,\
 	mkdir -p $(dir $(1)) && \
 	mkdir -p $(dir $(call gb_CxxObject_get_dep_target,$(2))) && \
 	$(gb_CXX) \
-		$(DEFS) $(CXXFLAGS) \
+		$(DEFS) \
 		-c $(3) \
 		-o $(1) \
 		-MMD -MT $(call gb_CxxObject_get_target,$(2)) \
 		-MF $(call gb_CxxObject_get_dep_target,$(2)) \
 		-I$(dir $(3)) \
-		$(INCLUDE_STL) $(INCLUDE))
+		$(INCLUDE_STL) $(INCLUDE) $(CXXFLAGS))
 endef
 
 
