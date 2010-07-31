--- imagepool/fileloader.cpp.orig	2010-07-26 21:27:54.000000000 +0000
+++ imagepool/fileloader.cpp	2010-07-26 21:41:27.000000000 +0000
@@ -56,7 +56,8 @@
 }
 
 void FileLoader::prescan_files(std::list< Glib::ustring >* filelist) {
-	std::string studyinstanceuid;
+	OFString studyinstanceuid;
+	const char *studyinstanceuid_str;
 	std::list< Glib::ustring >::iterator i = filelist->begin();
 	unsigned int curr = 0;
 	unsigned int max = filelist->size();
@@ -70,16 +71,18 @@
 							(*i).c_str(),
 							EXS_Unknown,
 							EGL_noChange,
-							DCM_MaxReadLength,
-							false);
+							DCM_MaxReadLength);
 	
 		if(cond.good() && dfile.getDataset()->findAndGetOFString(DCM_StudyInstanceUID, studyinstanceuid).good()) {
-			std::string seriesinstanceuid;
+			studyinstanceuid_str = studyinstanceuid.c_str();
+			OFString seriesinstanceuid;
+			const char *seriesinstanceuid_str;
 			dfile.getDataset()->findAndGetOFString(DCM_SeriesInstanceUID, seriesinstanceuid);
+			seriesinstanceuid_str = seriesinstanceuid.c_str();
 
-			m_cache[studyinstanceuid].m_instancecount++;
-			m_cache[studyinstanceuid].m_seriesuid.insert(seriesinstanceuid);
-			m_cache[studyinstanceuid].m_seriescount = m_cache[studyinstanceuid].m_seriesuid.size();
+			m_cache[studyinstanceuid_str].m_instancecount++;
+			m_cache[studyinstanceuid_str].m_seriesuid.insert(seriesinstanceuid_str);
+			m_cache[studyinstanceuid_str].m_seriescount = m_cache[studyinstanceuid_str].m_seriesuid.size();
 		}
 	}
 }
@@ -87,7 +90,7 @@
 bool FileLoader::run() {
 	std::list< Glib::ustring >* filelist = m_filelist;
 	std::list< Glib::ustring >::iterator i = filelist->begin();
-	std::string studyinstanceuid;
+	OFString studyinstanceuid;
 
 	for(; i != filelist->end(); i++) {
 		DcmFileFormat dfile;
@@ -96,8 +99,7 @@
 							(*i).c_str(),
 							EXS_Unknown,
 							EGL_noChange,
-							DCM_MaxReadLength,
-							false);
+							DCM_MaxReadLength);
 		
 		if(!cond.good()) {
 			std::cout << "unable to open file !!!" << std::endl;
