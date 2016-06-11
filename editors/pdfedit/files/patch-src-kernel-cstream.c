--- ./src/kernel/cstream.cc.orig	2015-08-23 03:19:33.639621000 +0900
+++ ./src/kernel/cstream.cc	2015-08-23 03:20:30.110651000 +0900
@@ -123,7 +123,7 @@
 CStream::createReqEntries ()
 {
 	// Add one required entry in the stream dictionary (according to pdf specification)
-	shared_ptr<CInt> len (new CInt (0));
+	boost::shared_ptr<CInt> len (new CInt (0));
 	assert (len);
 	dictionary.addProperty ("Length", *len);
 }
@@ -152,7 +152,7 @@
 	CDict::Value::const_iterator it = dictionary.value.begin ();
 	for (; it != dictionary.value.end (); ++it)
 	{
-		shared_ptr<IProperty> newIp = ((*it).second)->clone ();
+		boost::shared_ptr<IProperty> newIp = ((*it).second)->clone ();
 		assert (newIp);
 		CDict::Value::value_type item =  make_pair ((*it).first, newIp);
 		clone_->dictionary.value.push_back (item);
@@ -204,7 +204,7 @@
 	this->canChange();
 
 	// Create context
-	shared_ptr<ObserverContext> context (this->_createContext());
+	boost::shared_ptr<ObserverContext> context (this->_createContext());
 
 	// Copy buf to buffer
 	buffer.clear ();
@@ -324,7 +324,7 @@
 size_t
 CStream::getLength () const 
 {
-	shared_ptr<IProperty> len = utils::getReferencedObject (dictionary.getProperty("Length"));
+	boost::shared_ptr<IProperty> len = utils::getReferencedObject (dictionary.getProperty("Length"));
 	if (isInt (len))
 	{
 		int length;
@@ -345,7 +345,7 @@
 IProperty::ObserverContext* 
 CStream::_createContext () const
 {
-	return new BasicObserverContext (shared_ptr<IProperty> (new CNull ()));
+	return new BasicObserverContext (boost::shared_ptr<IProperty> (new CNull ()));
 }
 
 
@@ -353,7 +353,7 @@
 //
 //
 void 
-CStream::_objectChanged (shared_ptr<const ObserverContext> context)
+CStream::_objectChanged (boost::shared_ptr<const ObserverContext> context)
 {
 	// Do not notify anything if we are not in a valid pdf
 	if (!hasValidPdf (this))
@@ -380,7 +380,7 @@
 		// doesn't clone but rather wrap this with shared pointer
 		// and empty deallocator to prevent from this instance
 		// deallocation
-		shared_ptr<IProperty> newValue(this, EmptyDeallocator<IProperty>());
+		boost::shared_ptr<IProperty> newValue(this, EmptyDeallocator<IProperty>());
 		// Fill it with correct values
 		newValue->setPdf (this->getPdf());
 		newValue->setIndiRef (this->getIndiRef());
