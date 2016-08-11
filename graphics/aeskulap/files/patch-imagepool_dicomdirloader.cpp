--- imagepool/dicomdirloader.cpp.orig	2014-01-19 07:38:17 UTC
+++ imagepool/dicomdirloader.cpp
@@ -42,7 +42,7 @@ namespace ImagePool {
             return false;
         }
 
-        if ( (ret=dir.error()) != ECC_Normal ) {
+        if ( (ret=dir.error()) != EC_Normal ) {
             std::cout << "DicomdirLoader::load Error: " << ret.text() << std::endl;
             return false;
         }
@@ -80,7 +80,7 @@ namespace ImagePool {
                 for ( studyRec = patRec->nextSub(NULL); studyRec; studyRec = patRec->nextSub(studyRec) ) {
                     if ( studyRec->getRecordType()==ERT_Study ) {
                         OFString uid;
-                        if ( studyRec->findAndGetOFString(DCM_StudyInstanceUID, uid)==ECC_Normal ) {
+                        if ( studyRec->findAndGetOFString(DCM_StudyInstanceUID, uid)==EC_Normal ) {
                             if ( studyinstanceuid == uid.c_str() )
                                 return studyRec;
                         }
@@ -107,9 +107,9 @@ namespace ImagePool {
         while ( seriesRec ) {
             OFString modality;
 
-            if ( seriesRec->findAndGetOFString(DCM_Modality, modality) == ECC_Normal ) {
+            if ( seriesRec->findAndGetOFString(DCM_Modality, modality) == EC_Normal ) {
                 OFString seriesinstanceuid;
-                if ( seriesRec->findAndGetOFString(DCM_SeriesInstanceUID, seriesinstanceuid) != ECC_Normal ) {
+                if ( seriesRec->findAndGetOFString(DCM_SeriesInstanceUID, seriesinstanceuid) != EC_Normal ) {
                     seriesRec = studyRec->nextSub(seriesRec);
                     continue;
                 }
@@ -124,7 +124,7 @@ namespace ImagePool {
                         switch ( sopRec->getRecordType() ) {
                         case ERT_Image:
                         case ERT_StoredPrint:
-                            if ( sopRec->findAndGetElement(DCM_ReferencedFileID, el, true)!=ECC_Normal ) {
+                            if ( sopRec->findAndGetElement(DCM_ReferencedFileID, el, true)!=EC_Normal ) {
                                 sopRec = seriesRec->nextSub(sopRec);
                                 continue;
                             }
