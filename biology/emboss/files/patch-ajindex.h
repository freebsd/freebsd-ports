--- ajax/ajindex.h.orig	Mon Jan 23 12:17:10 2006
+++ ajax/ajindex.h	Thu Dec 22 13:12:32 2005
@@ -67,6 +67,23 @@
 } AjOBtNode;
 #define AjPBtNode AjOBtNode*
 
+
+
+
+typedef struct AjSBtMem
+{
+    struct AjSBtMem *next;
+    struct AjSBtMem *prev;
+    AjPStr *karray;
+    ajlong *parray;
+    ajlong *overflows;
+    AjBool used;
+} AjOBtMem;
+#define AjPBtMem AjOBtMem*
+
+
+
+
 /* @data AjPBtId ***************************************************
 **
 ** Btree ID
@@ -137,6 +154,54 @@
 
 
 
+/* @data AjPBtNumId ***************************************************
+**
+** Btree ID
+**
+** @attr id [AjPStr] Unique ID
+** @attr dbno [ajint] Database file number
+** @attr dups [ajint] Duplicates
+** @attr offset [ajlong] Offset within database file (ftello)
+** @attr refoffset [ajlong] Offset within reference database file (ftello)
+******************************************************************************/
+
+typedef struct AjSBtNumId
+{
+    ajint  dbno;
+    ajlong offset;
+    ajlong refoffset;
+} AjOBtNumId;
+#define AjPBtNumId AjOBtNumId*
+
+
+
+
+/* @data AjPNumBucket ***************************************************
+**
+** Offset bucket structure on disc
+**
+** Key, filenumber, ftell ID, subkey page (char*, ajint, ajlong, ajlong)
+**
+** @attr NodeType [ajint] Node type
+** @attr Nentries [ajint] Number of entries
+** @attr Overflow [ajlong] Offset to overflow block
+** @attr offset [ajlong*] file offsets
+** @attr refoffset [ajlong*] ref file offsets
+** @attr offset [ajint*] database numbers
+******************************************************************************/
+
+typedef struct AjSNumBucket
+{
+    ajint    NodeType;
+    ajint    Nentries;
+    ajlong   Overflow;
+    AjPBtNumId *NumId;
+} AjONumBucket;
+#define AjPNumBucket AjONumBucket*
+
+
+
+
 /* Database file name structure
 **
 ** ajint        order			Order of B+tree
@@ -387,6 +452,10 @@
 ** @attr snperbucket [ajint] Undocumented
 ** @attr secrootblock [ajlong] secondary tree root block
 ** @attr kwlimit [ajint] Max length of secondary key
+** @attr bmem [AjPBtMem] primary memory allocation MRU bottom
+** @attr bsmem [AjPBtMem] secondary memory allocation MRU bottom
+** @attr tmem [AjPBtMem] primary memory allocation MRU top
+** @attr tsmem [AjPBtMem] secondary memory allocation MRU top
 ******************************************************************************/
 
 typedef struct AjSBtCache
@@ -409,6 +478,12 @@
     ajint snperbucket;
     ajlong secrootblock;
     ajint  kwlimit;
+
+    AjPBtMem bmem;
+    AjPBtMem tmem;
+    AjPBtMem bsmem;
+    AjPBtMem tsmem;
+
 } AjOBtcache;
 #define AjPBtcache AjOBtcache*
 
@@ -511,6 +586,32 @@
 
 
 
+/* @data AjPBtHybrid ***************************************************
+**
+** Btree ID
+**
+** @attr key1 [AjPStr] Unique ID
+** @attr dbno [ajint] Database file number
+** @attr dups [ajint] Duplicates
+** @attr offset [ajlong] Offset within database file (ftello)** @attr refoffset [ajlong] Offset within reference database file (ftello)
+** @attr refoffset [ajlong] Offset within reference database file (ftello)
+** @attr treeblock [ajlong] Secondary tree root page
+******************************************************************************/
+
+typedef struct AjSBtHybrid
+{
+    AjPStr key1;
+    ajint  dbno;
+    ajint  dups;
+    ajlong offset;
+    ajlong refoffset;
+    ajlong treeblock;
+} AjOBtHybrid;
+#define AjPBtHybrid AjOBtHybrid*
+
+
+
+
 AjPBtcache ajBtreeCacheNewC(const char *file, const char *ext,
 			    const char *idir, const char *mode,
 			    ajint pagesize, ajint order, ajint fill,
@@ -553,7 +654,8 @@
 AjBool     ajBtreeReplaceId(AjPBtcache cache, const AjPBtId rid);
 
 ajint      ajBtreeReadEntries(const char *filename, const char *indexdir,
-		   	      AjPStr **seqfiles, AjPStr **reffiles);
+			      const char *directory,
+			      AjPStr **seqfiles, AjPStr **reffiles);
 void       ajBtreeInsertDupId(AjPBtcache cache, AjPBtId id);
 AjPList    ajBtreeDupFromKey(AjPBtcache cache, const char *key);
 
@@ -580,6 +682,21 @@
 void       ajBtreeInsertKeyword(AjPBtcache cache, const AjPBtPri pri);
 
 void       ajBtreeLockTest(AjPBtcache cache);
+
+
+
+AjPBtpage   ajBtreeHybFindInsert(AjPBtcache cache, const char *key);
+AjPBtpage   ajBtreeNumFindInsert(AjPBtcache cache, const ajlong key);
+
+void        ajBtreeInsertNum(AjPBtcache cache, AjPBtNumId num, AjPBtpage page);
+void        ajBtreeHybInsertId(AjPBtcache cache, AjPBtHybrid hyb);
+AjPBtHybrid ajBtreeHybNew(void);
+void        ajBtreeHybDel(AjPBtHybrid *thys);
+void        ajBtreeFreePriArray(AjPBtcache cache);
+void        ajBtreeFreeSecArray(AjPBtcache cache);
+void 	    ajBtreeHybLeafList(AjPBtcache cache, ajlong rootblock,
+			       AjPStr idname, AjPList list);
+
 
 #endif
 
