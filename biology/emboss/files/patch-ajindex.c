--- ajax/ajindex.c.orig	Mon Jan 23 12:17:02 2006
+++ ajax/ajindex.c	Thu Dec 22 13:12:27 2005
@@ -22,7 +22,6 @@
 
 
 
-
 static AjPBtpage  btreeCacheLocate(const AjPBtcache cache, ajlong page);
 static AjPBtpage  btreeCacheLruUnlink(AjPBtcache cache);
 static void       btreeCacheUnlink(AjPBtcache cache, AjPBtpage cpage);
@@ -35,10 +34,14 @@
 				    AjBool isread);
 static AjPBtpage  btreeFindINode(AjPBtcache cache, AjPBtpage page,
 				 const char *item);
+static AjPBtpage  btreeSecFindINode(AjPBtcache cache, AjPBtpage page,
+				    const char *item);
 
 
 static AjPBtpage  btreePageFromKey(AjPBtcache cache, unsigned char *buf,
 				   const char *item);
+static AjPBtpage  btreeSecPageFromKey(AjPBtcache cache, unsigned char *buf,
+				      const char *item);
 static ajint      btreeNumInBucket(AjPBtcache cache, ajlong pageno);
 static AjPBucket  btreeReadBucket(AjPBtcache cache, ajlong pageno);
 static void       btreeWriteBucket(AjPBtcache cache, const AjPBucket bucket,
@@ -55,6 +58,7 @@
 				 AjPStr const *keys, const ajlong *ptrs,
 				 ajint nkeys);
 static AjBool     btreeNodeIsFull(const AjPBtcache cache, AjPBtpage page);
+static AjBool     btreeNodeIsFullSec(const AjPBtcache cache, AjPBtpage page);
 static void       btreeInsertNonFull(AjPBtcache cache, AjPBtpage page,
 				     const AjPStr key, ajlong less,
 				     ajlong greater);
@@ -87,6 +91,8 @@
 
 
 
+
+
 #if 0
 static AjPBtpage  btreeTraverseLeaves(AjPBtcache cache, AjPBtpage thys);
 static void       btreeJoinLeaves(AjPBtcache cache);
@@ -168,6 +174,63 @@
 static ajint         btreeDbnoCompare(const void *a, const void *b);
 
 
+static AjPBtMem      btreeAllocPriArray(AjPBtcache cache);
+static void          btreeDeallocPriArray(AjPBtcache cache, AjPBtMem node);
+static AjPBtMem      btreeAllocSecArray(AjPBtcache cache);
+static void          btreeDeallocSecArray(AjPBtcache cache, AjPBtMem node);
+
+
+
+static void          btreeAddToHybBucket(AjPBtcache cache, ajlong pageno,
+					 const AjPBtHybrid id);
+static AjPBtpage     btreeHybFindINode(AjPBtcache cache, AjPBtpage page,
+				       const char *item);
+static AjPBtpage     btreeHybPageFromKey(AjPBtcache cache,
+					 unsigned char *buf, const char *key);
+static ajlong        btreeHybInsertShift(AjPBtcache cache, AjPBtpage *retpage,
+					 const char *key);
+static AjBool        btreeHybReorderBuckets(AjPBtcache cache, AjPBtpage leaf);
+static AjPBtpage     btreeHybSplitLeaf(AjPBtcache cache, AjPBtpage spage);
+static void          btreeHybInsertKey(AjPBtcache cache, AjPBtpage page,
+				       const AjPStr key, ajlong less,
+				       ajlong greater);
+static void          btreeHybSplitRoot(AjPBtcache cache);
+static void          btreeHybDupInsert(AjPBtcache cache, AjPBtHybrid hyb,
+				       AjPBtId btid);
+static void          btreeGetNumKeys(AjPBtcache cache, unsigned char *buf,
+				     ajlong **keys, ajlong **ptrs);
+static void          btreeWriteNumNode(AjPBtcache cache, AjPBtpage spage,
+				       const ajlong *keys, const ajlong *ptrs,
+				       ajint nkeys);
+static AjPNumBucket  btreeReadNumBucket(AjPBtcache cache, ajlong pageno);
+static void          btreeNumBucketDel(AjPNumBucket *thys);
+static void          btreeAddToNumBucket(AjPBtcache cache, ajlong pageno,
+					 const AjPBtNumId num);
+static AjPBtpage     btreeNumFindINode(AjPBtcache cache, AjPBtpage page,
+				       const ajlong item);
+static AjPBtpage     btreeNumPageFromKey(AjPBtcache cache, unsigned char *buf,
+					 const ajlong key);
+static ajint         btreeNumInNumBucket(AjPBtcache cache, ajlong pageno);
+static AjBool        btreeReorderNumBuckets(AjPBtcache cache, AjPBtpage leaf);
+static AjPNumBucket  btreeNumBucketNew(ajint n);
+static ajint         btreeNumIdCompare(const void *a, const void *b);
+static AjBool        btreeNumNodeIsFull(const AjPBtcache cache,
+					AjPBtpage page);
+static void          btreeNumInsertNonFull(AjPBtcache cache, AjPBtpage page,
+					   const ajlong key, ajlong less,
+					   ajlong greater);
+static void          btreeNumInsertKey(AjPBtcache cache, AjPBtpage page,
+				       const ajlong key, ajlong less,
+				       ajlong greater);
+static void          btreeNumSplitRoot(AjPBtcache cache);
+static void          btreeNumKeyShift(AjPBtcache cache, AjPBtpage tpage);
+static ajlong        btreeNumInsertShift(AjPBtcache cache, AjPBtpage *retpage,
+					 ajlong key);
+static AjPBtpage     btreeNumSplitLeaf(AjPBtcache cache, AjPBtpage spage);
+
+
+
+
 
 
 
