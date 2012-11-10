--- unix.mk.orig	1998-04-16 00:48:11.000000000 +0900
+++ unix.mk	2012-07-09 16:52:30.000000000 +0900
@@ -13,7 +13,7 @@
 # solaris       Set environment variables for Sun with Solaris 2.X
 #		and gnu C/C++
 
-MAKE         = make
+#MAKE         = make
 DOS2UNIX     = ./dos2unix.sh
 SUBDIRS      = sources taste cplus2 taste_cp
 SUBDIRS2     = docs frames frames/cplus2 cplus2 samples
@@ -47,7 +47,7 @@
 all1:
 		set -e; \
 		for i in $(SUBDIRS);\
-		do (cd $$i; $(MAKE) -f unix.mk)\
+		do (echo "===> $$i"; cd $$i; $(MAKE) -f unix.mk)\
 		done
 
 linux:		;$(MAKE) -f unix.mk CC=cc all1
