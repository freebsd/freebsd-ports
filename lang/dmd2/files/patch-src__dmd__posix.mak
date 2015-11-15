--- ../../src/dmd/posix.mak.orig	2015-11-11 02:36:12.000000000 -0800
+++ ../../src/dmd/posix.mak	2015-11-15 01:40:55.280252455 -0800
@@ -57,13 +57,13 @@
 else
   # Auto-bootstrapping, will download dmd automatically
   HOST_DMD_VER=2.067.1
-  HOST_DMD_ROOT=/tmp/.host_dmd-$(HOST_DMD_VER)
+  HOST_DMD_ROOT=${WRKDIR}/.host_dmd-$(HOST_DMD_VER)
   # dmd.2.067.1.osx.zip or dmd.2.067.1.freebsd-64.zip
   HOST_DMD_ZIP=dmd.$(HOST_DMD_VER).$(OS)$(if $(filter $(OS),freebsd),-$(MODEL),).zip
   # http://downloads.dlang.org/releases/2.x/2.067.1/dmd.2.067.1.osx.zip
   HOST_DMD_URL=http://downloads.dlang.org/releases/2.x/$(HOST_DMD_VER)/$(HOST_DMD_ZIP)
   HOST_DMD=$(HOST_DMD_ROOT)/dmd2/$(OS)/$(if $(filter $(OS),osx),bin,bin$(MODEL))/dmd
-  HOST_DMD_PATH=$(HOST_DMD)
+  HOST_DMD_PATH=$(HOST_DMD_ROOT)/stage/usr/local/bin/dmd
   HOST_DMD_RUN=$(HOST_DMD) -conf=$(dir $(HOST_DMD))dmd.conf
 endif
 
@@ -308,15 +308,6 @@
 		verstr.h SYSCONFDIR.imp core *.cov *.deps *.gcda *.gcno *.a
 	@[ ! -d ${PGO_DIR} ] || echo You should issue manually: rm -rf ${PGO_DIR}
 
-######## Download and install the last dmd buildable without dmd
-
-ifneq (,$(AUTO_BOOTSTRAP))
-$(HOST_DMD_PATH):
-	mkdir -p ${HOST_DMD_ROOT}
-	TMPFILE=$$(mktemp deleteme.XXXXXXXX) && curl -fsSL ${HOST_DMD_URL} > $${TMPFILE}.zip && \
-		unzip -qd ${HOST_DMD_ROOT} $${TMPFILE}.zip && rm $${TMPFILE}.zip
-endif
-
 ######## generate a default dmd.conf
 
 define DEFAULT_DMD_CONF
@@ -423,7 +392,7 @@
 	$(eval bin_dir=$(if $(filter $(OS),osx), bin, bin$(MODEL)))
 	mkdir -p $(INSTALL_DIR)/$(OS)/$(bin_dir)
 	cp dmd $(INSTALL_DIR)/$(OS)/$(bin_dir)/dmd
-	cp ../ini/$(OS)/$(bin_dir)/dmd.conf $(INSTALL_DIR)/$(OS)/$(bin_dir)/dmd.conf
+	cp ../../$(OS)/$(bin_dir)/dmd.conf $(INSTALL_DIR)/$(OS)/$(bin_dir)/dmd.conf
 	cp backendlicense.txt $(INSTALL_DIR)/dmd-backendlicense.txt
 	cp boostlicense.txt $(INSTALL_DIR)/dmd-boostlicense.txt
 
