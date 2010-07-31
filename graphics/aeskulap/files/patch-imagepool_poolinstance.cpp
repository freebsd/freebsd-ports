--- imagepool/poolinstance.cpp.orig	2010-07-26 21:55:22.000000000 +0000
+++ imagepool/poolinstance.cpp	2010-07-27 14:33:34.000000000 +0000
@@ -37,6 +37,8 @@
 
 #include <iostream>
 
+#include <libintl.h>
+
 namespace ImagePool {
 	
 Instance::Instance(const std::string& sopinstanceuid) :
@@ -279,35 +281,35 @@
 
 	// get SOPInstanceUID
 	
-	std::string sop;
+	OFString sop;
 	dset->findAndGetOFString(DCM_SOPInstanceUID, sop).bad();
 	
 	// wrap in smartpointer
-	Glib::RefPtr<ImagePool::Instance> r = Glib::RefPtr<ImagePool::Instance>(new ImagePool::Instance(sop));
+	Glib::RefPtr<ImagePool::Instance> r = Glib::RefPtr<ImagePool::Instance>(new ImagePool::Instance(sop.c_str()));
 
 	// set encoding
-	std::string enc[2];
+	OFString enc[2];
 	dset->findAndGetOFString(DCM_SpecificCharacterSet, enc[0], 0);
 	dset->findAndGetOFString(DCM_SpecificCharacterSet, enc[1], 1);
-	r->set_encoding(enc[0], enc[1]);
+	r->set_encoding(enc[0].c_str(), enc[1].c_str());
 
 	// set dicom uid's
-	r->m_sopinstanceuid = sop;
+	r->m_sopinstanceuid = sop.c_str();
 
-	std::string seriesuid;
+	OFString seriesuid;
 	if(dset->findAndGetOFString(DCM_SeriesInstanceUID, seriesuid).good()) {
-		r->m_seriesinstanceuid = seriesuid;
+		r->m_seriesinstanceuid = seriesuid.c_str();
 	}
 
-	std::string studyuid;
+	OFString studyuid;
 	if(dset->findAndGetOFString(DCM_StudyInstanceUID, studyuid).good()) {
-		r->m_studyinstanceuid = studyuid;
+		r->m_studyinstanceuid = studyuid.c_str();
 	}
 
 	r->m_default_windowcenter = 0;
 	r->m_default_windowwidth = 0;
 
-	std::string value;
+	OFString value;
 
 	// get instancenumber
 	if(dset->findAndGetOFString(DCM_InstanceNumber, value).good()) {
@@ -438,29 +440,29 @@
 
 	// set date
 	if(dset->findAndGetOFString(DCM_AcquisitionDate, value).good()) {
-		r->m_date = value;
+		r->m_date = value.c_str();
 	}
 	else if(dset->findAndGetOFString(DCM_SeriesDate, value).good()) {
-		r->m_date = value;
+		r->m_date = value.c_str();
 	}
 	else if(dset->findAndGetOFString(DCM_StudyDate, value).good()) {
-		r->m_date = value;
+		r->m_date = value.c_str();
 	}
 
 	// set time
 	if(dset->findAndGetOFString(DCM_AcquisitionTime, value).good()) {
-		r->m_time = value;
+		r->m_time = value.c_str();
 	}
 	else if(dset->findAndGetOFString(DCM_SeriesTime, value).good()) {
-		r->m_time = value;
+		r->m_time = value.c_str();
 	}
 	else if(dset->findAndGetOFString(DCM_StudyTime, value).good()) {
-		r->m_time = value;
+		r->m_time = value.c_str();
 	}
 
 	// set ManufacturersModelName
 	if(dset->findAndGetOFString(DCM_ManufacturersModelName, value).good()) {
-		r->m_model = value;
+		r->m_model = value.c_str();
 	}
 	
 	// set pixelspacing
@@ -512,8 +514,10 @@
 	if(dset->findAndGetOFString(DCM_PatientsName, value).good()) {
 		r->m_patientsname = r->convert_string(value.c_str());
 	}
-	dset->findAndGetOFString(DCM_PatientsBirthDate, r->m_patientsbirthdate);
-	dset->findAndGetOFString(DCM_PatientsSex, r->m_patientssex);
+	dset->findAndGetOFString(DCM_PatientsBirthDate, value);
+	r->m_patientsbirthdate = value.c_str();
+	dset->findAndGetOFString(DCM_PatientsSex, value);
+	r->m_patientssex = value.c_str();
 	if(dset->findAndGetOFString(DCM_StudyDescription, value).good()) {
 		r->m_studydescription = r->convert_string(value.c_str());
 	}
@@ -528,8 +532,10 @@
 		r->m_studydescription = gettext("no description");
 	}
 
-	dset->findAndGetOFString(DCM_StudyDate, r->m_studydate);
-	dset->findAndGetOFString(DCM_StudyTime, r->m_studytime);
+	dset->findAndGetOFString(DCM_StudyDate, value);
+	r->m_studydate = value.c_str();
+	dset->findAndGetOFString(DCM_StudyTime, value);
+	r->m_studytime = value.c_str();
 
 	// series params
 	if(dset->findAndGetOFString(DCM_InstitutionName, value).good()) {
@@ -549,7 +555,8 @@
 		r->m_seriesdescription = gettext("no description");
 	}
 
-	dset->findAndGetOFString(DCM_Modality, r->m_modality);
+	dset->findAndGetOFString(DCM_Modality, value);
+	r->m_modality = value.c_str();
 
 	Glib::RefPtr<ImagePool::Study> new_study = get_study(r->m_studyinstanceuid);
 	if(new_study->size() == 0) {