@@ -196,11 +259,14 @@
 {
     FILE *fp;
     AjPBtcache cache = NULL;
+#if 0
 #if defined (HAVE64) && !defined(_OSF_SOURCE) && !defined(_AIX) && !defined(__hpux) && !defined(__ppc__) && !defined(__FreeBSD__)
     struct stat64 buf;
 #else
     struct stat buf;
 #endif
+#endif
+
     ajlong filelen = 0L;
 
     AjPStr fn = NULL;
@@ -213,12 +279,18 @@
 	return NULL;
 
 
+    /* Commented out pending database updating */
+#if 0
+    if(strcmp(mode,"r"))
+    {
 #if defined (HAVE64) && !defined(_OSF_SOURCE) && !defined(_AIX) && !defined(__hpux) && !defined(__ppc__) && !defined(__FreeBSD__)
-    if(!stat64(file, &buf))
+	if(!stat64(fn->Ptr, &buf))
 #else
-    if(!stat(file, &buf))
+	    if(!stat(fn->Ptr, &buf))
 #endif
-	filelen = buf.st_size;
+		filelen = buf.st_size;
+    }
+#endif    
 
     AJNEW0(cache);
 
@@ -244,6 +316,13 @@
     cache->totsize    = filelen;
     cache->cachesize  = cachesize;
 
+    cache->bmem = NULL;
+    cache->tmem = NULL;
+
+    cache->bsmem = NULL;
+    cache->tsmem = NULL;
+
+
     /* Add slevel, sorder and snperbucket ???? */
 
     ajStrDel(&fn);
@@ -808,7 +887,7 @@
     root = btreeCacheLocate(cache,0L);
 
     if(!root)
-	ajFatal("Something has unlocked the PRI root cache page\n");
+	ajFatal("The PRI root cache page has been unlocked\n");
     
     if(!cache->level)
 	return root;
@@ -863,6 +942,48 @@
 
 
 
+/* @funcstatic btreeSecFindINode *************************************************
+**
+** Recursive search for insert node in a secondary tree
+**
+** @param [u] cache [AjPBtcache] cache
+** @param [u] page [AjPBtpage] page
+** @param [r] item [const char*] key to search for 
+**
+** @return [AjPBtpage] leaf node where item should be inserted
+** @@
+******************************************************************************/
+
+static AjPBtpage btreeSecFindINode(AjPBtcache cache, AjPBtpage page,
+				 const char *item)
+{
+    AjPBtpage ret = NULL;
+    AjPBtpage pg  = NULL;
+
+    unsigned char *buf = NULL;
+    ajint status       = 0;
+    ajint ival         = 0;
+
+    /* ajDebug("In btreeSecFindINode\n"); */
+    
+    ret = page;
+    buf = page->buf;
+    GBT_NODETYPE(buf,&ival);
+    if(ival != BT_LEAF)
+    {
+	status = ret->dirty;
+	ret->dirty = BT_LOCK;	/* Lock in case of lots of overflow pages */
+	pg = btreeSecPageFromKey(cache,buf,item);
+	ret->dirty = status;
+	ret = btreeSecFindINode(cache,pg,item);
+    }
+    
+    return ret;
+}
+
+
+
+
 /* @funcstatic btreePageFromKey *******************************************
 **
 ** Return next lower index page given a key
@@ -928,6 +1049,71 @@
 
 
 
+/* @funcstatic btreeSecPageFromKey *******************************************
+**
+** Return next lower index page given a key in a secondary tree
+**
+** @param [u] cache [AjPBtcache] cache
+** @param [u] buf [unsigned char *] page buffer
+** @param [r] key [const char *] key to search for 
+**
+** @return [AjPBtpage] pointer to a page
+** @@
+******************************************************************************/
+
+static AjPBtpage btreeSecPageFromKey(AjPBtcache cache, unsigned char *buf,
+				     const char *key)
+{
+    unsigned char *rootbuf = NULL;
+    ajint nkeys = 0;
+    ajint order = 0;
+    ajint i;
+    
+    ajlong blockno = 0L;
+    AjPStr *karray = NULL;
+    ajlong *parray = NULL;
+    AjPBtpage page = NULL;
+    
+    /* ajDebug("In btreePageFromKey\n"); */
+    
+    rootbuf = buf;
+
+
+    GBT_NKEYS(rootbuf,&nkeys);
+    order = cache->sorder;
+
+    AJCNEW0(karray,order);
+    AJCNEW0(parray,order);
+    for(i=0;i<order;++i)
+	karray[i] = ajStrNew();
+
+    btreeGetKeys(cache,rootbuf,&karray,&parray);
+    i = 0;
+    while(i!=nkeys && strcmp(key,karray[i]->Ptr)>=0)
+	++i;
+    if(i==nkeys)
+    {
+	if(strcmp(key,karray[i-1]->Ptr)<0)
+	    blockno = parray[i-1];
+	else
+	    blockno = parray[i];
+    }
+    else
+	blockno = parray[i];
+
+    for(i=0;i<order;++i)
+	ajStrDel(&karray[i]);
+    AJFREE(karray);
+    AJFREE(parray);
+
+    page =  ajBtreeCacheRead(cache,blockno);
+
+    return page;
+}
+
+
+
+
 /* @func ajBtreeIdNew *********************************************
 **
 ** Constructor for index bucket ID informationn
@@ -1617,6 +1803,36 @@
 
 
 
+/* @funcstatic btreeNodeIsFullSec *****************************************
+**
+** Tests whether a secondary node is full of keys
+**
+** @param [r] cache [const AjPBtcache] cache
+** @param [u] page [AjPBtpage] original page
+**
+** @return [AjBool] true if full
+** @@
+******************************************************************************/
+
+static AjBool btreeNodeIsFullSec(const AjPBtcache cache, AjPBtpage page)
+{
+    unsigned char *buf = NULL;
+    ajint nkeys = 0;
+
+    /* ajDebug("In btreeNodeIsFull\n"); */
+
+    buf = page->buf;
+    GBT_NKEYS(buf,&nkeys);
+
+    if(nkeys == cache->sorder - 1)
+	return ajTrue;
+
+    return ajFalse;
+}
+
+
+
+
 /* @funcstatic btreeInsertNonFull *****************************************
 **
 ** Insert a key into a non-full node
@@ -2289,6 +2505,25 @@
 
 
 
+/* @funcstatic btreeNumIdCompare *******************************************
+**
+** Comparison function for ajListSort
+**
+** @param [r] a [const void*] ID 1
+** @param [r] b [const void*] ID 2
+**
+** @return [ajint] 0 = bases match
+** @@
+******************************************************************************/
+
+static ajint btreeNumIdCompare(const void *a, const void *b)
+{
+    return (*(AjPBtNumId*)a)->offset - (*(AjPBtNumId*)b)->offset;
+}
+
+
+
+
 /* @funcstatic btreeWriteNode *******************************************
 **
 ** Write an internal node
@@ -2999,8 +3234,7 @@
     rno = totalkeys - lno;
 
     maxnperbucket = nperbucket >> 1;
-    if(!maxnperbucket)
-	++maxnperbucket;
+    ++maxnperbucket;
 
     cbucket = btreeBucketNew(maxnperbucket);
 
@@ -5729,7 +5963,17 @@
     {
 	bentries = buckets[i]->Nentries;
 	for(j=0;j<bentries;++j)
-	    ajListPush(list,(void *)buckets[i]->Ids[j]);
+	{
+	    if(!buckets[i]->Ids[j]->dups)
+		ajListPush(list,(void *)buckets[i]->Ids[j]);
+	    else
+	    {
+		ajBtreeHybLeafList(cache,buckets[i]->Ids[j]->offset,
+				   buckets[i]->Ids[j]->id,list);
+		ajBtreeIdDel(&buckets[i]->Ids[j]);
+	    }
+	}
+	
 	AJFREE(buckets[i]->keylen);
 	AJFREE(buckets[i]->Ids);
 	AJFREE(buckets[i]);
@@ -6273,6 +6517,7 @@
 **
 ** @param [r] filename [const char*] file name
 ** @param [r] indexdir [const char*] index file directory
+** @param [r] directory [const char*] file directory
 ** @param [w] seqfiles [AjPStr**] sequence file names
 ** @param [w] reffiles [AjPStr**] reference file names (if any)
 
@@ -6282,6 +6527,7 @@
 ******************************************************************************/
 
 ajint ajBtreeReadEntries(const char *filename, const char *indexdir,
+			 const char *directory,
 			 AjPStr **seqfiles, AjPStr **reffiles)
 {
     AjPStr line = NULL;
@@ -6292,6 +6538,8 @@
 
     AjPStr seqname = NULL;
     AjPStr refname = NULL;
+    AjPStr tseqname = NULL;
+    AjPStr trefname = NULL;
     
     AjPFile inf   = NULL;
     char p;
@@ -6303,6 +6551,9 @@
     line    = ajStrNew();
     list    = ajListNew();
     reflist = ajListNew();
+
+    tseqname = ajStrNew();
+    trefname = ajStrNew();
     
     fn = ajStrNew();
     ajFmtPrintS(&fn,"%s/%s",indexdir,filename);
@@ -6329,7 +6580,8 @@
 	while(ajFileReadLine(inf, &line))
 	{
 	    seqname = ajStrNew();
-	    ajFmtScanS(line,"%S",&seqname);
+	    ajFmtScanS(line,"%S",&tseqname);
+	    ajFmtPrintS(&seqname,"%s/%S",directory,tseqname);
 	    ajListPushApp(list,(void *)seqname);
 	}
 
@@ -6342,7 +6594,9 @@
 	{
 	    seqname = ajStrNew();
 	    refname = ajStrNew();
-	    ajFmtScanS(line,"%S%S",&seqname,&refname);
+	    ajFmtScanS(line,"%S%S",&tseqname,&trefname);
+	    ajFmtPrintS(&seqname,"%s/%S",directory,tseqname);
+	    ajFmtPrintS(&refname,"%s/%S",directory,trefname);
 	    ajListPushApp(list,(void *)seqname);
 	    ajListPushApp(reflist,(void *)refname);
 	}
@@ -6357,6 +6611,11 @@
     ajListDel(&reflist);
     ajStrDel(&line);
     ajStrDel(&fn);
+
+    ajStrDel(&tseqname);
+    ajStrDel(&trefname);
+    
+
     ajFileClose(&inf);
 
     return entries;
@@ -6967,7 +7226,7 @@
 	pripage = btreeCacheLocate(cache,0L);
 	pripage->dirty = BT_LOCK;
 
-	ajDebug("Created secondary tree at block %d\n",(ajint)secrootpage);
+	/* ajDebug("Created 2ry tree at block %d\n",(ajint)secrootpage); */
     }
     else
     {
@@ -7776,8 +8035,7 @@
     rno = totalkeys - lno;
 
     maxnperbucket = nperbucket >> 1;
-    if(!maxnperbucket)
-	++maxnperbucket;
+    ++maxnperbucket;
 
     cbucket = btreePriBucketNew(maxnperbucket);
 
@@ -8230,11 +8488,13 @@
 {
     FILE *fp;
     AjPBtcache cache = NULL;
+#if 0
 #if defined (HAVE64) && !defined(_OSF_SOURCE) && !defined(_AIX) && !defined(__hpux) && !defined(__ppc__) && !defined(__FreeBSD__)
     struct stat64 buf;
 #else
     struct stat buf;
 #endif
+#endif
     ajlong filelen = 0L;
 
     AjPStr fn = NULL;
@@ -8246,13 +8506,18 @@
     if(!fp)
 	return NULL;
 
-
+    /* Commented out pending database updating */
+#if 0
+    if(strcmp(mode,"r"))
+    {
 #if defined (HAVE64) && !defined(_OSF_SOURCE) && !defined(_AIX) && !defined(__hpux) && !defined(__ppc__) && !defined(__FreeBSD__)
-    if(!stat64(file, &buf))
+	if(!stat64(fn->Ptr, &buf))
 #else
-    if(!stat(file, &buf))
+	    if(!stat(fn->Ptr, &buf))
+#endif
+		filelen = buf.st_size;
+    }
 #endif
-	filelen = buf.st_size;
 
     AJNEW0(cache);
 
@@ -8283,6 +8548,12 @@
     cache->snperbucket = sfill;
     cache->count = count;
     cache->kwlimit = kwlimit;
+
+    cache->bmem = NULL;
+    cache->tmem = NULL;
+
+    cache->bsmem = NULL;
+    cache->tsmem = NULL;
     
     ajStrDel(&fn);
     
@@ -8456,8 +8727,7 @@
     rno = totalkeys - lno;
 
     maxnperbucket = nperbucket >> 1;
-    if(!maxnperbucket)
-	++maxnperbucket;
+    ++maxnperbucket;
 
     cbucket = btreeSecBucketNew(maxnperbucket);
 
@@ -9070,7 +9340,7 @@
     if(!cache->slevel)
 	return root;
     
-    ret = btreeFindINode(cache,root,key);
+    ret = btreeSecFindINode(cache,root,key);
 
     return ret;
 }
@@ -9694,7 +9964,7 @@
     
     /* ajDebug("In btreeInsertKeySec\n"); */
 
-    if(!btreeNodeIsFull(cache,page))
+    if(!btreeNodeIsFullSec(cache,page))
     {
 	btreeInsertNonFullSec(cache,page,key,less,greater);
 	return;
@@ -10572,7 +10842,7 @@
 
     list = ajListNew();
 
-    order = cache->order;
+    order = cache->sorder;
 
     AJCNEW0(karray,order);
     AJCNEW0(parray,order);
@@ -11724,3 +11994,4580 @@
     return (*(AjPBtId*)a)->dbno -
 		  (*(AjPBtId*)b)->dbno;
 }
+
+
+
+
+
+
+
+
+/* @func ajBtreeHybNew *********************************************
+**
+** Constructor for index bucket ID informationn
+**
+**
+** @return [AjPBtHybrid] Index ID object
+** @@
+******************************************************************************/
+
+AjPBtHybrid ajBtreeHybNew(void)
+{
+    AjPBtHybrid Id = NULL;
+
+    /* ajDebug("In ajBtreeHybNew\n"); */
+
+    AJNEW0(Id);
+    Id->key1 = ajStrNew();
+    Id->dbno = 0;
+    Id->dups = 0;
+    Id->offset = 0L;
+    Id->refoffset = 0L;
+    Id->treeblock = 0L;    
+
+    return Id;
+}
+
+
+
+
+/* @func ajBtreeHybDel *********************************************
+**
+** Destructor for index bucket ID information
+**
+** @param [w] thys [AjPBtHybrid*] index ID object
+**
+** @return [void]
+** @@
+******************************************************************************/
+
+void ajBtreeHybDel(AjPBtHybrid *thys)
+{
+    AjPBtHybrid Id = NULL;
+
+    /* ajDebug("In ajBtreeIdDel\n"); */
+
+    if(!thys || !*thys)
+	return;
+    Id = *thys;
+    
+    ajStrDel(&Id->key1);
+    AJFREE(Id);
+    *thys = NULL;
+
+    return;
+}
+
+
+
+
+/* @funcstatic btreeAllocPriArray *******************************************
+**
+** Allocate karray and parray arrays for a primary key
+**
+** @param [rw] cache [AjPBtcache] cache
+**
+** @return [AjPBtMem] memory node
+** @@
+******************************************************************************/
+
+static AjPBtMem btreeAllocPriArray(AjPBtcache cache)
+{
+    AjPBtMem node = NULL;
+    ajint i;
+    ajint limit;
+    AjPBtMem p = NULL;
+
+    limit = cache->order;
+    if(!cache->bmem)
+    {
+        AJNEW0(node);
+        cache->bmem = node;
+        cache->tmem = node;
+        node->prev = NULL;
+        node->next = NULL;
+        node->used = ajTrue;
+        AJCNEW0(node->karray,limit);
+        AJCNEW0(node->parray,limit);
+        AJCNEW0(node->overflows,limit);
+        for(i=0;i<limit;++i)
+            node->karray[i] = ajStrNew();
+
+        return node;
+    }
+
+    if(!cache->bmem->used)
+    {
+        cache->bmem->used = ajTrue;
+
+        if(cache->bmem->next)
+        {
+            p = cache->bmem->next;
+
+            cache->tmem->next = cache->bmem;
+            cache->bmem->next = NULL;
+
+            cache->bmem->prev = cache->tmem;
+
+            cache->tmem = cache->bmem;
+
+            cache->bmem = p;
+            cache->bmem->prev = NULL;
+
+	    memset(cache->tmem->parray,0,sizeof(ajlong)*limit);
+	    
+	    return cache->tmem;
+        }
+
+	memset(cache->bmem->parray,0,sizeof(ajlong)*limit);
+	
+        return cache->bmem;
+    }
+
+
+    AJNEW0(node);
+    node->used = ajTrue;
+    node->next = NULL;
+    node->prev = cache->tmem;
+    cache->tmem->next = node;
+    cache->tmem = node;
+
+    AJCNEW0(node->karray,limit);
+    AJCNEW0(node->parray,limit);
+    AJCNEW0(node->overflows,limit);
+    for(i=0;i<limit;++i)
+        node->karray[i] = ajStrNew();
+
+    return node;
+}
+
+
+
+
+/* @funcstatic btreeDeallocPriArray *******************************************
+**
+** Deallocate karray and parray arrays for a primary key
+**
+** @param [rw] cache [AjPBtcache] cache
+** @param [rw] node [AjPBtMem] node
+**
+** @return [void]
+** @@
+******************************************************************************/
+
+static void btreeDeallocPriArray(AjPBtcache cache, AjPBtMem node)
+{
+    node->used = ajFalse;
+    if(!node->prev)
+        return;
+
+    node->prev->next = node->next;
+    if(node->next)
+        node->next->prev = node->prev;
+    else
+        cache->tmem = node->prev;
+
+    node->next = cache->bmem;
+    cache->bmem->prev = node;
+    cache->bmem = node;
+    node->prev = NULL;
+
+    return;
+}
+
+
+
+
+
+/* @funcstatic btreeAllocSecArray *******************************************
+**
+** Allocate karray and parray arrays for a primary key
+**
+** @param [rw] cache [AjPBtcache] cache
+**
+** @return [AjPBtMem] memory node
+** @@
+******************************************************************************/
+
+static AjPBtMem btreeAllocSecArray(AjPBtcache cache)
+{
+    AjPBtMem node = NULL;
+    ajint i;
+    ajint limit;
+    AjPBtMem p = NULL;
+
+    limit = cache->sorder;
+    if(!cache->bsmem)
+    {
+        AJNEW0(node);
+        cache->bsmem = node;
+        cache->tsmem = node;
+        node->prev = NULL;
+        node->next = NULL;
+        node->used = ajTrue;
+        AJCNEW0(node->karray,limit);
+        AJCNEW0(node->parray,limit);
+        AJCNEW0(node->overflows,limit);
+        for(i=0;i<limit;++i)
+            node->karray[i] = ajStrNew();
+
+        return node;
+    }
+
+    if(!cache->bsmem->used)
+    {
+        cache->bsmem->used = ajTrue;
+
+        if(cache->bsmem->next)
+        {
+            p = cache->bsmem->next;
+
+            cache->tsmem->next = cache->bsmem;
+            cache->bsmem->next = NULL;
+
+            cache->bsmem->prev = cache->tsmem;
+
+            cache->tsmem = cache->bsmem;
+
+            cache->bsmem = p;
+            cache->bsmem->prev = NULL;
+
+	    memset(cache->tsmem->parray,0,sizeof(ajlong)*limit);
+	    return cache->tsmem;
+        }
+
+	memset(cache->bsmem->parray,0,sizeof(ajlong)*limit);
+        return cache->bsmem;
+    }
+
+    AJNEW0(node);
+    node->used = ajTrue;
+    node->next = NULL;
+    node->prev = cache->tsmem;
+    cache->tsmem->next = node;
+    cache->tsmem = node;
+
+    AJCNEW0(node->karray,limit);
+    AJCNEW0(node->parray,limit);
+    AJCNEW0(node->overflows,limit);
+    for(i=0;i<limit;++i)
+        node->karray[i] = ajStrNew();
+
+    return node;
+}
+
+
+
+
+/* @funcstatic btreeDeallocSecArray *******************************************
+**
+** Deallocate karray and parray arrays for a primary key
+**
+** @param [rw] cache [AjPBtcache] cache
+** @param [rw] node [AjPBtMem] node
+**
+** @return [void]
+** @@
+******************************************************************************/
+
+static void btreeDeallocSecArray(AjPBtcache cache, AjPBtMem node)
+{
+    node->used = ajFalse;
+    if(!node->prev)
+        return;
+
+    node->prev->next = node->next;
+    if(node->next)
+        node->next->prev = node->prev;
+    else
+        cache->tsmem = node->prev;
+
+    node->next = cache->bsmem;
+    cache->bsmem->prev = node;
+    cache->bsmem = node;
+    node->prev = NULL;
+
+    return;
+}
+
+
+
+
+/* @funcstatic btreeAddToHybBucket *******************************************
+**
+** Add an ID to a bucket
+** Only called if there is room in the bucket
+**
+** @param [u] cache [AjPBtcache] cache
+** @param [r] pageno [ajlong] page number of bucket
+** @param [r] id [const AjPBtId] ID info
+**
+** @return [void]
+** @@
+******************************************************************************/
+
+static void btreeAddToHybBucket(AjPBtcache cache, ajlong pageno,
+				const AjPBtHybrid hyb)
+{
+    AjPBucket bucket = NULL;
+    AjPBtId   destid = NULL;
+    
+    ajint nentries;
+    
+    /* ajDebug("In btreeAddToHybBucket\n"); */
+
+    bucket   = btreeReadBucket(cache,pageno);
+    nentries = bucket->Nentries;
+
+
+    /* Reading a bucket always gives one extra ID position */
+    bucket->Ids[nentries] = ajBtreeIdNew();
+    destid = bucket->Ids[nentries];
+
+    ajStrAssS(&destid->id,hyb->key1);
+    destid->dbno      = hyb->dbno;
+    destid->offset    = hyb->offset;
+    destid->refoffset = hyb->refoffset;
+    destid->dups      = hyb->dups;
+    
+    ++bucket->Nentries;
+
+    btreeWriteBucket(cache,bucket,pageno);
+
+    btreeBucketDel(&bucket);
+    
+    return;
+}
+
+
+
+
+/* @func ajBtreeHybFindInsert ***********************************************
+**
+** Find the node that should contain a new key for insertion
+**
+** @param [u] cache [AjPBtcache] cache
+** @param [r] key [const char*] key to search for 
+**
+** @return [AjPBtpage] leaf node where item should be inserted
+** @@
+******************************************************************************/
+
+AjPBtpage ajBtreeHybFindInsert(AjPBtcache cache, const char *key)
+{
+    AjPBtpage root = NULL;
+    AjPBtpage ret  = NULL;
+
+    /* ajDebug("In ajBtreeHybFindInsert\n"); */
+
+    /* The root node should always be in the cache (BT_LOCKed) */
+    root = btreeCacheLocate(cache,0L);
+
+    if(!root)
+	ajFatal("The PRI root cache page has been unlocked\n");
+    
+    if(!cache->level)
+	return root;
+    
+    ret = btreeHybFindINode(cache,root,key);
+    
+    return ret;
+}
+
+
+
+
+/* @funcstatic btreeHybFindINode *********************************************
+**
+** Recursive search for insert node
+**
+** @param [u] cache [AjPBtcache] cache
+** @param [u] page [AjPBtpage] page
+** @param [r] item [const char*] key to search for 
+**
+** @return [AjPBtpage] leaf node where item should be inserted
+** @@
+******************************************************************************/
+
+static AjPBtpage btreeHybFindINode(AjPBtcache cache, AjPBtpage page,
+				 const char *item)
+{
+    AjPBtpage ret = NULL;
+    AjPBtpage pg  = NULL;
+
+    unsigned char *buf = NULL;
+    ajint status       = 0;
+    ajint ival         = 0;
+
+    /* ajDebug("In btreeHybFindINode\n"); */
+    
+    ret = page;
+    buf = page->buf;
+    GBT_NODETYPE(buf,&ival);
+    if(ival != BT_LEAF)
+    {
+	status = ret->dirty;
+	ret->dirty = BT_LOCK;	/* Lock in case of lots of overflow pages */
+	pg = btreeHybPageFromKey(cache,buf,item);
+	ret->dirty = status;
+	ret = btreeHybFindINode(cache,pg,item);
+    }
+    
+    return ret;
+}
+
+
+
+
+/* @funcstatic btreeHybPageFromKey *******************************************
+**
+** Return next lower index page given a key
+**
+** @param [u] cache [AjPBtcache] cache
+** @param [u] buf [unsigned char *] page buffer
+** @param [r] key [const char *] key to search for 
+**
+** @return [AjPBtpage] pointer to a page
+** @@
+******************************************************************************/
+
+static AjPBtpage btreeHybPageFromKey(AjPBtcache cache, unsigned char *buf,
+				     const char *key)
+{
+    unsigned char *rootbuf = NULL;
+    ajint nkeys = 0;
+    ajint order = 0;
+    ajint i;
+    
+    ajlong blockno = 0L;
+    AjPStr *karray = NULL;
+    ajlong *parray = NULL;
+    AjPBtpage page = NULL;
+    AjPBtMem arrays = NULL;
+    
+    /* ajDebug("In btreeHybPageFromKey\n"); */
+    
+    rootbuf = buf;
+
+
+    GBT_NKEYS(rootbuf,&nkeys);
+    order = cache->order;
+
+    arrays = btreeAllocPriArray(cache);
+    karray = arrays->karray;
+    parray = arrays->parray;
+
+    btreeGetKeys(cache,rootbuf,&karray,&parray);
+    i = 0;
+    while(i!=nkeys && strcmp(key,karray[i]->Ptr)>=0)
+	++i;
+    if(i==nkeys)
+    {
+	if(strcmp(key,karray[i-1]->Ptr)<0)
+	    blockno = parray[i-1];
+	else
+	    blockno = parray[i];
+    }
+    else
+	blockno = parray[i];
+
+    btreeDeallocPriArray(cache,arrays);
+
+    page =  ajBtreeCacheRead(cache,blockno);
+
+    return page;
+}
+
+
+
+
+/* @funcstatic btreeHybInsertShift ********************************************
+**
+** Rebalance buckets on insertion
+**
+** @param [u] cache [AjPBtcache] cache
+** @param [u] retpage [AjPBtpage*] page
+** @param [r] key [const char *] key
+**
+** @return [ajlong] bucket block or 0L if shift not posible 
+** @@
+******************************************************************************/
+
+static ajlong btreeHybInsertShift(AjPBtcache cache, AjPBtpage *retpage,
+				  const char *key)
+{
+    unsigned char *tbuf = NULL;
+    unsigned char *pbuf = NULL;
+    unsigned char *sbuf = NULL;
+
+    AjPBtpage ppage = NULL;
+    AjPBtpage spage = NULL;
+    AjPBtpage tpage = NULL;
+
+    ajint tkeys = 0;
+    ajint pkeys = 0;
+    ajint skeys = 0;
+    ajint order = 0;
+    
+    ajint i;
+    ajint n;
+    
+    ajlong parent  = 0L;
+    ajlong blockno = 0L;
+    
+    AjPStr *kTarray = NULL;
+    AjPStr *kParray = NULL;
+    AjPStr *kSarray = NULL;
+    ajlong *pTarray = NULL;
+    ajlong *pParray = NULL;
+    ajlong *pSarray = NULL;
+
+    AjPStr *karray = NULL;
+    ajlong *parray = NULL;
+
+    ajint ppos    = 0;
+    ajint pkeypos = 0;
+    ajint minsize = 0;
+
+    AjPBtMem arrays1 = NULL;
+    AjPBtMem arrays2 = NULL;
+    AjPBtMem arrays3 = NULL;
+    
+    /* ajDebug("In btreeHybInsertShift\n"); */
+
+
+    tpage = *retpage;
+
+    tbuf = tpage->buf;
+
+    GBT_PREV(tbuf,&parent);
+    GBT_NKEYS(tbuf,&tkeys);
+
+    order = cache->order;
+    minsize = order / 2;
+    if(order % 2)
+	++minsize;
+
+    if(tkeys <= minsize)
+	return 0L;
+
+    ppage = ajBtreeCacheRead(cache,parent);
+    
+    pbuf = ppage->buf;
+    GBT_NKEYS(pbuf,&pkeys);
+    
+
+    arrays1 = btreeAllocPriArray(cache);
+    kParray = arrays1->karray;
+    pParray = arrays1->parray;
+
+    arrays2 = btreeAllocPriArray(cache);
+    kSarray = arrays2->karray;
+    pSarray = arrays2->parray;
+
+    arrays3 = btreeAllocPriArray(cache);
+    kTarray = arrays3->karray;
+    pTarray = arrays3->parray;
+    
+
+    btreeGetKeys(cache,pbuf,&kParray,&pParray);
+
+    i=0;
+    while(i!=pkeys && strcmp(key,kParray[i]->Ptr)>=0)
+	++i;
+    pkeypos = i;
+    
+    if(i==pkeys)
+    {
+	if(strcmp(key,kParray[i-1]->Ptr)<0)
+	    ppos = i-1;
+	else
+	    ppos = i;
+    }
+    else
+	ppos = i;
+
+    
+    if(ppos) /* There is another leaf to the left */
+    {
+	spage = ajBtreeCacheRead(cache,pParray[ppos-1]);
+	sbuf = spage->buf;
+	GBT_NKEYS(sbuf,&skeys);
+    }
+
+    if(i && skeys != order-1) /* There is space in the left leaf */
+    {
+	/* ajDebug("Left shift\n"); */
+	btreeGetKeys(cache,tbuf,&kTarray,&pTarray);
+	if(skeys)
+	    btreeGetKeys(cache,sbuf,&kSarray,&pSarray);
+
+	i = 0;
+	while(pParray[i] != tpage->pageno)
+	    ++i;
+	--i;
+
+	pkeypos = i;
+
+	ajStrAssS(&kSarray[skeys],kParray[pkeypos]);
+	pSarray[skeys+1] = pTarray[0];
+	++skeys;
+	--tkeys;
+	ajStrAssS(&kParray[pkeypos],kTarray[0]);
+	for(i=0;i<tkeys;++i)
+	{
+	    ajStrAssS(&kTarray[i],kTarray[i+1]);
+	    pTarray[i] = pTarray[i+1];
+	}
+	pTarray[i] = pTarray[i+1];
+	pTarray[i+1] = 0L;
+	
+	btreeWriteNode(cache,spage,kSarray,pSarray,skeys);
+	btreeWriteNode(cache,tpage,kTarray,pTarray,tkeys);
+	btreeWriteNode(cache,ppage,kParray,pParray,pkeys);
+	if(!ppage->pageno)
+	    ppage->dirty = BT_LOCK;
+
+	i = 0;
+	while(i!=pkeys && strcmp(key,kParray[i]->Ptr)>=0)
+	    ++i;
+	if(i==pkeys)
+	{
+	    if(strcmp(key,kParray[i-1]->Ptr)<0)
+		blockno = pParray[i-1];
+	    else
+		blockno = pParray[i];
+	}
+	else
+	    blockno = pParray[i];
+
+	if(blockno == spage->pageno)
+	{
+	    *retpage = spage;
+	    karray = kSarray;
+	    parray = pSarray;
+	    n = skeys;
+	}
+	else
+	{
+	    karray = kTarray;
+	    parray = pTarray;
+	    n = tkeys;
+	}
+	
+
+	i = 0;
+	while(i!=n && strcmp(key,karray[i]->Ptr)>=0)
+	    ++i;
+	if(i==n)
+	{
+	    if(strcmp(key,karray[i-1]->Ptr)<0)
+		blockno = parray[i-1];
+	    else
+		blockno = parray[i];
+	}
+	else
+	    blockno = parray[i];
+
+	btreeDeallocPriArray(cache,arrays1);
+	btreeDeallocPriArray(cache,arrays2);
+	btreeDeallocPriArray(cache,arrays3);
+
+	/* ajDebug("... returns blockno (a) %Ld\n",blockno); */
+
+	return blockno;
+    }
+    
+
+    if(ppos != pkeys)	/* There is a right node */
+    {
+	spage = ajBtreeCacheRead(cache,pParray[ppos+1]);
+	sbuf = spage->buf;
+	GBT_NKEYS(sbuf,&skeys);
+    }
+
+
+    /* Space in the right leaf */
+    if(ppos != pkeys && skeys != order-1)
+    {
+	/* ajDebug("Right shift\n"); */
+	btreeGetKeys(cache,tbuf,&kTarray,&pTarray);
+	btreeGetKeys(cache,sbuf,&kSarray,&pSarray);
+
+	i = 0;
+	while(pParray[i] != tpage->pageno)
+	    ++i;
+	pkeypos = i;
+	
+	pSarray[skeys+1] = pSarray[skeys];
+	for(i=skeys-1;i>-1;--i)
+	{
+	    ajStrAssS(&kSarray[i+1],kSarray[i]);
+	    pSarray[i+1] = pSarray[i];
+	}
+	ajStrAssS(&kSarray[0],kParray[pkeypos]);
+	pSarray[0] = pTarray[tkeys];
+	ajStrAssS(&kParray[pkeypos],kTarray[tkeys-1]);
+	++skeys;
+	--tkeys;
+	pTarray[tkeys+1] = 0L;
+	
+	btreeWriteNode(cache,spage,kSarray,pSarray,skeys);
+	btreeWriteNode(cache,tpage,kTarray,pTarray,tkeys);
+	btreeWriteNode(cache,ppage,kParray,pParray,pkeys);
+	if(!ppage->pageno)
+	    ppage->dirty = BT_LOCK;
+
+	i = 0;
+	while(i!=pkeys && strcmp(key,kParray[i]->Ptr)>=0)
+	    ++i;
+	if(i==pkeys)
+	{
+	    if(strcmp(key,kParray[i-1]->Ptr)<0)
+		blockno = pParray[i-1];
+	    else
+		blockno = pParray[i];
+	}
+	else
+	    blockno = pParray[i];
+
+	if(blockno == spage->pageno)
+	{
+	    *retpage = spage;
+	    karray = kSarray;
+	    parray = pSarray;
+	    n = skeys;
+	}
+	else
+	{
+	    karray = kTarray;
+	    parray = pTarray;
+	    n = tkeys;
+	}
+	
+	i = 0;
+	while(i!=n && strcmp(key,karray[i]->Ptr)>=0)
+	    ++i;
+	if(i==n)
+	{
+	    if(strcmp(key,karray[i-1]->Ptr)<0)
+		blockno = parray[i-1];
+	    else
+		blockno = parray[i];
+	}
+	else
+	    blockno = parray[i];
+
+	btreeDeallocPriArray(cache,arrays1);
+	btreeDeallocPriArray(cache,arrays2);
+	btreeDeallocPriArray(cache,arrays3);
+
+	/* ajDebug("... returns blockno (b) %Ld\n",blockno); */
+	
+	return blockno;
+    }
+
+
+    btreeDeallocPriArray(cache,arrays1);
+    btreeDeallocPriArray(cache,arrays2);
+    btreeDeallocPriArray(cache,arrays3);
+
+    /* ajDebug("... returns 0L\n"); */
+
+    return 0L;
+}
+
+
+
+
+/* @funcstatic btreeHybReorderBuckets *****************************************
+**
+** Re-order leaf buckets
+** Must only be called if one of the buckets is full
+**
+** @param [u] cache [AjPBtcache] cache
+** @param [u] leaf [AjPBtpage] leaf page
+**
+** @return [AjBool] true if reorder was successful i.e. leaf not full
+** @@
+******************************************************************************/
+
+static AjBool btreeHybReorderBuckets(AjPBtcache cache, AjPBtpage leaf)
+{
+    ajint nkeys = 0;
+    unsigned char *lbuf = NULL;
+    AjPBucket *buckets  = NULL;
+    AjPStr *keys        = NULL;
+    ajlong *ptrs        = NULL;
+    ajlong *overflows   = NULL;
+    AjPBtMem arrays     = NULL;
+
+    ajint i = 0;
+    ajint j = 0;
+    
+    ajint order;
+    ajint bentries      = 0;
+    ajint totalkeys     = 0;
+    ajint nperbucket    = 0;
+    ajint maxnperbucket = 0;
+    ajint count         = 0;
+    ajint totkeylen     = 0;
+    ajint keylimit      = 0;
+    ajint bucketn       = 0;
+    ajint bucketlimit   = 0;
+    ajint nodetype      = 0;
+    
+    AjPList idlist    = NULL;
+    ajint   dirtysave = 0;
+    AjPBtId bid       = NULL;
+    AjPBucket cbucket = NULL;
+    AjPBtId cid       = NULL;
+
+    ajint   v = 0;
+    
+    /* ajDebug("In btreeHybReorderBuckets\n"); */
+
+    dirtysave = leaf->dirty;
+
+    leaf->dirty = BT_LOCK;
+    lbuf = leaf->buf;
+
+    GBT_NODETYPE(lbuf,&nodetype);
+
+    order = cache->order;
+    nperbucket = cache->nperbucket;
+    
+
+    /* Read keys/ptrs */
+    arrays    = btreeAllocPriArray(cache);
+    keys      = arrays->karray;
+    ptrs      = arrays->parray;
+    overflows = arrays->overflows;
+
+    btreeGetKeys(cache,lbuf,&keys,&ptrs);
+
+    GBT_NKEYS(lbuf,&nkeys);
+
+
+    if(!nkeys)
+	ajFatal("BucketReorder: Attempt to reorder empty leaf");
+
+    for(i=0;i<nkeys;++i)
+	totalkeys += btreeNumInBucket(cache,ptrs[i]);
+    totalkeys += btreeNumInBucket(cache,ptrs[i]);
+
+    /* Set the number of entries per bucket to approximately half full */
+    maxnperbucket = nperbucket >> 1;
+
+    if(!maxnperbucket)
+	++maxnperbucket;
+
+    /* Work out the number of new buckets needed */
+    bucketn = (totalkeys / maxnperbucket);
+    if(totalkeys % maxnperbucket)
+	++bucketn;
+    
+    if(bucketn > order)
+    {
+	btreeDeallocPriArray(cache,arrays);
+
+	leaf->dirty = dirtysave;
+	return ajFalse;
+    }
+    
+
+    /* Read buckets */
+    AJCNEW0(buckets,nkeys+1);
+    keylimit = nkeys + 1;
+    
+    for(i=0;i<keylimit;++i)
+	buckets[i] = btreeReadBucket(cache,ptrs[i]);
+
+
+    /* Read IDs from all buckets and push to list and sort (increasing id) */
+    idlist  = ajListNew();
+    
+    for(i=0;i<keylimit;++i)
+    {
+	overflows[i] = buckets[i]->Overflow;
+	bentries = buckets[i]->Nentries;
+	for(j=0;j<bentries;++j)
+	    ajListPush(idlist,(void *)buckets[i]->Ids[j]);
+	
+	AJFREE(buckets[i]->keylen);
+	AJFREE(buckets[i]->Ids);
+	AJFREE(buckets[i]);
+    }
+    ajListSort(idlist,btreeIdCompare);
+    AJFREE(buckets);
+
+    cbucket = btreeBucketNew(maxnperbucket);
+    bucketlimit = bucketn - 1;
+    
+    for(i=0;i<bucketlimit;++i)
+    {
+	cbucket->Overflow = overflows[i];
+	cbucket->Nentries = 0;
+
+	count = 0;
+	while(count!=maxnperbucket)
+	{
+	    ajListPop(idlist,(void **)&bid);
+	    
+	    cid = cbucket->Ids[count];
+	    ajStrAssS(&cid->id,bid->id);
+	    cid->dbno = bid->dbno;
+	    cid->dups = bid->dups;
+	    cid->offset = bid->offset;
+	    cid->refoffset = bid->refoffset;
+	    
+	    cbucket->keylen[count] = BT_BUCKIDLEN(bid->id);
+	    ++cbucket->Nentries;
+	    ++count;
+	    ajBtreeIdDel(&bid);
+	}
+
+
+	ajListPeek(idlist,(void **)&bid);
+	ajStrAssS(&keys[i],bid->id);
+
+	totkeylen += ajStrLen(bid->id);
+
+	if(!ptrs[i])
+	    ptrs[i] = cache->totsize;
+	btreeWriteBucket(cache,cbucket,ptrs[i]);
+    }
+
+
+    /* Deal with greater-than bucket */
+
+    cbucket->Overflow = overflows[i];
+    cbucket->Nentries = 0;
+
+    count = 0;
+    while(ajListPop(idlist,(void **)&bid))
+    {
+	cid = cbucket->Ids[count];
+	ajStrAssS(&cid->id,bid->id);
+	cid->dbno = bid->dbno;
+	cid->dups = bid->dups;
+	cid->offset = bid->offset;
+	cid->refoffset = bid->refoffset;
+	
+	++cbucket->Nentries;
+	++count;
+	ajBtreeIdDel(&bid);
+    }
+    
+    
+    if(!ptrs[i])
+	ptrs[i] = cache->totsize;
+    btreeWriteBucket(cache,cbucket,ptrs[i]);
+
+    cbucket->Nentries = maxnperbucket;
+    btreeBucketDel(&cbucket);
+
+    /* Now write out a modified leaf with new keys/ptrs */
+
+    nkeys = bucketn - 1;
+    v = nkeys;
+    SBT_NKEYS(lbuf,v);
+    v = totkeylen;
+    SBT_TOTLEN(lbuf,v);
+
+    btreeWriteNode(cache,leaf,keys,ptrs,nkeys);
+
+    leaf->dirty = BT_DIRTY;
+    if(nodetype == BT_ROOT)
+	leaf->dirty = BT_LOCK;
+
+    btreeDeallocPriArray(cache,arrays);
+    
+    btreeBucketDel(&cbucket);
+    ajListDel(&idlist);
+
+    return ajTrue;
+}
+
+
+
+
+/* @funcstatic btreeHybSplitLeaf *********************************************
+**
+** Split a leaf and propagate up if necessary
+**
+** @param [u] cache [AjPBtcache] cache
+** @param [u] spage [AjPBtpage] page
+**
+** @return [AjPBtpage] pointer to a parent page
+** @@
+******************************************************************************/
+
+static AjPBtpage btreeHybSplitLeaf(AjPBtcache cache, AjPBtpage spage)
+{
+    ajint nkeys     = 0;
+    ajint order     = 0;
+    ajint totalkeys = 0;
+    ajint bentries  = 0;
+    ajint keylimit  = 0;
+    ajint nodetype  = 0;
+
+    ajint rootnodetype  = 0;
+    
+    ajint i;
+    ajint j;
+    
+    AjPBtpage lpage = NULL;
+    AjPBtpage rpage = NULL;
+    AjPBtpage page  = NULL;
+    
+    AjPStr mediankey  = NULL;
+    ajlong mediangtr  = 0L;
+    ajlong medianless = 0L;
+    
+
+    AjPBtId bid = NULL;
+    AjPBtId cid = NULL;
+
+    unsigned char *buf  = NULL;
+    unsigned char *lbuf = NULL;
+    unsigned char *rbuf = NULL;
+
+    AjPList idlist = NULL;
+
+    AjPBucket *buckets = NULL;
+    AjPBucket cbucket  = NULL;
+    
+    AjPStr *karray = NULL;
+    ajlong *parray = NULL;
+    AjPBtMem arrays     = NULL;
+    
+    ajint keypos = 0;
+    ajint lno    = 0;
+    ajint rno    = 0;
+
+    ajint bucketlimit   = 0;
+    ajint maxnperbucket = 0;
+    ajint nperbucket    = 0;
+    ajint bucketn       = 0;
+    ajint count         = 0;
+    ajint totkeylen     = 0;
+    
+    ajlong lblockno = 0L;
+    ajlong rblockno = 0L;
+    ajlong prev     = 0L;
+    ajlong overflow = 0L;
+    ajlong prevsave = 0L;
+
+    ajlong zero = 0L;
+    ajlong join = 0L;
+    
+    ajlong lv = 0L;
+    ajint  v  = 0;
+    
+    /* ajDebug("In btreeHybSplitLeaf\n"); */
+
+    order = cache->order;
+    nperbucket = cache->nperbucket;
+
+    mediankey = ajStrNew();
+
+    arrays    = btreeAllocPriArray(cache);
+    karray    = arrays->karray;
+    parray    = arrays->parray;
+
+
+    buf = spage->buf;
+    lbuf = buf;
+
+    GBT_NKEYS(buf,&nkeys);
+
+    for(i=nkeys+1; i<order; ++i)
+	parray[i] = 0L;
+
+    GBT_NODETYPE(buf,&rootnodetype);
+
+    if(rootnodetype == BT_ROOT)
+    {
+	/* ajDebug("Splitting root node\n"); */
+	lblockno = cache->totsize;
+	lpage = ajBtreeCacheWrite(cache,lblockno);
+	lpage->pageno = cache->totsize;
+	cache->totsize += cache->pagesize;
+	lbuf = lpage->buf;
+	lv = prev;
+	SBT_PREV(lbuf,lv);
+    }
+    else
+    {
+	lblockno = spage->pageno;
+	lpage = spage;
+    }
+
+    lpage->dirty = BT_LOCK;
+
+
+    rblockno = cache->totsize;
+    rpage = ajBtreeCacheWrite(cache,rblockno);
+    rpage->pageno = cache->totsize;
+    rpage->dirty = BT_LOCK;
+    cache->totsize += cache->pagesize;
+    rbuf = rpage->buf;
+
+
+    if(rootnodetype == BT_ROOT)
+    {
+	lv = zero;
+	SBT_RIGHT(rbuf,lv);
+	lv = zero;
+	SBT_LEFT(lbuf,lv);
+    }
+    else
+    {
+	GBT_RIGHT(lbuf,&join);
+	lv = join;
+	SBT_RIGHT(rbuf,lv);
+    }
+    lv = lblockno;
+    SBT_LEFT(rbuf,lv);
+    lv = rblockno;
+    SBT_RIGHT(lbuf,lv);
+
+
+    btreeGetKeys(cache,buf,&karray,&parray);
+
+
+    keylimit = nkeys+1;
+    AJCNEW0(buckets,keylimit);
+    for(i=0;i<keylimit;++i)
+	buckets[i] = btreeReadBucket(cache,parray[i]);
+
+    idlist = ajListNew();
+    for(i=0;i<keylimit;++i)
+    {
+	bentries = buckets[i]->Nentries;
+	for(j=0;j<bentries;++j)
+	    ajListPush(idlist,(void *)buckets[i]->Ids[j]);
+	AJFREE(buckets[i]->keylen);
+	AJFREE(buckets[i]->Ids);
+	AJFREE(buckets[i]);
+    }
+    ajListSort(idlist,btreeIdCompare);
+    AJFREE(buckets);
+
+
+    totalkeys = ajListLength(idlist);
+
+    keypos = totalkeys / 2;
+
+    lno = keypos;
+    rno = totalkeys - lno;
+
+    maxnperbucket = nperbucket >> 1;
+    ++maxnperbucket;
+
+    cbucket = btreeBucketNew(maxnperbucket);
+
+    bucketn = lno / maxnperbucket;
+    if(lno % maxnperbucket)
+	++bucketn;
+    bucketlimit = bucketn - 1;
+
+
+    totkeylen = 0;
+    count = 0;
+    for(i=0;i<bucketlimit;++i)
+    {
+	cbucket->Nentries = 0;
+	for(j=0;j<maxnperbucket;++j)
+	{
+	    ajListPop(idlist,(void **)&bid);
+	    
+	    cid = cbucket->Ids[j];
+	    ajStrAssS(&cid->id,bid->id);
+	    cid->dbno = bid->dbno;
+	    cid->dups = bid->dups;
+	    cid->offset = bid->offset;
+	    cid->refoffset = bid->refoffset;
+	    
+	    cbucket->keylen[j] = BT_BUCKIDLEN(bid->id);
+	    ++count;
+	    ++cbucket->Nentries;
+	    ajBtreeIdDel(&bid);
+	}
+	ajListPeek(idlist,(void **)&bid);
+	
+	ajStrAssS(&karray[i],bid->id);
+	totkeylen += ajStrLen(bid->id);
+
+	if(!parray[i])
+	    parray[i] = cache->totsize;
+	btreeWriteBucket(cache,cbucket,parray[i]);
+    }
+
+    cbucket->Nentries = 0;
+
+    j = 0;
+    while(count != lno)
+    {
+	ajListPop(idlist,(void **)&bid);
+	cid = cbucket->Ids[j];
+	++j;
+	++count;
+
+	ajStrAssS(&cid->id,bid->id);
+	cid->dbno = bid->dbno;
+	cid->dups = bid->dups;
+	cid->offset = bid->offset;
+	cid->refoffset = bid->refoffset;
+	
+	++cbucket->Nentries;
+	ajBtreeIdDel(&bid);
+    }
+
+    if(!parray[i])
+	parray[i] = cache->totsize;
+    btreeWriteBucket(cache,cbucket,parray[i]);
+
+    nkeys = bucketn - 1;
+    v = nkeys;
+    SBT_NKEYS(lbuf,v);
+    v = totkeylen;
+    SBT_TOTLEN(lbuf,v);
+    nodetype = BT_LEAF;
+    v = nodetype;
+    SBT_NODETYPE(lbuf,v);
+    lpage->dirty = BT_DIRTY;
+
+    GBT_PREV(lbuf,&prevsave);
+
+    btreeWriteNode(cache,lpage,karray,parray,nkeys);
+
+    ajListPeek(idlist,(void **)&bid);
+    ajStrAssS(&mediankey,bid->id);
+
+    totkeylen = 0;
+    bucketn = rno / maxnperbucket;
+    if(rno % maxnperbucket)
+	++bucketn;
+    bucketlimit = bucketn - 1;
+
+    for(i=0;i<bucketlimit;++i)
+    {
+	cbucket->Nentries = 0;
+	for(j=0;j<maxnperbucket;++j)
+	{
+	    ajListPop(idlist,(void **)&bid);
+	    
+	    cid = cbucket->Ids[j];
+	    ajStrAssS(&cid->id,bid->id);
+	    cid->dbno = bid->dbno;
+	    cid->dups = bid->dups;
+	    cid->offset = bid->offset;
+	    cid->refoffset = bid->refoffset;
+	    
+	    cbucket->keylen[j] = BT_BUCKIDLEN(bid->id);
+	    ++cbucket->Nentries;
+	    ajBtreeIdDel(&bid);
+	}
+
+	ajListPeek(idlist,(void **)&bid);
+	ajStrAssS(&karray[i],bid->id);
+	totkeylen += ajStrLen(bid->id);
+
+	parray[i] = cache->totsize;
+	btreeWriteBucket(cache,cbucket,parray[i]);
+    }
+
+    cbucket->Nentries = 0;
+
+    j = 0;
+    while(ajListPop(idlist,(void**)&bid))
+    {
+	cid = cbucket->Ids[j];
+	++j;
+
+	ajStrAssS(&cid->id,bid->id);
+	cid->dbno = bid->dbno;
+	cid->dups = bid->dups;
+	cid->offset = bid->offset;
+	cid->refoffset = bid->refoffset;
+	
+	++cbucket->Nentries;
+	ajBtreeIdDel(&bid);
+    }
+    
+    parray[i] = cache->totsize;
+    btreeWriteBucket(cache,cbucket,parray[i]);
+
+    nkeys = bucketn - 1;
+
+    v = nkeys;
+    SBT_NKEYS(rbuf,v);
+    v = totkeylen;
+    SBT_TOTLEN(rbuf,v);
+    nodetype = BT_LEAF;
+    v = nodetype;
+    SBT_NODETYPE(rbuf,v);
+    lv = prevsave;
+    SBT_PREV(rbuf,lv);
+    lv = overflow;
+    SBT_OVERFLOW(rbuf,lv);
+
+    btreeWriteNode(cache,rpage,karray,parray,nkeys);
+    rpage->dirty = BT_DIRTY;
+
+    cbucket->Nentries = maxnperbucket;
+    btreeBucketDel(&cbucket);
+    ajListDel(&idlist);
+
+
+
+    medianless = lblockno;
+    mediangtr  = rblockno;
+
+
+    if(rootnodetype == BT_ROOT)
+    {
+	ajStrAssS(&karray[0],mediankey);
+	parray[0]=lblockno;
+	parray[1]=rblockno;
+	nkeys = 1;
+	btreeWriteNode(cache,spage,karray,parray,nkeys);	
+	spage->dirty = BT_LOCK;
+
+	btreeDeallocPriArray(cache,arrays);
+
+	ajStrDel(&mediankey);
+	++cache->level;
+	return spage;
+    }
+
+
+    btreeDeallocPriArray(cache,arrays);
+
+    page = ajBtreeCacheRead(cache,prevsave);
+    btreeHybInsertKey(cache,page,mediankey,medianless,mediangtr);
+    ajStrDel(&mediankey);
+
+    page = ajBtreeCacheRead(cache,prevsave);
+
+    return page;
+}
+
+
+
+
+/* @funcstatic btreeHybInsertKey *****************************************
+**
+** Insert a key into a potentially full node
+**
+** @param [u] cache [AjPBtcache] cache
+** @param [u] page [AjPBtpage] original page
+** @param [r] key [const AjPStr] key to insert
+** @param [r] less [ajlong] less-than pointer
+** @param [r] greater [ajlong] greater-than pointer
+**
+** @return [void]
+** @@
+******************************************************************************/
+
+static void btreeHybInsertKey(AjPBtcache cache, AjPBtpage page,
+			      const AjPStr key, ajlong less, ajlong greater)
+{
+    unsigned char *lbuf = NULL;
+    unsigned char *rbuf = NULL;
+    unsigned char *tbuf = NULL;
+    AjPStr *karray      = NULL;
+    ajlong *parray      = NULL;
+    AjPStr *tkarray     = NULL;
+    ajlong *tparray     = NULL;
+
+    AjPBtMem arrays1    = NULL;
+    AjPBtMem arrays2    = NULL;
+
+    ajint nkeys    = 0;
+    ajint order    = 0;
+    ajint keypos   = 0;
+    ajint rkeyno   = 0;
+    
+    ajint i = 0;
+    ajint n = 0;
+    
+    ajint nodetype  = 0;
+    AjPBtpage ipage = NULL;
+    AjPBtpage lpage = NULL;
+    AjPBtpage rpage = NULL;
+    AjPBtpage tpage = NULL;
+
+    ajlong blockno  = 0L;
+    ajlong rblockno = 0L;
+    ajlong lblockno = 0L;
+    AjPStr mediankey  = NULL;
+    ajlong medianless = 0L;
+    ajlong mediangtr  = 0L;
+    ajlong overflow   = 0L;
+    ajlong prev       = 0L;
+    ajint  totlen     = 0;
+    
+    ajlong lv = 0L;
+    ajint  v  = 0;
+    
+    /* ajDebug("In btreeHybInsertKey\n"); */
+
+    if(!btreeNodeIsFull(cache,page))
+    {
+	btreeInsertNonFull(cache,page,key,less,greater);
+	return;
+    }
+    
+    order = cache->order;
+    lbuf = page->buf;
+    GBT_NODETYPE(lbuf,&nodetype);
+    page->dirty = BT_LOCK;
+
+    if(nodetype == BT_ROOT)
+    {
+	arrays1   = btreeAllocPriArray(cache);
+	karray    = arrays1->karray;
+	parray    = arrays1->parray;
+
+	btreeHybSplitRoot(cache);
+
+	if(page->pageno)
+	    page->dirty = BT_DIRTY;
+	btreeGetKeys(cache,lbuf,&karray,&parray);
+
+	if(strcmp(key->Ptr,karray[0]->Ptr)<0)
+	    blockno = parray[0];
+	else
+	    blockno = parray[1];
+	ipage = ajBtreeCacheRead(cache,blockno);
+	btreeInsertNonFull(cache,ipage,key,less,greater);
+
+	btreeDeallocPriArray(cache,arrays1);
+	return;
+    }
+
+
+    arrays1   = btreeAllocPriArray(cache);
+    karray    = arrays1->karray;
+    parray    = arrays1->parray;
+
+    arrays2   = btreeAllocPriArray(cache);
+    tkarray   = arrays2->karray;
+    tparray   = arrays2->parray;
+
+    mediankey = ajStrNew();
+    
+    lpage = page;
+    lbuf = lpage->buf;
+    
+    btreeGetKeys(cache,lbuf,&karray,&parray);
+
+    GBT_BLOCKNUMBER(lbuf,&lblockno);
+    rblockno = cache->totsize;
+    rpage = ajBtreeCacheWrite(cache,rblockno);
+    rpage->dirty = BT_LOCK;
+    rpage->pageno = cache->totsize;
+    cache->totsize += cache->pagesize;
+    rbuf = rpage->buf;
+    lv = rblockno;
+    SBT_BLOCKNUMBER(rbuf,lv);
+
+    
+    GBT_PREV(lbuf,&prev);
+    lv = prev;
+    SBT_PREV(rbuf,lv);
+
+    nkeys = order - 1;
+    keypos = nkeys / 2;
+    if(!(nkeys % 2))
+	--keypos;
+
+    ajStrAssS(&mediankey,karray[keypos]);
+    medianless = lblockno;
+    mediangtr  = rblockno;
+
+
+    GBT_NODETYPE(lbuf,&nodetype);
+    v = nodetype;
+    SBT_NODETYPE(rbuf,v);
+    lv = overflow;
+    SBT_OVERFLOW(rbuf,lv);
+
+
+    totlen = 0;
+    for(i=0;i<keypos;++i)
+    {
+	ajStrAssS(&tkarray[i],karray[i]);
+	totlen += ajStrLen(karray[i]);
+	tparray[i] = parray[i];
+    }
+    tparray[i] = parray[i];
+    v = totlen;
+    SBT_TOTLEN(lbuf,v);
+    n = i;
+    v = n;
+    SBT_NKEYS(lbuf,v);
+    btreeWriteNode(cache,lpage,tkarray,tparray,i);
+
+
+
+    for(i=0;i<n+1;++i)
+    {
+	tpage = ajBtreeCacheRead(cache,tparray[i]);
+	tbuf = tpage->buf;
+	lv = lblockno;
+	SBT_PREV(tbuf,lv);
+	tpage->dirty = BT_DIRTY;
+    }
+
+
+    totlen = 0;
+    for(i=keypos+1;i<nkeys;++i)
+    {
+	ajStrAssS(&tkarray[i-(keypos+1)],karray[i]);
+	totlen += ajStrLen(karray[i]);
+	tparray[i-(keypos+1)] = parray[i];
+    }
+    tparray[i-(keypos+1)] = parray[i];
+    v = totlen;
+    SBT_TOTLEN(rbuf,v);
+    rkeyno = (nkeys-keypos) - 1;
+    v = rkeyno;
+    SBT_NKEYS(rbuf,v);
+    rpage->dirty = BT_DIRTY;
+    btreeWriteNode(cache,rpage,tkarray,tparray,rkeyno);
+
+
+    for(i=0;i<rkeyno+1;++i)
+    {
+	tpage = ajBtreeCacheRead(cache,tparray[i]);
+	tbuf = tpage->buf;
+	lv = rblockno;
+	SBT_PREV(tbuf,lv);
+	tpage->dirty = BT_DIRTY;
+    }
+
+
+    ipage = rpage;
+    if(strcmp(key->Ptr,mediankey->Ptr)<0)
+	ipage = lpage;
+
+    btreeInsertNonFull(cache,ipage,key,less,greater);
+
+
+    btreeDeallocPriArray(cache,arrays1);
+    btreeDeallocPriArray(cache,arrays2);
+
+    ipage = ajBtreeCacheRead(cache,prev);
+
+    btreeHybInsertKey(cache,ipage,mediankey,medianless,mediangtr);
+    ajStrDel(&mediankey);
+
+    return;
+}
+
+
+
+
+/* @funcstatic btreeHybSplitRoot *****************************************
+**
+** Split the root node
+**
+** @param [u] cache [AjPBtcache] cache
+**
+** @return [void]
+** @@
+******************************************************************************/
+
+static void btreeHybSplitRoot(AjPBtcache cache)
+{
+    AjPBtpage rootpage = NULL;
+    AjPBtpage rpage    = NULL;
+    AjPBtpage lpage    = NULL;
+    AjPBtpage tpage    = NULL;
+
+    AjPStr *karray     = NULL;
+    AjPStr *tkarray    = NULL;
+    ajlong *parray     = NULL;
+    ajlong *tparray    = NULL;
+    AjPBtMem arrays1   = NULL;
+    AjPBtMem arrays2   = NULL;
+
+    ajint order     = 0;
+    ajint nkeys     = 0;
+    ajint keypos    = 0;
+    
+    ajlong rblockno = 0L;
+    ajlong lblockno = 0L;
+    
+    AjPStr key = NULL;
+    ajint  i;
+
+    unsigned char *rootbuf = NULL;
+    unsigned char *rbuf    = NULL;
+    unsigned char *lbuf    = NULL;
+    unsigned char *tbuf    = NULL;
+    
+    ajint nodetype  = 0;
+    ajlong overflow = 0L;
+    ajlong zero     = 0L;
+    ajint totlen    = 0;
+    ajint rkeyno    = 0;
+    ajint n         = 0;
+
+    ajlong lv = 0L;
+    ajint  v  = 0;
+    
+    
+    /* ajDebug("In btreeHybSplitRoot\n"); */
+
+    order = cache->order;
+
+    arrays1   = btreeAllocPriArray(cache);
+    karray    = arrays1->karray;
+    parray    = arrays1->parray;
+
+    arrays2   = btreeAllocPriArray(cache);
+    tkarray   = arrays2->karray;
+    tparray   = arrays2->parray;
+
+    key = ajStrNew();
+
+    rootpage = btreeCacheLocate(cache,0L);
+    if(!rootpage)
+	ajFatal("Root page has been unlocked 1");
+    
+    rootbuf = rootpage->buf;
+
+    nkeys = order - 1;
+
+    keypos = nkeys / 2;
+    if(!(nkeys % 2))
+	--keypos;
+
+
+    rblockno = cache->totsize;
+    rpage = ajBtreeCacheWrite(cache,rblockno);
+    rpage->dirty = BT_LOCK;
+    rpage->pageno = cache->totsize;
+    cache->totsize += cache->pagesize;
+
+    lblockno = cache->totsize;
+    lpage = ajBtreeCacheWrite(cache,lblockno);
+    lpage->pageno = cache->totsize;
+    cache->totsize += cache->pagesize;
+
+    lv = rblockno;
+    SBT_BLOCKNUMBER(rpage->buf,lv);
+    lv = lblockno;
+    SBT_BLOCKNUMBER(lpage->buf,lv);
+
+    if(!cache->level)
+    {
+	lv = zero;
+	SBT_LEFT(lpage->buf,lv);
+	lv = rblockno;
+	SBT_RIGHT(lpage->buf,lv);
+	lv = lblockno;
+	SBT_LEFT(rpage->buf,lv);
+	lv = zero;
+	SBT_RIGHT(rpage->buf,lv);
+    }
+
+    btreeGetKeys(cache,rootbuf,&karray,&parray);
+
+    /* Get key for root node and write new root node */
+    ajStrAssS(&tkarray[0],karray[keypos]);
+    tparray[0] = lblockno;
+    tparray[1] = rblockno;
+    
+
+    n = 1;
+    v = n;
+    SBT_NKEYS(rootbuf,v);
+    btreeWriteNode(cache,rootpage,tkarray,tparray,1);
+    rootpage->dirty = BT_LOCK;
+
+    rbuf = rpage->buf;
+    lbuf = lpage->buf;
+    
+    if(cache->level)
+	nodetype = BT_INTERNAL;
+    else
+	nodetype = BT_LEAF;
+
+    v = nodetype;
+    SBT_NODETYPE(rbuf,v);
+    v = nodetype;
+    SBT_NODETYPE(lbuf,v);
+    lv = overflow;
+    SBT_OVERFLOW(rbuf,lv);
+    lv = overflow;
+    SBT_PREV(rbuf,lv);
+    lv = overflow;
+    SBT_OVERFLOW(lbuf,lv);
+    lv = overflow;
+    SBT_PREV(lbuf,lv);
+
+    totlen = 0;
+    for(i=0;i<keypos;++i)
+    {
+	ajStrAssS(&tkarray[i],karray[i]);
+	totlen += ajStrLen(karray[i]);
+	tparray[i] = parray[i];
+    }
+    tparray[i] = parray[i];
+    v = totlen;
+    SBT_TOTLEN(lbuf,v);
+    n = i;
+    v = n;
+    SBT_NKEYS(lbuf,v);
+    btreeWriteNode(cache,lpage,tkarray,tparray,i);
+
+    for(i=0;i<n+1;++i)
+    {
+	tpage = ajBtreeCacheRead(cache,tparray[i]);
+	tbuf = tpage->buf;
+	lv = lblockno;
+	SBT_PREV(tbuf,lv);
+	tpage->dirty = BT_DIRTY;
+    }
+
+    totlen = 0;
+    for(i=keypos+1;i<nkeys;++i)
+    {
+	ajStrAssS(&tkarray[i-(keypos+1)],karray[i]);
+	totlen += ajStrLen(karray[i]);
+	tparray[i-(keypos+1)] = parray[i];
+    }
+    tparray[i-(keypos+1)] = parray[i];
+    v = totlen;
+    SBT_TOTLEN(rbuf,v);
+    rkeyno = (nkeys-keypos) - 1;
+    v = rkeyno;
+    SBT_NKEYS(rbuf,v);
+    rpage->dirty = BT_DIRTY;
+    btreeWriteNode(cache,rpage,tkarray,tparray,rkeyno);
+
+    for(i=0;i<rkeyno+1;++i)
+    {
+	tpage = ajBtreeCacheRead(cache,tparray[i]);
+	tbuf = tpage->buf;
+	lv = rblockno;
+	SBT_PREV(tbuf,lv);
+	tpage->dirty = BT_DIRTY;
+    }
+
+
+    btreeDeallocPriArray(cache,arrays1);
+    btreeDeallocPriArray(cache,arrays2);
+
+    ++cache->level;
+
+    ajStrDel(&key);
+    
+    return;
+}
+
+
+
+
+/* @func ajBtreeHybInsertId *********************************************
+**
+** Insert an ID structure into the tree
+**
+** @param [u] cache [AjPBtcache] cache
+** @param [r] id [const AjPBtId] Id object
+**
+** @return [void] pointer to a page
+** @@
+******************************************************************************/
+
+void ajBtreeHybInsertId(AjPBtcache cache, AjPBtHybrid hyb)
+{
+    AjPBtpage spage   = NULL;
+    AjPBtpage parent  = NULL;
+    AjPStr key        = NULL;
+    const char *ckey  = NULL;
+    AjPBucket lbucket = NULL;
+    AjPBucket rbucket = NULL;
+    AjPBucket bucket  = NULL;
+    ajlong lblockno = 0L;
+    ajlong rblockno = 0L;
+    ajlong blockno  = 0L;
+    ajlong shift    = 0L;
+
+    ajint nkeys = 0;
+    ajint order = 0;
+
+    ajint nodetype = 0;
+    ajint nentries = 0;
+    
+    AjPStr *karray = NULL;
+    ajlong *parray = NULL;
+    AjPBtMem arrays = NULL;
+    AjBool found = ajFalse;
+    AjPBtId btid = NULL;
+    
+    ajint i;
+    ajint n;
+    
+    unsigned char *buf = NULL;
+
+    /* ajDebug("In ajBtreeHybInsertId\n"); */
+
+    key = ajStrNew();
+    
+
+    ajStrAssS(&key,hyb->key1);
+    if(!ajStrLen(key))
+    {
+	ajStrDel(&key);
+	return;
+    }
+
+    ckey = ajStrStr(key);
+    spage = ajBtreeHybFindInsert(cache,ckey);
+    buf = spage->buf;
+
+    GBT_NKEYS(buf,&nkeys);
+    GBT_NODETYPE(buf,&nodetype);
+    
+    order = cache->order;
+
+    arrays = btreeAllocPriArray(cache);
+    karray = arrays->karray;
+    parray = arrays->parray;
+    
+    if(!nkeys)
+    {
+	lbucket  = btreeBucketNew(0);
+	rbucket  = btreeBucketNew(0);
+
+	lblockno = cache->totsize;
+	btreeWriteBucket(cache,lbucket,lblockno);
+
+	rblockno = cache->totsize;
+	btreeWriteBucket(cache,rbucket,rblockno);	
+
+	parray[0] = lblockno;
+	parray[1] = rblockno;
+	ajStrAssS(karray,key);
+	
+	btreeWriteNode(cache,spage,karray,parray,1);
+
+	btreeBucketDel(&lbucket);
+	btreeBucketDel(&rbucket);
+
+	btreeAddToHybBucket(cache,rblockno,hyb);
+
+	btreeDeallocPriArray(cache,arrays);
+
+	ajStrDel(&key);
+
+	return;
+    }
+
+
+    /* Search to see whether entry exists */
+    
+    btreeGetKeys(cache,buf,&karray,&parray);
+
+    i=0;
+    while(i!=nkeys && strcmp(key->Ptr,karray[i]->Ptr)>=0)
+	++i;
+    if(i==nkeys)
+    {
+	if(strcmp(key->Ptr,karray[i-1]->Ptr)<0)
+	    blockno = parray[i-1];
+	else
+	    blockno = parray[i];
+    }
+    else
+	blockno = parray[i];
+
+
+    bucket = btreeReadBucket(cache,blockno);
+    
+    nentries = bucket->Nentries;
+    
+    found = ajFalse;
+
+    for(i=0;i<nentries;++i)
+	if(!strcmp(hyb->key1->Ptr,bucket->Ids[i]->id->Ptr))
+	{
+	    found = ajTrue;
+	    break;
+	}
+    
+
+    if(found)
+    {
+	btid = bucket->Ids[i];
+
+	btreeHybDupInsert(cache,hyb,btid);
+
+	btreeWriteBucket(cache,bucket,blockno);
+	btreeBucketDel(&bucket);
+
+	btreeDeallocPriArray(cache,arrays);
+
+	ajStrDel(&key);
+	
+	return;
+    }
+    else
+	btreeBucketDel(&bucket);
+
+    if(nodetype != BT_ROOT)
+	if((shift = btreeHybInsertShift(cache,&spage,key->Ptr)))
+	    blockno = shift;
+
+    buf = spage->buf;
+
+    n = btreeNumInBucket(cache,blockno);
+
+    if(n == cache->nperbucket)
+    {
+	if(btreeHybReorderBuckets(cache,spage))
+	{
+	    GBT_NKEYS(buf,&nkeys);	    
+	    btreeGetKeys(cache,buf,&karray,&parray);
+
+	    i=0;
+	    while(i!=nkeys && strcmp(key->Ptr,karray[i]->Ptr)>=0)
+		++i;
+
+	    if(i==nkeys)
+	    {
+		if(strcmp(key->Ptr,karray[i-1]->Ptr)<0)
+		    blockno = parray[i-1];
+		else
+		    blockno = parray[i];
+	    }
+	    else
+		blockno = parray[i];
+	}
+	else
+	{
+	    parent = btreeHybSplitLeaf(cache,spage);
+	    spage  = ajBtreeHybFindInsert(cache,ckey);
+	    buf = spage->buf;
+
+	    btreeGetKeys(cache,buf,&karray,&parray);
+
+	    GBT_NKEYS(buf,&nkeys);
+	    i=0;
+	    while(i!=nkeys && strcmp(key->Ptr,karray[i]->Ptr)>=0)
+		++i;
+
+	    if(i==nkeys)
+	    {
+		if(strcmp(key->Ptr,karray[i-1]->Ptr)<0)
+		    blockno = parray[i-1];
+		else
+		    blockno = parray[i];
+	    }
+	    else
+		blockno = parray[i];
+
+	}
+    }
+
+
+    btreeAddToHybBucket(cache,blockno,hyb);
+
+    ++cache->count;
+
+    btreeDeallocPriArray(cache,arrays);
+
+    ajStrDel(&key);
+
+    return;
+}
+
+
+
+
+static void btreeHybDupInsert(AjPBtcache cache, AjPBtHybrid hyb,
+			      AjPBtId btid)
+{
+    AjPBtpage page;
+    AjPBtpage rpage;
+    ajlong secrootpage = 0L;
+    unsigned char *buf;
+    ajlong right = 0L;
+    AjPBtNumId num = NULL;
+
+    /* ajDebug("In btreeHybDupInsert\n"); */
+
+    if(!btid->dups)
+    {
+	btid->dups = 1;
+	AJNEW0(num);
+	
+	num->offset    = btid->offset;
+	num->refoffset = btid->refoffset;
+	num->dbno      = btid->dbno;
+
+	secrootpage = cache->totsize;
+
+	btid->offset = secrootpage;
+
+	ajBtreeCreateRootNode(cache,secrootpage);
+	cache->secrootblock = secrootpage;
+	page = ajBtreeCacheWrite(cache,secrootpage);
+	page->dirty = BT_DIRTY;
+	ajBtreeCacheSync(cache,secrootpage);
+	page->dirty = BT_LOCK;
+	
+	rpage = btreeCacheLocate(cache, 0L);
+	rpage->dirty = BT_LOCK;
+
+	cache->slevel = 0;
+
+	ajBtreeInsertNum(cache,num,page);
+
+	num->offset    = hyb->offset;
+	num->refoffset = hyb->refoffset;
+	num->dbno      = hyb->dbno;
+
+	ajBtreeInsertNum(cache,num,page);
+	++btid->dups;
+
+	AJFREE(num);
+
+	return;
+    }
+    else
+    {
+	cache->secrootblock = btid->offset;
+	page = ajBtreeCacheWrite(cache,cache->secrootblock);
+	page->dirty = BT_LOCK;
+	buf = page->buf;
+	GBT_RIGHT(buf,&right);
+	cache->slevel = (ajint) right;
+
+	AJNEW0(num);
+	
+	num->offset    = hyb->offset;
+	num->refoffset = hyb->refoffset;
+	num->dbno      = hyb->dbno;
+	
+	ajBtreeInsertNum(cache,num,page);
+
+	AJFREE(num);
+	
+	++btid->dups;
+    }
+    
+
+    page->dirty = BT_DIRTY;
+
+    return;
+}
+
+
+
+
+/* @funcstatic btreeGetNumKeys *********************************************
+**
+** Get Keys and Pointers from an internal node
+**
+** @param [u] cache [AjPBtcache] cache
+** @param [u] buf [unsigned char *] page buffer
+** @param [w] keys [ajlong **] keys
+** @param [w] ptrs [ajlong**] ptrs
+**
+** @return [void]
+** @@
+******************************************************************************/
+
+static void btreeGetNumKeys(AjPBtcache cache, unsigned char *buf,
+			    ajlong **keys, ajlong **ptrs)
+{
+    ajlong *karray = NULL;
+    ajlong *parray = NULL;
+    
+    ajint nkeys = 0;
+    unsigned char *pptr = NULL;
+    ajint    i;
+
+    /* ajDebug("In btreeGetNumKeys\n"); */
+
+
+    karray = *keys;
+    parray = *ptrs;
+
+    pptr = PBT_KEYLEN(buf);
+    GBT_NKEYS(buf,&nkeys);
+    if(!nkeys)
+	ajFatal("GetNumKeys: No keys in node");
+
+    for(i=0;i<nkeys;++i)
+    {
+	BT_GETAJLONG(pptr,&karray[i]);
+	pptr += sizeof(ajlong);
+    }
+
+    for(i=0;i<nkeys;++i)
+    {
+	BT_GETAJLONG(pptr,&parray[i]);
+	pptr += sizeof(ajlong);
+    }
+    
+    BT_GETAJLONG(pptr,&parray[i]);
+
+    return;
+}
+
+
+
+
+/* @funcstatic btreeWriteNumNode *******************************************
+**
+** Write an internal node
+**
+** @param [u] cache [AjPBtcache] cache
+** @param [u] spage [AjPBtpage] buffer
+** @param [r] keys [AjPStr const *] keys
+** @param [r] ptrs [const ajlong*] page pointers
+** @param [r] nkeys [ajint] number of keys
+
+**
+** @return [void]
+** @@
+******************************************************************************/
+
+static void btreeWriteNumNode(AjPBtcache cache, AjPBtpage spage,
+			      const ajlong *keys, const ajlong *ptrs,
+			      ajint nkeys)
+{
+    unsigned char *pptr   = NULL;
+    unsigned char *buf;
+    
+    ajint tnkeys = 0;
+
+    ajlong aspace   = 0L;
+    ajlong lv       = 0L;
+    ajlong overflow = 0L;
+    ajint i;
+
+
+    /* ajDebug("In btreeWriteNumNode\n"); */
+
+    buf = spage->buf;
+
+    tnkeys = nkeys;
+    SBT_NKEYS(buf,tnkeys);
+
+    pptr = PBT_KEYLEN(buf);
+    aspace = 2 * nkeys * sizeof(ajlong) + sizeof(ajlong);
+    if((pptr+aspace)-buf > cache->pagesize)
+	ajFatal("WriteNumNode: too many keys for available pagesize");
+
+    for(i=0;i<nkeys;++i)
+    {
+	lv = keys[i];
+	BT_SETAJLONG(pptr,lv);
+	pptr += sizeof(ajlong);
+    }
+
+    for(i=0;i<nkeys;++i)
+    {
+	lv = ptrs[i];
+	BT_SETAJLONG(pptr,lv);
+	pptr += sizeof(ajlong);
+    }
+    
+    lv = ptrs[i];
+    BT_SETAJLONG(pptr,lv);
+
+    spage->dirty = BT_DIRTY;
+
+    overflow = 0L;
+    SBT_OVERFLOW(buf,overflow);
+
+
+    return;
+}
+
+
+
+
+/* @funcstatic btreeWriteNumBucket *******************************************
+**
+** Write index bucket object to the cache given a disc page number
+**
+** @param [u] cache [AjPBtcache] cache
+** @param [r] bucket [const AjPBucket] bucket
+** @param [r] pageno [ajlong] page number
+**
+** @return [void]
+** @@
+******************************************************************************/
+
+static void btreeWriteNumBucket(AjPBtcache cache, const AjPNumBucket bucket,
+			     ajlong pageno)
+{
+    AjPBtpage page      = NULL;
+    unsigned char *buf  = NULL;
+    unsigned char *pptr = NULL;
+
+    ajint   v   = 0;
+    ajint   i   = 0;
+    ajlong lv   = 0L;
+    ajint  nentries = 0;
+    ajlong overflow = 0L;
+
+    /* ajDebug("In btreeWriteNumBucket\n"); */
+
+    if(pageno == cache->totsize)
+    {
+	page = ajBtreeCacheWrite(cache,pageno);
+	page->pageno = cache->totsize;
+	cache->totsize += cache->pagesize;
+	buf = page->buf;
+	overflow = 0L;
+	lv = overflow;
+	SBT_BUCKOVERFLOW(buf,lv);
+    }
+    else
+    {
+	page = ajBtreeCacheRead(cache,pageno);
+	buf = page->buf;
+	GBT_BUCKOVERFLOW(buf,&overflow);
+    }
+
+    v = BT_BUCKET;
+    SBT_BUCKNODETYPE(buf,v);
+    page->dirty = BT_LOCK;
+
+    nentries = bucket->Nentries;
+    v = nentries;
+    SBT_BUCKNENTRIES(buf,v);
+    
+    pptr = PBT_BUCKKEYLEN(buf);
+
+    for(i=0;i<nentries;++i)
+    {
+	lv = bucket->NumId[i]->offset;
+	BT_SETAJLONG(pptr,lv);
+	pptr += sizeof(ajlong);
+	lv = bucket->NumId[i]->refoffset;
+	BT_SETAJLONG(pptr,lv);
+	pptr += sizeof(ajlong);
+	v = bucket->NumId[i]->dbno;
+	BT_SETAJINT(pptr,v);
+	pptr += sizeof(ajint);
+    }
+    
+    lv = 0L;
+    SBT_BUCKOVERFLOW(buf,lv);
+    page->dirty = BT_DIRTY;
+
+    return;
+}
+
+
+
+
+/* @funcstatic btreeReadNumBucket *********************************************
+**
+** Constructor for index bucket given a disc page number
+** Creates one empty key slot for possible addition
+**
+** @param [u] cache [AjPBtcache] cache
+** @param [r] pageno [ajlong] page number
+**
+** @return [AjPNumBucket] bucket
+** @@
+******************************************************************************/
+
+static AjPNumBucket btreeReadNumBucket(AjPBtcache cache, ajlong pageno)
+{
+    AjPNumBucket bucket    = NULL;
+    AjPBtpage page      = NULL;
+    unsigned char *buf  = NULL;
+    unsigned char *pptr = NULL;
+    ajint  nodetype  = 0;
+    ajint  nentries  = 0;
+    ajlong overflow  = 0L;
+    ajint  dirtysave = 0;
+    
+    ajint  i;
+    
+    /* ajDebug("In btreeReadNumBucket\n"); */
+
+    if(pageno == cache->secrootblock)
+	ajFatal("ReadNumBucket: cannot read bucket from a root page");
+
+    page = ajBtreeCacheRead(cache,pageno);
+    dirtysave = page->dirty;
+    page->dirty = BT_LOCK;
+    buf = page->buf;
+
+    GBT_BUCKNODETYPE(buf,&nodetype);
+    if(nodetype != BT_BUCKET)
+	ajFatal("ReadNumBucket: Nodetype mismatch. Not bucket (%d)",nodetype);
+
+    GBT_BUCKNENTRIES(buf,&nentries);
+    if(nentries > cache->snperbucket)
+	ajFatal("ReadNumBucket: Bucket too full");
+
+    GBT_BUCKOVERFLOW(buf,&overflow);
+
+    AJNEW0(bucket);
+    bucket->NodeType = nodetype;
+    bucket->Nentries = nentries;
+    bucket->Overflow = overflow;
+
+    AJCNEW0(bucket->NumId,nentries+1);
+    for(i=0;i<nentries;++i)
+	AJNEW0(bucket->NumId[i]);
+    
+
+    pptr = PBT_BUCKKEYLEN(buf);
+
+    for(i=0;i<nentries;++i)
+    {
+	BT_GETAJLONG(pptr,&bucket->NumId[i]->offset);
+	pptr += sizeof(ajlong);
+	BT_GETAJLONG(pptr,&bucket->NumId[i]->refoffset);
+	pptr += sizeof(ajlong);
+	BT_GETAJINT(pptr,&bucket->NumId[i]->dbno);
+	pptr += sizeof(ajint);
+    }
+    
+    page->dirty = dirtysave;
+
+    return bucket;
+}
+
+
+
+
+/* @funcstatic btreeNumBucketDel *********************************************
+**
+** Delete a bucket object
+**
+** @param [w] thys [AjPNumBucket*] bucket
+**
+** @return [void]
+** @@
+******************************************************************************/
+
+static void btreeNumBucketDel(AjPNumBucket *thys)
+{
+    AjPNumBucket pthis = NULL;
+    int i;
+    
+    
+    /* ajDebug("In btreeNumBucketDel\n"); */
+
+    if(!thys || !*thys)
+	return;
+
+    pthis = *thys;
+
+    if(pthis->Nentries)
+    {
+	for(i=0;i<pthis->Nentries;++i)
+	    AJFREE(pthis->NumId[i]);
+    
+	AJFREE(pthis->NumId);
+    }
+    
+    
+    AJFREE(pthis);
+
+    *thys = NULL;
+
+    return;
+}
+
+
+
+
+/* @func ajBtreeNumFindInsert ***********************************************
+**
+** Find the node that should contain a new key for insertion
+**
+** @param [u] cache [AjPBtcache] cache
+** @param [r] key [const ajlong] key to search for 
+**
+** @return [AjPBtpage] leaf node where item should be inserted
+** @@
+******************************************************************************/
+
+AjPBtpage ajBtreeNumFindInsert(AjPBtcache cache, const ajlong key)
+{
+    AjPBtpage root = NULL;
+    AjPBtpage ret  = NULL;
+
+    /* ajDebug("In ajBtreeNumFindInsert\n"); */
+
+    /* The root node should always be in the cache (BT_LOCKed) */
+    root = btreeCacheLocate(cache,cache->secrootblock);
+
+    /* ajDebug("cache->slevel = %d root=%d\n",cache->slevel,(ajint)root); */
+    
+
+    if(!cache->slevel)
+	return root;
+    
+    ret = btreeNumFindINode(cache,root,key);
+
+    return ret;
+}
+
+
+
+
+/* @funcstatic btreeNumFindINode **********************************************
+**
+** Recursive search for insert node in a secondary tree
+**
+** @param [u] cache [AjPBtcache] cache
+** @param [u] page [AjPBtpage] page
+** @param [r] item [const ajlong] key to search for 
+**
+** @return [AjPBtpage] leaf node where item should be inserted
+** @@
+******************************************************************************/
+
+static AjPBtpage btreeNumFindINode(AjPBtcache cache, AjPBtpage page,
+				   const ajlong item)
+{
+    AjPBtpage ret = NULL;
+    AjPBtpage pg  = NULL;
+
+    unsigned char *buf = NULL;
+    ajint status       = 0;
+    ajint ival         = 0;
+
+    /* ajDebug("In btreeNumFindINode\n"); */
+    
+    ret = page;
+    buf = page->buf;
+    GBT_NODETYPE(buf,&ival);
+    if(ival != BT_LEAF)
+    {
+	status = ret->dirty;
+	ret->dirty = BT_LOCK;	/* Lock in case of lots of overflow pages */
+	pg = btreeNumPageFromKey(cache,buf,item);
+	ret->dirty = status;
+	ret = btreeNumFindINode(cache,pg,item);
+    }
+    
+    return ret;
+}
+
+
+
+
+/* @funcstatic btreeNumPageFromKey *******************************************
+**
+** Return next lower index page given a key in a secondary tree
+**
+** @param [u] cache [AjPBtcache] cache
+** @param [u] buf [unsigned char *] page buffer
+** @param [r] key [const ajlong] key to search for 
+**
+** @return [AjPBtpage] pointer to a page
+** @@
+******************************************************************************/
+
+static AjPBtpage btreeNumPageFromKey(AjPBtcache cache, unsigned char *buf,
+				     const ajlong key)
+{
+    unsigned char *rootbuf = NULL;
+    ajint nkeys = 0;
+    ajint order = 0;
+    ajint i;
+    
+    ajlong blockno = 0L;
+    ajlong *karray = NULL;
+    ajlong *parray = NULL;
+    AjPBtpage page = NULL;
+    AjPBtMem array = NULL;
+
+    /* ajDebug("In btreeNumPageFromKey\n"); */
+    
+    rootbuf = buf;
+
+
+    GBT_NKEYS(rootbuf,&nkeys);
+    order = cache->sorder;
+
+    array = btreeAllocSecArray(cache);
+    karray = array->overflows;
+    parray = array->parray;
+    
+    btreeGetNumKeys(cache,rootbuf,&karray,&parray);
+    i = 0;
+    while(i!=nkeys && key >= karray[i])
+	++i;
+    if(i==nkeys)
+    {
+	if(key < karray[i-1])
+	    blockno = parray[i-1];
+	else
+	    blockno = parray[i];
+    }
+    else
+	blockno = parray[i];
+
+    btreeDeallocSecArray(cache,array);
+
+    page =  ajBtreeCacheRead(cache,blockno);
+
+    return page;
+}
+
+
+
+
+/* @funcstatic btreeAddToNumBucket *******************************************
+**
+** Add offset info to a bucket
+** Only called if there is room in the bucket
+**
+** @param [u] cache [AjPBtcache] cache
+** @param [r] pageno [ajlong] page number of bucket
+** @param [r] num [const AjPBtNumId] ID info
+**
+** @return [void]
+** @@
+******************************************************************************/
+
+static void btreeAddToNumBucket(AjPBtcache cache, ajlong pageno,
+				const AjPBtNumId num)
+{
+    AjPNumBucket bucket = NULL;
+    ajint nentries;
+    
+    /* ajDebug("In btreeAddToNumBucket\n"); */
+
+    bucket   = btreeReadNumBucket(cache,pageno);
+
+    nentries = bucket->Nentries;
+
+    /* Reading a bucket always gives one extra ID position */
+
+    AJNEW0(bucket->NumId[nentries]);
+    bucket->NumId[nentries]->offset    = num->offset;
+    bucket->NumId[nentries]->refoffset = num->refoffset;
+    bucket->NumId[nentries]->dbno      = num->dbno;
+
+    
+    ++bucket->Nentries;
+
+    btreeWriteNumBucket(cache,bucket,pageno);
+
+    btreeNumBucketDel(&bucket);
+    
+    return;
+}
+
+
+
+
+/* @funcstatic btreeNumInNumBucket *******************************************
+**
+** Return number of entries in a bucket
+**
+** @param [u] cache [AjPBtcache] cache
+** @param [r] pageno [ajlong] page number
+**
+** @return [ajint] Number of entries in bucket
+** @@
+******************************************************************************/
+
+static ajint btreeNumInNumBucket(AjPBtcache cache, ajlong pageno)
+{
+    AjPBtpage page     = NULL;
+    unsigned char *buf = NULL;
+    ajint  nodetype    = 0;
+    ajint  nentries    = 0;
+    
+    /* ajDebug("In btreeNumInNumBucket\n"); */
+    
+    if(pageno == cache->secrootblock)
+	ajFatal("NumInNumBucket: Attempt to read bucket from root page\n");
+
+    page  = ajBtreeCacheRead(cache,pageno);
+
+    buf = page->buf;
+
+    GBT_BUCKNODETYPE(buf,&nodetype);
+    if(nodetype != BT_BUCKET)
+	ajFatal("NumInNumBucket: NodeType mismatch. Not bucket (%d)",
+		nodetype);
+    
+    GBT_BUCKNENTRIES(buf,&nentries);
+
+    return nentries;
+}
+
+
+
+
+/* @funcstatic btreeNumBucketNew *********************************************
+**
+** Construct a bucket object
+**
+** @param [r] n [ajint] Number of IDs
+**
+** @return [AjPBucket] initialised disc block cache structure
+** @@
+******************************************************************************/
+
+static AjPNumBucket btreeNumBucketNew(ajint n)
+{
+    AjPNumBucket bucket = NULL;
+    ajint i;
+
+    /* ajDebug("In btreeNumBucketNew\n"); */
+    
+    AJNEW0(bucket);
+
+    if(n)
+    {
+	AJCNEW0(bucket->NumId,n);
+	for(i=0;i<n;++i)
+	    AJNEW0(bucket->NumId[i]);
+    }
+
+    bucket->NodeType = BT_BUCKET;
+    bucket->Nentries = n;
+    bucket->Overflow = 0L;
+    
+    return bucket;
+}
+
+
+
+
+/* @funcstatic btreeReorderNumBuckets *****************************************
+**
+** Re-order leaf buckets
+** Must only be called if one of the buckets is full
+**
+** @param [u] cache [AjPBtcache] cache
+** @param [u] leaf [AjPBtpage] leaf page
+**
+** @return [AjBool] true if reorder was successful i.e. leaf not full
+** @@
+******************************************************************************/
+
+static AjBool btreeReorderNumBuckets(AjPBtcache cache, AjPBtpage leaf)
+{
+    ajint nkeys = 0;
+    unsigned char *lbuf = NULL;
+
+    ajlong *keys        = NULL;
+    ajlong *ptrs        = NULL;
+
+    AjPNumBucket *buckets  = NULL;
+    
+    ajint i = 0;
+    ajint j = 0;
+    
+    ajint order;
+    ajint bentries      = 0;
+    ajint totalkeys     = 0;
+    ajint nperbucket    = 0;
+    ajint maxnperbucket = 0;
+    ajint count         = 0;
+    ajint keylimit      = 0;
+    ajint bucketn       = 0;
+    ajint bucketlimit   = 0;
+    ajint nodetype      = 0;
+    
+    AjPList idlist    = NULL;
+    ajint   dirtysave = 0;
+    AjPBtNumId bid       = NULL;
+    AjPNumBucket cbucket = NULL;
+    AjPBtNumId cid       = NULL;
+
+    ajint   v = 0;
+    AjPBtMem array = NULL;
+    
+    /* ajDebug("In btreeReorderNumBuckets\n"); */
+
+    dirtysave = leaf->dirty;
+
+    leaf->dirty = BT_LOCK;
+    lbuf = leaf->buf;
+
+    GBT_NODETYPE(lbuf,&nodetype);
+
+    order = cache->sorder;
+    nperbucket = cache->snperbucket;
+    
+
+    array = btreeAllocSecArray(cache);
+    keys  = array->overflows;
+    ptrs  = array->parray;
+
+    /* Read keys/ptrs */
+
+    btreeGetNumKeys(cache,lbuf,&keys,&ptrs);
+
+    GBT_NKEYS(lbuf,&nkeys);
+
+
+    if(!nkeys)
+	ajFatal("NumBucketReorder: Attempt to reorder empty leaf");
+
+    for(i=0;i<nkeys;++i)
+	totalkeys += btreeNumInNumBucket(cache,ptrs[i]);
+    totalkeys += btreeNumInNumBucket(cache,ptrs[i]);
+
+    /* Set the number of entries per bucket to approximately half full */
+    maxnperbucket = nperbucket >> 1;
+
+    if(!maxnperbucket)
+	++maxnperbucket;
+
+    /* Work out the number of new buckets needed */
+    bucketn = (totalkeys / maxnperbucket);
+    if(totalkeys % maxnperbucket)
+	++bucketn;
+    
+    if(bucketn > order)
+    {
+	btreeDeallocSecArray(cache,array);
+	
+	leaf->dirty = dirtysave;
+	return ajFalse;
+    }
+    
+
+    /* Read buckets */
+    AJCNEW0(buckets,nkeys+1);
+    keylimit = nkeys + 1;
+    
+    for(i=0;i<keylimit;++i)
+	buckets[i] = btreeReadNumBucket(cache,ptrs[i]);
+
+
+    /* Read IDs from all buckets and push to list and sort (increasing id) */
+    idlist  = ajListNew();
+    
+    for(i=0;i<keylimit;++i)
+    {
+	bentries = buckets[i]->Nentries;
+	for(j=0;j<bentries;++j)
+	    ajListPush(idlist,(void *)buckets[i]->NumId[j]);
+	
+	AJFREE(buckets[i]->NumId);
+	AJFREE(buckets[i]);
+    }
+    ajListSort(idlist,btreeNumIdCompare);
+    AJFREE(buckets);
+
+    cbucket = btreeNumBucketNew(maxnperbucket);
+    bucketlimit = bucketn - 1;
+    
+    for(i=0;i<bucketlimit;++i)
+    {
+	cbucket->Nentries = 0;
+
+	count = 0;
+	while(count!=maxnperbucket)
+	{
+	    ajListPop(idlist,(void **)&bid);
+	    
+	    cid = cbucket->NumId[count];
+	    cid->dbno = bid->dbno;
+	    cid->offset = bid->offset;
+	    cid->refoffset = bid->refoffset;
+	    
+	    ++cbucket->Nentries;
+	    ++count;
+	    AJFREE(bid);
+	}
+
+
+	ajListPeek(idlist,(void **)&bid);
+	keys[i] = bid->offset;
+
+	if(!ptrs[i])
+	    ptrs[i] = cache->totsize;
+	btreeWriteNumBucket(cache,cbucket,ptrs[i]);
+    }
+
+
+    /* Deal with greater-than bucket */
+
+    cbucket->Nentries = 0;
+
+    count = 0;
+    while(ajListPop(idlist,(void **)&bid))
+    {
+	cid = cbucket->NumId[count];
+	cid->dbno = bid->dbno;
+	cid->offset = bid->offset;
+	cid->refoffset = bid->refoffset;
+	
+	++cbucket->Nentries;
+	++count;
+	AJFREE(bid);
+    }
+    
+    
+    if(!ptrs[i])
+	ptrs[i] = cache->totsize;
+    btreeWriteNumBucket(cache,cbucket,ptrs[i]);
+
+    cbucket->Nentries = maxnperbucket;
+    btreeNumBucketDel(&cbucket);
+
+    /* Now write out a modified leaf with new keys/ptrs */
+
+    nkeys = bucketn - 1;
+    v = nkeys;
+    SBT_NKEYS(lbuf,v);
+
+    btreeWriteNumNode(cache,leaf,keys,ptrs,nkeys);
+
+    leaf->dirty = BT_DIRTY;
+    if(nodetype == BT_ROOT)
+	leaf->dirty = BT_LOCK;
+    
+    btreeDeallocSecArray(cache,array);
+
+    ajListDel(&idlist);
+
+    return ajTrue;
+}
+
+
+
+
+/* @funcstatic btreeNumNodeIsFull *****************************************
+**
+** Tests whether a node is full of keys
+**
+** @param [r] cache [const AjPBtcache] cache
+** @param [u] page [AjPBtpage] original page
+**
+** @return [AjBool] true if full
+** @@
+******************************************************************************/
+
+static AjBool btreeNumNodeIsFull(const AjPBtcache cache, AjPBtpage page)
+{
+    unsigned char *buf = NULL;
+    ajint nkeys = 0;
+
+    /* ajDebug("In btreeNumNodeIsFull\n"); */
+
+    buf = page->buf;
+    GBT_NKEYS(buf,&nkeys);
+
+    if(nkeys == cache->sorder - 1)
+	return ajTrue;
+
+    return ajFalse;
+}
+
+
+
+
+/* @funcstatic btreeNumInsertNonFull *****************************************
+**
+** Insert a key into a non-full node
+**
+** @param [u] cache [AjPBtcache] cache
+** @param [u] page [AjPBtpage] original page
+** @param [r] key [const ajlong] key to insert
+** @param [r] less [ajlong] less-than pointer
+** @param [r] greater [ajlong] greater-than pointer
+**
+** @return [void]
+** @@
+******************************************************************************/
+
+static void btreeNumInsertNonFull(AjPBtcache cache, AjPBtpage page,
+				  const ajlong key, ajlong less,
+				  ajlong greater)
+{
+    unsigned char *buf = NULL;
+    ajlong *karray     = NULL;
+    ajlong *parray     = NULL;
+    ajint nkeys  = 0;
+    ajint order  = 0;
+    ajint ipos   = 0;
+    ajint i;
+    ajint count  = 0;
+
+    ajlong lv = 0L;
+    ajint  v  = 0;
+    AjPBtMem array = NULL;    
+
+    AjPBtpage ppage = NULL;
+    ajlong pageno   = 0L;
+
+    ajint nodetype = 0;
+    
+    /* ajDebug("In btreeNumInsertNonFull\n"); */
+
+    order = cache->sorder;
+
+    array = btreeAllocSecArray(cache);
+    karray  = array->overflows;
+    parray  = array->parray;
+
+
+    buf = page->buf;
+    GBT_NKEYS(buf,&nkeys);
+    GBT_NODETYPE(buf,&nodetype);
+    
+    btreeGetNumKeys(cache,buf,&karray,&parray);
+
+    i = 0;
+    while(i!=nkeys && key >= karray[i])
+	++i;
+
+    ipos = i;
+
+    count = nkeys - ipos;
+    
+
+    if(ipos == nkeys)
+    {
+	karray[ipos] = key;
+	parray[ipos+1] = greater;
+	parray[ipos]   = less;
+    }
+    else
+    {
+	parray[nkeys+1] = parray[nkeys];
+
+	for(i=nkeys-1; count>0; --count, --i)
+	{
+	    karray[i+1] = karray[i];
+	    parray[i+1] = parray[i];
+	}
+
+	karray[ipos] = key;
+	parray[ipos] = less;
+	parray[ipos+1] = greater;
+    }
+
+    ++nkeys;
+    v = nkeys;
+    SBT_NKEYS(buf,v);
+
+    btreeWriteNumNode(cache,page,karray,parray,nkeys);
+    if(nodetype == BT_ROOT)
+	page->dirty = BT_LOCK;
+
+    pageno = page->pageno;
+    ppage = ajBtreeCacheRead(cache,less);
+    lv = pageno;
+    SBT_PREV(ppage->buf,lv);
+    ppage->dirty = BT_DIRTY;
+    ppage = ajBtreeCacheRead(cache,greater);
+    lv = pageno;
+    SBT_PREV(ppage->buf,lv);
+    ppage->dirty = BT_DIRTY;
+    
+
+    btreeDeallocSecArray(cache,array);
+
+    if(nodetype != BT_ROOT)
+	btreeNumKeyShift(cache,page);
+
+    return;
+}
+
+
+
+
+/* @funcstatic btreeNumInsertKey **********************************************
+**
+** Insert a key into a potentially full node
+**
+** @param [u] cache [AjPBtcache] cache
+** @param [u] page [AjPBtpage] original page
+** @param [r] key [const ajlong] key to insert
+** @param [r] less [ajlong] less-than pointer
+** @param [r] greater [ajlong] greater-than pointer
+**
+** @return [void]
+** @@
+******************************************************************************/
+
+static void btreeNumInsertKey(AjPBtcache cache, AjPBtpage page,
+			      const ajlong key, ajlong less, ajlong greater)
+{
+    unsigned char *lbuf = NULL;
+    unsigned char *rbuf = NULL;
+    unsigned char *tbuf = NULL;
+    ajlong *karray      = NULL;
+    ajlong *parray      = NULL;
+    ajlong *tkarray     = NULL;
+    ajlong *tparray     = NULL;
+    ajint nkeys    = 0;
+    ajint order    = 0;
+    ajint keypos   = 0;
+    ajint rkeyno   = 0;
+    
+    ajint i = 0;
+    ajint n = 0;
+    
+    ajint nodetype  = 0;
+    AjPBtpage ipage = NULL;
+    AjPBtpage lpage = NULL;
+    AjPBtpage rpage = NULL;
+    AjPBtpage tpage = NULL;
+
+    ajlong blockno  = 0L;
+    ajlong rblockno = 0L;
+    ajlong lblockno = 0L;
+    ajlong mediankey  = 0L;
+    ajlong medianless = 0L;
+    ajlong mediangtr  = 0L;
+    ajlong overflow   = 0L;
+    ajlong prev       = 0L;
+    ajint  totlen     = 0;
+    
+    ajlong lv = 0L;
+    ajint  v  = 0;
+    AjPBtMem array  = NULL;    
+    AjPBtMem array2 = NULL;    
+    
+    /* ajDebug("In btreeNumInsertKey\n"); */
+
+    if(!btreeNumNodeIsFull(cache,page))
+    {
+	btreeNumInsertNonFull(cache,page,key,less,greater);
+	return;
+    }
+    
+    order = cache->sorder;
+    lbuf = page->buf;
+    GBT_NODETYPE(lbuf,&nodetype);
+    page->dirty = BT_LOCK;
+
+    if(nodetype == BT_ROOT)
+    {
+	array = btreeAllocSecArray(cache);
+	karray  = array->overflows;
+	parray  = array->parray;
+
+	btreeNumSplitRoot(cache);
+
+	if(page->pageno)
+	    page->dirty = BT_DIRTY;
+	btreeGetNumKeys(cache,lbuf,&karray,&parray);
+
+	if(key < karray[0])
+	    blockno = parray[0];
+	else
+	    blockno = parray[1];
+	ipage = ajBtreeCacheRead(cache,blockno);
+	btreeNumInsertNonFull(cache,ipage,key,less,greater);
+
+	btreeDeallocSecArray(cache,array);
+	return;
+    }
+
+
+    array = btreeAllocSecArray(cache);
+    karray  = array->overflows;
+    parray  = array->parray;
+    
+    array2 = btreeAllocSecArray(cache);
+    tkarray  = array2->overflows;
+    tparray  = array2->parray;
+
+    
+    lpage = page;
+    lbuf = lpage->buf;
+    
+    btreeGetNumKeys(cache,lbuf,&karray,&parray);
+
+    GBT_BLOCKNUMBER(lbuf,&lblockno);
+    rblockno = cache->totsize;
+    rpage = ajBtreeCacheWrite(cache,rblockno);
+    rpage->dirty = BT_LOCK;
+    rpage->pageno = cache->totsize;
+    cache->totsize += cache->pagesize;
+    rbuf = rpage->buf;
+    lv = rblockno;
+    SBT_BLOCKNUMBER(rbuf,lv);
+
+    
+    GBT_PREV(lbuf,&prev);
+    lv = prev;
+    SBT_PREV(rbuf,lv);
+
+    nkeys = order - 1;
+    keypos = nkeys / 2;
+    if(!(nkeys % 2))
+	--keypos;
+
+    mediankey = karray[keypos];
+    medianless = lblockno;
+    mediangtr  = rblockno;
+
+
+    GBT_NODETYPE(lbuf,&nodetype);
+    v = nodetype;
+    SBT_NODETYPE(rbuf,v);
+    lv = overflow;
+    SBT_OVERFLOW(rbuf,lv);
+
+
+    totlen = 0;
+    for(i=0;i<keypos;++i)
+    {
+	tkarray[i] = karray[i];
+	tparray[i] = parray[i];
+    }
+    tparray[i] = parray[i];
+
+    n = i;
+    v = n;
+    SBT_NKEYS(lbuf,v);
+    btreeWriteNumNode(cache,lpage,tkarray,tparray,i);
+
+
+
+    for(i=0;i<n+1;++i)
+    {
+	tpage = ajBtreeCacheRead(cache,tparray[i]);
+	tbuf = tpage->buf;
+	lv = lblockno;
+	SBT_PREV(tbuf,lv);
+	tpage->dirty = BT_DIRTY;
+    }
+
+
+    totlen = 0;
+    for(i=keypos+1;i<nkeys;++i)
+    {
+	tkarray[i-(keypos+1)] = karray[i];
+	tparray[i-(keypos+1)] = parray[i];
+    }
+    tparray[i-(keypos+1)] = parray[i];
+
+    rkeyno = (nkeys-keypos) - 1;
+    v = rkeyno;
+    SBT_NKEYS(rbuf,v);
+    rpage->dirty = BT_DIRTY;
+    btreeWriteNumNode(cache,rpage,tkarray,tparray,rkeyno);
+
+
+    for(i=0;i<rkeyno+1;++i)
+    {
+	tpage = ajBtreeCacheRead(cache,tparray[i]);
+	tbuf = tpage->buf;
+	lv = rblockno;
+	SBT_PREV(tbuf,lv);
+	tpage->dirty = BT_DIRTY;
+    }
+
+
+    ipage = rpage;
+    if(key < mediankey)
+	ipage = lpage;
+
+    btreeNumInsertNonFull(cache,ipage,key,less,greater);
+
+
+    btreeDeallocSecArray(cache,array);
+    btreeDeallocSecArray(cache,array2);
+
+    ipage = ajBtreeCacheRead(cache,prev);
+
+    btreeNumInsertKey(cache,ipage,mediankey,medianless,mediangtr);
+
+    return;
+}
+
+
+
+
+/* @funcstatic btreeNumSplitRoot *****************************************
+**
+** Split s secondary root node
+**
+** @param [u] cache [AjPBtcache] cache
+**
+** @return [void]
+** @@
+******************************************************************************/
+
+static void btreeNumSplitRoot(AjPBtcache cache)
+{
+    AjPBtpage rootpage = NULL;
+    AjPBtpage rpage    = NULL;
+    AjPBtpage lpage    = NULL;
+    AjPBtpage tpage    = NULL;
+
+    ajlong *karray  = NULL;
+    ajlong *tkarray = NULL;
+    ajlong *parray  = NULL;
+    ajlong *tparray = NULL;
+
+    ajint order  = 0;
+    ajint nkeys  = 0;
+    ajint keypos = 0;
+    
+    ajlong rblockno = 0L;
+    ajlong lblockno = 0L;
+
+    ajlong right;
+    
+    ajint  i;
+
+    unsigned char *rootbuf = NULL;
+    unsigned char *rbuf    = NULL;
+    unsigned char *lbuf    = NULL;
+    unsigned char *tbuf    = NULL;
+    
+    ajint nodetype  = 0;
+    ajlong overflow = 0L;
+    ajlong zero     = 0L;
+    ajint rkeyno    = 0;
+    ajint n         = 0;
+
+    ajlong lv = 0L;
+    ajint  v  = 0;
+
+    AjPBtMem array  = NULL;    
+    AjPBtMem array2 = NULL;    
+    
+    
+    /* ajDebug("In btreeNumSplitRoot\n"); */
+
+    order = cache->sorder;
+
+    array = btreeAllocSecArray(cache);
+    karray  = array->overflows;
+    parray  = array->parray;
+    
+    array2 = btreeAllocSecArray(cache);
+    tkarray  = array2->overflows;
+    tparray  = array2->parray;
+
+
+    rootpage = btreeCacheLocate(cache,cache->secrootblock);
+    rootbuf = rootpage->buf;
+
+    nkeys = order - 1;
+
+    keypos = nkeys / 2;
+    if(!(nkeys % 2))
+	--keypos;
+
+
+    rblockno = cache->totsize;
+    rpage = ajBtreeCacheWrite(cache,rblockno);
+    rpage->pageno = cache->totsize;
+    cache->totsize += cache->pagesize;
+    rpage->dirty = BT_LOCK;
+    
+    lblockno = cache->totsize;
+    lpage = ajBtreeCacheWrite(cache,lblockno);
+    lpage->pageno = cache->totsize;
+    cache->totsize += cache->pagesize;
+
+    lv = rblockno;
+    SBT_BLOCKNUMBER(rpage->buf,lv);
+    lv = lblockno;
+    SBT_BLOCKNUMBER(lpage->buf,lv);
+
+    /* Comment this next block out after the beta test */
+    if(!cache->slevel)
+    {
+	fprintf(stderr,"btreeSplitRootSec: Shouldn't get here\n");
+	exit(0);
+	lv = zero;
+	SBT_LEFT(lpage->buf,lv);
+	lv = rblockno;
+	SBT_RIGHT(lpage->buf,lv);
+	lv = lblockno;
+	SBT_LEFT(rpage->buf,lv);
+	lv = zero;
+	SBT_RIGHT(rpage->buf,lv);
+    }
+
+    btreeGetNumKeys(cache,rootbuf,&karray,&parray);
+
+    /* Get key for root node and write new root node */
+    tkarray[0] = karray[keypos];
+    tparray[0] = lblockno;
+    tparray[1] = rblockno;
+    
+
+    n = 1;
+    v = n;
+    SBT_NKEYS(rootbuf,v);
+    btreeWriteNumNode(cache,rootpage,tkarray,tparray,1);
+    right = (ajlong)(cache->slevel + 1);
+    SBT_RIGHT(rootbuf,right);
+
+    rootpage->dirty = BT_LOCK;
+
+    rbuf = rpage->buf;
+    lbuf = lpage->buf;
+    
+    if(cache->slevel)
+	nodetype = BT_INTERNAL;
+    else
+	nodetype = BT_LEAF;
+
+    v = nodetype;
+    SBT_NODETYPE(rbuf,v);
+    v = nodetype;
+    SBT_NODETYPE(lbuf,v);
+    lv = overflow;
+    SBT_OVERFLOW(rbuf,lv);
+    lv = cache->secrootblock;
+    SBT_PREV(rbuf,lv);
+    lv = overflow;
+    SBT_OVERFLOW(lbuf,lv);
+    lv = cache->secrootblock;
+    SBT_PREV(lbuf,lv);
+
+    for(i=0;i<keypos;++i)
+    {
+	tkarray[i] = karray[i];
+	tparray[i] = parray[i];
+    }
+    tparray[i] = parray[i];
+
+    n = i;
+    v = n;
+    SBT_NKEYS(lbuf,v);
+    btreeWriteNumNode(cache,lpage,tkarray,tparray,i);
+
+    for(i=0;i<n+1;++i)
+    {
+	tpage = ajBtreeCacheRead(cache,tparray[i]);
+	tbuf = tpage->buf;
+	lv = lblockno;
+	SBT_PREV(tbuf,lv);
+	tpage->dirty = BT_DIRTY;
+    }
+
+    for(i=keypos+1;i<nkeys;++i)
+    {
+	tkarray[i-(keypos+1)] = karray[i];
+	tparray[i-(keypos+1)] = parray[i];
+    }
+    tparray[i-(keypos+1)] = parray[i];
+
+    rkeyno = (nkeys-keypos) - 1;
+    v = rkeyno;
+    SBT_NKEYS(rbuf,v);
+    rpage->dirty = BT_DIRTY;
+    btreeWriteNumNode(cache,rpage,tkarray,tparray,rkeyno);
+
+    for(i=0;i<rkeyno+1;++i)
+    {
+	tpage = ajBtreeCacheRead(cache,tparray[i]);
+	tbuf = tpage->buf;
+	lv = rblockno;
+	SBT_PREV(tbuf,lv);
+	tpage->dirty = BT_DIRTY;
+    }
+
+
+    ++cache->slevel;
+
+    btreeDeallocSecArray(cache,array);
+    btreeDeallocSecArray(cache,array2);
+    
+    return;
+}
+
+
+
+
+/* @funcstatic btreeNumKeyShift ********************************************
+**
+** Rebalance Nodes on insertion
+**
+** @param [u] cache [AjPBtcache] cache
+** @param [u] tpage [AjPBtpage] page
+**
+** @return [void]
+** @@
+******************************************************************************/
+
+static void btreeNumKeyShift(AjPBtcache cache, AjPBtpage tpage)
+{
+    unsigned char *tbuf = NULL;
+    unsigned char *pbuf = NULL;
+    unsigned char *sbuf = NULL;
+    unsigned char *buf  = NULL;
+
+    AjPBtpage ppage = NULL;
+    AjPBtpage spage = NULL;
+    AjPBtpage page  = NULL;
+
+    ajint tkeys = 0;
+    ajint pkeys = 0;
+    ajint skeys = 0;
+    ajint order = 0;
+    
+    ajint i;
+    
+    ajlong parent  = 0L;
+    
+    ajlong *kTarray = NULL;
+    ajlong *kParray = NULL;
+    ajlong *kSarray = NULL;
+    ajlong *pTarray = NULL;
+    ajlong *pParray = NULL;
+    ajlong *pSarray = NULL;
+
+    ajint pkeypos = 0;
+    ajint minsize = 0;
+
+    ajlong lv = 0L;
+
+    AjPBtMem array  = NULL;    
+    AjPBtMem array2 = NULL;    
+    AjPBtMem array3 = NULL;    
+    
+    /* ajDebug("In btreeNumKeyShift\n"); */
+    
+    tbuf = tpage->buf;
+
+    GBT_PREV(tbuf,&parent);
+    GBT_NKEYS(tbuf,&tkeys);
+
+    order = cache->sorder;
+    minsize = order / 2;
+    if(order % 2)
+	++minsize;
+
+    if(tkeys <= minsize)
+	return;
+
+    
+    ppage = ajBtreeCacheRead(cache,parent);
+    pbuf = ppage->buf;
+    GBT_NKEYS(pbuf,&pkeys);
+    
+    array = btreeAllocSecArray(cache);
+    kParray  = array->overflows;
+    pParray  = array->parray;
+    
+    array2 = btreeAllocSecArray(cache);
+    kSarray  = array2->overflows;
+    pSarray  = array2->parray;
+
+    array3 = btreeAllocSecArray(cache);
+    kTarray  = array3->overflows;
+    pTarray  = array3->parray;
+
+
+    btreeGetNumKeys(cache,tbuf,&kTarray,&pTarray);
+    GBT_NKEYS(tbuf,&tkeys);
+
+
+    btreeGetNumKeys(cache,pbuf,&kParray,&pParray);
+    i=0;
+    while(pParray[i] != tpage->pageno)
+	++i;
+
+    if(i) /* There is another leaf to the left */
+    {
+	pkeypos = i-1;
+	spage = ajBtreeCacheRead(cache,pParray[pkeypos]);
+	sbuf = spage->buf;
+	GBT_NKEYS(sbuf,&skeys);
+	
+    }
+
+    if(i && skeys != order-1) /* There is space in the left leaf */
+    {
+	if(skeys)
+	    btreeGetNumKeys(cache,sbuf,&kSarray,&pSarray);
+
+	kSarray[skeys] = kParray[pkeypos];
+	pSarray[skeys+1] = pTarray[0];
+	++skeys;
+	--tkeys;
+	kParray[pkeypos] = kTarray[0];
+	for(i=0;i<tkeys;++i)
+	{
+	    kTarray[i] = kTarray[i+1];
+	    pTarray[i] = pTarray[i+1];
+	}
+	pTarray[i] = pTarray[i+1];
+	pTarray[i+1] = 0L;
+	
+	btreeWriteNumNode(cache,spage,kSarray,pSarray,skeys);
+	btreeWriteNumNode(cache,tpage,kTarray,pTarray,tkeys);
+	btreeWriteNumNode(cache,ppage,kParray,pParray,pkeys);
+	if(!ppage->pageno)
+	    ppage->dirty = BT_LOCK;
+
+	page = ajBtreeCacheRead(cache,pSarray[skeys]);
+	buf = page->buf;
+	lv = spage->pageno;
+	SBT_PREV(buf,lv);
+	page->dirty = BT_DIRTY;
+
+
+	btreeDeallocSecArray(cache,array);
+	btreeDeallocSecArray(cache,array2);
+	btreeDeallocSecArray(cache,array3);
+
+	return;
+    }
+
+
+
+    if(i != pkeys)	/* There is a right node */
+    {
+	pkeypos = i;
+	spage = ajBtreeCacheRead(cache,pParray[pkeypos+1]);
+	sbuf = spage->buf;
+	GBT_NKEYS(sbuf,&skeys);
+    }
+
+
+    if(i != pkeys && skeys != order-1) /* Space in the right node */
+    {
+	if(skeys)
+	    btreeGetNumKeys(cache,sbuf,&kSarray,&pSarray);
+
+	pSarray[skeys+1] = pSarray[skeys];
+	for(i=skeys-1;i>-1;--i)
+	{
+	    kSarray[i+1] = kSarray[i];
+	    pSarray[i+1] = pSarray[i];
+	}
+	kSarray[0] = kParray[pkeypos];
+	pSarray[0] = pTarray[tkeys];
+	kParray[pkeypos] = kTarray[tkeys-1];
+	++skeys;
+	--tkeys;
+	pTarray[tkeys+1] = 0L;
+	
+	btreeWriteNumNode(cache,spage,kSarray,pSarray,skeys);
+	btreeWriteNumNode(cache,tpage,kTarray,pTarray,tkeys);
+	btreeWriteNumNode(cache,ppage,kParray,pParray,pkeys);
+	if(!ppage->pageno)
+	    ppage->dirty = BT_LOCK;
+
+	page = ajBtreeCacheRead(cache,pSarray[0]);
+	buf = page->buf;
+	lv = spage->pageno;
+	SBT_PREV(buf,lv);
+	page->dirty = BT_DIRTY;
+
+	btreeDeallocSecArray(cache,array);
+	btreeDeallocSecArray(cache,array2);
+	btreeDeallocSecArray(cache,array3);
+
+	return;
+    }
+
+
+    btreeDeallocSecArray(cache,array);
+    btreeDeallocSecArray(cache,array2);
+    btreeDeallocSecArray(cache,array3);
+
+    return;
+}
+
+
+
+
+/* @funcstatic btreeNumInsertShift ********************************************
+**
+** Rebalance buckets on insertion
+**
+** @param [u] cache [AjPBtcache] cache
+** @param [u] retpage [AjPBtpage*] page
+** @param [r] key [const ajlong] key
+**
+** @return [ajlong] bucket block or 0L if shift not posible 
+** @@
+******************************************************************************/
+
+static ajlong btreeNumInsertShift(AjPBtcache cache, AjPBtpage *retpage,
+				  ajlong key)
+{
+    unsigned char *tbuf = NULL;
+    unsigned char *pbuf = NULL;
+    unsigned char *sbuf = NULL;
+
+    AjPBtpage ppage = NULL;
+    AjPBtpage spage = NULL;
+    AjPBtpage tpage = NULL;
+
+    ajint tkeys = 0;
+    ajint pkeys = 0;
+    ajint skeys = 0;
+    ajint order = 0;
+    
+    ajint i;
+    ajint n;
+    
+    ajlong parent  = 0L;
+    ajlong blockno = 0L;
+    
+    ajlong *kTarray = NULL;
+    ajlong *kParray = NULL;
+    ajlong *kSarray = NULL;
+    ajlong *pTarray = NULL;
+    ajlong *pParray = NULL;
+    ajlong *pSarray = NULL;
+
+    ajlong *karray = NULL;
+    ajlong *parray = NULL;
+
+    ajint ppos    = 0;
+    ajint pkeypos = 0;
+    ajint minsize = 0;
+
+    AjPBtMem array  = NULL;    
+    AjPBtMem array2 = NULL;    
+    AjPBtMem array3 = NULL;    
+
+
+    
+    /* ajDebug("In btreeNumInsertShift\n"); */
+
+
+    tpage = *retpage;
+
+    tbuf = tpage->buf;
+
+    GBT_PREV(tbuf,&parent);
+    GBT_NKEYS(tbuf,&tkeys);
+
+
+    order = cache->sorder;
+    minsize = order / 2;
+    if(order % 2)
+	++minsize;
+
+    if(tkeys <= minsize)
+	return 0L;
+
+    ppage = ajBtreeCacheRead(cache,parent);
+
+
+    
+    pbuf = ppage->buf;
+    GBT_NKEYS(pbuf,&pkeys);
+
+    
+    array = btreeAllocSecArray(cache);
+    kParray  = array->overflows;
+    pParray  = array->parray;
+    
+    array2 = btreeAllocSecArray(cache);
+    kSarray  = array2->overflows;
+    pSarray  = array2->parray;
+
+    array3 = btreeAllocSecArray(cache);
+    kTarray  = array3->overflows;
+    pTarray  = array3->parray;
+
+
+    btreeGetNumKeys(cache,pbuf,&kParray,&pParray);
+
+    i=0;
+    while(i!=pkeys && key >= kParray[i])
+	++i;
+    pkeypos = i;
+    
+    if(i==pkeys)
+    {
+	if(key < kParray[i-1])
+	    ppos = i-1;
+	else
+	    ppos = i;
+    }
+    else
+	ppos = i;
+
+    
+    if(ppos) /* There is another leaf to the left */
+    {
+	spage = ajBtreeCacheRead(cache,pParray[ppos-1]);
+	sbuf = spage->buf;
+	GBT_NKEYS(sbuf,&skeys);
+    }
+
+    if(i && skeys != order-1) /* There is space in the left leaf */
+    {
+	/* ajDebug("Left shift\n"); */
+	btreeGetNumKeys(cache,tbuf,&kTarray,&pTarray);
+	if(skeys)
+	    btreeGetNumKeys(cache,sbuf,&kSarray,&pSarray);
+
+	i = 0;
+	while(pParray[i] != tpage->pageno)
+	    ++i;
+	--i;
+
+	pkeypos = i;
+
+	kSarray[skeys] = kParray[pkeypos];
+	pSarray[skeys+1] = pTarray[0];
+	++skeys;
+	--tkeys;
+	kParray[pkeypos] = kTarray[0];
+	for(i=0;i<tkeys;++i)
+	{
+	    kTarray[i] = kTarray[i+1];
+	    pTarray[i] = pTarray[i+1];
+	}
+	pTarray[i] = pTarray[i+1];
+	pTarray[i+1] = 0L;
+	
+	btreeWriteNumNode(cache,spage,kSarray,pSarray,skeys);
+	btreeWriteNumNode(cache,tpage,kTarray,pTarray,tkeys);
+	btreeWriteNumNode(cache,ppage,kParray,pParray,pkeys);
+	if(!ppage->pageno)
+	    ppage->dirty = BT_LOCK;
+
+	i = 0;
+	while(i!=pkeys && key >= kParray[i])
+	    ++i;
+	if(i==pkeys)
+	{
+	    if(key < kParray[i-1])
+		blockno = pParray[i-1];
+	    else
+		blockno = pParray[i];
+	}
+	else
+	    blockno = pParray[i];
+
+	if(blockno == spage->pageno)
+	{
+	    *retpage = spage;
+	    karray = kSarray;
+	    parray = pSarray;
+	    n = skeys;
+	}
+	else
+	{
+	    karray = kTarray;
+	    parray = pTarray;
+	    n = tkeys;
+	}
+	
+
+	i = 0;
+	while(i!=n && key >= karray[i])
+	    ++i;
+	if(i==n)
+	{
+	    if(key < karray[i-1])
+		blockno = parray[i-1];
+	    else
+		blockno = parray[i];
+	}
+	else
+	    blockno = parray[i];
+
+	btreeDeallocSecArray(cache,array);
+	btreeDeallocSecArray(cache,array2);
+	btreeDeallocSecArray(cache,array3);
+
+	/* ajDebug("... returns blockno (a) %Ld\n",blockno); */
+
+	return blockno;
+    }
+    
+
+    if(ppos != pkeys)	/* There is a right node */
+    {
+	spage = ajBtreeCacheRead(cache,pParray[ppos+1]);
+	sbuf = spage->buf;
+	GBT_NKEYS(sbuf,&skeys);
+    }
+
+
+    /* Space in the right leaf */
+    if(ppos != pkeys && skeys != order-1)
+    {
+	/* ajDebug("Right shift\n"); */
+	btreeGetNumKeys(cache,tbuf,&kTarray,&pTarray);
+	btreeGetNumKeys(cache,sbuf,&kSarray,&pSarray);
+
+	i = 0;
+	while(pParray[i] != tpage->pageno)
+	    ++i;
+	pkeypos = i;
+	
+	pSarray[skeys+1] = pSarray[skeys];
+	for(i=skeys-1;i>-1;--i)
+	{
+	    kSarray[i+1] = kSarray[i];
+	    pSarray[i+1] = pSarray[i];
+	}
+	kSarray[0] = kParray[pkeypos];
+	pSarray[0] = pTarray[tkeys];
+	kParray[pkeypos] = kTarray[tkeys-1];
+	++skeys;
+	--tkeys;
+	pTarray[tkeys+1] = 0L;
+	
+	btreeWriteNumNode(cache,spage,kSarray,pSarray,skeys);
+	btreeWriteNumNode(cache,tpage,kTarray,pTarray,tkeys);
+	btreeWriteNumNode(cache,ppage,kParray,pParray,pkeys);
+	if(!ppage->pageno)
+	    ppage->dirty = BT_LOCK;
+
+	i = 0;
+	while(i!=pkeys && key >= kParray[i])
+	    ++i;
+	if(i==pkeys)
+	{
+	    if(key < kParray[i-1])
+		blockno = pParray[i-1];
+	    else
+		blockno = pParray[i];
+	}
+	else
+	    blockno = pParray[i];
+
+	if(blockno == spage->pageno)
+	{
+	    *retpage = spage;
+	    karray = kSarray;
+	    parray = pSarray;
+	    n = skeys;
+	}
+	else
+	{
+	    karray = kTarray;
+	    parray = pTarray;
+	    n = tkeys;
+	}
+	
+	i = 0;
+	while(i!=n && key >= karray[i])
+	    ++i;
+	if(i==n)
+	{
+	    if(key < karray[i-1])
+		blockno = parray[i-1];
+	    else
+		blockno = parray[i];
+	}
+	else
+	    blockno = parray[i];
+
+	btreeDeallocSecArray(cache,array);
+	btreeDeallocSecArray(cache,array2);
+	btreeDeallocSecArray(cache,array3);
+
+	/* ajDebug("... returns blockno (b) %Ld\n",blockno); */
+	
+	return blockno;
+    }
+
+
+    btreeDeallocSecArray(cache,array);
+    btreeDeallocSecArray(cache,array2);
+    btreeDeallocSecArray(cache,array3);
+
+    /* ajDebug("... returns 0L\n"); */
+
+    return 0L;
+}
+
+
+
+
+void ajBtreeInsertNum(AjPBtcache cache, AjPBtNumId num, AjPBtpage page)
+{
+    unsigned char *buf = NULL;
+    ajint order;
+    AjPBtMem array = NULL;
+    ajlong key;
+    AjPBtpage spage  = NULL;
+    AjPBtpage parent = NULL;
+    ajint nkeys = 0;
+    ajint nodetype = 0;
+    ajlong *karray = NULL;
+    ajlong *parray = NULL;
+    AjPNumBucket lbucket = NULL;
+    AjPNumBucket rbucket = NULL;
+    ajlong lblockno;
+    ajlong rblockno;
+    ajlong blockno;
+    ajlong shift;
+    ajint n;
+    ajint i;
+
+    /* ajDebug("In ajBtreeInsertNum\n"); */
+
+    key = num->offset;
+
+    spage = ajBtreeNumFindInsert(cache,key);
+    buf = spage->buf;
+
+    GBT_NKEYS(buf,&nkeys);
+    GBT_NODETYPE(buf,&nodetype);
+
+    order = cache->sorder;
+
+    array = btreeAllocSecArray(cache);
+    karray = array->overflows;
+    parray = array->parray;
+
+    if(!nkeys)
+    {
+	lbucket = btreeNumBucketNew(0);
+	rbucket = btreeNumBucketNew(0);
+
+	lblockno = cache->totsize;
+	btreeWriteNumBucket(cache,lbucket,lblockno);
+	rblockno = cache->totsize;
+	btreeWriteNumBucket(cache,rbucket,rblockno);
+
+	parray[0] = lblockno;
+	parray[1] = rblockno;
+	karray[0] = key;
+
+	btreeWriteNumNode(cache,spage,karray,parray,1);
+
+	btreeNumBucketDel(&lbucket);
+	btreeNumBucketDel(&rbucket);
+
+	btreeAddToNumBucket(cache,rblockno,num);
+
+	btreeDeallocSecArray(cache,array);
+
+	return;
+    }
+
+
+    btreeGetNumKeys(cache,buf,&karray,&parray);
+    i=0;
+    while(i != nkeys && key >= karray[i])
+	++i;
+    if(i==nkeys)
+    {
+	if(key < karray[i-1])
+	    blockno = parray[i-1];
+	else
+	    blockno = parray[i];
+    }
+    else
+	blockno = parray[i];
+
+    if(nodetype != BT_ROOT)
+	if((shift = btreeNumInsertShift(cache,&spage,key)))
+	    blockno = shift;
+
+
+    buf = spage->buf;
+    n = btreeNumInNumBucket(cache,blockno);
+
+    if(n == cache->snperbucket)
+    {
+	if(btreeReorderNumBuckets(cache,spage))
+	{
+	    GBT_NKEYS(buf,&nkeys);
+	    btreeGetNumKeys(cache,buf,&karray,&parray);
+	    i=0;
+	    while(i != nkeys && key >= karray[i])
+		++i;
+	    if(i==nkeys)
+	    {
+		if(key < karray[i-1])
+		    blockno = parray[i-1];
+		else
+		    blockno = parray[i];
+	    }
+	    else
+		blockno = parray[i];
+	}
+	else
+	{
+	    parent = btreeNumSplitLeaf(cache,spage);
+	    spage = ajBtreeNumFindInsert(cache,key);
+	    buf = spage->buf;
+
+	    btreeGetNumKeys(cache,buf,&karray,&parray);
+	    GBT_NKEYS(buf,&nkeys);
+	
+	    i=0;
+	    while(i != nkeys && key >= karray[i])
+		++i;
+	    if(i==nkeys)
+	    {
+		if(key < karray[i-1])
+		    blockno = parray[i-1];
+		else
+		    blockno = parray[i];
+	    }
+	    else
+		blockno = parray[i];
+	}
+    }
+
+    btreeAddToNumBucket(cache,blockno,num);
+
+    btreeDeallocSecArray(cache,array);
+
+    ++cache->count;
+
+    return;
+}
+
+
+
+
+/* @funcstatic btreeNumSplitLeaf *********************************************
+**
+** Split a leaf and propagate up if necessary
+**
+** @param [u] cache [AjPBtcache] cache
+** @param [u] spage [AjPBtpage] page
+**
+** @return [AjPBtpage] pointer to a parent page
+** @@
+******************************************************************************/
+
+static AjPBtpage btreeNumSplitLeaf(AjPBtcache cache, AjPBtpage spage)
+{
+    ajint nkeys     = 0;
+    ajint order     = 0;
+    ajint totalkeys = 0;
+    ajint bentries  = 0;
+    ajint keylimit  = 0;
+    ajint nodetype  = 0;
+
+    ajint rootnodetype = 0;
+    
+    ajint i;
+    ajint j;
+    
+    AjPBtpage lpage = NULL;
+    AjPBtpage rpage = NULL;
+    AjPBtpage page  = NULL;
+    
+    ajlong mediankey  = 0L;
+    ajlong mediangtr  = 0L;
+    ajlong medianless = 0L;
+
+    AjPBtNumId bid = NULL;
+
+    unsigned char *buf  = NULL;
+    unsigned char *lbuf = NULL;
+    unsigned char *rbuf = NULL;
+
+    AjPList idlist = NULL;
+
+    AjPNumBucket *buckets = NULL;
+    AjPNumBucket cbucket  = NULL;
+    
+    ajlong *karray = NULL;
+    ajlong *parray = NULL;
+    
+    ajint keypos = 0;
+    ajint lno    = 0;
+    ajint rno    = 0;
+
+    ajint bucketlimit   = 0;
+    ajint maxnperbucket = 0;
+    ajint nperbucket    = 0;
+    ajint bucketn       = 0;
+    ajint count         = 0;
+    
+    ajlong lblockno = 0L;
+    ajlong rblockno = 0L;
+    ajlong overflow = 0L;
+    ajlong prevsave = 0L;
+    
+    ajlong zero = 0L;
+    ajlong join = 0L;
+    
+    ajlong lv = 0L;
+    ajint  v  = 0;
+
+    AjPBtMem array = NULL;
+    
+    
+    /* ajDebug("In btreeNumSplitLeaf\n"); */
+
+    order = cache->sorder;
+    nperbucket = cache->snperbucket;
+
+    array = btreeAllocSecArray(cache);
+    karray = array->overflows;
+    parray = array->parray;
+
+    buf = spage->buf;
+    lbuf = buf;
+
+    GBT_NKEYS(buf,&nkeys);
+    GBT_NODETYPE(buf,&rootnodetype);
+
+    if(rootnodetype == BT_ROOT)
+    {
+	/* ajDebug("Root leaf splitting\n"); */
+	lblockno = cache->totsize;
+	lpage = ajBtreeCacheWrite(cache,lblockno);
+	lpage->pageno = cache->totsize;
+	cache->totsize += cache->pagesize;
+	lbuf = lpage->buf;
+	lv = cache->secrootblock;
+	SBT_PREV(lbuf,lv);
+    }
+    else
+    {
+	lblockno = spage->pageno;
+	lpage = spage;
+    }
+
+    lpage->dirty = BT_LOCK;
+
+    rblockno = cache->totsize;
+    rpage = ajBtreeCacheWrite(cache,rblockno);
+    rpage->pageno = cache->totsize;
+    cache->totsize += cache->pagesize;
+    rbuf = rpage->buf;
+    rpage->dirty = BT_LOCK;
+
+    if(rootnodetype == BT_ROOT)
+    {
+	lv = zero;
+	SBT_RIGHT(rbuf,lv);
+	lv = zero;
+	SBT_LEFT(lbuf,lv);
+    }
+    else
+    {
+	GBT_RIGHT(lbuf,&join);
+	lv = join;
+	SBT_RIGHT(rbuf,lv);
+    }
+    lv = lblockno;
+    SBT_LEFT(rbuf,lv);
+    lv = rblockno;
+    SBT_RIGHT(lbuf,lv);
+
+
+    btreeGetNumKeys(cache,buf,&karray,&parray);
+
+
+    keylimit = nkeys+1;
+    AJCNEW0(buckets,keylimit);
+    for(i=0;i<keylimit;++i)
+	buckets[i] = btreeReadNumBucket(cache,parray[i]);
+
+    idlist = ajListNew();
+    for(i=0;i<keylimit;++i)
+    {
+	bentries = buckets[i]->Nentries;
+	for(j=0;j<bentries;++j)
+	    ajListPush(idlist,(void *)buckets[i]->NumId[j]);
+	AJFREE(buckets[i]->NumId);
+	AJFREE(buckets[i]);
+    }
+
+
+
+    ajListSort(idlist,btreeNumIdCompare);
+    AJFREE(buckets);
+
+    totalkeys = ajListLength(idlist);
+
+    keypos = totalkeys / 2;
+
+    lno = keypos;
+    rno = totalkeys - lno;
+
+    maxnperbucket = nperbucket >> 1;
+    ++maxnperbucket;
+
+    cbucket = btreeNumBucketNew(maxnperbucket);
+
+    bucketn = lno / maxnperbucket;
+    if(lno % maxnperbucket)
+	++bucketn;
+    bucketlimit = bucketn - 1;
+
+
+    count = 0;
+    for(i=0;i<bucketlimit;++i)
+    {
+	cbucket->Nentries = 0;
+	for(j=0;j<maxnperbucket;++j)
+	{
+	    ajListPop(idlist,(void **)&bid);
+
+	    cbucket->NumId[j]->offset    = bid->offset;
+	    cbucket->NumId[j]->refoffset = bid->refoffset;
+	    cbucket->NumId[j]->dbno      = bid->dbno;
+	    
+	    ++count;
+	    ++cbucket->Nentries;
+	    AJFREE(bid);
+	}
+	ajListPeek(idlist,(void **)&bid);
+
+	karray[i] = bid->offset;
+
+	if(!parray[i])
+	    parray[i] = cache->totsize;
+	btreeWriteNumBucket(cache,cbucket,parray[i]);
+    }
+
+    cbucket->Nentries = 0;
+
+    j = 0;
+    while(count != lno)
+    {
+	ajListPop(idlist,(void **)&bid);
+
+	cbucket->NumId[j]->offset    = bid->offset;
+	cbucket->NumId[j]->refoffset = bid->refoffset;
+	cbucket->NumId[j]->dbno      = bid->dbno;
+
+	++j;
+	++count;
+
+
+	++cbucket->Nentries;
+	AJFREE(bid);
+    }
+
+    if(!parray[i])
+	parray[i] = cache->totsize;
+    btreeWriteNumBucket(cache,cbucket,parray[i]);
+
+    nkeys = bucketn - 1;
+    v = nkeys;
+    SBT_NKEYS(lbuf,v);
+    nodetype = BT_LEAF;
+    v = nodetype;
+    SBT_NODETYPE(lbuf,v);
+    GBT_PREV(lbuf,&prevsave);
+    lpage->dirty = BT_DIRTY;
+    btreeWriteNumNode(cache,lpage,karray,parray,nkeys);
+
+    ajListPeek(idlist,(void **)&bid);
+    mediankey = bid->offset;
+
+    bucketn = rno / maxnperbucket;
+    if(rno % maxnperbucket)
+	++bucketn;
+    bucketlimit = bucketn - 1;
+
+    for(i=0;i<bucketlimit;++i)
+    {
+	cbucket->Nentries = 0;
+	for(j=0;j<maxnperbucket;++j)
+	{
+	    ajListPop(idlist,(void **)&bid);
+	    
+	    cbucket->NumId[j]->offset    = bid->offset;
+	    cbucket->NumId[j]->refoffset = bid->refoffset;
+	    cbucket->NumId[j]->dbno      = bid->dbno;
+	    
+	    ++cbucket->Nentries;
+	    AJFREE(bid);
+	}
+
+	ajListPeek(idlist,(void **)&bid);
+	karray[i] = bid->offset;
+
+	parray[i] = cache->totsize;
+	btreeWriteNumBucket(cache,cbucket,parray[i]);
+    }
+
+    cbucket->Nentries = 0;
+
+    j = 0;
+    while(ajListPop(idlist,(void**)&bid))
+    {
+	cbucket->NumId[j]->offset    = bid->offset;
+	cbucket->NumId[j]->refoffset = bid->refoffset;
+	cbucket->NumId[j]->dbno      = bid->dbno;
+	++j;
+
+
+	++cbucket->Nentries;
+	AJFREE(bid);
+    }
+    
+    parray[i] = cache->totsize;
+    btreeWriteNumBucket(cache,cbucket,parray[i]);
+
+    nkeys = bucketn - 1;
+
+    v = nkeys;
+    SBT_NKEYS(rbuf,v);
+    nodetype = BT_LEAF;
+    v = nodetype;
+    SBT_NODETYPE(rbuf,v);
+    lv = prevsave;
+    SBT_PREV(rbuf,lv);
+    lv = overflow;
+    SBT_OVERFLOW(rbuf,lv);
+    
+    btreeWriteNumNode(cache,rpage,karray,parray,nkeys);
+    rpage->dirty = BT_DIRTY;
+
+    cbucket->Nentries = maxnperbucket;
+    btreeNumBucketDel(&cbucket);
+    ajListDel(&idlist);
+
+
+
+    medianless = lblockno;
+    mediangtr  = rblockno;
+
+
+    if(rootnodetype == BT_ROOT)
+    {
+	karray[0] = mediankey;
+	parray[0]=lblockno;
+	parray[1]=rblockno;
+	nkeys = 1;
+	spage->dirty = BT_DIRTY;
+	btreeWriteNumNode(cache,spage,karray,parray,nkeys);	
+
+	++cache->slevel;
+	lv = cache->slevel;
+	SBT_RIGHT(buf,lv);
+	spage->dirty = BT_LOCK;
+
+	btreeDeallocSecArray(cache,array);
+
+	return spage;
+    }
+
+    btreeDeallocSecArray(cache,array);
+
+
+    page = ajBtreeCacheRead(cache,prevsave);
+    btreeNumInsertKey(cache,page,mediankey,medianless,mediangtr);
+
+
+    page = ajBtreeCacheRead(cache,prevsave);
+
+    return page;
+}
+
+
+
+
+/* @func ajBtreeFreePriArray *******************************************
+**
+** Free karray and parray arrays for a primary key
+**
+** @param [rw] cache [AjPBtcache] cache
+**
+** @return [void]
+** @@
+******************************************************************************/
+
+void ajBtreeFreePriArray(AjPBtcache cache)
+{
+    AjPBtMem p;
+    AjPBtMem next;
+    ajint i;
+
+    /* ajDebug("In ajBtreeFreePriArray\n"); */
+    
+    if(!cache->bmem)
+	return;
+
+    p = cache->bmem;
+    next = p->next;
+    
+    while(next)
+    {
+	AJFREE(p->parray);
+	AJFREE(p->overflows);
+	for(i=0;i<cache->order;++i)
+	    ajStrDel(&p->karray[i]);
+	AJFREE(p->karray);
+	AJFREE(p);
+	p = next;
+	next = p->next;
+    }
+    
+
+    AJFREE(p->parray);
+    AJFREE(p->overflows);
+    for(i=0;i<cache->order;++i)
+	ajStrDel(&p->karray[i]);
+    AJFREE(p->karray);
+    AJFREE(p);
+    
+    cache->bmem = NULL;
+    cache->tmem = NULL;
+
+    return;
+}
+
+
+
+
+/* @func ajBtreeFreeSecArray *******************************************
+**
+** Free karray and parray arrays for a secondary key
+**
+** @param [rw] cache [AjPBtcache] cache
+**
+** @return [void]
+** @@
+******************************************************************************/
+
+void ajBtreeFreeSecArray(AjPBtcache cache)
+{
+    AjPBtMem p;
+    AjPBtMem next;
+    ajint i;
+
+    /* ajDebug("In ajBtreeFreeSecArray\n"); */
+    
+    if(!cache->bsmem)
+	return;
+
+    p = cache->bsmem;
+    next = p->next;
+    
+    while(next)
+    {
+	AJFREE(p->parray);
+	AJFREE(p->overflows);
+	for(i=0;i<cache->sorder;++i)
+	    ajStrDel(&p->karray[i]);
+	AJFREE(p->karray);
+	AJFREE(p);
+	
+	p = next;
+	next = p->next;
+    }
+    
+
+    AJFREE(p->parray);
+    AJFREE(p->overflows);
+    for(i=0;i<cache->sorder;++i)
+	ajStrDel(&p->karray[i]);
+    AJFREE(p->karray);
+    AJFREE(p);
+
+    cache->bsmem = NULL;
+    cache->tsmem = NULL;
+
+    return;
+}
+
+
+
+
+/* @func ajBtreeHybLeafList ********************************************
+**
+** Read the leaves of a secondary hybrid tree
+**
+** @param [u] cache [AjPBtcache] cache
+** @param [r] rootblock [ajlong] root page of secondary tree
+** @param [r] idname [AjPStr] id name
+** @param [r] list [AjPList] list to add BtIDs to
+**
+** @return [void]
+** @@
+******************************************************************************/
+
+void ajBtreeHybLeafList(AjPBtcache cache, ajlong rootblock, AjPStr idname,
+			AjPList list)
+{
+    AjPBtId id = NULL;
+    
+    ajint order;
+    ajlong *karray;
+    ajlong *parray;
+    AjPBtpage page;
+    unsigned char *buf;
+    ajint nodetype;
+    ajint i;
+    ajint j;
+    ajlong level = 0L;
+    
+    AjPNumBucket bucket;
+    ajint nkeys;
+    ajlong right;
+    AjPBtMem array = NULL;
+
+    order = cache->sorder;
+
+    array = btreeAllocSecArray(cache);
+    karray = array->overflows;
+    parray = array->parray;
+
+    page = ajBtreeCacheRead(cache, rootblock);
+    buf = page->buf;
+
+    GBT_RIGHT(buf,&level);
+    cache->slevel = (ajint) level;
+
+    btreeGetNumKeys(cache,buf,&karray,&parray);
+    GBT_NODETYPE(buf,&nodetype);
+
+    while(nodetype != BT_LEAF && cache->slevel != 0)
+    {
+	page = ajBtreeCacheRead(cache,parray[0]);
+	buf = page->buf;
+	btreeGetNumKeys(cache,buf,&karray,&parray);
+	GBT_NODETYPE(buf,&nodetype);
+    }
+
+    do
+    {
+	GBT_NKEYS(buf,&nkeys);
+	for(i=0;i<nkeys+1;++i)
+	{
+	    bucket = btreeReadNumBucket(cache,parray[i]);
+	    for(j=0;j<bucket->Nentries;++j)
+	    {
+		id = ajBtreeIdNew();
+		ajStrAssS(&id->id,idname);
+		id->offset = bucket->NumId[j]->offset;
+		id->refoffset = bucket->NumId[j]->refoffset;
+		id->dbno = bucket->NumId[j]->dbno;
+		ajListPush(list, (void*)id);
+	    }
+	    btreeNumBucketDel(&bucket);
+	}
+
+	right = 0L;
+	if(cache->slevel)
+	{
+	    GBT_RIGHT(buf,&right);
+	    if(right)
+	    {
+		page = ajBtreeCacheRead(cache,right);
+		buf = page->buf;
+		btreeGetNumKeys(cache,buf,&karray,&parray);
+	    }
+	}
+    } while(right);
+
+    btreeDeallocSecArray(cache,array);
+
+    return;
+}
+
