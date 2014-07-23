--- src/location.cpp.orig	2014-07-12 13:18:13.000000000 -0700
+++ src/location.cpp	2014-07-18 05:40:36.000000000 -0700
@@ -1957,7 +1957,7 @@
 			if (field.gabbi_name != "") {
 				// A field that may exist
 				XMLElement el;
-				if (ep->second.getFirstElement(field.gabbi_name, el)) {
+				if (ep->second->getFirstElement(field.gabbi_name, el)) {
 					field.cdata = el.getText();
 					switch (field.input_type) {
                                                 case TQSL_LOCATION_FIELD_DDLIST:
@@ -2086,11 +2086,11 @@
 	for (ep = ellist.find("StationData"); ep != ellist.end(); ep++) {
 		if (ep->first != "StationData")
 			break;
-		pair<string, bool> rval = ep->second.getAttribute("name");
+		pair<string, bool> rval = ep->second->getAttribute("name");
 		if (rval.second) {
 			TQSL_LOCATION *oldloc;
 			TQSL_LOCATION *newloc;
-			ep->second.getFirstElement("CALL", call);
+			ep->second->getFirstElement("CALL", call);
 			for (size_t j = 0; j < calls.size(); j++) {
 				if (calls[j] == call.getText()) {
 					if (tqsl_getStationLocation(reinterpret_cast<tQSL_Location *>(&oldloc), rval.first.c_str())) { // Location doesn't exist
@@ -2125,7 +2125,7 @@
 	for (ep = ellist.find("StationData"); ep != ellist.end(); ep++) {
 		if (ep->first != "StationData")
 			break;
-		pair<string, bool> rval = ep->second.getAttribute("name");
+		pair<string, bool> rval = ep->second->getAttribute("name");
 		if (rval.second && !strcasecmp(rval.first.c_str(), name)) {
 			ellist.erase(ep);
 			return tqsl_dump_station_data(sfile);
@@ -2158,7 +2158,7 @@
 	for (ep = ellist.find("StationData"); ep != ellist.end(); ep++) {
 		if (ep->first != "StationData")
 			break;
-		pair<string, bool> rval = ep->second.getAttribute("name");
+		pair<string, bool> rval = ep->second->getAttribute("name");
 		if (rval.second && !strcasecmp(trim(rval.first).c_str(), trim(loc->name).c_str())) {
 			exists = true;
 			break;
@@ -2321,30 +2321,31 @@
 			return 1;
 		for (int i = 0; i < numf; i++) {
 			TQSL_LOCATION_FIELD& field = loc->pagelist[loc->page-1].fieldlist[i];
-			XMLElement fd;
-			fd.setPretext(sd.getPretext() + "  ");
-			fd.setElementName(field.gabbi_name);
+			shared_ptr<XMLElement> fd(new XMLElement);
+			fd->setPretext(sd.getPretext() + "  ");
+			fd->setElementName(field.gabbi_name);
 			switch (field.input_type) {
                                 case TQSL_LOCATION_FIELD_DDLIST:
                                 case TQSL_LOCATION_FIELD_LIST:
 					if (field.idx < 0 || field.idx >= static_cast<int>(field.items.size())) {
-						fd.setText("");
+						fd->setText("");
 					} else if (field.data_type == TQSL_LOCATION_FIELD_INT) {
 						char numbuf[20];
 						snprintf(numbuf, sizeof numbuf, "%d", field.items[field.idx].ivalue);
-						fd.setText(numbuf);
+						fd->setText(numbuf);
 					} else {
-						fd.setText(field.items[field.idx].text);
+						fd->setText(field.items[field.idx].text);
 					}
 					break;
                                 case TQSL_LOCATION_FIELD_TEXT:
 					field.cdata = trim(field.cdata);
 					if (field.flags & TQSL_LOCATION_FIELD_UPPER)
 						field.cdata = string_toupper(field.cdata);
-					fd.setText(field.cdata);
+					fd->setText(field.cdata);
 					break;
 			}
-			if (strcmp(fd.getText().c_str(), ""))
+			if (strcmp(fd->getText().c_str(), ""))
+			if (strcmp(fd->getText().c_str(), ""))
 				sd.addElement(fd);
 		}
 		int rval;
@@ -2407,7 +2408,7 @@
 	for (ep = ellist.find("StationData"); ep != ellist.end(); ep++) {
 		if (ep->first != "StationData")
 			break;
-		pair<string, bool> rval = ep->second.getAttribute("name");
+		pair<string, bool> rval = ep->second->getAttribute("name");
 		if (rval.second && !strcasecmp(rval.first.c_str(), loc->name.c_str())) {
 			exists = true;
 			break;
@@ -2417,12 +2418,12 @@
 		tQSL_Error = TQSL_NAME_EXISTS;
 		return 1;
 	}
-	XMLElement sd("StationData");
-	sd.setPretext("\n  ");
-	if (tqsl_location_to_xml(loc, sd))
+	shared_ptr<XMLElement> sd(new XMLElement("StationData"));
+	sd->setPretext("\n  ");
+	if (tqsl_location_to_xml(loc, *sd))
 		return 1;
-	sd.setAttribute("name", loc->name);
-	sd.setText("\n  ");
+	sd->setAttribute("name", loc->name);
+	sd->setText("\n  ");
 
 	// If 'exists', ep points to the existing station record
 	if (exists)
