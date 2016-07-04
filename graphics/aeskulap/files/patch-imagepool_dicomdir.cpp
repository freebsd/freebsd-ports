--- imagepool/dicomdir.cpp.orig	2014-01-19 07:38:17 UTC
+++ imagepool/dicomdir.cpp
@@ -43,7 +43,7 @@ namespace ImagePool {
         DcmDicomDir dir(dicomdir.c_str());
         OFCondition ret;
 
-        if ( (ret=dir.error()) != ECC_Normal ) {
+        if ( (ret=dir.error()) != EC_Normal ) {
             std::cout << "DICOMDIR Error: " << ret.text() << std::endl;
             return;
         }
@@ -151,21 +151,21 @@ namespace ImagePool {
             DcmDataset study;
             DcmElement *el;
 
-            if ( studyRec->findAndGetElement(DCM_SpecificCharacterSet, el, OFFalse, OFTrue) == ECC_Normal )
+            if ( studyRec->findAndGetElement(DCM_SpecificCharacterSet, el, OFFalse, OFTrue) == EC_Normal )
                 study.insert(el);
-            if ( studyRec->findAndGetElement(DCM_StudyInstanceUID, el, OFFalse, OFTrue) == ECC_Normal )
+            if ( studyRec->findAndGetElement(DCM_StudyInstanceUID, el, OFFalse, OFTrue) == EC_Normal )
                 study.insert(el);
-            if ( studyRec->findAndGetElement(DCM_StudyDate, el, OFFalse, OFTrue) == ECC_Normal )
+            if ( studyRec->findAndGetElement(DCM_StudyDate, el, OFFalse, OFTrue) == EC_Normal )
                 study.insert(el);
-            if ( studyRec->findAndGetElement(DCM_StudyTime, el, OFFalse, OFTrue) == ECC_Normal )
+            if ( studyRec->findAndGetElement(DCM_StudyTime, el, OFFalse, OFTrue) == EC_Normal )
                 study.insert(el);
-            if ( studyRec->findAndGetElement(DCM_StudyDescription, el, OFFalse, OFTrue) == ECC_Normal )
+            if ( studyRec->findAndGetElement(DCM_StudyDescription, el, OFFalse, OFTrue) == EC_Normal )
                 study.insert(el);
-            if ( patRec->findAndGetElement(DCM_PatientName, el, OFFalse, OFTrue) == ECC_Normal )
+            if ( patRec->findAndGetElement(DCM_PatientName, el, OFFalse, OFTrue) == EC_Normal )
                 study.insert(el);
-            if ( patRec->findAndGetElement(DCM_PatientBirthDate, el, OFFalse, OFTrue) == ECC_Normal )
+            if ( patRec->findAndGetElement(DCM_PatientBirthDate, el, OFFalse, OFTrue) == EC_Normal )
                 study.insert(el);
-            if ( patRec->findAndGetElement(DCM_PatientSex, el, OFFalse, OFTrue) == ECC_Normal )
+            if ( patRec->findAndGetElement(DCM_PatientSex, el, OFFalse, OFTrue) == EC_Normal )
                 study.insert(el);
             resultslot(create_query_study(&study, std::string("DICOMDIR:") + dicomdir));
         }
@@ -179,7 +179,7 @@ namespace ImagePool {
         DcmDirectoryRecord *seriesRec;
         OFCondition ret;
 
-        if ( dir.error() != ECC_Normal ) {
+        if ( dir.error() != EC_Normal ) {
             std::cout << "DICOMDIR Error: " << ret.text() << std::endl;
             return;
         }
@@ -191,7 +191,7 @@ namespace ImagePool {
                 for ( studyRec=patRec->nextSub(NULL); studyRec; studyRec = patRec->nextSub(studyRec) ) {
                     if ( studyRec->getRecordType()==ERT_Study ) {
                         OFString uid;
-                        if ( studyRec->findAndGetOFString(DCM_StudyInstanceUID, uid)==ECC_Normal ) {
+                        if ( studyRec->findAndGetOFString(DCM_StudyInstanceUID, uid)==EC_Normal ) {
                             if ( studyinstanceuid == uid.c_str() ) {
                                 open_dicomdir_series_result(dicomdir, patRec, studyRec, resultslot);
                                 return;
@@ -221,21 +221,21 @@ namespace ImagePool {
             DcmDataset series;
             DcmElement *el;
 
-            if ( seriesRec->findAndGetElement(DCM_SpecificCharacterSet, el, OFFalse, OFTrue) == ECC_Normal )
+            if ( seriesRec->findAndGetElement(DCM_SpecificCharacterSet, el, OFFalse, OFTrue) == EC_Normal )
                 series.insert(el);
-            if ( seriesRec->findAndGetElement(DCM_SeriesDescription, el, OFFalse, OFTrue) == ECC_Normal )
+            if ( seriesRec->findAndGetElement(DCM_SeriesDescription, el, OFFalse, OFTrue) == EC_Normal )
                 series.insert(el);
-            if ( seriesRec->findAndGetElement(DCM_SeriesInstanceUID, el, OFFalse, OFTrue) == ECC_Normal )
+            if ( seriesRec->findAndGetElement(DCM_SeriesInstanceUID, el, OFFalse, OFTrue) == EC_Normal )
                 series.insert(el);
-            if ( seriesRec->findAndGetElement(DCM_Modality, el, OFFalse, OFTrue) == ECC_Normal )
+            if ( seriesRec->findAndGetElement(DCM_Modality, el, OFFalse, OFTrue) == EC_Normal )
                 series.insert(el);
-            if ( seriesRec->findAndGetElement(DCM_SeriesDate, el, OFFalse, OFTrue) == ECC_Normal )
+            if ( seriesRec->findAndGetElement(DCM_SeriesDate, el, OFFalse, OFTrue) == EC_Normal )
                 series.insert(el);
-            if ( seriesRec->findAndGetElement(DCM_SeriesTime, el, OFFalse, OFTrue) == ECC_Normal )
+            if ( seriesRec->findAndGetElement(DCM_SeriesTime, el, OFFalse, OFTrue) == EC_Normal )
                 series.insert(el);
-            if ( studyRec->findAndGetElement(DCM_StudyDescription, el, OFFalse, OFTrue) == ECC_Normal )
+            if ( studyRec->findAndGetElement(DCM_StudyDescription, el, OFFalse, OFTrue) == EC_Normal )
                 series.insert(el);
-            if ( studyRec->findAndGetElement(DCM_StationName, el, OFFalse, OFTrue) == ECC_Normal )
+            if ( studyRec->findAndGetElement(DCM_StationName, el, OFFalse, OFTrue) == EC_Normal )
                 series.insert(el);
 
             // Count Related SOP Instances
