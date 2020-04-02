--- cpp/build/support.mk.orig	2020-02-10 15:58:14 UTC
+++ cpp/build/support.mk
@@ -67,8 +67,8 @@ endif
 
 ifeq ($(GITVERSION),)
 $(warning  git describe returned an empty result, setting GITVERSION to VERSION_MAJ.VERSION_MIN.-1 and VERSION_REV to 0)
-GITVERSION	:= $(VERSION_MAJ).$(VERSION_MIN).-1
-VERSION_REV	:= 0
+GITVERSION	:= $(VERSION_MAJ).$(VERSION_MIN).$(VERSION_REV)
+#VERSION_REV	:= 0
 else
 VERSION_REV 	?= $(shell echo $(GITVERSION) | awk '{split($$0,a,"-"); print a[2]}')
 endif
