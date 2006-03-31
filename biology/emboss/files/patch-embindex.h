--- nucleus/embindex.h.orig	Mon Jan 23 12:24:46 2006
+++ nucleus/embindex.h	Thu Dec 22 13:12:44 2005
@@ -16,6 +16,76 @@
 #define BTREE_DEF_CACHESIZE 100
 #define BTREE_DEF_PAGESIZE  2048
 
+/* @data EmbPBtreeEntry *******************************************************
+**
+** Index tree entries
+**
+** @alias EmbSBtreeEntry
+**
+** @attr do_id [AjBool] Undocumented
+** @attr do_accession [AjBool] Undocumented
+** @attr do_sv [AjBool] Undocumented
+** @attr do_description [AjBool] Undocumented
+** @attr do_keyword [AjBool] Undocumented
+** @attr do_taxonomy [AjBool] Undocumented
+** @attr dbname [AjPStr] Undocumented
+** @attr dbrs [AjPStr] Undocumented
+** @attr release [AjPStr] Undocumented
+** @attr date [AjPStr] Undocumented
+** @attr dbtype [AjPStr] Undocumented
+** @attr directory [AjPStr] Undocumented
+** @attr idirectory [AjPStr] Undocumented
+** @attr files [AjPList] Undocumented
+** @attr reffiles [AjPList] Undocumented
+** @attr nfiles [ajint] Undocumented
+** @attr cachesize [ajint] Undocumented
+** @attr pagesize [ajint] Undocumented
+** @attr idlen [ajint] Undocumented
+** @attr aclen [ajint] Undocumented
+** @attr svlen [ajint] Undocumented
+** @attr kwlen [ajint] Undocumented
+** @attr delen [ajint] Undocumented
+** @attr txlen [ajint] Undocumented
+** @attr idorder [ajint] Undocumented
+** @attr idfill [ajint] Undocumented
+** @attr idsecorder [ajint] Undocumented
+** @attr idsecfill [ajint] Undocumented
+** @attr acorder [ajint] Undocumented
+** @attr acfill [ajint] Undocumented
+** @attr acsecorder [ajint] Undocumented
+** @attr acsecfill [ajint] Undocumented
+** @attr svorder [ajint] Undocumented
+** @attr svfill [ajint] Undocumented
+** @attr svsecorder [ajint] Undocumented
+** @attr svsecfill [ajint] Undocumented
+** @attr kworder [ajint] Undocumented
+** @attr kwfill [ajint] Undocumented
+** @attr kwsecorder [ajint] Undocumented
+** @attr kwsecfill [ajint] Undocumented
+** @attr deorder [ajint] Undocumented
+** @attr defill [ajint] Undocumented
+** @attr desecorder [ajint] Undocumented
+** @attr desecfill [ajint] Undocumented
+** @attr txorder [ajint] Undocumented
+** @attr txfill [ajint] Undocumented
+** @attr txsecorder [ajint] Undocumented
+** @attr txsecfill [ajint] Undocumented
+** @attr idcache [AjPBtcache] Undocumented
+** @attr accache [AjPBtcache] Undocumented
+** @attr svcache [AjPBtcache] Undocumented
+** @attr kwcache [AjPBtcache] Undocumented
+** @attr decache [AjPBtcache] Undocumented
+** @attr txcache [AjPBtcache] Undocumented
+** @attr fpos [ajlong] Undocumented
+** @attr reffpos [ajlong] Undocumented
+** @attr id [AjPStr] Undocumented
+** @attr ac [AjPList] Undocumented
+** @attr sv [AjPList] Undocumented
+** @attr tx [AjPList] Undocumented
+** @attr kw [AjPList] Undocumented
+** @attr de [AjPList] Undocumented
+******************************************************************************/
+
 typedef struct EmbSBtreeEntry
 {
     AjBool do_id;
@@ -48,10 +118,16 @@
 
     ajint idorder;
     ajint idfill;
+    ajint idsecorder;
+    ajint idsecfill;
     ajint acorder;
     ajint acfill;
+    ajint acsecorder;
+    ajint acsecfill;
     ajint svorder;
     ajint svfill;
+    ajint svsecorder;
+    ajint svsecfill;
 
     ajint kworder;
     ajint kwfill;
