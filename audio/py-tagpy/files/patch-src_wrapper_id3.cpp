--- src/wrapper/id3.cpp.orig	2022-12-27 17:50:55 UTC
+++ src/wrapper/id3.cpp
@@ -265,7 +265,7 @@ void exposeID3()
   {
     typedef ID3v2::AttachedPictureFrame cl;
     class_<cl, bases<ID3v2::Frame>, boost::noncopyable>
-      ("id3v2_AttachedPictureFrame", init<optional<const ByteVector &> >())
+      ("id3v2_AttachedPictureFrame", init<boost::python::optional<const ByteVector &> >())
       .DEF_SIMPLE_METHOD(textEncoding)
       .DEF_SIMPLE_METHOD(setTextEncoding)
       .DEF_SIMPLE_METHOD(mimeType)
@@ -282,7 +282,7 @@ void exposeID3()
   {
     typedef ID3v2::CommentsFrame cl;
     class_<cl, bases<ID3v2::Frame>, boost::noncopyable>
-      ("id3v2_CommentsFrame", init<optional<const ByteVector &> >())
+      ("id3v2_CommentsFrame", init<boost::python::optional<const ByteVector &> >())
       .def(init<String::Type>())
       .DEF_SIMPLE_METHOD(language)
       .DEF_SIMPLE_METHOD(setLanguage)
@@ -336,7 +336,7 @@ void exposeID3()
   {
     typedef ID3v2::TextIdentificationFrame cl;
     class_<cl, bases<ID3v2::Frame>, boost::noncopyable>
-      ("id3v2_TextIdentificationFrame", init<const ByteVector &, optional<String::Type> >())
+      ("id3v2_TextIdentificationFrame", init<const ByteVector &, boost::python::optional<String::Type> >())
       .def("setText", (void (cl::*)(const String &)) &cl::setText)
       .def("setText", (void (cl::*)(const StringList &)) &cl::setText)
       .DEF_SIMPLE_METHOD(textEncoding)
@@ -348,7 +348,7 @@ void exposeID3()
   {
     typedef ID3v2::UnsynchronizedLyricsFrame cl;
     class_<cl, bases<ID3v2::Frame>, boost::noncopyable>
-      ("id3v2_UnsynchronizedLyricsFrame", init<optional<const ByteVector &> >())
+      ("id3v2_UnsynchronizedLyricsFrame", init<boost::python::optional<const ByteVector &> >())
       .def(init<String::Type>())
       .DEF_SIMPLE_METHOD(language)
       .DEF_SIMPLE_METHOD(setLanguage)
@@ -363,7 +363,7 @@ void exposeID3()
     typedef ID3v2::UserTextIdentificationFrame cl;
     class_<cl, bases<ID3v2::TextIdentificationFrame>, boost::noncopyable>
       ("id3v2_UserTextIdentificationFrame", init<const ByteVector &>())
-      .def(init<optional<String::Type> >())
+      .def(init<boost::python::optional<String::Type> >())
       .DEF_SIMPLE_METHOD(description)
       .DEF_SIMPLE_METHOD(setDescription)
       .DEF_SIMPLE_METHOD(fieldList)
@@ -420,8 +420,8 @@ void exposeID3()
     typedef MPEG::File cl;
     class_<MPEG::File, bases<File>, boost::noncopyable>
       ("mpeg_File",
-       init<const char *, optional<bool, AudioProperties::ReadStyle> >())
-      .def(init<const char *, ID3v2::FrameFactory *, optional<bool, AudioProperties::ReadStyle> >())
+       init<const char *, boost::python::optional<bool, AudioProperties::ReadStyle> >())
+      .def(init<const char *, ID3v2::FrameFactory *, boost::python::optional<bool, AudioProperties::ReadStyle> >())
       .def("save",
            #if (TAGPY_TAGLIB_HEX_VERSION >= 0x10800)
              (bool (MPEG::File::*)(int, bool, int))
