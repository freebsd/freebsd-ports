--- emboss/marscan.c.orig	Mon Jan 23 11:36:36 2006
+++ emboss/marscan.c	Mon Jan 23 08:56:35 2006
@@ -1,7 +1,7 @@
 /* @source marscan application
 **
 ** Finds MAR/SAR sites in nucleic sequences
-** @author: Copyright (C) Gary Williams (gwilliam@hgmp.mrc.ac.uk)
+** @author Copyright (C) Gary Williams (gwilliam@hgmp.mrc.ac.uk)
 ** @@
 **
 ** This program is free software; you can redistribute it and/or
@@ -249,33 +249,41 @@
 			 amino8rev, carboxyl8rev, buf8rev, off8rev,
 			 sotable8rev, solimit8rev, regexp8rev, skipm8rev,
 			 &hits8rev, m8rev, &tidy8rev);
+	ajDebug("Marscan '%S' hits %d:%d %d:%d\n", seqname,
+		hits16, hits16rev,
+		hits8, hits8rev);
+
+	/* initialise the output feature table */
+	tab = ajFeattableNewDna(seqname);
+
+	/*
+	**  append reverse lists to forward lists and sort them by match
+	**  position
+	*/
 
-	if((hits16 || hits16rev) && (hits8 || hits8rev))
+	if(hits8 || hits8rev)
 	{
-	    /*
-	    **  append reverse lists to forward lists and sort them by match
-	    **  position
-	    */
 	    ajListPushList(l8, &l8rev);
 	    ajListSort(l8, embPatRestrictStartCompare);
-
+	}
+	if((hits16 || hits16rev))
+	{
 	    ajListPushList(l16, &l16rev);
 	    ajListSort(l16, embPatRestrictStartCompare);
 
-	    /* initialise the output feature table */
-	    if(!tab)
-		tab = ajFeattableNewDna(seqname);
-
-	    /*
-	    **  find pairs of hits within the required distance and output
-	    **  the results
-	    */
-	    marscan_stepdown(l16, l8, &tab);
-
-	    /* write features and tidy up */
-	    ajReportWrite(report, tab, seq);
-	    ajFeattableDel(&tab);
 	}
+
+
+	/*
+	**  find pairs of hits within the required distance and output
+	**  the results
+	*/
+	marscan_stepdown(l16, l8, &tab);
+
+	ajDebug("Marscan reportwrite '%S'\n", seqname);
+	/* write features and tidy up */
+	ajReportWrite(report, tab, seq);
+	ajFeattableDel(&tab);
 
         while(ajListPop(l16,(void **)&aptr))
             embMatMatchDel(&aptr);
