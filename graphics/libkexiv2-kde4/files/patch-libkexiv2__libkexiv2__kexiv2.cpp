--- ./libkexiv2/libkexiv2/kexiv2.cpp.orig	2009-02-27 09:39:37.000000000 +0100
+++ ./libkexiv2/libkexiv2/kexiv2.cpp	2011-04-12 00:45:19.851801624 +0200
@@ -1603,7 +1603,11 @@
     {
         std::string exifkey(exifTagName);
         Exiv2::ExifKey ek(exifkey);
+#if (EXIV2_TEST_VERSION(0,21,0))
+	return QString::fromLocal8Bit( ek.tagLabel().c_str() );
+#else
         return QString::fromLocal8Bit( Exiv2::ExifTags::tagTitle(ek.tag(), ek.ifdId()) );
+#endif
     }
     catch (Exiv2::Error& e)
     {
@@ -1619,7 +1623,11 @@
     {
         std::string exifkey(exifTagName);
         Exiv2::ExifKey ek(exifkey);
+#if (EXIV2_TEST_VERSION(0,21,0))
+	return QString::fromLocal8Bit( ek.tagDesc().c_str() );
+#else
         return QString::fromLocal8Bit( Exiv2::ExifTags::tagDesc(ek.tag(), ek.ifdId()) );
+#endif
     }
     catch (Exiv2::Error& e)
     {
