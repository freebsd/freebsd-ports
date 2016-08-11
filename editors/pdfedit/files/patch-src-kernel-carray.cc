--- src/kernel/carray.cc.orig	2009-09-11 12:02:56 UTC
+++ src/kernel/carray.cc
@@ -80,7 +80,7 @@ CArray::getStringRepresentation (string&
 //
 //
 //
-shared_ptr<IProperty>
+boost::shared_ptr<IProperty>
 CArray::getProperty (PropertyId id) const
 {
 	//kernelPrintDbg (debug::DBG_DBG,"getProperty() " << id);
@@ -88,7 +88,7 @@ CArray::getProperty (PropertyId id) cons
 	if (id >= value.size())
 		throw OutOfRange ();
 	
-	shared_ptr<IProperty> ip = value[id];
+	boost::shared_ptr<IProperty> ip = value[id];
 	// Set mode only if pdf is valid
 	_setMode (ip,id);
 
@@ -146,7 +146,7 @@ CArray::delProperty (PropertyId id)
 	// Check whether we can make the change
 	this->canChange();
 
-	shared_ptr<IProperty> oldip = value[id];
+	boost::shared_ptr<IProperty> oldip = value[id];
 
 	// Delete that item
 	value.erase (remove (value.begin(), value.end(), oldip));
@@ -156,11 +156,11 @@ CArray::delProperty (PropertyId id)
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
@@ -181,7 +181,7 @@ CArray::delProperty (PropertyId id)
 //
 // Correctly to add an object (without name) can be done only to Array object
 //
-shared_ptr<IProperty>
+boost::shared_ptr<IProperty>
 CArray::addProperty (const IProperty& newIp)
 {
 	//kernelPrintDbg (debug::DBG_DBG,"addProperty(...)");
@@ -193,7 +193,7 @@ CArray::addProperty (const IProperty& ne
 //
 // REMARK: because of the compiler, we can't put PropertyId here
 //
-shared_ptr<IProperty>
+boost::shared_ptr<IProperty>
 CArray::addProperty (PropertyId position, const IProperty& newIp)
 {
 	//kernelPrintDbg (debug::DBG_DBG,"addProperty(" << position << ")");
@@ -208,7 +208,7 @@ CArray::addProperty (PropertyId position
 	this->canChange();
 
 	// Clone the added property
-	shared_ptr<IProperty> newIpClone = newIp.clone ();
+	boost::shared_ptr<IProperty> newIpClone = newIp.clone ();
 	assert (newIpClone);
 	
 	// Inherit id, gen number and pdf
@@ -230,7 +230,7 @@ CArray::addProperty (PropertyId position
 		assert (hasValidRef (this));
 		
 		// Create contest
-		shared_ptr<ObserverContext> context (_createContext(shared_ptr<IProperty>(new CNull ()), position));
+		boost::shared_ptr<ObserverContext> context (_createContext(boost::shared_ptr<IProperty>(new CNull ()), position));
 
 		try {
 			// notify observers and dispatch the change
@@ -256,7 +256,7 @@ CArray::addProperty (PropertyId position
 //
 //
 //
-shared_ptr<IProperty>
+boost::shared_ptr<IProperty>
 CArray::setProperty (PropertyId id, IProperty& newIp)
 {
 	//kernelPrintDbg (debug::DBG_DBG, "setProperty(" << id << ")");
@@ -269,9 +269,9 @@ CArray::setProperty (PropertyId id, IPro
 	this->canChange();
 
 	// Save the old one
-	shared_ptr<IProperty> oldip = value[id];
+	boost::shared_ptr<IProperty> oldip = value[id];
 	// Clone the added property
-	shared_ptr<IProperty> newIpClone = newIp.clone ();
+	boost::shared_ptr<IProperty> newIpClone = newIp.clone ();
 	assert (newIpClone);
 	
 	// Inherit id, gen number and pdf
@@ -289,7 +289,7 @@ CArray::setProperty (PropertyId id, IPro
 		assert (hasValidRef (this));
 		
 		// Create contest
-		shared_ptr<ObserverContext> context (_createContext (oldip,id));	
+		boost::shared_ptr<ObserverContext> context (_createContext (oldip,id));	
 
 		try {
 			// notify observers and dispatch the change
@@ -437,7 +437,7 @@ CArray::doClone () const
 //
 //
 IProperty::ObserverContext* 
-CArray::_createContext (shared_ptr<IProperty> changedIp, PropertyId id)
+CArray::_createContext (boost::shared_ptr<IProperty> changedIp, PropertyId id)
 {
 	//kernelPrintDbg (debug::DBG_DBG, "");
 
