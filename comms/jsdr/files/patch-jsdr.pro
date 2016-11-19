--- jsdr.pro.orig	2016-11-18 22:17:37 UTC
+++ jsdr.pro
@@ -0,0 +1,8 @@
+TEMPLATE = subdirs
+
+SUBDIRS = make-x64/swreceiver \
+          make-x64/fmreceiver \
+          make-x64/spectrum-viewer \
+          make-x64/mini-receiver
+
+CONFIG += ordered 
