--- src/grip.c.orig	Mon Jun 17 22:13:35 2002
+++ src/grip.c	Wed Jul 24 21:24:57 2002
@@ -61,6 +61,7 @@
 
 #define BASE_CFG_ENTRIES \
 {"cd_device",CFG_ENTRY_STRING,256,ginfo->cd_device},\
+{"force_scsi",CFG_ENTRY_STRING,256,ginfo->force_scsi},\
 {"ripexename",CFG_ENTRY_STRING,256,ginfo->ripexename},\
 {"ripcmdline",CFG_ENTRY_STRING,256,ginfo->ripcmdline},\
 {"wav_filter_cmd",CFG_ENTRY_STRING,256,ginfo->wav_filter_cmd},\
@@ -126,8 +127,7 @@
 {"disable_extra_paranoia",CFG_ENTRY_BOOL,0,&ginfo->disable_extra_paranoia},\
 {"disable_scratch_detect",CFG_ENTRY_BOOL,0,&ginfo->disable_scratch_detect},\
 {"disable_scratch_repair",CFG_ENTRY_BOOL,0,&ginfo->disable_scratch_repair},\
-{"calc_gain",CFG_ENTRY_BOOL,0,&ginfo->calc_gain},\
-{"force_scsi",CFG_ENTRY_STRING,256,ginfo->force_scsi},
+{"calc_gain",CFG_ENTRY_BOOL,0,&ginfo->calc_gain},
 
 #ifdef CDPAR
 #define CFG_ENTRIES BASE_CFG_ENTRIES CDPAR_CFG_ENTRIES
@@ -607,10 +607,11 @@
   ginfo->volume=255;
 #if defined(__FreeBSD__)
   ginfo->poll_drive=FALSE;
+  ginfo->poll_interval=15;
 #else
   ginfo->poll_drive=TRUE;
-#endif
   ginfo->poll_interval=1;
+#endif
 
   ginfo->changer_slots=0;
   ginfo->current_disc=0;
