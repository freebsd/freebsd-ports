--- src/kernel/cpage.cc.orig	2009-07-27 08:18:10 UTC
+++ src/kernel/cpage.cc
@@ -88,9 +88,9 @@ CPage::CPage (boost::shared_ptr<CDict>& 
 	//
 	// Init modules
 	//
-	_contents = shared_ptr<CPageContents> (new CPageContents(this));
+	_contents = boost::shared_ptr<CPageContents> (new CPageContents(this));
 	_modules.push_back (_contents);
-	_display = shared_ptr<CPageDisplay> (new CPageDisplay(this));
+	_display = boost::shared_ptr<CPageDisplay> (new CPageDisplay(this));
 	_modules.push_back (_display);
 	_fonts = boost::shared_ptr<CPageFonts> (new CPageFonts(this));
 	_modules.push_back (_fonts);
@@ -252,7 +252,7 @@ size_t
 CPage::getPagePosition () const
 {
 	if (hasValidPdf (_dict))
-		return _dict->getPdf().lock()->getPagePosition (shared_ptr<CPage>(const_cast<CPage*>(this),EmptyDeallocator<CPage> ()));
+		return _dict->getPdf().lock()->getPagePosition (boost::shared_ptr<CPage>(const_cast<CPage*>(this),EmptyDeallocator<CPage> ()));
 
 	throw CObjInvalidOperation ();
 }
@@ -284,9 +284,9 @@ CPage::_objectChanged (bool invalid)
 
 	// Notify observers
 	if (invalid)
-		this->notifyObservers (current, shared_ptr<const ObserverContext> ());
+		this->notifyObservers (current, boost::shared_ptr<const ObserverContext> ());
 	else
-		this->notifyObservers (current, shared_ptr<const ObserverContext> (new BasicObserverContext (current)));
+		this->notifyObservers (current, boost::shared_ptr<const ObserverContext> (new BasicObserverContext (current)));
 }
 
 
