--- ../svxlink-11.05.orig/svxlink/modules/tcl_voice_mail/ModuleTclVoiceMail.tcl	2010-12-05 09:34:33.000000000 -0800
+++ svxlink/modules/tcl_voice_mail/ModuleTclVoiceMail.tcl	2012-05-28 10:27:56.000000000 -0700
@@ -47,7 +47,7 @@
 #
 # Configuration file names
 #
-set cfg_etc "/etc/svxlink/TclVoiceMail.conf";
+set cfg_etc "%%LOCALBASE%%/etc/svxlink/TclVoiceMail.conf";
 set cfg_home "$env(HOME)/.svxlink/TclVoiceMail.conf";
 
 
