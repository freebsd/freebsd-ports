--- src/kernel/cpageattributes.cc.orig	2009-07-27 08:18:10 UTC
+++ src/kernel/cpageattributes.cc
@@ -47,7 +47,7 @@ using namespace utils;
 //
 //
 void 
-CPageAttributes::fillInherited(const shared_ptr<CDict> pageDict, InheritedAttributes& attrs)
+CPageAttributes::fillInherited(const boost::shared_ptr<CDict> pageDict, InheritedAttributes& attrs)
 {
 	int initialized=0;
 
@@ -59,7 +59,7 @@ CPageAttributes::fillInherited(const sha
 		// attrs.__resources field is not specified yet, so tries this dictionary
 		if(pageDict->containsProperty(Specification::Page::RESOURCES))
 		{
-			shared_ptr<IProperty> prop=pageDict->getProperty(Specification::Page::RESOURCES);
+			boost::shared_ptr<IProperty> prop=pageDict->getProperty(Specification::Page::RESOURCES);
 			if(isRef(prop))
 			{
 				attrs._resources=getCObjectFromRef<CDict>(prop);
@@ -81,7 +81,7 @@ CPageAttributes::fillInherited(const sha
 		// attrs._mediaBox field is not specified yet, so tries this array
 		if(pageDict->containsProperty(Specification::Page::MEDIABOX))
 		{
-			shared_ptr<IProperty> prop=pageDict->getProperty(Specification::Page::MEDIABOX);
+			boost::shared_ptr<IProperty> prop=pageDict->getProperty(Specification::Page::MEDIABOX);
 			if(isRef(prop))
 			{
 				attrs._mediaBox=getCObjectFromRef<CArray>(prop);
@@ -102,7 +102,7 @@ CPageAttributes::fillInherited(const sha
 		// attrs._cropBox field is not specified yet, so tries this array
 		if(pageDict->containsProperty(Specification::Page::CROPBOX))
 		{
-			shared_ptr<IProperty> prop=pageDict->getProperty(Specification::Page::CROPBOX);
+			boost::shared_ptr<IProperty> prop=pageDict->getProperty(Specification::Page::CROPBOX);
 			if(isRef(prop))
 			{
 				attrs._cropBox=getCObjectFromRef<CArray>(prop);
@@ -123,7 +123,7 @@ CPageAttributes::fillInherited(const sha
 		// attrs._rotate field is not specified yet, so tries this array
 		if(pageDict->containsProperty(Specification::Page::ROTATE))
 		{
-			shared_ptr<IProperty> prop=pageDict->getProperty(Specification::Page::ROTATE);
+			boost::shared_ptr<IProperty> prop=pageDict->getProperty(Specification::Page::ROTATE);
 			if(isRef(prop))
 			{
 				attrs._rotate=getCObjectFromRef<CInt>(prop);
@@ -147,19 +147,19 @@ CPageAttributes::fillInherited(const sha
 		// stops recursion and initializes values with default
 		if(pageDict->containsProperty(Specification::Page::PARENT))
 		{
-			shared_ptr<IProperty> parentRef=pageDict->getProperty(Specification::Page::PARENT);
+			boost::shared_ptr<IProperty> parentRef=pageDict->getProperty(Specification::Page::PARENT);
 			if(!isRef(parentRef))
 				// this should not happen - malformed page tree structure
 				return;
 
-			shared_ptr<CDict> parentDict=getCObjectFromRef<CDict>(parentRef);
+			boost::shared_ptr<CDict> parentDict=getCObjectFromRef<CDict>(parentRef);
 			CPageAttributes::fillInherited(parentDict, attrs);
 		}else
 		{
 			// Resources is required and at least empty dictionary should be
 			// specified 
 			if(!attrs._resources.get())
-				attrs._resources=shared_ptr<CDict>(CDictFactory::getInstance());
+				attrs._resources=boost::shared_ptr<CDict>(CDictFactory::getInstance());
 
 			// default A4 sized box
 			libs::Rectangle defaultRect(
@@ -191,7 +191,7 @@ CPageAttributes::fillInherited(const sha
 				// direct usage of static DEFAULT_ROTATE value caused linkage
 				// error
 				int defRot=DisplayParams::DEFAULT_ROTATE;
-				attrs._rotate=shared_ptr<CInt>(CIntFactory::getInstance(defRot));
+				attrs._rotate=boost::shared_ptr<CInt>(CIntFactory::getInstance(defRot));
 			}
 		}
 	}
@@ -203,7 +203,7 @@ CPageAttributes::fillInherited(const sha
 //
 //
 void 
-CPageAttributes::setInheritable(shared_ptr<CDict>& pageDict)
+CPageAttributes::setInheritable(boost::shared_ptr<CDict>& pageDict)
 {
 	InheritedAttributes attrs;
 	CPageAttributes::fillInherited(pageDict, attrs);
