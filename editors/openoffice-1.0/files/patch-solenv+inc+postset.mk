--- solenv/inc/postset.mk.orig	Tue Jan  7 17:22:04 2003
+++ solenv/inc/postset.mk	Tue Feb 25 16:52:34 2003
@@ -220,6 +220,19 @@
 RCLANGFLAGS_07+= -d RUSS
 iso_07=ru
 
+.IF "$(RES_UKRA)"!="" || "$(give_me_all_languages)"!=""
+alllangext+=38
+ukra$(LANG_GUI)*=$(default$(LANG_GUI))
+cmd_ukra:=ukra 38 -lgUKRAINIAN $(IBM_PC_852) $(ukra$(LANG_GUI))
+lang_38=ukra
+longlang_38=ukrainian
+langext_38=38
+rsclang_38=-lgUKRAINIAN $(IBM_PC_852)
+rescharset_38=$(ukra$(LANG_GUI))
+RCLANGFLAGS_38+= -d UKRA
+iso_38=uk
+.ENDIF
+
 .IF "$(RES_POL)"!="" || "$(give_me_all_languages)"!=""
 alllangext+=48
 .ENDIF 
