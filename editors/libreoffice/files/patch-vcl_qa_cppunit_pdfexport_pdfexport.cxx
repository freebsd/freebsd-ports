--- vcl/qa/cppunit/pdfexport/pdfexport.cxx.orig	2025-10-01 11:38:12 UTC
+++ vcl/qa/cppunit/pdfexport/pdfexport.cxx
@@ -1821,7 +1821,7 @@ CPPUNIT_TEST_FIXTURE(PdfExportTest, testTdf66597_3)
                 auto pName
                     = dynamic_cast<vcl::filter::PDFNameElement*>(pObject->Lookup("BaseFont"_ostr));
                 auto aName = pName->GetValue().copy(7); // skip the subset id
-                CPPUNIT_ASSERT_EQUAL_MESSAGE("Unexpected font name", "GentiumBasic"_ostr, aName);
+                CPPUNIT_ASSERT_EQUAL_MESSAGE("Unexpected font name", "Gentium"_ostr, aName);
 
                 auto pToUnicodeRef = dynamic_cast<vcl::filter::PDFReferenceElement*>(
                     pObject->Lookup("ToUnicode"_ostr));
