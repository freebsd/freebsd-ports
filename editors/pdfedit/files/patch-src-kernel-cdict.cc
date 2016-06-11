--- src/kernel/cdict.cc.orig	2010-04-28 03:42:09.000000000 +0900
+++ src/kernel/cdict.cc	2016-06-11 06:01:28.994503000 +0900
@@ -95,7 +95,7 @@
 //
 //
 //
-shared_ptr<IProperty>
+boost::shared_ptr<IProperty>
 CDict::getProperty (PropertyId id) const
 {
 	//kernelPrintDbg (debug::DBG_DBG,"getProperty() " << id);
@@ -111,7 +111,7 @@
 	if (it == value.end())
 		throw ElementNotFoundException ("", "");
 	
-	shared_ptr<IProperty> ip = cmp.getIProperty ();
+	boost::shared_ptr<IProperty> ip = cmp.getIProperty ();
 
 	// Set mode only if pdf is valid
 	_setMode (ip,id);
@@ -188,7 +188,7 @@
 	if (oldit == value.end())
 		throw ElementNotFoundException ("CDict", "item not found");
 	
-	shared_ptr<IProperty> oldip = cmp.getIProperty ();
+	boost::shared_ptr<IProperty> oldip = cmp.getIProperty ();
 	
 	// Delete that item	
 	value.erase (oldit);
@@ -198,11 +198,11 @@
 		assert (hasValidRef (this));
 		
 		// Indicate that this object has changed
-		shared_ptr<ObserverContext> context (_createContext (oldip,id));	
+		boost::shared_ptr<ObserverContext> context (_createContext (oldip,id));	
 		
 		try {
 			// notify observers and dispatch the change
-			_objectChanged (shared_ptr<IProperty> (new CNull), context);
+			_objectChanged (boost::shared_ptr<IProperty> (new CNull), context);
 			
 		}catch (PdfException&)
 		{
@@ -224,7 +224,7 @@
 //
 // Correctly add an object (with name) can be done only to Dict and Stream object
 //
-shared_ptr<IProperty>
+boost::shared_ptr<IProperty>
 CDict::addProperty (const string& propertyName, const IProperty& newIp)
 {
 	kernelPrintDbg (debug::DBG_DBG,"addProperty( " << propertyName << ",...)");
@@ -239,7 +239,7 @@
 		throw CObjInvalidObject ();
 
 	// Clone the added property
-	shared_ptr<IProperty> newIpClone = newIp.clone ();
+	boost::shared_ptr<IProperty> newIpClone = newIp.clone ();
 	if (newIpClone)
 	{
 		// Inherit id, gen number and pdf
@@ -260,7 +260,7 @@
 		assert (hasValidRef (this));
 		
 		// notify observers and dispatch change
-		shared_ptr<ObserverContext> context (_createContext(shared_ptr<IProperty>(new CNull ()), propertyName));
+		boost::shared_ptr<ObserverContext> context (_createContext(boost::shared_ptr<IProperty>(new CNull ()), propertyName));
 
 		try {
 			// notify observers and dispatch the change
@@ -285,7 +285,7 @@
 //
 //
 //
-shared_ptr<IProperty>
+boost::shared_ptr<IProperty>
 CDict::setProperty (PropertyId id, IProperty& newIp)
 {
 	kernelPrintDbg (debug::DBG_DBG, "setProperty(" << id << ")");
@@ -308,9 +308,9 @@
 		return addProperty (id, newIp);
 
 	// Save the old one
-	shared_ptr<IProperty> oldIp = cmp.getIProperty ();
+	boost::shared_ptr<IProperty> oldIp = cmp.getIProperty ();
 	// Clone the added property
-	shared_ptr<IProperty> newIpClone = newIp.clone ();
+	boost::shared_ptr<IProperty> newIpClone = newIp.clone ();
 	assert (newIpClone);
 	
 	// Inherit id, gen number and pdf
@@ -328,7 +328,7 @@
 		assert (hasValidRef (this));
 		
 		// Notify observers and dispatch change
-		shared_ptr<ObserverContext> context (_createContext (oldIp,id));
+		boost::shared_ptr<ObserverContext> context (_createContext (oldIp,id));
 
 		try {
 			// notify observers and dispatch the change
@@ -382,7 +382,7 @@
 	Value::const_iterator it = value.begin();
 	for (; it != value.end(); ++it)
 	{
-		shared_ptr<IProperty> prop = it->second;
+		boost::shared_ptr<IProperty> prop = it->second;
 		Object * propObj = prop->_makeXpdfObject();
 		dictObj->dictAdd(copyString((it->first).c_str()), propObj);
 		gfree(propObj);
@@ -398,7 +398,7 @@
 //
 void 
 CDict::_objectChanged 
-	(shared_ptr<IProperty> newValue, shared_ptr<const ObserverContext> context)
+	(boost::shared_ptr<IProperty> newValue, boost::shared_ptr<const ObserverContext> context)
 {
 	// Do not notify anything if we are not in a valid pdf
 	if (!hasValidPdf (this))
@@ -424,10 +424,10 @@
 // Set mode
 //
 void
-CDict::_setMode (shared_ptr<IProperty> ip, PropertyId id) const
+CDict::_setMode (boost::shared_ptr<IProperty> ip, PropertyId id) const
 {
 	configuration::ModeController* modecontroller = NULL;
-	shared_ptr<CPdf> p = this->getPdf().lock();
+	boost::shared_ptr<CPdf> p = this->getPdf().lock();
 	if ( p && (NULL != (modecontroller=p->getModeController())))
 	{
 		assert (modecontroller);		
@@ -451,7 +451,7 @@
 		}else	
 		{ // We have found a type
 			string tmp;
-			shared_ptr<IProperty> type = cmp.getIProperty ();
+			boost::shared_ptr<IProperty> type = cmp.getIProperty ();
 			if (isName (type))
 				IProperty::getSmartCObjectPtr<CName>(type)->getValue(tmp);
 			mode = modecontroller->getMode (tmp, id);
@@ -498,7 +498,7 @@
 //
 //
 IProperty::ObserverContext* 
-CDict::_createContext (shared_ptr<IProperty> changedIp, PropertyId id)
+CDict::_createContext (boost::shared_ptr<IProperty> changedIp, PropertyId id)
 {
 	// Create the context
 	return new CDictComplexObserverContext (changedIp, id);
