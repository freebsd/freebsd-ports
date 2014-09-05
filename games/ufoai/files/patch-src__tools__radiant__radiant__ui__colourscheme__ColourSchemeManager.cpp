--- ./src/tools/radiant/radiant/ui/colourscheme/ColourSchemeManager.cpp.orig	2014-06-05 06:18:39.000000000 +0200
+++ ./src/tools/radiant/radiant/ui/colourscheme/ColourSchemeManager.cpp	2014-08-07 16:55:49.627279079 +0200
@@ -5,13 +5,15 @@
 #include "stream/stringstream.h"
 #include "stream/textfilestream.h"
 
+#include <stdexcept>
+
 namespace ui {
 
 /*	returns true, if the scheme called <name> exists
  */
 bool ColourSchemeManager::schemeExists(const std::string& name) {
 	ColourSchemeMap::iterator it = _colourSchemes.find(name);
-	return (it != _colourSchemes.end());
+	return it != _colourSchemes.end();
 }
 
 ColourSchemeMap& ColourSchemeManager::getSchemeList() {
@@ -19,11 +21,15 @@
 }
 
 ColourScheme& ColourSchemeManager::getActiveScheme() {
-	return _colourSchemes[_activeScheme];
+	return getScheme(_activeScheme);
 }
 
 ColourScheme& ColourSchemeManager::getScheme(const std::string& name) {
-	return _colourSchemes[name];
+	ColourSchemeMap::iterator i = _colourSchemes.find(name);
+	if (i == _colourSchemes.end()) {
+		throw std::runtime_error("ColourSchemeManager: active scheme not found");
+	}
+	return i->second;
 }
 
 /*	Returns true, if the scheme called <name> is currently active
@@ -32,9 +38,7 @@
 	if (schemeExists(name)) {
 		return (name == _activeScheme);
 	}
-	else {
-		return false;
-	}
+	return false;
 }
 
 void ColourSchemeManager::setActive(const std::string& name) {
@@ -53,7 +57,7 @@
 		globalOutputStream() << "Dump: Schemename: " << it->first << "\n";
 
 		// Retrieve the list with all the ColourItems of this scheme
-		ColourItemMap& colourMap = _colourSchemes[it->first].getColourMap();
+		ColourItemMap& colourMap = getScheme(it->first).getColourMap();
 
 		//globalOutputStream() << "Dump: Number of ColourItems: " << colourMap.size();
 		globalOutputStream() << "\n";
@@ -95,7 +99,8 @@
 	xml::Node schemeNode = GlobalRegistry().createKeyWithName(basePath, "colourscheme", name);
 
 	// Set the readonly attribute if necessary
-	if (_colourSchemes[name].isReadOnly()) {
+	ColourScheme& scheme = getScheme(name);
+	if (scheme.isReadOnly()) {
 		schemeNode.setAttributeValue("readonly", "1");
 	}
 
@@ -108,7 +113,7 @@
 	std::string schemePath = basePath + "/colourscheme[@name='" + name + "']";
 
 	// Retrieve the list with all the ColourItems of this scheme
-	ColourItemMap& colourMap = _colourSchemes[name].getColourMap();
+	ColourItemMap& colourMap = scheme.getColourMap();
 
 	// Cycle through all the ColourItems and save them into the registry
 	for (ColourItemMap::iterator it = colourMap.begin(); it != colourMap.end(); ++it) {
@@ -157,7 +162,7 @@
 			// If the scheme is already in the list, skip it
 			if (!schemeExists(schemeName)) {
 				// Construct the ColourScheme class from the xml::node
-				_colourSchemes[schemeName] = ColourScheme(schemeNodes[i]);
+				_colourSchemes.insert(std::pair<std::string,ColourScheme>(schemeName, ColourScheme(schemeNodes[i])));
 
 				// Check, if this is the currently active scheme
 				if (schemeNodes[i].getAttributeValue("active") == "1") {
@@ -179,8 +184,11 @@
 void ColourSchemeManager::copyScheme(const std::string& fromName, const std::string& toName) {
 	if (schemeExists(fromName)) {
 		// Copy the actual entry
-		_colourSchemes[toName] = _colourSchemes[fromName];
-		_colourSchemes[toName].setReadOnly(false);
+		ColourScheme& copy = getScheme(fromName);
+		std::pair<ColourSchemeMap::iterator, bool> i = _colourSchemes.insert(std::pair<std::string,ColourScheme>(toName, copy));
+		if (i.second) {
+			i.first->second.setReadOnly(false);
+		}
 	}
 	else {
 		globalOutputStream() << "ColourSchemeManager: Scheme " << fromName << " does not exist!\n";
@@ -189,11 +197,11 @@
 
 Vector3 ColourSchemeManager::getColourVector3(const std::string& colourName) {
 	// Cast the ColourItem object onto a Vector3
-	return _colourSchemes[_activeScheme].getColour(colourName);
+	return getActiveScheme().getColour(colourName);
 }
 
 ColourItem& ColourSchemeManager::getColour(const std::string& colourName) {
-	return _colourSchemes[_activeScheme].getColour(colourName);
+	return getActiveScheme().getColour(colourName);
 }
 
 } // namespace ui
