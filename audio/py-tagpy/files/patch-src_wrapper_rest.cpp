--- src/wrapper/rest.cpp.orig	2022-12-23 20:39:57 UTC
+++ src/wrapper/rest.cpp
@@ -84,7 +84,7 @@ void exposeRest()
   {
     typedef Ogg::XiphComment cl;
     class_<cl, bases<Tag>, boost::noncopyable>
-      ("ogg_XiphComment", init<optional<const ByteVector &> >())
+      ("ogg_XiphComment", init<boost::python::optional<const ByteVector &> >())
       .DEF_SIMPLE_METHOD(fieldCount)
       .def("fieldListMap", &cl::fieldListMap,
            return_internal_reference<>())
@@ -109,14 +109,14 @@ void exposeRest()
   {
     typedef Ogg::FLAC::File cl;
     class_<cl, bases<Ogg::File>, boost::noncopyable>
-      ("ogg_flac_File", init<const char *, optional<bool, AudioProperties::ReadStyle> >())
+      ("ogg_flac_File", init<const char *, boost::python::optional<bool, AudioProperties::ReadStyle> >())
       ;
   }
 
   {
     typedef Ogg::Vorbis::File cl;
     class_<cl, bases<Ogg::File>, boost::noncopyable>
-      ("ogg_vorbis_File", init<const char *, optional<bool, AudioProperties::ReadStyle> >())
+      ("ogg_vorbis_File", init<const char *, boost::python::optional<bool, AudioProperties::ReadStyle> >())
       ;
   }
 
@@ -126,7 +126,7 @@ void exposeRest()
   {
     typedef APE::Footer cl;
     class_<cl, boost::noncopyable>(
-      "ape_Footer", init<optional<const ByteVector &> >())
+      "ape_Footer", init<boost::python::optional<const ByteVector &> >())
       .DEF_SIMPLE_METHOD(version)
       .DEF_SIMPLE_METHOD(headerPresent)
       .DEF_SIMPLE_METHOD(footerPresent)
@@ -193,8 +193,8 @@ void exposeRest()
   {
     typedef FLAC::File cl;
     class_<cl, boost::noncopyable, bases<File> >("flac_File",
-                                   init<const char *, optional<bool, AudioProperties::ReadStyle> >())
-      .def(init<const char *, ID3v2::FrameFactory *, optional<bool, AudioProperties::ReadStyle> >())
+                                   init<const char *, boost::python::optional<bool, AudioProperties::ReadStyle> >())
+      .def(init<const char *, ID3v2::FrameFactory *, boost::python::optional<bool, AudioProperties::ReadStyle> >())
       .def("ID3v1Tag",
            (ID3v1::Tag *(FLAC::File::*)(bool))
            &FLAC::File::ID3v1Tag,
@@ -227,7 +227,7 @@ void exposeRest()
   {
     typedef MPC::File cl;
     class_<MPC::File, bases<File>, boost::noncopyable>
-      ("mpc_File", init<const char *, optional<bool, AudioProperties::ReadStyle> >())
+      ("mpc_File", init<const char *, boost::python::optional<bool, AudioProperties::ReadStyle> >())
       .def("ID3v1Tag",
            (ID3v1::Tag *(cl::*)(bool))
            &cl::ID3v1Tag,
@@ -255,7 +255,7 @@ void exposeRest()
   {
     typedef TagLib::RIFF::WAV::File cl;
     class_<cl, bases<File>, boost::noncopyable>
-      ("wav_File", init<const char *, optional<bool, AudioProperties::ReadStyle> >())
+      ("wav_File", init<const char *, boost::python::optional<bool, AudioProperties::ReadStyle> >())
       .def("ID3v2Tag",
            (ID3v2::Tag *(TagLib::RIFF::WAV::File::*)())
            &cl::ID3v2Tag,
