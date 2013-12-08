--- src/logbook/logsupport.cxx.orig	2013-05-12 06:54:05.000000000 -0400
+++ src/logbook/logsupport.cxx	2013-11-20 11:01:28.405205821 -0500
@@ -211,7 +211,7 @@
 		}
 	}
 	string sp = p;
-	if (sp.find("."ADIF_SUFFIX) == string::npos) sp.append("."ADIF_SUFFIX);
+	if (sp.find("." ADIF_SUFFIX) == string::npos) sp.append("." ADIF_SUFFIX);
 	adifFile.writeFile (sp.c_str(), &qsodb);
 }
 
@@ -308,8 +308,8 @@
 	const char* p = FSEL::saveas( title.c_str(), filter.c_str(), logbook_filename.c_str());
 	if (p) {
 		logbook_filename = p;
-		if (logbook_filename.find("."ADIF_SUFFIX) == string::npos)
-			logbook_filename.append("."ADIF_SUFFIX);
+		if (logbook_filename.find("." ADIF_SUFFIX) == string::npos)
+			logbook_filename.append("." ADIF_SUFFIX);
 		dlgLogbook->label(fl_filename_name(logbook_filename.c_str()));
 
 		cQsoDb::reverse = false;
@@ -1544,7 +1544,11 @@
 
 
 #include <tr1/unordered_map>
+#ifdef __clang__
+typedef std::unordered_map<string, unsigned> dxcc_entity_cache_t;
+#else
 typedef tr1::unordered_map<string, unsigned> dxcc_entity_cache_t;
+#endif
 static dxcc_entity_cache_t dxcc_entity_cache;
 static bool dxcc_entity_cache_enabled = false;
 
