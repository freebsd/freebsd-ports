--- unix.mk.orig	1998-04-15 15:48:11 UTC
+++ unix.mk
@@ -13,7 +13,7 @@
 # solaris       Set environment variables for Sun with Solaris 2.X
 #		and gnu C/C++
 
-MAKE         = make
+#MAKE         = make
 DOS2UNIX     = ./dos2unix.sh
 SUBDIRS      = sources taste cplus2 taste_cp
 SUBDIRS2     = docs frames frames/cplus2 cplus2 samples
@@ -47,7 +47,7 @@ help:
 all1:
 		set -e; \
 		for i in $(SUBDIRS);\
-		do (cd $$i; $(MAKE) -f unix.mk)\
+		do (echo "===> $$i"; cd $$i; $(MAKE) -f unix.mk)\
 		done
 
 linux:		;$(MAKE) -f unix.mk CC=cc all1
