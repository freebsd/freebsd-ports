--- src/kernel/cobject.cc.orig	2009-09-11 12:02:56 UTC
+++ src/kernel/cobject.cc
@@ -60,7 +60,7 @@ objHasParent (const IProperty& ip, boost
 	if (!hasValidPdf (ip))
 		throw CObjInvalidOperation ();
 
-	shared_ptr<CPdf> pdf = ip.getPdf ().lock ();
+	boost::shared_ptr<CPdf> pdf = ip.getPdf ().lock ();
 	IndiRef ref = ip.getIndiRef();
 	if ( &ip == (indiObj=pdf->getIndirectProperty(ref)).get() )
 		return false;
