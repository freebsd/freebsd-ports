--- src/convert.hpp.orig	2026-11-02 14:15:12 UTC
+++ src/convert.hpp
@@ -1,6 +1,7 @@
 #pragma once
 
 #include "filehandle.hpp"
+#include "glb_postprocess.hpp"
 #include "iges.hpp"
 #include "materials.hpp"
 #include "primitives.hpp"
@@ -27,6 +28,18 @@
 #include <Bnd_Box.hxx>
 // GLTF Write methods
 #include <RWGltf_CafWriter.hxx>
+
+// CASCADIO_HAVE_GLTF_CALLBACKS is defined by CMake when RWGltf_CafWriter
+// provides the callbacks added by patches/tm_brep_faces.patch. Without them
+// (unpatched OpenCASCADE port), JSON/binary post-processing is applied to
+// the finished GLB instead, and per-face BREP data is unavailable.
+#ifdef CASCADIO_HAVE_GLTF_CALLBACKS
+using JsonPostProcessCallback = RWGltf_CafWriter::JsonPostProcessCallback;
+using BinaryAppendCallback = RWGltf_CafWriter::BinaryAppendCallback;
+#else
+using JsonPostProcessCallback = GlbJsonPostProcessCallback;
+using BinaryAppendCallback = GlbBinaryAppendCallback;
+#endif
 // OBJ Write methods
 #include <RWObj_CafWriter.hxx>
 
@@ -153,13 +166,14 @@ static bool exportToGlbFile(
     Handle(TDocStd_Document) doc, const char *output_path,
     bool merge_primitives, bool use_parallel,
     std::vector<FaceTriangleData> *faceData = nullptr,
-    RWGltf_CafWriter::JsonPostProcessCallback jsonCallback = nullptr,
-    RWGltf_CafWriter::BinaryAppendCallback binaryCallback = nullptr) {
+    JsonPostProcessCallback jsonCallback = nullptr,
+    BinaryAppendCallback binaryCallback = nullptr) {
   RWGltf_CafWriter cafWriter(output_path, true);
   cafWriter.SetMergeFaces(merge_primitives);
   cafWriter.SetParallel(use_parallel);
   cafWriter.SetTransformationFormat(RWGltf_WriterTrsfFormat_Mat4);
 
+#ifdef CASCADIO_HAVE_GLTF_CALLBACKS
   // Set callback to collect face data if requested
   if (faceData != nullptr) {
     faceData->clear();
@@ -179,6 +193,15 @@ static bool exportToGlbFile(
   if (binaryCallback) {
     cafWriter.SetBinaryAppendCallback(binaryCallback);
   }
+#else
+  // Callbacks are applied afterwards by exportToGlbBytes(); face data
+  // cannot be collected without the patched writer.
+  if (faceData != nullptr) {
+    faceData->clear();
+  }
+  (void)jsonCallback;
+  (void)binaryCallback;
+#endif
 
   Message_ProgressRange progress;
   NCollection_IndexedDataMap<TCollection_AsciiString, TCollection_AsciiString>
@@ -190,8 +213,8 @@ static std::vector<char> exportToGlbBytes(
 static std::vector<char> exportToGlbBytes(
     Handle(TDocStd_Document) doc, bool merge_primitives, bool use_parallel,
     std::vector<FaceTriangleData> *faceData = nullptr,
-    RWGltf_CafWriter::JsonPostProcessCallback jsonCallback = nullptr,
-    RWGltf_CafWriter::BinaryAppendCallback binaryCallback = nullptr) {
+    JsonPostProcessCallback jsonCallback = nullptr,
+    BinaryAppendCallback binaryCallback = nullptr) {
   // OCCT's RWGltf_CafWriter requires a file path. With our memfd patch,
   // both the output and internal .bin.tmp use memfd on Linux - zero filesystem
   // writes. Falls back to temp files on other platforms.
@@ -210,7 +233,15 @@ static std::vector<char> exportToGlbBytes(
 
   // Read result back
   handle.prepare_for_read();
+#ifdef CASCADIO_HAVE_GLTF_CALLBACKS
   return handle.read_all();
+#else
+  std::vector<char> glb = handle.read_all();
+  if (!glb.empty() && !postProcessGlb(glb, jsonCallback, binaryCallback)) {
+    return {};
+  }
+  return glb;
+#endif
 }
 
 // ============================================================================
@@ -228,6 +259,14 @@ std::vector<char> to_glb_bytes(const char *data, size_
                                std::set<std::string> brep_types = {},
                                bool include_materials = false) {
 
+#ifndef CASCADIO_HAVE_GLTF_CALLBACKS
+  if (include_brep) {
+    std::cerr << "Warning: include_brep is not supported: cascadio was built "
+                 "against an OpenCASCADE without the RWGltf_CafWriter face "
+                 "callbacks; BREP face data will be omitted" << std::endl;
+  }
+#endif
+
   LoadResult loaded = loadBytes(data, data_len, file_type, tol_linear, tol_angle,
                                 tol_relative, use_parallel);
   if (!loaded.success) {
@@ -299,8 +338,8 @@ std::vector<char> to_glb_bytes(const char *data, size_
   };
 
   // Setup callbacks for direct injection (avoids GLB roundtrip)
-  RWGltf_CafWriter::JsonPostProcessCallback jsonCallback = nullptr;
-  RWGltf_CafWriter::BinaryAppendCallback binaryCallback = nullptr;
+  JsonPostProcessCallback jsonCallback = nullptr;
+  BinaryAppendCallback binaryCallback = nullptr;
 
   if (include_brep || include_materials) {
     if (include_brep && faceDataPtr) {
