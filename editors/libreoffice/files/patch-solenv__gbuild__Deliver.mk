--- solenv/gbuild/Deliver.mk.orig	2013-05-02 11:55:29.000000000 -0400
+++ solenv/gbuild/Deliver.mk	2013-05-08 17:43:53.000000000 -0400
@@ -60,7 +60,7 @@
 endef
 
 define gb_Deliver__deliver
-$(if $(gb_Deliver_CLEARONDELIVER),rm -f $(2) &&) $(if $(gb_Deliver_HARDLINK),ln,cp -P -f) $(1) $(2) && touch $(if $(filter-out MACOSX,$(OS_FOR_BUILD)),--no-dereference) -r $(1) $(2)
+$(if $(gb_Deliver_CLEARONDELIVER),rm -f $(2) &&) $(if $(gb_Deliver_HARDLINK),ln,cp -P -f) $(1) $(2) && touch $(if $(filter-out FREEBSD NETBSD OPENBSD DRAGONFLY MACOSX,$(OS_FOR_BUILD)),--no-dereference) -r $(1) $(2)
 endef
 
 ifneq ($(strip $(gb_Deliver_GNUCOPY)),)
