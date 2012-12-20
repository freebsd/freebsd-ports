--- ghc.mk.orig	2012-06-06 18:10:25.000000000 +0100
+++ ghc.mk	2012-08-25 12:57:51.000000000 +0100
@@ -81,6 +81,7 @@
 # Catch make if it runs away into an infinite loop
 ifeq      "$(MAKE_RESTARTS)" ""
 else ifeq "$(MAKE_RESTARTS)" "1"
+else ifeq "$(MAKE_RESTARTS)" "2"
 else
 $(error Make has restarted itself $(MAKE_RESTARTS) times; is there a makefile bug?)
 endif
