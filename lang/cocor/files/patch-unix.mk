--- unix.mk.orig	Sun Mar 24 14:37:17 2002
+++ unix.mk	Sun Mar 24 14:37:47 2002
@@ -47,7 +47,7 @@
 all1:
 		set -e; \
 		for i in $(SUBDIRS);\
-		do (cd $$i; $(MAKE) -f unix.mk)\
+		do (echo "===> $$i"; cd $$i; $(MAKE) -f unix.mk)\
 		done
 
 linux:		;$(MAKE) -f unix.mk CC=cc all1
