$FreeBSD$

--- stream.cc.orig	Fri Jun  7 22:30:45 2002
+++ stream.cc	Fri Jun  7 22:30:52 2002
@@ -611,7 +611,7 @@
  *	CLASS ht_memmap_file
  */
 
-void ht_memmap_file::init(byte *b, UINT s = 0)
+void ht_memmap_file::init(byte *b, UINT s)
 {
 	ht_streamfile::init();
 	buf = b;
