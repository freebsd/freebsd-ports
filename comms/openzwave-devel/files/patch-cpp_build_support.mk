--- cpp/build/support.mk.orig	2019-08-26 02:51:02 UTC
+++ cpp/build/support.mk
@@ -46,8 +46,8 @@ VERSION_REV ?= 0
 else
 GITVERSION	:= $(shell $(GIT) --git-dir $(top_srcdir)/.git describe --long --tags --dirty 2>/dev/null | sed s/^v//)
 ifeq ($(GITVERSION),)
-GITVERSION	:= $(VERSION_MAJ).$(VERSION_MIN).-1
-VERSION_REV	:= 0
+GITVERSION	:= $(VERSION_MAJ).$(VERSION_MIN).$(VERSION_REV)
+#VERSION_REV	:= 0
 else
 VERSION_REV 	?= $(shell echo $(GITVERSION) | awk '{split($$0,a,"-"); print a[2]}')
 endif
