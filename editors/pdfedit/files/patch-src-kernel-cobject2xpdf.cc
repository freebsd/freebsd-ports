--- src/kernel/cobject2xpdf.cc.orig	2009-09-11 12:02:56 UTC
+++ src/kernel/cobject2xpdf.cc
@@ -453,16 +453,16 @@ namespace {
 				// Get Object at i-th position
 				array.arrayGetNF (i, obj.get());
 					
-				shared_ptr<IProperty> cobj;
+				boost::shared_ptr<IProperty> cobj;
 				// Create CObject from it
 				if (isPdfValid(pdf))
 				{
 					hasValidRef (ip);
-					cobj = shared_ptr<IProperty> (createObjFromXpdfObj (pdf, *obj, ip.getIndiRef()));
+					cobj = boost::shared_ptr<IProperty> (createObjFromXpdfObj (pdf, *obj, ip.getIndiRef()));
 
 				}else
 				{
-					cobj = shared_ptr<IProperty> (createObjFromXpdfObj (*obj));
+					cobj = boost::shared_ptr<IProperty> (createObjFromXpdfObj (*obj));
 				}
 
 				if (cobj)
@@ -504,12 +504,12 @@ namespace {
 				obj->free ();
 				dict.dictGetValNF (i,obj.get());
 
-				shared_ptr<IProperty> cobj;
+				boost::shared_ptr<IProperty> cobj;
 				// Create CObject from it
 				if (isPdfValid (pdf))
-					cobj = shared_ptr<IProperty> (createObjFromXpdfObj (pdf, *obj, ip.getIndiRef()));
+					cobj = boost::shared_ptr<IProperty> (createObjFromXpdfObj (pdf, *obj, ip.getIndiRef()));
 				else
-					cobj = shared_ptr<IProperty> (createObjFromXpdfObj (*obj));
+					cobj = boost::shared_ptr<IProperty> (createObjFromXpdfObj (*obj));
 
 				if (cobj)
 				{
@@ -1021,7 +1021,7 @@ size_t streamToCharBuffer (const Object 
 	// for Dict -> String conversion
 	// initDict increases streamDict's reference thus we need to
 	// decrease it back by free
-	shared_ptr< ::Object> streamDictObj(XPdfObjectFactory::getInstance(), xpdf::object_deleter());
+	boost::shared_ptr< ::Object> streamDictObj(XPdfObjectFactory::getInstance(), xpdf::object_deleter());
 	streamDictObj->initDict((Dict *)streamObject.streamGetDict());
 	std::string dict;
 	xpdfObjToString(*streamDictObj, dict);
