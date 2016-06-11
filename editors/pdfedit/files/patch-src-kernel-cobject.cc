--- src/kernel/cobject.cc.orig	2016-06-11 06:02:30.123217000 +0900
+++ src/kernel/cobject.cc	2016-06-11 06:02:50.095614000 +0900
@@ -60,7 +60,7 @@
 	if (!hasValidPdf (ip))
 		throw CObjInvalidOperation ();
 
-	shared_ptr<CPdf> pdf = ip.getPdf ().lock ();
+	boost::shared_ptr<CPdf> pdf = ip.getPdf ().lock ();
 	IndiRef ref = ip.getIndiRef();
 	if ( &ip == (indiObj=pdf->getIndirectProperty(ref)).get() )
 		return false;
