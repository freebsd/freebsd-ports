--- src/kernel/cobject2string.cc.orig	2016-06-11 06:20:13.726775000 +0900
+++ src/kernel/cobject2string.cc	2016-06-11 06:20:28.472463000 +0900
@@ -81,7 +81,7 @@
 void
 simpleValueFromString (const std::string& str, double& val)
 {
-	shared_ptr<Object> ptrObj (xpdfObjFromString(str), xpdf::object_deleter());
+	boost::shared_ptr<Object> ptrObj (xpdfObjFromString(str), xpdf::object_deleter());
 	
 		assert (objReal == ptrObj->getType ());
 		if (objReal != ptrObj->getType() && objInt != ptrObj->getType())
