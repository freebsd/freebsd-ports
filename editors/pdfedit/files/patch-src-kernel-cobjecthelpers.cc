--- src/kernel/cobjecthelpers.cc.orig	2009-04-06 15:24:58 UTC
+++ src/kernel/cobjecthelpers.cc
@@ -42,14 +42,14 @@ int getIntFromDict(std::string name, boo
 {
 	using namespace boost;
 
-	shared_ptr<IProperty> prop_ptr=dict->getProperty(name);	
+	boost::shared_ptr<IProperty> prop_ptr=dict->getProperty(name);	
 	if(prop_ptr->getType() != pInt)
 	{
 		// malformed dictionary
 		throw ElementBadTypeException(name/*, prop_ptr->getType()*/);
 	}
 
-	shared_ptr<CInt> int_ptr=IProperty::getSmartCObjectPtr<CInt>(prop_ptr);
+	boost::shared_ptr<CInt> int_ptr=IProperty::getSmartCObjectPtr<CInt>(prop_ptr);
 	return int_ptr->getValue();
 }
 
@@ -57,14 +57,14 @@ IndiRef getRefFromDict(std::string name,
 {
 	using namespace boost;
 
-	shared_ptr<IProperty> prop_ptr=dict->getProperty(name);	
+	boost::shared_ptr<IProperty> prop_ptr=dict->getProperty(name);	
 	if(prop_ptr->getType() != pRef)
 	{
 		// malformed dictionary
 		throw ElementBadTypeException(name/*, prop_ptr->getType()*/);
 	}
 
-	shared_ptr<CRef> int_ptr=IProperty::getSmartCObjectPtr<CRef>(prop_ptr);
+	boost::shared_ptr<CRef> int_ptr=IProperty::getSmartCObjectPtr<CRef>(prop_ptr);
 	return int_ptr->getValue();
 }
 
@@ -72,14 +72,14 @@ std::string getStringFromDict(std::strin
 {
 	using namespace boost;
 
-	shared_ptr<IProperty> prop_ptr=dict->getProperty(name);	
+	boost::shared_ptr<IProperty> prop_ptr=dict->getProperty(name);	
 	if(prop_ptr->getType() != pString)
 	{
 		// malformed dictionary
 		throw ElementBadTypeException(name);
 	}
 
-	shared_ptr<CString> str_ptr=IProperty::getSmartCObjectPtr<CString>(prop_ptr);
+	boost::shared_ptr<CString> str_ptr=IProperty::getSmartCObjectPtr<CString>(prop_ptr);
 	return str_ptr->getValue();
 }
 	
@@ -87,14 +87,14 @@ std::string getNameFromDict(std::string 
 {
 	using namespace boost;
 
-	shared_ptr<IProperty> prop_ptr=dict->getProperty(name);	
+	boost::shared_ptr<IProperty> prop_ptr=dict->getProperty(name);	
 	if(prop_ptr->getType() != pName)
 	{
 		// malformed dictionary
 		throw ElementBadTypeException(name);
 	}
 
-	shared_ptr<CName> name_ptr=IProperty::getSmartCObjectPtr<CName>(prop_ptr);
+	boost::shared_ptr<CName> name_ptr=IProperty::getSmartCObjectPtr<CName>(prop_ptr);
 	std::string value;
 	name_ptr->getValue(value);
 
@@ -125,7 +125,7 @@ boost::shared_ptr<CDict> getDictFromRef(
 	// gets reference value and dereferences indirect object
 	IndiRef ref;
 	IProperty::getSmartCObjectPtr<CRef>(refProp)->getValue(ref);
-	shared_ptr<CPdf> pdf = refProp->getPdf().lock();
+	boost::shared_ptr<CPdf> pdf = refProp->getPdf().lock();
 	assert(pdf);
 	boost::shared_ptr<IProperty> indirect_ptr=pdf->getIndirectProperty(ref);
 	if(indirect_ptr->getType() != pDict)
@@ -237,7 +237,7 @@ getReferencedObject (boost::shared_ptr<I
 
 			IndiRef ref;
 			IProperty::getSmartCObjectPtr<CRef>(ip)->getValue(ref);
-			shared_ptr<CPdf> pdf = ip->getPdf().lock();
+			boost::shared_ptr<CPdf> pdf = ip->getPdf().lock();
 			assert(pdf);
 			return pdf->getIndirectProperty (ref);
 
@@ -254,7 +254,7 @@ using namespace boost;
 
 	// pdf specification says that two diagonal corners should be used and
 	// readers has to be prepared to normalize it
-	shared_ptr<CArray> array(CArrayFactory::getInstance());
+	boost::shared_ptr<CArray> array(CArrayFactory::getInstance());
 	scoped_ptr<IProperty> llx(CRealFactory::getInstance(rect.xleft));
 	scoped_ptr<IProperty> lly(CRealFactory::getInstance(rect.yleft));
 	scoped_ptr<IProperty> urx(CRealFactory::getInstance(rect.xright));
@@ -267,12 +267,12 @@ using namespace boost;
 	return array;
 }
 
-void getRectangleFromProperty(const shared_ptr<IProperty> prop, libs::Rectangle & rect)
+void getRectangleFromProperty(const boost::shared_ptr<IProperty> prop, libs::Rectangle & rect)
 {
 	if(!isArray(prop))
 		throw CObjBadValue();
 	
-	shared_ptr<CArray> array = IProperty::getSmartCObjectPtr<CArray>(prop);
+	boost::shared_ptr<CArray> array = IProperty::getSmartCObjectPtr<CArray>(prop);
 	if(array->getPropertyCount() != 4)
 		throw CObjBadValue();
 
@@ -286,7 +286,7 @@ boost::shared_ptr<IProperty> getIPropert
 {
 using namespace boost;
 
-	shared_ptr<CString> dateString(CStringFactory::getInstance());
+	boost::shared_ptr<CString> dateString(CStringFactory::getInstance());
 	char buffer[30];
 	memset(buffer, '\0', sizeof(buffer));
 
@@ -304,7 +304,7 @@ bool checkAndReplace(boost::shared_ptr<C
 {
 using namespace boost;
 
-	shared_ptr<IProperty> value;
+	boost::shared_ptr<IProperty> value;
 	try
 	{
 		value=annotDict->getProperty(fieldName);
@@ -323,9 +323,9 @@ using namespace boost;
 //
 //
 ::XRef*
-getXRef (shared_ptr<IProperty> ip)
+getXRef (boost::shared_ptr<IProperty> ip)
 {
-	shared_ptr<CPdf> pdf = ip->getPdf().lock();
+	boost::shared_ptr<CPdf> pdf = ip->getPdf().lock();
 	if(!pdf)
 		return NULL;
 	return pdf->getCXref(); 
