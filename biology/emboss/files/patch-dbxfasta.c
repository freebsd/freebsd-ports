--- emboss/dbxfasta.c.orig	Mon Jan 23 12:22:12 2006
+++ emboss/dbxfasta.c	Wed Jan  4 16:31:37 2006
@@ -2,7 +2,7 @@
 **
 ** Index flatfile databases
 **
-** @author: Copyright (C) Alan Bleasby (ableasby@hgmp.mrc.ac.uk)
+** @author Copyright (C) Alan Bleasby (ableasby@hgmp.mrc.ac.uk)
 ** @@
 **
 ** This program is free software; you can redistribute it and/or
@@ -77,6 +77,7 @@
     
     AjPBtId  idobj  = NULL;
     AjPBtPri priobj = NULL;
+    AjPBtHybrid hyb = NULL;
     
 
     AjPRegexp typeexp = NULL;
@@ -102,7 +103,8 @@
     
     idobj   = ajBtreeIdNew();
     priobj  = ajBtreePriNew();
-
+    hyb     = ajBtreeHybNew();
+    
 
     nfields = embBtreeSetFields(entry,fieldarray);
     embBtreeSetDbInfo(entry,dbname,dbrs,datestr,release,dbtype,directory,
@@ -134,22 +136,22 @@
 	    if(entry->do_id)
 	    {
 		ajStrToLower(&entry->id);
-		ajStrAssS(&idobj->id,entry->id);
-		idobj->dbno = i;
-		idobj->offset = entry->fpos;
-		idobj->dups = 0;
-		ajBtreeInsertId(entry->idcache,idobj);
+		ajStrAssS(&hyb->key1,entry->id);
+		hyb->dbno = i;
+		hyb->offset = entry->fpos;
+		hyb->dups = 0;
+		ajBtreeHybInsertId(entry->idcache,hyb);
 	    }
 
 	    if(entry->do_accession)
                 while(ajListPop(entry->ac,(void **)&word))
                 {
 		    ajStrToLower(&word);
-                    ajStrAssS(&idobj->id,word);
-                    idobj->dbno = i;
-		    idobj->offset = entry->fpos;
-		    idobj->dups = 0;
-		    ajBtreeInsertId(entry->accache,idobj);
+                    ajStrAssS(&hyb->key1,word);
+                    hyb->dbno = i;
+		    hyb->offset = entry->fpos;
+		    hyb->dups = 0;
+		    ajBtreeHybInsertId(entry->accache,hyb);
 		    ajStrDel(&word);
                 }
 
@@ -157,11 +159,11 @@
                 while(ajListPop(entry->sv,(void **)&word))
                 {
 		    ajStrToLower(&word);
-                    ajStrAssS(&idobj->id,word);
-                    idobj->dbno = i;
-		    idobj->offset = entry->fpos;
-		    idobj->dups = 0;
-		    ajBtreeInsertId(entry->svcache,idobj);
+                    ajStrAssS(&hyb->key1,word);
+                    hyb->dbno = i;
+		    hyb->offset = entry->fpos;
+		    hyb->dups = 0;
+		    ajBtreeHybInsertId(entry->svcache,hyb);
 		    ajStrDel(&word);
                 }
 
@@ -197,7 +199,8 @@
 
     ajBtreeIdDel(&idobj);
     ajBtreePriDel(&priobj);
-
+    ajBtreeHybDel(&hyb);
+    
     ajExit();
 
     return 0;
