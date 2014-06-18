--- src/location.cpp	2014-05-08 17:59:25.000000000 -0700
+++ ../../work.fixed/tqsl-2.0.2/src/location.cpp	2014-05-24 00:29:01.000000000 -0700
@@ -1958,7 +1958,7 @@
 			if (field.gabbi_name != "") {
 				// A field that may exist
 				XMLElement el;
-				if (ep->second.getFirstElement(field.gabbi_name, el)) {
+				if (ep->second.elem->getFirstElement(field.gabbi_name, el)) {
 					field.cdata = el.getText();
 					switch (field.input_type) {
                                                 case TQSL_LOCATION_FIELD_DDLIST:
@@ -2085,11 +2085,11 @@
 	for (ep = ellist.find("StationData"); ep != ellist.end(); ep++) {
 		if (ep->first != "StationData")
 			break;
-		pair<string, bool> rval = ep->second.getAttribute("name");
+		pair<string, bool> rval = ep->second.elem->getAttribute("name");
 		if (rval.second) {
 			TQSL_LOCATION *oldloc;
 			TQSL_LOCATION *newloc;
-			ep->second.getFirstElement("CALL", call);
+			ep->second.elem->getFirstElement("CALL", call);
 			for (size_t j = 0; j < calls.size(); j++) {
 				if (calls[j] == call.getText()) {
 					if (tqsl_getStationLocation(reinterpret_cast<tQSL_Location *>(&oldloc), rval.first.c_str())) { // Location doesn't exist
@@ -2124,7 +2124,7 @@
 	for (ep = ellist.find("StationData"); ep != ellist.end(); ep++) {
 		if (ep->first != "StationData")
 			break;
-		pair<string, bool> rval = ep->second.getAttribute("name");
+		pair<string, bool> rval = ep->second.elem->getAttribute("name");
 		if (rval.second && !strcasecmp(rval.first.c_str(), name)) {
 			ellist.erase(ep);
 			return tqsl_dump_station_data(sfile);
@@ -2157,7 +2157,7 @@
 	for (ep = ellist.find("StationData"); ep != ellist.end(); ep++) {
 		if (ep->first != "StationData")
 			break;
-		pair<string, bool> rval = ep->second.getAttribute("name");
+		pair<string, bool> rval = ep->second.elem->getAttribute("name");
 		if (rval.second && !strcasecmp(trim(rval.first).c_str(), trim(loc->name).c_str())) {
 			exists = true;
 			break;
@@ -2402,7 +2402,7 @@
 	for (ep = ellist.find("StationData"); ep != ellist.end(); ep++) {
 		if (ep->first != "StationData")
 			break;
-		pair<string, bool> rval = ep->second.getAttribute("name");
+		pair<string, bool> rval = ep->second.elem->getAttribute("name");
 		if (rval.second && !strcasecmp(rval.first.c_str(), loc->name.c_str())) {
 			exists = true;
 			break;
