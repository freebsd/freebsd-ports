--- ghc.mk.orig	2017-01-03 15:59:18 UTC
+++ ghc.mk
@@ -96,6 +96,7 @@ endif
 # Catch make if it runs away into an infinite loop
 ifeq      "$(MAKE_RESTARTS)" ""
 else ifeq "$(MAKE_RESTARTS)" "1"
+else ifeq "$(MAKE_RESTARTS)" "2"
 else
 $(error Make has restarted itself $(MAKE_RESTARTS) times; is there a makefile bug? See http://ghc.haskell.org/trac/ghc/wiki/Building/Troubleshooting#Makehasrestarteditself3timesisthereamakefilebug for details)
 endif
@@ -459,10 +460,7 @@ PACKAGES_STAGE1 += ghc-boot-th
 PACKAGES_STAGE1 += ghc-boot
 PACKAGES_STAGE1 += template-haskell
 PACKAGES_STAGE1 += ghc-compact
-
-ifeq "$(HADDOCK_DOCS)" "YES"
 PACKAGES_STAGE1 += xhtml
-endif
 
 ifeq "$(WITH_TERMINFO)" "YES"
 PACKAGES_STAGE1 += terminfo
