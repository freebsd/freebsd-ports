$FreeBSD$

--- htformat.cc.orig	Fri Jun  7 22:03:32 2002
+++ htformat.cc	Fri Jun  7 22:03:41 2002
@@ -4234,7 +4234,7 @@
  *	CLASS ht_mask
  */
 
-void ht_mask_sub::init(ht_streamfile *f, UINT u, fmt_vaddress ba=0)
+void ht_mask_sub::init(ht_streamfile *f, UINT u, fmt_vaddress ba)
 {
 	ht_sub::init(f);
 	masks = new ht_string_list();
