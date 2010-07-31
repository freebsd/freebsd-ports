--- imagepool/poolmoveassociation.cpp.orig	2010-07-27 14:42:55.000000000 +0000
+++ imagepool/poolmoveassociation.cpp	2010-07-27 14:53:04.000000000 +0000
@@ -33,7 +33,6 @@
 #include "djencode.h"
 #include "djrplol.h"
 
-
 MoveAssociation::MoveAssociation() {
 	m_abstractSyntax = UID_MOVEStudyRootQueryRetrieveInformationModel;
 	m_maxReceivePDULength = ASC_DEFAULTMAXPDU;
@@ -175,6 +174,9 @@
 					knownAbstractSyntaxes, DIM_OF(knownAbstractSyntaxes),
 					transferSyntaxes, DIM_OF(transferSyntaxes));
 
+		/* FIXME
+		 * dcmStorageSOPClassUIDs and numberOfDcmStorageSOPClassUIDs
+		 * are not defined anymore
 		if (cond.good()) {
 			// the array of Storage SOP Class UIDs comes from dcuid.h
 			cond = ASC_acceptContextsWithPreferredTransferSyntaxes(
@@ -182,6 +184,7 @@
 					dcmStorageSOPClassUIDs, numberOfDcmStorageSOPClassUIDs,
 					transferSyntaxes, DIM_OF(transferSyntaxes));
 		}
+		*/
 	}
 
 	if (cond.good()) {
