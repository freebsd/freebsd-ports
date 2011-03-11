--- src/dcmtk_interface.cc.orig	2009-12-14 05:53:11.000000000 +0100
+++ src/dcmtk_interface.cc	2011-02-11 10:59:18.612565854 +0100
@@ -32,7 +32,7 @@
 #include <unistd.h>
 #endif
 #include "dcmtk_interface.h" 
-#include "dcddirif.h"     /* for class DicomDirInterface */
+#include "dcmtk/dcmdata/dcddirif.h"     /* for class DicomDirInterface */
 #include <dirent.h>
 #include <sys/stat.h>
 #include "amitk_data_set_DOUBLE_0D_SCALING.h"
@@ -44,7 +44,8 @@
 #undef PACKAGE_STRING
 #undef PACKAGE_TARNAME
 #undef PACKAGE_VERSION
-#include <dctk.h>
+#include "amide_config.h"
+#include <dcmtk/dcmdata/dctk.h>
 //#include <dcostrmb.h>
 const gchar * dcmtk_version = OFFIS_DCMTK_VERSION;
 
@@ -188,7 +189,7 @@
   }
   dim.y = return_uint16;
 
-  if (dcm_dataset->findAndGetUint16(DCM_Planes, return_uint16).bad()) 
+  if (dcm_dataset->findAndGetUint16(DCM_RETIRED_Planes, return_uint16).bad()) 
     dim.z = 1;
   else
     dim.z = return_uint16;
@@ -352,7 +353,7 @@
   if (dcm_dataset->findAndGetString(DCM_PatientID, return_str, OFTrue).good()) 
     amitk_data_set_set_subject_id(ds, return_str);
 
-  if (dcm_dataset->findAndGetFloat64(DCM_PatientsWeight, return_float64).good()) {
+  if (dcm_dataset->findAndGetFloat64(DCM_PatientWeight, return_float64).good()) {
     amitk_data_set_set_subject_weight(ds, return_float64);
     amitk_data_set_set_displayed_weight_unit(ds, AMITK_WEIGHT_UNIT_KILOGRAM);
   }
@@ -429,7 +430,7 @@
     }
   }
 
-  if (dcm_dataset->findAndGetString(DCM_PatientsName, return_str, OFTrue).good()) {
+  if (dcm_dataset->findAndGetString(DCM_PatientName, return_str, OFTrue).good()) {
       if (AMITK_OBJECT_NAME(ds) == NULL)
 	amitk_object_set_name(AMITK_OBJECT(ds), return_str);
       amitk_data_set_set_subject_name(ds, return_str);
@@ -495,7 +496,7 @@
     }
   }
 
-  if (dcm_dataset->findAndGetString(DCM_PatientsBirthDate, return_str, OFTrue).good()) 
+  if (dcm_dataset->findAndGetString(DCM_PatientBirthDate, return_str, OFTrue).good()) 
     amitk_data_set_set_subject_dob(ds, return_str);
 
   /* because of how the dicom coordinates are setup, after reading in the patient slices, 
@@ -1257,7 +1258,7 @@
   if (return_str != NULL) 
       info->patient_id = g_strdup(return_str);
 
-  dcm_dataset->findAndGetString(DCM_PatientsName, return_str, OFTrue);
+  dcm_dataset->findAndGetString(DCM_PatientName, return_str, OFTrue);
   if (return_str != NULL) 
       info->patient_name = g_strdup(return_str);
 
@@ -1537,7 +1538,7 @@
 
   /* go through the whole directory */
   while ((patient_record = dcm_root_record->nextSub(patient_record)) != NULL) {
-    patient_record->findAndGetString(DCM_PatientsName, record_name[0]);
+    patient_record->findAndGetString(DCM_PatientName, record_name[0]);
     patient_record->findAndGetString(DCM_PatientID, patient_id, OFTrue);
 
 
@@ -1802,8 +1803,9 @@
   }
 
 #ifdef AMIDE_DEBUG  
-  dcm_dir.enableVerboseMode(TRUE);
-  dcm_dir.setLogStream(&ofConsole);
+// These are not defined in the latest dcmtk and could not find substitutes.
+//  dcm_dir.enableVerboseMode(TRUE);
+//  dcm_dir.setLogStream(&ofConsole);
 #endif
 
   /* create the DICOMDIR, unless already made in which case we'll append to it */
@@ -1905,15 +1907,15 @@
 
   /* other stuff */
   if (AMITK_DATA_SET_SUBJECT_NAME(ds) != NULL) 
-    insert_str(dcm_ds,DCM_PatientsName, AMITK_DATA_SET_SUBJECT_NAME(ds));
+    insert_str(dcm_ds,DCM_PatientName, AMITK_DATA_SET_SUBJECT_NAME(ds));
   if (AMITK_DATA_SET_SUBJECT_ID(ds) != NULL) 
     insert_str(dcm_ds,DCM_PatientID, AMITK_DATA_SET_SUBJECT_ID(ds));
   if (AMITK_DATA_SET_SUBJECT_DOB(ds) != NULL) 
-    insert_str(dcm_ds,DCM_PatientsBirthDate, AMITK_DATA_SET_SUBJECT_DOB(ds));
+    insert_str(dcm_ds,DCM_PatientBirthDate, AMITK_DATA_SET_SUBJECT_DOB(ds));
   if (AMITK_OBJECT_NAME(ds) != NULL)
     insert_str(dcm_ds,DCM_StudyDescription, AMITK_OBJECT_NAME(ds));
   insert_double(dcm_ds,DCM_RadionuclideTotalDose, AMITK_DATA_SET_INJECTED_DOSE(ds));
-  insert_double(dcm_ds,DCM_PatientsWeight, AMITK_DATA_SET_SUBJECT_WEIGHT(ds));
+  insert_double(dcm_ds,DCM_PatientWeight, AMITK_DATA_SET_SUBJECT_WEIGHT(ds));
 
   switch(AMITK_DATA_SET_SUBJECT_ORIENTATION(ds)) {
   case AMITK_SUBJECT_ORIENTATION_SUPINE_HEADFIRST:
@@ -1949,7 +1951,7 @@
   case AMITK_MODALITY_PET:
     insert_str(dcm_ds,DCM_Modality, "PT");
     dcm_metainfo->putAndInsertString(DCM_MediaStorageSOPClassUID,
-				     UID_PETImageStorage);
+				     UID_EnhancedPETImageStorage);
     break;
   case AMITK_MODALITY_SPECT:
     insert_str(dcm_ds,DCM_Modality, "ST");
