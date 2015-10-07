--- vcl/qa/cppunit/BitmapTest.cxx.orig	2015-08-22 06:41:35 UTC
+++ vcl/qa/cppunit/BitmapTest.cxx
@@ -62,7 +62,7 @@ void BitmapTest::testConvert()
     CPPUNIT_ASSERT_EQUAL(sal_uInt16(24), aBitmap.GetBitCount());
     {
         Bitmap::ScopedReadAccess pReadAccess(aBitmap);
-#if defined LINUX
+#if defined FREEBSD || defined LINUX
         // 24 bit Bitmap on SVP backend uses 32bit BGRX format
         CPPUNIT_ASSERT_EQUAL(static_cast<sal_uInt16>(32), pReadAccess->GetBitCount());
         CPPUNIT_ASSERT_EQUAL(sal_uLong(40), pReadAccess->GetScanlineSize());
