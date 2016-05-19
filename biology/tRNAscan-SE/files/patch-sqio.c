--- sqio.c.orig	2002-04-12 20:12:04 UTC
+++ sqio.c
@@ -235,7 +235,7 @@ readline(FILE *f, char *s)
 }
 
 static void 
-getline(struct ReadSeqVars *V)
+get_line(struct ReadSeqVars *V)
 {
   readline(V->f, V->sbuffer);
 }
@@ -306,7 +306,7 @@ readLoop(int addfirst, int (*endTest)(ch
   V->seqlen = 0;
   if (addfirst) addseq(V->sbuffer, V);
   do {
-    getline(V);
+    get_line(V);
     done = feof(V->f);
     done |= (*endTest)(V->sbuffer, &addend);
     if (addend || !done)
@@ -332,7 +332,7 @@ readPIR(struct ReadSeqVars *V)
   char *sptr;
 				/* load first line of entry  */
   while (!feof(V->f) && strncmp(V->sbuffer, "ENTRY", 5) != 0)
-    getline(V);
+    get_line(V);
   if (feof(V->f)) return;
 
   if ((sptr = strtok(V->sbuffer + 15, "\n\t ")) != NULL)
@@ -341,7 +341,7 @@ readPIR(struct ReadSeqVars *V)
       SetSeqinfoString(V->sqinfo, sptr, SQINFO_ID);
     }
   do {
-    getline(V);
+    get_line(V);
     if (!feof(V->f) && strncmp(V->sbuffer, "TITLE", 5) == 0)
       SetSeqinfoString(V->sqinfo, V->sbuffer+15, SQINFO_DESC);
     else if (!feof(V->f) && strncmp(V->sbuffer, "ACCESSION", 9) == 0)
@@ -350,7 +350,7 @@ readPIR(struct ReadSeqVars *V)
 	  SetSeqinfoString(V->sqinfo, sptr, SQINFO_ACC);
       }
   } while (! feof(V->f) && (strncmp(V->sbuffer,"SEQUENCE", 8) != 0));
-  getline(V);			/* skip next line, coords */
+  get_line(V);			/* skip next line, coords */
 
   readLoop(0, endPIR, V);
 
@@ -364,7 +364,7 @@ readPIR(struct ReadSeqVars *V)
   /* get next line
    */
   while (!feof(V->f) && strncmp(V->sbuffer, "ENTRY", 5) != 0)
-    getline(V);
+    get_line(V);
 }
 
 
@@ -382,7 +382,7 @@ readIG(struct ReadSeqVars *V)
   char *nm;
 				/* position past ';' comments */
   do {
-    getline(V);
+    get_line(V);
   } while (! (feof(V->f) || ((*V->sbuffer != 0) && (*V->sbuffer != ';')) ));
 
   if (!feof(V->f))
@@ -394,7 +394,7 @@ readIG(struct ReadSeqVars *V)
     }
   
   while (!(feof(V->f) || ((*V->sbuffer != '\0') && (*V->sbuffer == ';'))))
-    getline(V);
+    get_line(V);
 }
 
 static int 
@@ -416,7 +416,7 @@ readStrider(struct ReadSeqVars *V)
 	  if ((nm = strtok(V->sbuffer+16, ",\n\t ")) != NULL)
 	    SetSeqinfoString(V->sqinfo, nm, SQINFO_NAME);
 	}
-      getline(V);
+      get_line(V);
     }
 
   if (! feof(V->f))
@@ -425,7 +425,7 @@ readStrider(struct ReadSeqVars *V)
   /* load next line
    */
   while ((!feof(V->f)) && (*V->sbuffer != ';')) 
-    getline(V);
+    get_line(V);
 }
 
 
@@ -443,7 +443,7 @@ readGenBank(struct ReadSeqVars *V)
   int   in_definition;
 
   while (strncmp(V->sbuffer, "LOCUS", 5) != 0)
-    getline(V);
+    get_line(V);
 
   if ((sptr = strtok(V->sbuffer+12, "\n\t ")) != NULL)
     {
@@ -454,7 +454,7 @@ readGenBank(struct ReadSeqVars *V)
   in_definition = FALSE;
   while (! feof(V->f))
     {
-      getline(V);
+      get_line(V);
       if (! feof(V->f) && strstr(V->sbuffer, "DEFINITION") == V->sbuffer)
 	{
 	  if ((sptr = strtok(V->sbuffer+12, "\n")) != NULL)
@@ -487,11 +487,11 @@ readGenBank(struct ReadSeqVars *V)
 
 
   while (!(feof(V->f) || ((*V->sbuffer!=0) && (strstr(V->sbuffer,"LOCUS") == V->sbuffer))))
-    getline(V);
+    get_line(V);
 				/* SRE: V->s now holds "//", so sequential
 				   reads are wedged: fixed Tue Jul 13 1993 */
   while (!feof(V->f) && strstr(V->sbuffer, "LOCUS  ") != V->sbuffer)
-    getline(V);
+    get_line(V);
 }
 
 static int
@@ -521,12 +521,12 @@ readNBRF(struct ReadSeqVars *V)
   if ((sptr = strtok(V->sbuffer+4, "\n\t ")) != NULL)
     SetSeqinfoString(V->sqinfo, sptr, SQINFO_NAME);
 
-  getline(V);   /*skip title-junk line*/
+  get_line(V);   /*skip title-junk line*/
 
   readLoop(0, endNBRF, V);
 
   while (!(feof(V->f) || (*V->sbuffer != 0 && *V->sbuffer == '>')))
-    getline(V);
+    get_line(V);
 }
 
 
@@ -559,7 +559,7 @@ readGCGdata(struct ReadSeqVars *V)
   } else Die("bogus GCGdata format? %s", V->sbuffer);
 
 				/* second line contains free text description */
