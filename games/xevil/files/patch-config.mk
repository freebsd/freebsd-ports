--- config.mk.orig	Sun Mar 23 00:08:58 2003
+++ config.mk	Fri Nov 24 15:44:19 2006
@@ -34,7 +34,7 @@
 # You can add -DNDEBUG to speed up a release build by removing the assert() 
 # calls.  But, on a really obscure Linux machine, this caused Xlib to blow up 
 # internally, so you do so at your own risk.
-DEBUG_OPT   =   -O #-DNDEBUG
+DEBUG_OPT   =   -DNDEBUG
 
 LINK_OPT    =	
 
@@ -83,7 +83,9 @@
 #### Attempt to guesss the host architecture using the HOSTYPE and hostype
 # variables.  Then call self with the architecture name.
 default:
-	@if [ $${HOSTTYPE-bob} != bob ] ; then \
+	@if [ $${OPSYS-bob} != bob ]; then \
+		archit=$$OPSYS ; \
+	elif [ $${HOSTTYPE-bob} != bob ] ; then \
 		archit=$$HOSTTYPE ; \
 	elif [ $${hosttype-bob} != bob ] ; then \
 		archit=$$hosttype ; \
@@ -161,9 +163,9 @@
 # The -DMSEC_PER_CLOCK=8 is kind of a hack, take it out if the game speed of 
 # XEvil is all screwed up.
 freebsd:
-	@$(MAKE) CC="c++" \
-CFLAGS="-DUSE_RANDOM -DPROTECTED_IS_PUBLIC -DMSEC_PER_CLOCK=8 -DUNAME_USR_BIN" \
-INCL_DIRS="-I/usr/X11R6/include" LIBS_DIRS="-L/usr/X11R6/lib" \
+	@$(MAKE) CC="${CXX}" \
+CFLAGS="-DUSE_RANDOM -DUSE_UINT_NET_LENGTH -DUNAME_USR_BIN ${CXXFLAGS}" \
+INCL_DIRS="-I$(LOCALBASE)/include" LIBS_DIRS="-L$(LOCALBASE)/lib" \
 OBJ_DIR=$(DEPTH)/x11/FREEBSD PCKG_NAME="freebsd" \
 LIBS="-lXpm -lX11 -lm" $(TARGETS)
 
