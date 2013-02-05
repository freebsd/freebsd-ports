--- ./rts/ghc.mk.orig		2012-06-06 19:10:25.000000000 +0200
+++ ./rts/ghc.mk		2013-01-30 16:40:21.000000000 +0100
@@ -105,8 +105,10 @@
 endif
 
 ifneq "$(BINDIST)" "YES"
+ifneq "$(UseSystemLibFFI)" "YES"
 rts_ffi_objs_stamp = rts/dist/ffi/stamp
 rts_ffi_objs       = rts/dist/ffi/*.o
+
 $(rts_ffi_objs_stamp): $(libffi_STATIC_LIB) $(TOUCH_DEP) | $$(dir $$@)/.
 	cd rts/dist/ffi && $(AR) x ../../../$(libffi_STATIC_LIB)
 	"$(TOUCH_CMD)" $@
@@ -119,6 +121,7 @@
 rts/dist/build/libffi-5.dll: libffi/build/inst/bin/libffi-5.dll
 	cp $< $@
 endif
+endif
 
 #-----------------------------------------------------------------------------
 # Building one way
@@ -169,6 +172,12 @@
 
 rts_dist_$1_CC_OPTS += -DRtsWay=\"rts_$1\"
 
+ifneq "$(UseSystemLibFFI)" "YES"
+rts_dist_FFI_SO = rts/dist/build/libffi$(soext)
+else
+rts_dist_FFI_SO =
+endif
+
 # Making a shared library for the RTS.
 ifneq "$$(findstring dyn, $1)" ""
 ifeq "$$(HOSTPLATFORM)" "i386-unknown-mingw32"
@@ -177,10 +186,15 @@
 	"$$(rts_dist_HC)" -package-name rts -shared -dynamic -dynload deploy \
 	  -no-auto-link-packages -Lrts/dist/build -lffi-5 `cat rts/libs.depend` $$(rts_$1_OBJS) $$(ALL_RTS_DEF_LIBS) -o $$@
 else
-$$(rts_$1_LIB) : $$(rts_$1_OBJS) $$(rts_$1_DTRACE_OBJS) rts/libs.depend rts/dist/build/libffi$$(soext)
+ifneq "$(UseSystemLibFFI)" "YES"
+ LIBFFI_LIBS= -Lrts/dist/build -lffi
+else
+ LIBFFI_LIBS= -L$(FFILibDir)
+endif
+$$(rts_$1_LIB) : $$(rts_$1_OBJS) $$(rts_$1_DTRACE_OBJS) rts/libs.depend $$(rts_dist_FFI_SO)
 	"$$(RM)" $$(RM_OPTS) $$@
 	"$$(rts_dist_HC)" -package-name rts -shared -dynamic -dynload deploy \
-	  -no-auto-link-packages -Lrts/dist/build -lffi `cat rts/libs.depend` $$(rts_$1_OBJS) \
+	  -no-auto-link-packages $$(LIBFFI_LIBS) `cat rts/libs.depend` $$(rts_$1_OBJS) \
 	  $$(rts_$1_DTRACE_OBJS) -o $$@
 ifeq "$$(darwin_HOST_OS)" "1"
 	# Ensure library's install name is correct before anyone links with it.
@@ -370,9 +384,14 @@
 endif
 
 # ffi.h triggers prototype warnings, so disable them here:
-rts/Interpreter_CC_OPTS += -Wno-strict-prototypes
-rts/Adjustor_CC_OPTS    += -Wno-strict-prototypes
-rts/sm/Storage_CC_OPTS  += -Wno-strict-prototypes
+ifeq "$(UseSystemLibFFI)" "YES"
+LIBFFI_CFLAGS = $(addprefix -I,$(FFIIncludeDir))
+else
+LIBFFI_CFLAGS =
+endif
+rts/Interpreter_CC_OPTS += -Wno-strict-prototypes $(LIBFFI_CFLAGS)
+rts/Adjustor_CC_OPTS    += -Wno-strict-prototypes $(LIBFFI_CFLAGS)
+rts/sm/Storage_CC_OPTS  += -Wno-strict-prototypes $(LIBFFI_CFLAGS)
 
 # inlining warnings happen in Compact
 rts/sm/Compact_CC_OPTS += -Wno-inline
@@ -430,6 +449,21 @@
 
 endif
 
+#-----------------------------------------------------------------------------
+# Use system provided libffi
+
+ifeq "$(UseSystemLibFFI)" "YES"
+
+rts_PACKAGE_CPP_OPTS    += -DFFI_INCLUDE_DIR=$(FFIIncludeDir)
+rts_PACKAGE_CPP_OPTS    += -DFFI_LIB_DIR=$(FFILibDir)
+
+else # UseSystemLibFFI==YES
+
+rts_PACKAGE_CPP_OPTS += -DFFI_INCLUDE_DIR=""
+rts_PACKAGE_CPP_OPTS += -DFFI_LIB_DIR=""
+
+endif
+
 # -----------------------------------------------------------------------------
 # dependencies
 
@@ -507,7 +541,11 @@
 INSTALL_LIBS += $(wildcard rts/dist/build/libffi$(soext)*)
 INSTALL_LIBS += $(wildcard rts/dist/build/libffi-5.dll)
 
+ifneq "$(UseSystemLibFFI)" "YES"
 install: install_libffi_headers
+else
+install:
+endif
 
 .PHONY: install_libffi_headers
 install_libffi_headers :