-  getline(V);
+  get_line(V);
   SetSeqinfoString(V->sqinfo, V->sbuffer, SQINFO_DESC);
 
   if (binary) {
@@ -579,7 +579,7 @@ readGCGdata(struct ReadSeqVars *V)
   else readLoop(0, endGCGdata, V);
   
   while (!(feof(V->f) || ((*V->sbuffer != 0) && (*V->sbuffer == '>'))))
-    getline(V);
+    get_line(V);
 }
 
 static int
@@ -625,7 +625,7 @@ readPearson(struct ReadSeqVars *V)
     readLoop(0, endPearson, V);
 
   while (!(feof(V->f) || ((*V->sbuffer != 0) && (*V->sbuffer == '>'))))
-    getline(V);
+    get_line(V);
 }
 
 
@@ -652,7 +652,7 @@ readEMBL(struct ReadSeqVars *V)
 
 				/* make sure we have first line */
   while (!feof(V->f) && strncmp(V->sbuffer, "ID  ", 4) != 0)
-    getline(V);
+    get_line(V);
 
   if ((sptr = strtok(V->sbuffer+5, "\n\t ")) != NULL)
     {
@@ -661,7 +661,7 @@ readEMBL(struct ReadSeqVars *V)
     }
 
   do {
-    getline(V);
+    get_line(V);
     if (!feof(V->f) && strstr(V->sbuffer, "AC  ") == V->sbuffer)
       {
 	if ((sptr = strtok(V->sbuffer+5, ";  \t\n")) != NULL)
@@ -685,7 +685,7 @@ readEMBL(struct ReadSeqVars *V)
 
 				/* load next record's ID line */
   while (!feof(V->f) && strncmp(V->sbuffer, "ID  ", 4) != 0)
-    getline(V);
+    get_line(V);
 }
 
 
@@ -701,7 +701,7 @@ readZuker(struct ReadSeqVars *V)
 {
   char *sptr;
 
-  getline(V);  /*s == "seqLen seqid string..."*/
+  get_line(V);  /*s == "seqLen seqid string..."*/
 
   if ((sptr = strtok(V->sbuffer+6, " \t\n")) != NULL)
     SetSeqinfoString(V->sqinfo, sptr, SQINFO_NAME);
@@ -712,7 +712,7 @@ readZuker(struct ReadSeqVars *V)
   readLoop(0, endZuker, V);
 
   while (!(feof(V->f) | ((*V->sbuffer != '\0') & (*V->sbuffer == '('))))
-    getline(V);
+    get_line(V);
 }
 
 static void 
@@ -734,7 +734,7 @@ readUWGCG(struct ReadSeqVars *V)
 
   do {
     done = feof(V->f);
-    getline(V);
+    get_line(V);
     if (! done) addseq(V->sbuffer, V);
   } while (!done);
 }
@@ -746,7 +746,7 @@ readSquid(struct ReadSeqVars *V)
   char *sptr;
   int   dostruc = FALSE;
 
-  while (strncmp(V->sbuffer, "NAM ", 4) != 0) getline(V);
+  while (strncmp(V->sbuffer, "NAM ", 4) != 0) get_line(V);
 
   if ((sptr = strtok(V->sbuffer+4, "\n\t ")) != NULL)
     SetSeqinfoString(V->sqinfo, sptr, SQINFO_NAME);
@@ -754,7 +754,7 @@ readSquid(struct ReadSeqVars *V)
   /*CONSTCOND*/
   while (1)
     {
-      getline(V);
+      get_line(V);
       if (feof(V->f)) {squid_errno = SQERR_FORMAT; return; }
 
       if (strncmp(V->sbuffer, "SRC ", 4) == 0)
@@ -786,14 +786,14 @@ readSquid(struct ReadSeqVars *V)
   while (1)
     {
 				/* sequence line */
-      getline(V);
+      get_line(V);
       if (feof(V->f) || strncmp(V->sbuffer, "++", 2) == 0) 
 	break;
       addseq(V->sbuffer, V);
 				/* structure line */
       if (dostruc)
 	{
-	  getline(V);
+	  get_line(V);
 	  if (feof(V->f)) { squid_errno = SQERR_FORMAT; return; }
 	  addstruc(V->sbuffer, V);
 	}
@@ -801,7 +801,7 @@ readSquid(struct ReadSeqVars *V)
 
 
   while (!feof(V->f) && strncmp(V->sbuffer, "NAM ", 4) != 0)
-    getline(V);
+    get_line(V);
 }
 
 
@@ -848,7 +848,7 @@ SeqfileOpen(char *filename, int format, 
 
   /* Load the first line.
    */
-  getline(dbfp);
+  get_line(dbfp);
 
   return dbfp;
 }
@@ -862,7 +862,7 @@ void
 SeqfilePosition(SQFILE *sqfp, long offset)
 {
   fseek(sqfp->f, offset, SEEK_SET);
-  getline(sqfp);
+  get_line(sqfp);
 }
 
 
@@ -954,7 +954,7 @@ ReadSeq(SQFILE *V, int format, char **re
 	do {			/* skip leading comments on GCG file */
 	  gotuw = (strstr(V->sbuffer,"..") != NULL);
 	  if (gotuw) readUWGCG(V);
-	  getline(V);
+	  get_line(V);
 	} while (! feof(V->f));
 	break;
 
