--- ../../src/dmd/posix.mak.orig	2015-11-11 02:36:12.000000000 -0800
+++ ../../src/dmd/posix.mak	2015-11-14 08:20:14.138530978 -0800
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
@@ -92,7 +92,7 @@
 	-Wno-unused-value \
 	-Wno-unused-variable
 # GCC Specific
-ifeq ($(HOST_CC), g++)
+ifeq ($(HOST_CC), c++)
 WARNINGS := $(WARNINGS) \
 	-Wno-logical-op \
 	-Wno-narrowing \
@@ -100,7 +100,7 @@
 	-Wno-uninitialized
 endif
 # Clang Specific
-ifeq ($(HOST_CC), clang++)
+ifeq ($(HOST_CC), clanc++)
 WARNINGS := $(WARNINGS) \
 	-Wno-tautological-constant-out-of-range-compare \
 	-Wno-tautological-compare \
@@ -112,7 +112,7 @@
 # Default Warnings
 WARNINGS := -Wno-deprecated -Wstrict-aliasing
 # Clang Specific
-ifeq ($(HOST_CC), clang++)
+ifeq ($(HOST_CC), clanc++)
 WARNINGS := $(WARNINGS) \
     -Wno-logical-op-parentheses \
     -Wno-dynamic-class-memaccess \
@@ -130,7 +130,7 @@
 	-D__pascal= -DMARS=1 -DTARGET_$(OS_UPCASE)=1 -DDM_TARGET_CPU_$(TARGET_CPU)=1 \
 	$(MODEL_FLAG)
 # GCC Specific
-ifeq ($(HOST_CC), g++)
+ifeq ($(HOST_CC), c++)
 CFLAGS := $(CFLAGS) \
     -std=gnu++98
 endif
@@ -312,7 +312,7 @@
 
 ifneq (,$(AUTO_BOOTSTRAP))
 $(HOST_DMD_PATH):
-	mkdir -p ${HOST_DMD_ROOT}
+	# mkdir -p ${HOST_DMD_ROOT}
 	TMPFILE=$$(mktemp deleteme.XXXXXXXX) && curl -fsSL ${HOST_DMD_URL} > $${TMPFILE}.zip && \
 		unzip -qd ${HOST_DMD_ROOT} $${TMPFILE}.zip && rm $${TMPFILE}.zip
 endif
@@ -423,7 +423,7 @@
 	$(eval bin_dir=$(if $(filter $(OS),osx), bin, bin$(MODEL)))
 	mkdir -p $(INSTALL_DIR)/$(OS)/$(bin_dir)
 	cp dmd $(INSTALL_DIR)/$(OS)/$(bin_dir)/dmd
-	cp ../ini/$(OS)/$(bin_dir)/dmd.conf $(INSTALL_DIR)/$(OS)/$(bin_dir)/dmd.conf
+	cp ../../$(OS)/$(bin_dir)/dmd.conf $(INSTALL_DIR)/$(OS)/$(bin_dir)/dmd.conf
 	cp backendlicense.txt $(INSTALL_DIR)/dmd-backendlicense.txt
 	cp boostlicense.txt $(INSTALL_DIR)/dmd-boostlicense.txt
 
