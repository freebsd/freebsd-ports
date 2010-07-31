--- imagepool/netquery.cpp.orig	2010-07-26 21:45:52.000000000 +0000
+++ imagepool/netquery.cpp	2010-07-26 21:53:57.000000000 +0000
@@ -31,10 +31,11 @@
 #include "dcdeftag.h"
 #include "poolfindassociation.h"
 #include "netclient.h"
-#include "gettext.h"
 
 #include <iostream>
 
+#include <libintl.h>
+
 namespace ImagePool {
 	
 static void fix_date(std::string& date) {
@@ -50,7 +51,7 @@
 }
 
 static void fix_time(std::string& time) {
-	unsigned int i = time.find(".");
+	size_t i = time.find(".");
 	if(i != std::string::npos) {
 		time = time.substr(0, i);
 	}
@@ -88,28 +89,35 @@
 
 Glib::RefPtr< ImagePool::Series > create_query_series(DcmDataset* dset) {
 	Glib::RefPtr< ImagePool::Series > result = Glib::RefPtr< ImagePool::Series >(new Series);
+	OFString res;
 
-	dset->findAndGetOFString(DCM_SeriesInstanceUID, result->m_seriesinstanceuid);
-	dset->findAndGetOFString(DCM_SeriesDescription, result->m_description);
+	dset->findAndGetOFString(DCM_SeriesInstanceUID, res);
+	result->m_seriesinstanceuid = res.c_str();
+	dset->findAndGetOFString(DCM_SeriesDescription, res);
+	result->m_description = res.c_str();
 	if(result->m_description.empty()) {
-		dset->findAndGetOFString(DCM_StudyDescription, result->m_description);
+		dset->findAndGetOFString(DCM_StudyDescription, res);
+		result->m_description = res.c_str();
 	}
 	if(result->m_description.empty()) {
 		result->m_description = gettext("no description");
 	}
 
-	dset->findAndGetOFString(DCM_Modality, result->m_modality);
+	dset->findAndGetOFString(DCM_Modality, res);
+	result->m_modality = res.c_str();
 
-	dset->findAndGetOFString(DCM_SeriesTime, result->m_seriestime);
+	dset->findAndGetOFString(DCM_SeriesTime, res);
+	result->m_seriestime = res.c_str();
 	if(result->m_seriestime.empty()) {
-		dset->findAndGetOFString(DCM_StudyTime, result->m_seriestime);
+		dset->findAndGetOFString(DCM_StudyTime, res);
+		result->m_seriestime = res.c_str();
 	}
 
-	dset->findAndGetOFString(DCM_StationName, result->m_stationname);
+	dset->findAndGetOFString(DCM_StationName, res);
+	result->m_stationname = res.c_str();
 
-	std::string buffer;
-	dset->findAndGetOFString(DCM_NumberOfSeriesRelatedInstances, buffer);
-	int i = atoi(buffer.c_str());
+	dset->findAndGetOFString(DCM_NumberOfSeriesRelatedInstances, res);
+	int i = atoi(res.c_str());
 	if(i != 0) {
 		result->m_instancecount = i;
 	}
