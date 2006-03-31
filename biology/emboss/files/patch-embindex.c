--- nucleus/embindex.c.orig	Mon Jan 23 12:24:54 2006
+++ nucleus/embindex.c	Thu Dec 22 13:12:38 2005
@@ -973,15 +973,14 @@
 	if(!do_ref)
 	{
 	    ajListPop(entry->files,(void **)&tmpstr);
-	    ajFmtPrintF(entfile,"%S%S\n",entry->directory,tmpstr);
+	    ajFmtPrintF(entfile,"%S\n",tmpstr);
 	    ajListPushApp(entry->files,(void *)tmpstr);
 	}
 	else
 	{
 	    ajListPop(entry->files,(void **)&tmpstr);
 	    ajListPop(entry->reffiles,(void **)&refstr);
-	    ajFmtPrintF(entfile,"%S%S %S%S\n",entry->directory,tmpstr,
-			entry->directory,refstr);
+	    ajFmtPrintF(entfile,"%S %S\n",tmpstr, refstr);
 	    ajListPushApp(entry->files,(void *)tmpstr);
 	    ajListPushApp(entry->reffiles,(void *)refstr);
 	}
@@ -1150,7 +1149,15 @@
     entry->desecfill  = (entry->pagesize - 16) / (entry->idlen + 4);
     entry->txsecfill  = (entry->pagesize - 16) / (entry->idlen + 4);
 
+    entry->idsecorder = (entry->pagesize - 60) / 24;
+    entry->idsecfill  = (entry->pagesize - 60) / 20;
 
+    entry->acsecorder = (entry->pagesize - 60) / 24;
+    entry->acsecfill  = (entry->pagesize - 60) / 20;
+
+    entry->svsecorder = (entry->pagesize - 60) / 24;
+    entry->svsecfill  = (entry->pagesize - 60) / 20;
+    
     ajStrDel(&value);
 
     return;
@@ -1183,28 +1190,38 @@
 
     if(entry->do_id)
     {
-	entry->idcache = ajBtreeCacheNewC(basenam,ID_EXTENSION,idir,"w+",
-					  entry->pagesize, entry->idorder,
-					  entry->idfill, level,
-					  entry->cachesize);
+	entry->idcache = ajBtreeSecCacheNewC(basenam,ID_EXTENSION,idir,"w+",
+					     entry->pagesize, entry->idorder,
+					     entry->idfill, level,
+					     entry->cachesize,
+					     entry->idsecorder, slevel,
+					     entry->idsecfill, count,
+					     entry->kwlen);
 	ajBtreeCreateRootNode(entry->idcache,0L);
     }
 
     if(entry->do_accession)
     {
-	entry->accache = ajBtreeCacheNewC(basenam,AC_EXTENSION,idir,"w+",
-					  entry->pagesize, entry->acorder,
-					  entry->acfill, level,
-					  entry->cachesize);
+	entry->accache = ajBtreeSecCacheNewC(basenam,AC_EXTENSION,idir,"w+",
+					     entry->pagesize,
+					     entry->acorder, entry->acfill,
+					     level,
+					     entry->cachesize,
+					     entry->acsecorder, slevel,
+					     entry->acsecfill, count,
+					     entry->kwlen);
 	ajBtreeCreateRootNode(entry->accache,0L);
     }
 
     if(entry->do_sv)
     {
-	entry->svcache = ajBtreeCacheNewC(basenam,SV_EXTENSION,idir,"w+",
-					  entry->pagesize, entry->svorder,
-					  entry->svfill, level,
-					  entry->cachesize);
+	entry->svcache = ajBtreeSecCacheNewC(basenam,SV_EXTENSION,idir,"w+",
+					     entry->pagesize, entry->svorder,
+					     entry->svfill, level,
+					     entry->cachesize,
+					     entry->svsecorder, slevel,
+					     entry->svsecfill, count,
+					     entry->kwlen);
 	ajBtreeCreateRootNode(entry->svcache,0L);
     }
 
@@ -1270,18 +1287,27 @@
 
     if(entry->do_id)
     {
+	ajBtreeFreePriArray(entry->idcache);
+	ajBtreeFreeSecArray(entry->idcache);
+
 	ajBtreeCacheSync(entry->idcache,0L);
 	ajBtreeCacheDel(&entry->idcache);
     }
 
     if(entry->do_accession)
     {
+	ajBtreeFreePriArray(entry->accache);
+	ajBtreeFreeSecArray(entry->accache);
+
 	ajBtreeCacheSync(entry->accache,0L);
 	ajBtreeCacheDel(&entry->accache);
     }
 
     if(entry->do_sv)
     {
+	ajBtreeFreePriArray(entry->svcache);
+	ajBtreeFreeSecArray(entry->svcache);
+
 	ajBtreeCacheSync(entry->svcache,0L);
 	ajBtreeCacheDel(&entry->svcache);
     }
