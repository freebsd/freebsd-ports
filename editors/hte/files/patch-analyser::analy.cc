$FreeBSD$

--- analyser/analy.cc.orig	Fri Jun  7 21:53:04 2002
+++ analyser/analy.cc	Fri Jun  7 21:53:40 2002
@@ -415,7 +415,7 @@
 /*
  *	addaddrlabel will never overwrite an existing label (like addlabel)
  */
-bool analyser::add_addr_label(ADDR Addr, char *Prefix, labeltype type, taddr *infunc=NULL)
+bool analyser::add_addr_label(ADDR Addr, char *Prefix, labeltype type, taddr *infunc)
 {
 	if (!valid_addr(Addr, scvalid)) return false;
 
@@ -461,7 +461,7 @@
  *           fail if label exist on another address
  *
  */
-bool analyser::add_label(ADDR Addr, char *label, labeltype type, taddr *infunc=NULL)
+bool analyser::add_label(ADDR Addr, char *label, labeltype type, taddr *infunc)
 {
 	if (!valid_addr(Addr, scvalid)) return false;
 
@@ -545,7 +545,7 @@
 /*
  *
  */
-bool analyser::assign_label(ADDR Addr, char *label, labeltype type, taddr *infunc=NULL)
+bool analyser::assign_label(ADDR Addr, char *label, labeltype type, taddr *infunc)
 {
 	if (!valid_addr(Addr, scvalid)) return false;
 
