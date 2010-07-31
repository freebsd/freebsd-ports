--- imagepool/poolnetwork.cpp.orig	2010-07-27 14:53:57.000000000 +0000
+++ imagepool/poolnetwork.cpp	2010-07-27 14:55:07.000000000 +0000
@@ -227,10 +227,14 @@
 	}
 
 	/* the array of Storage SOP Class UIDs comes from dcuid.h */
+	/* FIXME
+	 * dcmStorageSOPClassUIDs and numberOfDcmStorageSOPClassUIDs
+	 * are not defined anymore
 	for (i=0; i<numberOfDcmStorageSOPClassUIDs && SUCCESS(cond); i++) {
 		cond = ASC_addPresentationContext(params, pid, dcmStorageSOPClassUIDs[i], transferSyntaxes, transferSyntaxes_count);
-		pid += 2;	/* only odd presentation context id's */
+		pid += 2;
 	}
+	*/
 
     return cond;
 }
