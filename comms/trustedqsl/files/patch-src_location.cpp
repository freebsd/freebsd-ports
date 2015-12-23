--- src/location.cpp.orig	2015-10-21 17:26:38 UTC
+++ src/location.cpp
@@ -2226,7 +2226,7 @@ tqsl_load_loc(TQSL_LOCATION *loc, XMLEle
 			if (field.gabbi_name != "") {
 				// A field that may exist
 				XMLElement el;
-				if (ep->second.getFirstElement(field.gabbi_name, el)) {
+				if (ep->second->getFirstElement(field.gabbi_name, el)) {
 					field.cdata = el.getText();
 					switch (field.input_type) {
                                                 case TQSL_LOCATION_FIELD_DDLIST:
@@ -2368,7 +2368,7 @@ tqsl_mergeStationLocations(const char *l
 	for (nameiter = namelist.find("StationData"); nameiter != namelist.end(); nameiter++) {
 		if (nameiter->first != "StationData")
 			break;
-		pair<string, bool> rval = nameiter->second.getAttribute("name");
+		pair<string, bool> rval = nameiter->second->getAttribute("name");
 		if (rval.second) {
 			locnames.push_back(rval.first);
 		}
@@ -2381,7 +2381,7 @@ tqsl_mergeStationLocations(const char *l
 	for (ep = ellist.find("StationData"); ep != ellist.end(); ep++) {
 		if (ep->first != "StationData")
 			break;
-		pair<string, bool> rval = ep->second.getAttribute("name");
+		pair<string, bool> rval = ep->second->getAttribute("name");
 		bool found = false;
 		if (rval.second) {
 			for (size_t j = 0; j < locnames.size(); j++) {
@@ -2393,19 +2393,19 @@ tqsl_mergeStationLocations(const char *l
 		}
 		if (!found) {
 			// Add this one to the station data file
-			XMLElement newtop("StationData");
-			newtop.setPretext("\n  ");
-			newtop.setAttribute("name", rval.first);
-			newtop.setText("\n  ");
-			XMLElement sub;
-			sub.setPretext(newtop.getPretext() + "  ");
+			std::shared_ptr<XMLElement> newtop(new XMLElement("StationData"));
+			newtop->setPretext("\n  ");
+			newtop->setAttribute("name", rval.first);
+			newtop->setText("\n  ");
+			std::shared_ptr<XMLElement> sub(new XMLElement);
+			sub->setPretext(newtop->getPretext() + "  ");
 			XMLElement el;
-			bool elok = ep->second.getFirstElement(el);
+			bool elok = ep->second->getFirstElement(el);
 			while (elok) {
-				sub.setElementName(el.getElementName());
-				sub.setText(el.getText());
-				newtop.addElement(sub);
-				elok = ep->second.getNextElement(el);
+				sub->setElementName(el.getElementName());
+				sub->setText(el.getText());
+				newtop->addElement(sub);
+				elok = ep->second->getNextElement(el);
 			}
 			old_data.addElement(newtop);
 			old_data.setText("\n");
@@ -2444,7 +2444,7 @@ tqsl_move_station_location(const char *n
 	for (from_ep = from_ellist.find("StationData"); from_ep != from_ellist.end(); from_ep++) {
 		if (from_ep->first != "StationData")
 			break;
-		pair<string, bool> from_rval = from_ep->second.getAttribute("name");
+		pair<string, bool> from_rval = from_ep->second->getAttribute("name");
 		if (from_rval.second && !strcasecmp(from_rval.first.c_str(), name)) {
 			// Match, move it.
 			// First, delete any old backup for this station location
@@ -2453,26 +2453,26 @@ tqsl_move_station_location(const char *n
 			for (to_ep = to_ellist.find("StationData"); to_ep != to_ellist.end(); to_ep++) {
 				if (to_ep->first != "StationData")
 					break;
-				pair<string, bool> to_rval = to_ep->second.getAttribute("name");
+				pair<string, bool> to_rval = to_ep->second->getAttribute("name");
 				if (to_rval.second && !strcasecmp(to_rval.first.c_str(), name)) {
 					to_ellist.erase(to_ep);
 					break;
 				}
 			}
 			// Now add it to the target
-			XMLElement newtop("StationData");
-			newtop.setPretext("\n  ");
-			newtop.setAttribute("name", from_rval.first);
-			newtop.setText("\n  ");
-			XMLElement sub;
-			sub.setPretext(newtop.getPretext() + "  ");
+			std::shared_ptr<XMLElement> newtop(new XMLElement("StationData"));
+			newtop->setPretext("\n  ");
+			newtop->setAttribute("name", from_rval.first);
+			newtop->setText("\n  ");
+			std::shared_ptr<XMLElement> sub(new XMLElement);
+			sub->setPretext(newtop->getPretext() + "  ");
 			XMLElement el;
-			bool elok = from_ep->second.getFirstElement(el);
+			bool elok = from_ep->second->getFirstElement(el);
 			while (elok) {
-				sub.setElementName(el.getElementName());
-				sub.setText(el.getText());
-				newtop.addElement(sub);
-				elok = from_ep->second.getNextElement(el);
+				sub->setElementName(el.getElementName());
+				sub->setText(el.getText());
+				newtop->addElement(sub);
+				elok = from_ep->second->getNextElement(el);
 			}
 			to_sfile.addElement(newtop);
 			to_sfile.setText("\n");
@@ -2528,7 +2528,7 @@ tqsl_getStationLocation(tQSL_Location *l
 	for (ep = ellist.find("StationData"); ep != ellist.end(); ep++) {
 		if (ep->first != "StationData")
 			break;
-		pair<string, bool> rval = ep->second.getAttribute("name");
+		pair<string, bool> rval = ep->second->getAttribute("name");
 		if (rval.second && !strcasecmp(trim(rval.first).c_str(), trim(loc->name).c_str())) {
 			exists = true;
 			break;
@@ -2724,33 +2724,33 @@ tqsl_location_to_xml(TQSL_LOCATION *loc,
 		}
 		for (int i = 0; i < numf; i++) {
 			TQSL_LOCATION_FIELD& field = loc->pagelist[loc->page-1].fieldlist[i];
-			XMLElement fd;
-			fd.setPretext(sd.getPretext() + "  ");
-			fd.setElementName(field.gabbi_name);
+			std::shared_ptr<XMLElement> fd(new XMLElement);
+			fd->setPretext(sd.getPretext() + "  ");
+			fd->setElementName(field.gabbi_name);
 			switch (field.input_type) {
                                 case TQSL_LOCATION_FIELD_DDLIST:
                                 case TQSL_LOCATION_FIELD_LIST:
 					if (field.idx < 0 || field.idx >= static_cast<int>(field.items.size())) {
-						fd.setText("");
+						fd->setText("");
 						if (field.gabbi_name == "CALL") {
-							fd.setText("NONE");
+							fd->setText("NONE");
 						}
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
 				sd.addElement(fd);
 		}
 		int rval;
@@ -2824,7 +2824,7 @@ tqsl_saveStationLocationCapture(tQSL_Loc
 	for (ep = ellist.find("StationData"); ep != ellist.end(); ep++) {
 		if (ep->first != "StationData")
 			break;
-		pair<string, bool> rval = ep->second.getAttribute("name");
+		pair<string, bool> rval = ep->second->getAttribute("name");
 		if (rval.second && !strcasecmp(rval.first.c_str(), loc->name.c_str())) {
 			exists = true;
 			break;
@@ -2835,14 +2835,14 @@ tqsl_saveStationLocationCapture(tQSL_Loc
 		tQSL_Error = TQSL_NAME_EXISTS;
 		return 1;
 	}
-	XMLElement sd("StationData");
-	sd.setPretext("\n  ");
-	if (tqsl_location_to_xml(loc, sd)) {
+	std::shared_ptr<XMLElement> sd(new XMLElement("StationData"));
+	sd->setPretext("\n  ");
+	if (tqsl_location_to_xml(loc, *sd)) {
 		tqslTrace("tqsl_saveStationLocationCaptureName", "error in loc_to_xml %d", tQSL_Error);
 		return 1;
 	}
-	sd.setAttribute("name", loc->name);
-	sd.setText("\n  ");
+	sd->setAttribute("name", loc->name);
+	sd->setText("\n  ");
 
 	// If 'exists', ep points to the existing station record
 	if (exists)
