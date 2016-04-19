--- ../../src/dmd/posix.mak.orig	2016-04-05 20:46:46.000000000 -0700
+++ ../../src/dmd/posix.mak	2016-04-07 06:19:55.204336000 -0700
@@ -66,14 +66,11 @@
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
 
@@ -333,19 +330,6 @@
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
@@ -452,7 +436,7 @@
 	$(eval bin_dir=$(if $(filter $(OS),osx), bin, bin$(MODEL)))
 	mkdir -p $(INSTALL_DIR)/$(OS)/$(bin_dir)
 	cp dmd $(INSTALL_DIR)/$(OS)/$(bin_dir)/dmd
-	cp ../ini/$(OS)/$(bin_dir)/dmd.conf $(INSTALL_DIR)/$(OS)/$(bin_dir)/dmd.conf
+	cp ../../$(OS)/$(bin_dir)/dmd.conf $(INSTALL_DIR)/$(OS)/$(bin_dir)/dmd.conf
 	cp backendlicense.txt $(INSTALL_DIR)/dmd-backendlicense.txt
 	cp boostlicense.txt $(INSTALL_DIR)/dmd-boostlicense.txt
 
