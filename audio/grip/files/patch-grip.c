--- grip.c.orig	Mon Jul 16 12:15:32 2001
+++ grip.c	Mon Jan 21 23:03:30 2002
@@ -54,6 +54,8 @@
 #include "parsecfg.h"
 #include "dialog/dialog.h"
 
+#define CDDB_USE_CANCEL 1
+
 #ifdef CDPAR
 #define size16 short
 #define size32 int
@@ -212,6 +214,8 @@
 
 GdkCursor *wait_cursor;
 
+int cddb_tmo = 30;
+
 int cd_desc;
 int changer_slots;
 int current_disc=0;
@@ -315,7 +319,7 @@
 gboolean use_proxy=FALSE;
 gboolean use_proxy_env=FALSE;
 
-char *bin_search_paths[]={"/cpd/misc/bin","/usr/bin","/usr/local/bin",NULL};
+char *bin_search_paths[]={"/cpd/misc/bin","/usr/bin","%%LOCALBASE%%/bin",NULL};
 Ripper ripper_defaults[]={
 #ifdef CDPAR
   {"grip (cdparanoia)",""},
@@ -328,7 +332,7 @@
 #endif
   {"other",""},
   {"",""}};
-char ripexename[256]="/usr/bin/cdparanoia";
+char ripexename[256]="%%LOCALBASE%%/bin/cdparanoia";
 char ripcmdline[256]="-d %c %t:[.%b]-%t:[.%e] %f";
 int selected_ripper=0;
 char outputdir[256];
@@ -347,7 +351,7 @@
 gboolean disable_extra_paranoia=FALSE;
 gboolean disable_scratch_detect=FALSE;
 gboolean disable_scratch_repair=FALSE;
-char mp3exename[256]="/usr/bin/bladeenc";
+char mp3exename[256]="%%LOCALBASE%%/bin/bladeenc";
 char mp3cmdline[256]="-%b -QUIT %f";
 int selected_encoder=1;
 char mp3fileformat[256]="~/mp3/%a/%d/%n.mp3";
@@ -450,7 +454,7 @@
   "Instrumental Rock", "Ethnic", "Gothic", "Darkwave", "Techno-Industrial",
   "Electronic", "Pop-Folk", "Eurodance", "Dream", "Southern Rock", "Comedy",
   "Cult", "Gangsta", "Top 40", "Christian Rap", "Pop/Funk", "Jungle",
-  "Native American", "Cabaret", "New Wave", "Psychadelic", "Rave", "Showtunes",
+  "Native American", "Cabaret", "New Wave", "Psychedelic", "Rave", "Showtunes",
   "Trailer", "Lo-Fi", "Tribal", "Acid Punk", "Acid Jazz", "Polka", "Retro",
   "Musical", "Rock & Roll", "Hard Rock", "Folk", "Folk/Rock", "National Folk",
   "Swing", "Fast Fusion", "Bebob", "Latin", "Revival", "Celtic", "Bluegrass",
@@ -1657,8 +1661,12 @@
   pthread_exit(&status);
 #elif defined(__FreeBSD__)
   pthread_kill(cddb_thread, 0);
+#elif defined(linux)
+#if CDDB_USE_CANCEL
+  pthread_cancel(cddb_thread);
 #else
-    pthread_kill_other_threads_np();
+  pthread_kill_other_threads_np();
+#endif
 #endif
     Debug("Aborted\n");
     looking_up=FALSE;
@@ -1722,6 +1730,7 @@
   int cddb_found = 0;
 
   if(!CDDBLookupDisc(&dbserver)) {
+    pthread_testcancel();
     if(*(dbserver2.name)) {
       if(CDDBLookupDisc(&dbserver2)) {
         cddb_found = 1;
@@ -1759,9 +1768,10 @@
   strncpy(hello.hello_program,PROGRAM,256);
   strncpy(hello.hello_version,VERSION,256);
 	
-  if(!CDDBDoQuery(cd_desc,server,&hello,&query)) {
+  if(!CDDBDoQuery(cd_desc,server,&hello,&query,cddb_tmo)) {
     update_required=TRUE;
   } else {
+    pthread_testcancel();
     switch(query.query_match) {
     case MATCH_INEXACT:
     case MATCH_EXACT:
@@ -1770,7 +1780,7 @@
 	     query.query_list[0].list_title);
       entry.entry_genre = query.query_list[0].list_genre;
       entry.entry_id = query.query_list[0].list_id;
-      CDDBRead(cd_desc,server,&hello,&entry,&ddata);
+      CDDBRead(cd_desc,server,&hello,&entry,&ddata,cddb_tmo);
 		
       Debug("Done\n");
       success=TRUE;
