--- Makefile2.m4.orig	Thu Dec  7 21:26:31 2006
+++ Makefile2.m4	Thu Dec  7 21:26:45 2006
@@ -560,7 +560,7 @@
 	@echo '*********************************************************' 1>&2
 
 pv:	version.c
-	make -f Makefile pv
+	$(MAKE) -f Makefile pv
 
 ################
 MAKEFILE2=Makefile2
