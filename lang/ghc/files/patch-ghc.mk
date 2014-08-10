--- ./ghc.mk.orig	2014-07-10 06:27:16.000000000 +0200
+++ ./ghc.mk	2014-07-11 10:28:11.000000000 +0200
@@ -96,6 +96,7 @@
 # Catch make if it runs away into an infinite loop
 ifeq      "$(MAKE_RESTARTS)" ""
 else ifeq "$(MAKE_RESTARTS)" "1"
+else ifeq "$(MAKE_RESTARTS)" "2"
 else
 $(error Make has restarted itself $(MAKE_RESTARTS) times; is there a makefile bug? See http://ghc.haskell.org/trac/ghc/wiki/Building/Troubleshooting#Makehasrestarteditself3timesisthereamakefilebug for details)
 endif
