--- ./genAM.py.orig	2009-06-01 05:18:41.000000000 +0900
+++ ./genAM.py	2009-06-17 19:44:58.000000000 +0900
@@ -62,7 +62,7 @@
 ocropusincludedir=$(includedir)/ocropus
 
 AM_CPPFLAGS = -I$(srcdir)/include -I$(srcdir)/ocr-utils \
--I@iulibheaders@ -I@tessheaders@
+-I@iulibheaders@
 
 AM_LDFLAGS =
 
@@ -180,7 +180,7 @@
 print """
 # run check-style everytime and give a hint about make check
 all:
-	$(srcdir)/utilities/check-style -f $(srcdir)
+#	$(srcdir)/utilities/check-style -f $(srcdir)
 	@echo
 	@echo "Use 'make check' to run tests!"
 	@echo
