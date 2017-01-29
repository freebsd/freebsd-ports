--- src/google/protobuf/compiler/plugin.pb.h.orig	2017-01-27 23:03:40 UTC
+++ src/google/protobuf/compiler/plugin.pb.h
@@ -235,21 +235,21 @@ class LIBPROTOC_EXPORT Version : public 
   bool has_major() const;
   void clear_major();
   static const int kMajorFieldNumber = 1;
-  ::google::protobuf::int32 major() const;
+  ::google::protobuf::int32 _major() const;
   void set_major(::google::protobuf::int32 value);
 
   // optional int32 minor = 2;
   bool has_minor() const;
   void clear_minor();
   static const int kMinorFieldNumber = 2;
-  ::google::protobuf::int32 minor() const;
+  ::google::protobuf::int32 _minor() const;
   void set_minor(::google::protobuf::int32 value);
 
   // optional int32 patch = 3;
   bool has_patch() const;
   void clear_patch();
   static const int kPatchFieldNumber = 3;
-  ::google::protobuf::int32 patch() const;
+  ::google::protobuf::int32 _patch() const;
   void set_patch(::google::protobuf::int32 value);
 
   // @@protoc_insertion_point(class_scope:google.protobuf.compiler.Version)
@@ -696,7 +696,7 @@ inline void Version::clear_major() {
   major_ = 0;
   clear_has_major();
 }
-inline ::google::protobuf::int32 Version::major() const {
+inline ::google::protobuf::int32 Version::_major() const {
   // @@protoc_insertion_point(field_get:google.protobuf.compiler.Version.major)
   return major_;
 }
@@ -720,7 +720,7 @@ inline void Version::clear_minor() {
   minor_ = 0;
   clear_has_minor();
 }
-inline ::google::protobuf::int32 Version::minor() const {
+inline ::google::protobuf::int32 Version::_minor() const {
   // @@protoc_insertion_point(field_get:google.protobuf.compiler.Version.minor)
   return minor_;
 }
@@ -744,7 +744,7 @@ inline void Version::clear_patch() {
   patch_ = 0;
   clear_has_patch();
 }
-inline ::google::protobuf::int32 Version::patch() const {
+inline ::google::protobuf::int32 Version::_patch() const {
   // @@protoc_insertion_point(field_get:google.protobuf.compiler.Version.patch)
   return patch_;
 }
