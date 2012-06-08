
$FreeBSD$

--- ghc.mk.orig	2012-02-01 19:10:32.000000000 +0100
+++ ghc.mk	2012-06-08 17:39:40.000000000 +0200
@@ -81,6 +81,7 @@
 # Catch make if it runs away into an infinite loop
 ifeq      "$(MAKE_RESTARTS)" ""
 else ifeq "$(MAKE_RESTARTS)" "1"
+else ifeq "$(MAKE_RESTARTS)" "2"
 else
 $(error Make has restarted itself $(MAKE_RESTARTS) times; is there a makefile bug?)
 endif
@@ -377,6 +378,8 @@
     endif
 endef
 
+PACKAGES =
+
 define addPackage # args: $1 = package, $2 = condition
 ifneq "$(filter $1,$(PKGS_THAT_USE_TH)) $(GhcProfiled)" "$1 YES"
 ifeq "$(filter $1,$(PKGS_THAT_BUILD_WITH_STAGE2))" "$1"
