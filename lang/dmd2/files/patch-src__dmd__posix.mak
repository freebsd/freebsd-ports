--- ../../src/dmd/posix.mak.orig	2015-11-11 02:36:12.000000000 -0800
+++ ../../src/dmd/posix.mak	2015-11-14 11:37:37.628381337 -0800
@@ -57,7 +57,7 @@
 else
   # Auto-bootstrapping, will download dmd automatically
   HOST_DMD_VER=2.067.1
-  HOST_DMD_ROOT=/tmp/.host_dmd-$(HOST_DMD_VER)
+  HOST_DMD_ROOT=${WRKDIR}/.host_dmd-$(HOST_DMD_VER)
   # dmd.2.067.1.osx.zip or dmd.2.067.1.freebsd-64.zip
   HOST_DMD_ZIP=dmd.$(HOST_DMD_VER).$(OS)$(if $(filter $(OS),freebsd),-$(MODEL),).zip
   # http://downloads.dlang.org/releases/2.x/2.067.1/dmd.2.067.1.osx.zip
@@ -423,7 +423,7 @@
 	$(eval bin_dir=$(if $(filter $(OS),osx), bin, bin$(MODEL)))
 	mkdir -p $(INSTALL_DIR)/$(OS)/$(bin_dir)
 	cp dmd $(INSTALL_DIR)/$(OS)/$(bin_dir)/dmd
-	cp ../ini/$(OS)/$(bin_dir)/dmd.conf $(INSTALL_DIR)/$(OS)/$(bin_dir)/dmd.conf
+	cp ../../$(OS)/$(bin_dir)/dmd.conf $(INSTALL_DIR)/$(OS)/$(bin_dir)/dmd.conf
 	cp backendlicense.txt $(INSTALL_DIR)/dmd-backendlicense.txt
 	cp boostlicense.txt $(INSTALL_DIR)/dmd-boostlicense.txt
 
