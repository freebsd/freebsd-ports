--- ../instsetoo/util/makefile.mk.orig	Sat Apr 12 15:24:45 2003
+++ ../instsetoo/util/makefile.mk	Sat Apr 12 15:24:55 2003
@@ -87,9 +87,7 @@
 
 .IF "$(alllangext)"!=""
 
-#pack: $(foreach,i,$(alllangext) pack_$i)
-#temp mh only 49 and 01 for the moment
-pack: pack_01 pack_49
+pack: $(foreach,i,$(alllangext) pack_$i)
 
 pack_%:
 	+-$(MKDIRHIER) $(INSTALLDIR)$/$(@:s/pack_//)$/normal
