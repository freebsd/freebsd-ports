--- src/kernel/carray.cc.orig	2009-09-11 21:02:56.000000000 +0900
+++ src/kernel/carray.cc	2016-06-11 05:52:59.028080000 +0900
@@ -80,7 +80,7 @@
 //
 //
 //
-shared_ptr<IProperty>
+boost::shared_ptr<IProperty>
 CArray::getProperty (PropertyId id) const
 {
 	//kernelPrintDbg (debug::DBG_DBG,"getProperty() " << id);
@@ -88,7 +88,7 @@
 	if (id >= value.size())
 		throw OutOfRange ();
 	
-	shared_ptr<IProperty> ip = value[id];
+	boost::shared_ptr<IProperty> ip = value[id];
 	// Set mode only if pdf is valid
 	_setMode (ip,id);
 
@@ -146,7 +146,7 @@
 	// Check whether we can make the change
 	this->canChange();
 
-	shared_ptr<IProperty> oldip = value[id];
+	boost::shared_ptr<IProperty> oldip = value[id];
 
 	// Delete that item
 	value.erase (remove (value.begin(), value.end(), oldip));
@@ -156,11 +156,11 @@
 		assert (hasValidRef (this));
 		
 		// Create contest
-		shared_ptr<ObserverContext> context (_createContext (oldip,id));	
+		boost::shared_ptr<ObserverContext> context (_createContext (oldip,id));	
 	
 		try {
 			// notify observers and dispatch the change
-			_objectChanged (shared_ptr<IProperty> (new CNull), context);
+			_objectChanged (boost::shared_ptr<IProperty> (new CNull), context);
 			
 		}catch (PdfException&)
 		{
@@ -181,7 +181,7 @@
 //
 // Correctly to add an object (without name) can be done only to Array object
 //
-shared_ptr<IProperty>
+boost::shared_ptr<IProperty>
 CArray::addProperty (const IProperty& newIp)
 {
 	//kernelPrintDbg (debug::DBG_DBG,"addProperty(...)");
@@ -193,7 +193,7 @@
 //
 // REMARK: because of the compiler, we can't put PropertyId here
 //
-shared_ptr<IProperty>
+boost::shared_ptr<IProperty>
 CArray::addProperty (PropertyId position, const IProperty& newIp)
 {
 	//kernelPrintDbg (debug::DBG_DBG,"addProperty(" << position << ")");
@@ -208,7 +208,7 @@
 	this->canChange();
 
 	// Clone the added property
-	shared_ptr<IProperty> newIpClone = newIp.clone ();
+	boost::shared_ptr<IProperty> newIpClone = newIp.clone ();
 	assert (newIpClone);
 	
 	// Inherit id, gen number and pdf
@@ -230,7 +230,7 @@
 		assert (hasValidRef (this));
 		
 		// Create contest
-		shared_ptr<ObserverContext> context (_createContext(shared_ptr<IProperty>(new CNull ()), position));
+		boost::shared_ptr<ObserverContext> context (_createContext(boost::shared_ptr<IProperty>(new CNull ()), position));
 
 		try {
 			// notify observers and dispatch the change
@@ -256,7 +256,7 @@
 //
 //
 //
-shared_ptr<IProperty>
+boost::shared_ptr<IProperty>
 CArray::setProperty (PropertyId id, IProperty& newIp)
 {
 	//kernelPrintDbg (debug::DBG_DBG, "setProperty(" << id << ")");
@@ -269,9 +269,9 @@
 	this->canChange();
 
 	// Save the old one
-	shared_ptr<IProperty> oldip = value[id];
+	boost::shared_ptr<IProperty> oldip = value[id];
 	// Clone the added property
-	shared_ptr<IProperty> newIpClone = newIp.clone ();
+	boost::shared_ptr<IProperty> newIpClone = newIp.clone ();
 	assert (newIpClone);
 	
 	// Inherit id, gen number and pdf
@@ -289,7 +289,7 @@
 		assert (hasValidRef (this));
 		
 		// Create contest
-		shared_ptr<ObserverContext> context (_createContext (oldip,id));	
+		boost::shared_ptr<ObserverContext> context (_createContext (oldip,id));	
 
 		try {
 			// notify observers and dispatch the change
@@ -437,7 +437,7 @@
 //
 //
 IProperty::ObserverContext* 
-CArray::_createContext (shared_ptr<IProperty> changedIp, PropertyId id)
+CArray::_createContext (boost::shared_ptr<IProperty> changedIp, PropertyId id)
 {
 	//kernelPrintDbg (debug::DBG_DBG, "");
 
