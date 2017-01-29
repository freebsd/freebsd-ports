--- src/google/protobuf/compiler/plugin.pb.cc.orig	2017-01-27 23:03:40 UTC
+++ src/google/protobuf/compiler/plugin.pb.cc
@@ -366,17 +366,17 @@ void Version::SerializeWithCachedSizes(
   // @@protoc_insertion_point(serialize_start:google.protobuf.compiler.Version)
   // optional int32 major = 1;
   if (has_major()) {
-    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->major(), output);
+    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->_major(), output);
   }
 
   // optional int32 minor = 2;
   if (has_minor()) {
-    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->minor(), output);
+    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->_minor(), output);
   }
 
   // optional int32 patch = 3;
   if (has_patch()) {
-    ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->patch(), output);
+    ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->_patch(), output);
   }
 
   // optional string suffix = 4;
@@ -402,17 +402,17 @@ void Version::SerializeWithCachedSizes(
   // @@protoc_insertion_point(serialize_to_array_start:google.protobuf.compiler.Version)
   // optional int32 major = 1;
   if (has_major()) {
-    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->major(), target);
+    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->_major(), target);
   }
 
   // optional int32 minor = 2;
   if (has_minor()) {
-    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->minor(), target);
+    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->_minor(), target);
   }
 
   // optional int32 patch = 3;
   if (has_patch()) {
-    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, this->patch(), target);
+    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, this->_patch(), target);
   }
 
   // optional string suffix = 4;
@@ -455,21 +455,21 @@ size_t Version::ByteSizeLong() const {
     if (has_major()) {
       total_size += 1 +
         ::google::protobuf::internal::WireFormatLite::Int32Size(
-          this->major());
+          this->_major());
     }
 
     // optional int32 minor = 2;
     if (has_minor()) {
       total_size += 1 +
         ::google::protobuf::internal::WireFormatLite::Int32Size(
-          this->minor());
+          this->_minor());
     }
 
     // optional int32 patch = 3;
     if (has_patch()) {
       total_size += 1 +
         ::google::protobuf::internal::WireFormatLite::Int32Size(
-          this->patch());
+          this->_patch());
     }
 
   }
@@ -505,13 +505,13 @@ void Version::MergeFrom(const Version& f
       suffix_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.suffix_);
     }
     if (from.has_major()) {
-      set_major(from.major());
+      set_major(from._major());
     }
     if (from.has_minor()) {
-      set_minor(from.minor());
+      set_minor(from._minor());
     }
     if (from.has_patch()) {
-      set_patch(from.patch());
+      set_patch(from._patch());
     }
   }
 }
