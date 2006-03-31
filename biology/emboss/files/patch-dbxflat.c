--- emboss/dbxflat.c.orig	Mon Jan 23 12:22:23 2006
+++ emboss/dbxflat.c	Sun Jan  1 07:29:09 2006
@@ -2,7 +2,7 @@
 **
 ** Index flatfile databases
 **
-** @author: Copyright (C) Alan Bleasby (ableasby@hgmp.mrc.ac.uk)
+** @author Copyright (C) Alan Bleasby (ableasby@hgmp.mrc.ac.uk)
 ** @@
 **
 ** This program is free software; you can redistribute it and/or
@@ -106,6 +106,7 @@
     
     AjPBtId  idobj  = NULL;
     AjPBtPri priobj = NULL;
+    AjPBtHybrid hyb = NULL;
     
 
     embInit("dbxflat", argc, argv);
@@ -126,7 +127,8 @@
     
     idobj   = ajBtreeIdNew();
     priobj  = ajBtreePriNew();
-
+    hyb     = ajBtreeHybNew();
+    
 
     nfields = embBtreeSetFields(entry,fieldarray);
     embBtreeSetDbInfo(entry,dbname,dbrs,datestr,release,dbtype,directory,
@@ -156,11 +158,11 @@
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
@@ -168,11 +170,11 @@
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
 	    }
@@ -182,11 +184,11 @@
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
 	    }
@@ -231,15 +233,11 @@
 	    }
 	}
 	
-
-
-
-
-
 	ajFileClose(&inf);
     }
     
 
+
     embBtreeDumpParameters(entry);
     embBtreeCloseCaches(entry);
     
@@ -256,7 +254,8 @@
 
     ajBtreeIdDel(&idobj);
     ajBtreePriDel(&priobj);
-
+    ajBtreeHybDel(&hyb);
+    
     ajExit();
 
     return 0;
@@ -306,11 +305,13 @@
 	}
 
 	if(entry->do_sv)
-	    if(ajStrPrefixC(line,"SV"))
+	    if(ajStrPrefixC(line,"SV") ||
+	       ajStrPrefixC(line,"IV"))	/* emblcds database format */
 		embBtreeEmblAC(line,entry->sv);
 
 	if(entry->do_accession)
-	    if(ajStrPrefixC(line,"AC"))
+	    if(ajStrPrefixC(line,"AC") ||
+	       ajStrPrefixC(line,"PA"))	/* emblcds database format */
 		embBtreeEmblAC(line,entry->ac);
 	
 	if(entry->do_keyword)
@@ -356,12 +357,10 @@
     
     line = ajStrNewC("");
     sumline = ajStrNew();
+
     
     while(!ajStrPrefixC(line,"//") && ret)
     {
-	pos = ajFileTell(inf);
-	
-	
 	if(ajStrPrefixC(line,"LOCUS"))
 	{
 	    entry->fpos = pos;
@@ -423,7 +422,7 @@
 	    }
 	
 
-
+	pos = ajFileTell(inf);
 
 	if(!ajFileReadLine(inf,&line))
 	    ret = ajFalse;
