--- ../../src/dmd/posix.mak.orig	2016-01-27 07:22:54.000000000 -0800
+++ ../../src/dmd/posix.mak	2016-01-28 12:32:14.044394178 -0800
@@ -31,9 +31,9 @@
 endif
 
 #ifeq (osx,$(OS))
-#	HOST_CC=clang++
+#	HOST_CC=clanc++
 #else
-	HOST_CC=g++
+	HOST_CC=c++
 #endif
 CC=$(HOST_CC)
 AR=ar
@@ -56,14 +56,11 @@
   HOST_DMD_RUN:=$(HOST_DMD)
 else
   # Auto-bootstrapping, will download dmd automatically
-  HOST_DMD_VER=2.068.2
-  HOST_DMD_ROOT=/tmp/.host_dmd-$(HOST_DMD_VER)
-  # dmd.2.068.2.osx.zip or dmd.2.068.2.linux.tar.xz
+  HOST_DMD_VER=2.067.1
+  HOST_DMD_ROOT=${WRKDIR}/.host_dmd-$(HOST_DMD_VER)
   HOST_DMD_BASENAME=dmd.$(HOST_DMD_VER).$(OS)$(if $(filter $(OS),freebsd),-$(MODEL),)
-  # http://downloads.dlang.org/releases/2.x/2.068.2/dmd.2.068.2.linux.tar.xz
-  HOST_DMD_URL=http://downloads.dlang.org/releases/2.x/$(HOST_DMD_VER)/$(HOST_DMD_BASENAME)
   HOST_DMD=$(HOST_DMD_ROOT)/dmd2/$(OS)/$(if $(filter $(OS),osx),bin,bin$(MODEL))/dmd
-  HOST_DMD_PATH=$(HOST_DMD)
+  HOST_DMD_PATH=$(HOST_DMD_ROOT)/stage/usr/local/bin/dmd
   HOST_DMD_RUN=$(HOST_DMD) -conf=$(dir $(HOST_DMD))dmd.conf
 endif
 
@@ -92,7 +89,7 @@
 	-Wno-unused-value \
 	-Wno-unused-variable
 # GCC Specific
-ifeq ($(HOST_CC), g++)
+ifeq ($(HOST_CC), c++)
 WARNINGS := $(WARNINGS) \
 	-Wno-logical-op \
 	-Wno-narrowing \
@@ -100,7 +97,7 @@
 	-Wno-uninitialized
 endif
 # Clang Specific
-ifeq ($(HOST_CC), clang++)
+ifeq ($(HOST_CC), clanc++)
 WARNINGS := $(WARNINGS) \
 	-Wno-tautological-constant-out-of-range-compare \
 	-Wno-tautological-compare \
@@ -112,7 +109,7 @@
 # Default Warnings
 WARNINGS := -Wno-deprecated -Wstrict-aliasing
 # Clang Specific
-ifeq ($(HOST_CC), clang++)
+ifeq ($(HOST_CC), clanc++)
 WARNINGS := $(WARNINGS) \
     -Wno-logical-op-parentheses \
     -Wno-dynamic-class-memaccess \
@@ -130,7 +127,7 @@
 	-D__pascal= -DMARS=1 -DTARGET_$(OS_UPCASE)=1 -DDM_TARGET_CPU_$(TARGET_CPU)=1 \
 	$(MODEL_FLAG)
 # GCC Specific
-ifeq ($(HOST_CC), g++)
+ifeq ($(HOST_CC), c++)
 CFLAGS := $(CFLAGS) \
     -std=gnu++98
 endif
@@ -321,19 +318,6 @@
 		verstr.h SYSCONFDIR.imp core *.cov *.deps *.gcda *.gcno *.a *.lst
 	@[ ! -d ${PGO_DIR} ] || echo You should issue manually: rm -rf ${PGO_DIR}
 
-######## Download and install the last dmd buildable without dmd
-
-ifneq (,$(AUTO_BOOTSTRAP))
-$(HOST_DMD_PATH):
-	mkdir -p ${HOST_DMD_ROOT}
-ifneq (,$(shell which xz 2>/dev/null))
-	curl -fsSL ${HOST_DMD_URL}.tar.xz | tar -C ${HOST_DMD_ROOT} -Jxf - || rm -rf ${HOST_DMD_ROOT}
-else
-	TMPFILE=$$(mktemp deleteme.XXXXXXXX) &&	curl -fsSL ${HOST_DMD_URL}.zip > $${TMPFILE}.zip && \
-		unzip -qd ${HOST_DMD_ROOT} $${TMPFILE}.zip && rm $${TMPFILE}.zip;
-endif
-endif
-
 ######## generate a default dmd.conf
 
 define DEFAULT_DMD_CONF
@@ -440,7 +424,7 @@
 	$(eval bin_dir=$(if $(filter $(OS),osx), bin, bin$(MODEL)))
 	mkdir -p $(INSTALL_DIR)/$(OS)/$(bin_dir)
 	cp dmd $(INSTALL_DIR)/$(OS)/$(bin_dir)/dmd
-	cp ../ini/$(OS)/$(bin_dir)/dmd.conf $(INSTALL_DIR)/$(OS)/$(bin_dir)/dmd.conf
+	cp ../../$(OS)/$(bin_dir)/dmd.conf $(INSTALL_DIR)/$(OS)/$(bin_dir)/dmd.conf
 	cp backendlicense.txt $(INSTALL_DIR)/dmd-backendlicense.txt
 	cp boostlicense.txt $(INSTALL_DIR)/dmd-boostlicense.txt
 
