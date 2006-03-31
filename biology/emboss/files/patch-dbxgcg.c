--- emboss/dbxgcg.c.orig	Mon Jan 23 12:22:30 2006
+++ emboss/dbxgcg.c	Thu Dec 22 13:13:18 2005
@@ -2,7 +2,7 @@
 **
 ** Index flatfile databases
 **
-** @author: Copyright (C) Alan Bleasby (ableasby@hgmp.mrc.ac.uk)
+** @author Copyright (C) Alan Bleasby (ableasby@hgmp.mrc.ac.uk)
 ** @@
 **
 ** This program is free software; you can redistribute it and/or
@@ -136,6 +136,7 @@
     
     AjPBtId  idobj  = NULL;
     AjPBtPri priobj = NULL;
+    AjPBtHybrid hyb = NULL;
     
 
     embInit("dbxgcg", argc, argv);
@@ -156,7 +157,8 @@
     
     idobj   = ajBtreeIdNew();
     priobj  = ajBtreePriNew();
-
+    hyb     = ajBtreeHybNew();
+    
 
     nfields = embBtreeSetFields(entry,fieldarray);
     embBtreeSetDbInfo(entry,dbname,dbrs,datestr,release,dbtype,directory,
@@ -204,12 +206,12 @@
 	    if(entry->do_id)
 	    {
 		ajStrToLower(&entry->id);
-		ajStrAssS(&idobj->id,entry->id);
-		idobj->dbno = i;
-		idobj->offset = entry->fpos;
-		idobj->refoffset = entry->reffpos;
-		idobj->dups = 0;
-		ajBtreeInsertId(entry->idcache,idobj);
+		ajStrAssS(&hyb->key1,entry->id);
+		hyb->dbno = i;
+		hyb->offset = entry->fpos;
+		hyb->refoffset = entry->reffpos;
+		hyb->dups = 0;
+		ajBtreeHybInsertId(entry->idcache,hyb);
 	    }
 
 	    if(entry->do_accession)
@@ -217,12 +219,12 @@
                 while(ajListPop(entry->ac,(void **)&word))
                 {
 		    ajStrToLower(&word);
-                    ajStrAssS(&idobj->id,word);
-                    idobj->dbno = i;
-		    idobj->offset = entry->fpos;
-		    idobj->refoffset = entry->reffpos;
-		    idobj->dups = 0;
-		    ajBtreeInsertId(entry->accache,idobj);
+                    ajStrAssS(&hyb->key1,word);
+                    hyb->dbno = i;
+		    hyb->offset = entry->fpos;
+		    hyb->refoffset = entry->reffpos;
+		    hyb->dups = 0;
+		    ajBtreeHybInsertId(entry->accache,hyb);
 		    ajStrDel(&word);
                 }
 	    }
@@ -232,12 +234,12 @@
                 while(ajListPop(entry->sv,(void **)&word))
                 {
 		    ajStrToLower(&word);
-                    ajStrAssS(&idobj->id,word);
-                    idobj->dbno = i;
-		    idobj->offset = entry->fpos;
-		    idobj->refoffset = entry->reffpos;
-		    idobj->dups = 0;
-		    ajBtreeInsertId(entry->svcache,idobj);
+                    ajStrAssS(&hyb->key1,word);
+                    hyb->dbno = i;
+		    hyb->offset = entry->fpos;
+		    hyb->refoffset = entry->reffpos;
+		    hyb->dups = 0;
+		    ajBtreeHybInsertId(entry->svcache,hyb);
 		    ajStrDel(&word);
                 }
 	    }
@@ -303,7 +305,8 @@
 
     ajBtreeIdDel(&idobj);
     ajBtreePriDel(&priobj);
-
+    ajBtreeHybDel(&hyb);
+    
     ajExit();
 
     return 0;
