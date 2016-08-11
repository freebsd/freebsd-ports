--- src/kernel/cannotation.cc.orig	2009-07-27 08:18:10 UTC
+++ src/kernel/cannotation.cc
@@ -114,13 +114,13 @@ bool UniversalAnnotInitializer::operator
 	AnnotList::const_iterator implElem;
 	if((implElem=implList.find(annotType))==implList.end())
 		return false;
-	shared_ptr<IAnnotInitializator> impl=implElem->second;
+	boost::shared_ptr<IAnnotInitializator> impl=implElem->second;
 
 	// use registerd implementator
 	return (*impl)(annotDict, annotType);
 }
 
-bool UniversalAnnotInitializer::registerInitializer(std::string annotType, shared_ptr<IAnnotInitializator> impl, bool forceNew)
+bool UniversalAnnotInitializer::registerInitializer(std::string annotType, boost::shared_ptr<IAnnotInitializator> impl, bool forceNew)
 {
 	AnnotList::iterator elem=implList.find(annotType);
 	if(elem!=implList.end())
@@ -229,10 +229,10 @@ bool LinkAnnotInitializer::operator()(bo
 } // namespace utils
 
 // initialization of static
-shared_ptr<utils::IAnnotInitializator> 
-CAnnotation::annotInit=shared_ptr<utils::IAnnotInitializator>(new utils::UniversalAnnotInitializer());
+boost::shared_ptr<utils::IAnnotInitializator> 
+CAnnotation::annotInit=boost::shared_ptr<utils::IAnnotInitializator>(new utils::UniversalAnnotInitializer());
 
-shared_ptr<CAnnotation> CAnnotation::createAnnotation(libs::Rectangle rect, string annotType)
+boost::shared_ptr<CAnnotation> CAnnotation::createAnnotation(libs::Rectangle rect, string annotType)
 {
 using namespace debug;
 using namespace utils;
@@ -240,7 +240,7 @@ using namespace utils;
 	kernelPrintDbg(DBG_DBG, "");
 	
 	// creates new empty dictionary for annotation
-	shared_ptr<CDict> annotDictionary(CDictFactory::getInstance());
+	boost::shared_ptr<CDict> annotDictionary(CDictFactory::getInstance());
 
 	// initializes annotation dictionary maintaining information:
 	// Type of annotation dictionary has to be Annot (this is not strongly
@@ -249,7 +249,7 @@ using namespace utils;
 	checkAndReplace(annotDictionary, "Type", *typeField);
 
 	// Rectangle of annotation is constructed from given parameter
-	shared_ptr<IProperty> rectField(getIPropertyFromRectangle(rect));
+	boost::shared_ptr<IProperty> rectField(getIPropertyFromRectangle(rect));
 	checkAndReplace(annotDictionary, "Rect", *rectField);
 
 	// last modified date field (M) is initialized to current local time
@@ -257,7 +257,7 @@ using namespace utils;
 	time(&currTime);
 	struct tm currLocalTime;
 	localtime_r(&currTime, &currLocalTime);
-	shared_ptr<IProperty> mField=getIPropertyFromDate(&currLocalTime);
+	boost::shared_ptr<IProperty> mField=getIPropertyFromDate(&currLocalTime);
 	checkAndReplace(annotDictionary, "M", *mField);
 	
 	// initializes annotation dictionary according desired type - at least Type
@@ -270,7 +270,7 @@ using namespace utils;
 	if(!initialized)
 		kernelPrintDbg(DBG_WARN, "Unable to initialize annotation dictionary with type="<<annotType);
 	
-	return shared_ptr<CAnnotation>(new CAnnotation(annotDictionary));
+	return boost::shared_ptr<CAnnotation>(new CAnnotation(annotDictionary));
 }
 
 void CAnnotation::invalidate()
@@ -285,8 +285,8 @@ using namespace utils;
 	// Uses this instance as newValue, but uses EmptyDeallocator to keep
 	// instance alive when shared_ptr tries to destroy its content.
 	// context is empty
-	shared_ptr<CAnnotation> current(this, EmptyDeallocator<CAnnotation>());
-	notifyObservers(current, shared_ptr<ChangeContext>());
+	boost::shared_ptr<CAnnotation> current(this, EmptyDeallocator<CAnnotation>());
+	notifyObservers(current, boost::shared_ptr<ChangeContext>());
 }
 
 CAnnotation::AnnotType CAnnotation::getType()const
@@ -295,14 +295,14 @@ using namespace debug;
 
 	try
 	{
-		shared_ptr<IProperty> subTypeProp=annotDictionary->getProperty("Subtype");
+		boost::shared_ptr<IProperty> subTypeProp=annotDictionary->getProperty("Subtype");
 		if(!isName(subTypeProp))
 		{
 			// TODO may be problem if value is indirect (what is not very usual)
 			kernelPrintDbg(DBG_WARN, "Subtype is not Name. Type="<<subTypeProp->getType());
 			return Unknown;
 		}
-		shared_ptr<CName> subTypeName=IProperty::getSmartCObjectPtr<CName>(subTypeProp);
+		boost::shared_ptr<CName> subTypeName=IProperty::getSmartCObjectPtr<CName>(subTypeProp);
 		string typeName;
 		subTypeName->getValue(typeName);
 		return utils::annotTypeMapping(typeName);
