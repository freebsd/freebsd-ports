--- ./src/exiv2wrapper.cpp.orig	2010-05-27 10:41:11.000000000 +0200
+++ ./src/exiv2wrapper.cpp	2011-04-12 07:51:12.423977241 +0200
@@ -457,6 +457,16 @@
         _data = 0;
     }
 
+#if EXIV2_TEST_VERSION(0,21,0)
+    Exiv2::ExifKey exifKey(key);
+    _type = Exiv2::TypeInfo::typeName(exifKey.defaultTypeId());
+    _name =exifKey.tagName();
+    _label = exifKey.tagLabel();
+    _description = exifKey.tagDesc();
+    _sectionName = Exiv2::ExifTags::sectionName(exifKey);
+    // section is no longer provided set it to sectionName currently
+    _sectionDescription = _sectionName;
+#else
     const uint16_t tag = _datum->tag();
     const Exiv2::IfdId ifd = _datum->ifdId();
     _type = Exiv2::TypeInfo::typeName(Exiv2::ExifTags::tagType(tag, ifd));
@@ -465,6 +475,7 @@
     _description = Exiv2::ExifTags::tagDesc(tag, ifd);
     _sectionName = Exiv2::ExifTags::sectionName(tag, ifd);
     _sectionDescription = Exiv2::ExifTags::sectionDesc(tag, ifd);
+#endif
 }
 
 ExifTag::~ExifTag()
