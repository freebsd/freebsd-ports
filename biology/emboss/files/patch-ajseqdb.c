--- ajax/ajseqdb.c.orig	Mon Jan 23 12:20:25 2006
+++ ajax/ajseqdb.c	Thu Dec 22 13:12:57 2005
@@ -27,8 +27,7 @@
 ******************************************************************************/
 
 #include "ajax.h"
-#include "ajmem.h"
-#include "ajfile.h"
+
 #include "limits.h"
 #include <stdarg.h>
 #include <sys/types.h>
@@ -3055,13 +3054,13 @@
 
 
     if(qryd->do_id)
-        seqEmbossOpenCache(qry,ID_EXTENSION,&qryd->idcache);
+        seqEmbossOpenSecCache(qry,ID_EXTENSION,&qryd->idcache);
 
     if(qryd->do_ac)
-	seqEmbossOpenCache(qry,AC_EXTENSION,&qryd->accache);
+	seqEmbossOpenSecCache(qry,AC_EXTENSION,&qryd->accache);
 
     if(qryd->do_sv)
-	seqEmbossOpenCache(qry,SV_EXTENSION,&qryd->svcache);
+	seqEmbossOpenSecCache(qry,SV_EXTENSION,&qryd->svcache);
 
     if(qryd->do_kw)
     {
@@ -3073,14 +3072,14 @@
     if(qryd->do_de)
     {
 	if(!qryd->idcache)
-	    seqEmbossOpenCache(qry,ID_EXTENSION,&qryd->idcache);	
+	    seqEmbossOpenSecCache(qry,ID_EXTENSION,&qryd->idcache);	
 	seqEmbossOpenSecCache(qry,DE_EXTENSION,&qryd->decache);
     }
 
     if(qryd->do_tx)
     {
 	if(!qryd->idcache)
-	    seqEmbossOpenCache(qry,ID_EXTENSION,&qryd->idcache);	
+	    seqEmbossOpenSecCache(qry,ID_EXTENSION,&qryd->idcache);	
 	seqEmbossOpenSecCache(qry,TX_EXTENSION,&qryd->txcache);
     }
 
@@ -3149,6 +3148,7 @@
     if(qryd->nentries == -1)
 	qryd->nentries = ajBtreeReadEntries(ajStrStr(qry->DbAlias),
 					    ajStrStr(qry->IndexDir),
+					    ajStrStr(qry->Directory),
 					    &qryd->files,&qryd->reffiles);
 
     *cache = ajBtreeCacheNewC(ajStrStr(qry->DbAlias),ext,
@@ -3209,6 +3209,7 @@
     if(qryd->nentries == -1)
 	qryd->nentries = ajBtreeReadEntries(ajStrStr(qry->DbAlias),
 					    ajStrStr(qry->IndexDir),
+					    ajStrStr(qry->Directory),
 					    &qryd->files,&qryd->reffiles);
     
     
@@ -3270,6 +3271,7 @@
 
 
     n = ajBtreeReadEntries(qry->DbAlias->Ptr,qry->IndexDir->Ptr,
+			   qry->Directory->Ptr,
 			   &filestrings,&reffilestrings);
 
 
@@ -3365,7 +3367,13 @@
     {
 	    entry = ajBtreeIdFromKey(qryd->idcache,ajStrStr(qry->Id));
 	    if(entry)
-		ajListPushApp(qryd->List,(void *)entry);
+	    {
+		if(!entry->dups)
+		    ajListPushApp(qryd->List,(void *)entry);
+		else
+		    ajBtreeHybLeafList(qryd->idcache,entry->offset,
+				       entry->id,qryd->List);
+	    }
     }
     
 
@@ -3373,14 +3381,26 @@
     {
 	    entry = ajBtreeIdFromKey(qryd->accache,ajStrStr(qry->Acc));
 	    if(entry)
-		ajListPushApp(qryd->List,(void *)entry);
+	    {
+		if(!entry->dups)
+		    ajListPushApp(qryd->List,(void *)entry);
+		else
+		    ajBtreeHybLeafList(qryd->accache,entry->offset,
+				       entry->id,qryd->List);
+	    }
     }
 
     if((qryd->do_sv && !entry) && (qryd->do_sv && qryd->svcache))
     {
 	    entry = ajBtreeIdFromKey(qryd->svcache,ajStrStr(qry->Gi));
 	    if(entry)
-		ajListPushApp(qryd->List,(void *)entry);
+	    {
+		if(!entry->dups)
+		    ajListPushApp(qryd->List,(void *)entry);
+		else
+		    ajBtreeHybLeafList(qryd->svcache,entry->offset,
+				       entry->id,qryd->List);
+	    }
     }
 
     if(!ajListLength(qryd->List))
@@ -3512,13 +3532,25 @@
     qryd = qry->QryData;
 
     if(qryd->do_id && qryd->idcache)
+    {
+	ajBtreeFreeSecArray(qryd->idcache);
 	ajBtreeCacheDel(&qryd->idcache);
+    }
+    
 
     if(qryd->do_ac && qryd->accache)
+    {
+	ajBtreeFreeSecArray(qryd->accache);	
 	ajBtreeCacheDel(&qryd->accache);
+    }
+    
 
     if(qryd->do_sv && qryd->svcache)
+    {
+	ajBtreeFreeSecArray(qryd->svcache);	
 	ajBtreeCacheDel(&qryd->svcache);
+    }
+
 
     if(qryd->do_kw && qryd->kwcache)
 	ajBtreeCacheDel(&qryd->kwcache);
@@ -3608,7 +3640,14 @@
 		    ajStrToLower(&kwid);
 		    id = ajBtreeIdFromKey(qryd->idcache,ajStrStr(kwid));
 		    if(id)
-			ajListPushApp(qryd->List,(void *)id);
+		    {
+			if(!id->dups)
+			    ajListPushApp(qryd->List,(void *)id);
+			else
+			    ajBtreeHybLeafList(qryd->idcache,id->offset,
+					       id->id,qryd->List);
+		    }
+		    ajStrDel(&kwid);
 		}
 		ajListDel(&tlist);
 		ajBtreePriDel(&pri);
@@ -3637,7 +3676,13 @@
 		    ajStrToLower(&kwid);
 		    id = ajBtreeIdFromKey(qryd->idcache,ajStrStr(kwid));
 		    if(id)
-			ajListPushApp(qryd->List,(void *)id);
+		    {
+			if(!id->dups)
+			    ajListPushApp(qryd->List,(void *)id);
+			else
+			    ajBtreeHybLeafList(qryd->idcache,id->offset,
+					       id->id,qryd->List);
+		    }
 		    ajStrDel(&kwid);
 		}
 		ajListDel(&tlist);
@@ -3667,7 +3712,14 @@
 		    ajStrToLower(&kwid);
 		    id = ajBtreeIdFromKey(qryd->idcache,ajStrStr(kwid));
 		    if(id)
-			ajListPushApp(qryd->List,(void *)id);
+		    {
+			if(!id->dups)
+			    ajListPushApp(qryd->List,(void *)id);
+			else
+			    ajBtreeHybLeafList(qryd->idcache,id->offset,
+					       id->id,qryd->List);
+		    }
+		    ajStrDel(&kwid);
 		}
 		ajListDel(&tlist);
 		ajBtreePriDel(&pri);
@@ -3832,6 +3884,7 @@
 	qryd = qry->QryData;
 	i = -1;
 	ajBtreeReadEntries(qry->DbAlias->Ptr,qry->IndexDir->Ptr,
+			   qry->Directory->Ptr,
 			   &qryd->files,&qryd->reffiles);
 
 	seqin->Single = ajTrue;
