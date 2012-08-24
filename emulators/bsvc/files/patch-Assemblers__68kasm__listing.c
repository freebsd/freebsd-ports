--- ./Assemblers/68kasm/listing.c.orig	2012-08-24 12:25:01.061915000 +0200
+++ ./Assemblers/68kasm/listing.c	2012-08-24 12:32:19.960913679 +0200
@@ -108,6 +108,7 @@
 }
 
 
+void
 listObj(data, size)
 int data, size;
 {
