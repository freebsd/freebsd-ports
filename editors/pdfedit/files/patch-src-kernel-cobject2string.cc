--- src/kernel/cobject2string.cc.orig	2010-05-03 19:05:24 UTC
+++ src/kernel/cobject2string.cc
@@ -81,7 +81,7 @@ simpleValueFromString (const std::string
 void
 simpleValueFromString (const std::string& str, double& val)
 {
-	shared_ptr<Object> ptrObj (xpdfObjFromString(str), xpdf::object_deleter());
+	boost::shared_ptr<Object> ptrObj (xpdfObjFromString(str), xpdf::object_deleter());
 	
 		assert (objReal == ptrObj->getType ());
 		if (objReal != ptrObj->getType() && objInt != ptrObj->getType())
