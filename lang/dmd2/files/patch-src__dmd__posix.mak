--- ../../src/dmd/posix.mak.orig	2017-01-22 15:46:00.000000000 -0800
+++ ../../src/dmd/posix.mak	2017-02-13 13:44:37.379009000 -0800
@@ -19,7 +19,7 @@
 endif
 
 INSTALL_DIR=../../install
-SYSCONFDIR=/etc
+SYSCONFDIR=/usr/local/etc
 PGO_DIR=$(abspath pgo)
 
 C=backend
@@ -42,11 +42,11 @@
 
 # determine whether CXX is gcc or clang based
 CXX_VERSION:=$(shell $(CXX) --version)
-ifneq (,$(findstring g++,$(CXX_VERSION))$(findstring gcc,$(CXX_VERSION))$(findstring GCC,$(CXX_VERSION)))
-	CXX_KIND=g++
+ifneq (,$(findstring c++,$(CXX_VERSION))$(findstring gcc,$(CXX_VERSION))$(findstring GCC,$(CXX_VERSION)))
+	CXX_KIND=c++
 endif
 ifneq (,$(findstring clang,$(CXX_VERSION)))
-	CXX_KIND=clang++
+	CXX_KIND=clanc++
 endif
 
 HOST_DC?=
@@ -67,14 +67,12 @@
 else
   # Auto-bootstrapping, will download dmd automatically
   # Keep var below in sync with other occurrences of that variable, e.g. in circleci.sh
-  HOST_DMD_VER=2.068.2
-  HOST_DMD_ROOT=/tmp/.host_dmd-$(HOST_DMD_VER)
+  HOST_DMD_VER=2.067.1
+  HOST_DMD_ROOT=${WRKDIR}/.host_dmd-$(HOST_DMD_VER)
   # dmd.2.068.2.osx.zip or dmd.2.068.2.linux.tar.xz
   HOST_DMD_BASENAME=dmd.$(HOST_DMD_VER).$(OS)$(if $(filter $(OS),freebsd),-$(MODEL),)
-  # http://downloads.dlang.org/releases/2.x/2.068.2/dmd.2.068.2.linux.tar.xz
-  HOST_DMD_URL=http://downloads.dlang.org/releases/2.x/$(HOST_DMD_VER)/$(HOST_DMD_BASENAME)
   HOST_DMD=$(HOST_DMD_ROOT)/dmd2/$(OS)/$(if $(filter $(OS),osx),bin,bin$(MODEL))/dmd
-  HOST_DMD_PATH=$(HOST_DMD)
+  HOST_DMD_PATH=$(HOST_DMD_ROOT)/stage/usr/local/bin/dmd
   HOST_DMD_RUN=$(HOST_DMD) -conf=$(dir $(HOST_DMD))dmd.conf
 endif
 
@@ -103,7 +101,7 @@
 	-Wno-unused-value \
 	-Wno-unused-variable
 # GCC Specific
-ifeq ($(CXX_KIND), g++)
+ifeq ($(CXX_KIND), c++)
 WARNINGS += \
 	-Wno-logical-op \
 	-Wno-narrowing \
@@ -111,7 +109,7 @@
 	-Wno-uninitialized
 endif
 # Clang Specific
-ifeq ($(HOST_CXX_KIND), clang++)
+ifeq ($(HOST_CXX_KIND), clanc++)
 WARNINGS += \
 	-Wno-tautological-constant-out-of-range-compare \
 	-Wno-tautological-compare \
@@ -123,7 +121,7 @@
 # Default Warnings
 WARNINGS := -Wno-deprecated -Wstrict-aliasing
 # Clang Specific
-ifeq ($(CXX_KIND), clang++)
+ifeq ($(CXX_KIND), clanc++)
 WARNINGS += \
     -Wno-logical-op-parentheses \
     -Wno-dynamic-class-memaccess \
@@ -141,7 +139,7 @@
 	-D__pascal= -DMARS=1 -DTARGET_$(OS_UPCASE)=1 -DDM_TARGET_CPU_$(TARGET_CPU)=1 \
 	$(MODEL_FLAG)
 # GCC Specific
-ifeq ($(CXX_KIND), g++)
+ifeq ($(CXX_KIND), c++)
 CXXFLAGS += \
     -std=gnu++98
 endif
@@ -342,19 +340,6 @@
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
@@ -461,7 +446,7 @@
 	$(eval bin_dir=$(if $(filter $(OS),osx), bin, bin$(MODEL)))
 	mkdir -p $(INSTALL_DIR)/$(OS)/$(bin_dir)
 	cp dmd $(INSTALL_DIR)/$(OS)/$(bin_dir)/dmd
-	cp ../ini/$(OS)/$(bin_dir)/dmd.conf $(INSTALL_DIR)/$(OS)/$(bin_dir)/dmd.conf
+	cp ../../$(OS)/$(bin_dir)/dmd.conf $(INSTALL_DIR)/$(OS)/$(bin_dir)/dmd.conf
 	cp backendlicense.txt $(INSTALL_DIR)/dmd-backendlicense.txt
 	cp boostlicense.txt $(INSTALL_DIR)/dmd-boostlicense.txt
 
