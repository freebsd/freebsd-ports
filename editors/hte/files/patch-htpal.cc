$FreeBSD$

--- htpal.cc.orig	Fri Jun  7 22:17:48 2002
+++ htpal.cc	Fri Jun  7 22:18:26 2002
@@ -214,7 +214,7 @@
  *	CLASS palette_entry
  */
  
-palette_entry::palette_entry(UINT _idx=0, vcp _color=0)
+palette_entry::palette_entry(UINT _idx, vcp _color)
 {
 	idx=_idx;
 	color=_color;
