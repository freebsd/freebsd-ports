--- src/kernel/textoutputengines.cc.orig	2009-09-11 12:02:56 UTC
+++ src/kernel/textoutputengines.cc
@@ -232,13 +232,13 @@ namespace {
 			PdfOperator::Operands ops;
 			op->getParameters (ops);
 			assert (1 == ops.size());
-			shared_ptr<CArray> array = IProperty::getSmartCObjectPtr<CArray> (ops.front());
+			boost::shared_ptr<CArray> array = IProperty::getSmartCObjectPtr<CArray> (ops.front());
 			//
 			// Loop through TJ operands either strings or nums
 			//
 			for (size_t i = 0; i < array->getPropertyCount(); ++i)
 			{
-				shared_ptr<IProperty> ip = array->getProperty (i);
+				boost::shared_ptr<IProperty> ip = array->getProperty (i);
 				if (isNumber (ip))
 				{
 					int wMode = s->getFont()->getWMode();
@@ -253,8 +253,8 @@ namespace {
 					// Create Tj with text and add it to output
 					string txt = getStringFromIProperty (ip);
 					PdfOperator::Operands opers;
-					opers.push_back (shared_ptr<CString> (new CString (txt)));
-					shared_ptr<PdfOperator> newop = createOperator ("Tj", opers);
+					opers.push_back (boost::shared_ptr<CString> (new CString (txt)));
+					boost::shared_ptr<PdfOperator> newop = createOperator ("Tj", opers);
 					// Set bbox 
 					BBox bbox;
 					StateUpdater::printTextUpdate (s.get(), txt, &bbox);
