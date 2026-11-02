--- src/glb_postprocess.hpp.orig	2026-11-02 14:17:13 UTC
+++ src/glb_postprocess.hpp
@@ -0,0 +1,127 @@
+#pragma once
+
+// Fallback used when OCCT's RWGltf_CafWriter lacks the cascadio callbacks
+// (e.g. the FreeBSD port of OpenCASCADE without patches/tm_brep_faces.patch).
+//
+// Applies the JSON post-process and binary append callbacks to an already
+// written GLB buffer, mimicking what the patched RWGltf_CafWriter does
+// while writing.
+
+#include <cstdint>
+#include <cstring>
+#include <functional>
+#include <iostream>
+#include <sstream>
+#include <string>
+#include <vector>
+
+/// Same signatures as the patched RWGltf_CafWriter callback types.
+using GlbJsonPostProcessCallback =
+    std::function<std::string(const std::string &theJson)>;
+using GlbBinaryAppendCallback =
+    std::function<uint32_t(std::ostream &theStream, uint32_t theExistingLength)>;
+
+namespace glb_detail {
+
+constexpr uint32_t GLB_MAGIC = 0x46546C67;      // "glTF"
+constexpr uint32_t GLB_CHUNK_JSON = 0x4E4F534A; // "JSON"
+constexpr uint32_t GLB_CHUNK_BIN = 0x004E4942;  // "BIN\0"
+
+inline uint32_t readU32(const std::vector<char> &buf, size_t off) {
+  uint32_t v;
+  std::memcpy(&v, buf.data() + off, 4);
+  return v;
+}
+
+inline void appendU32(std::vector<char> &buf, uint32_t v) {
+  const char *p = reinterpret_cast<const char *>(&v);
+  buf.insert(buf.end(), p, p + 4);
+}
+
+inline void padTo4(std::string &s, char pad) {
+  while (s.size() % 4 != 0) {
+    s.push_back(pad);
+  }
+}
+
+} // namespace glb_detail
+
+/// Rewrite a GLB buffer: pass its JSON chunk through jsonCallback and append
+/// the output of binaryCallback to its BIN chunk. Callbacks may be empty.
+/// The JSON callback is invoked before the binary one, as in the patched
+/// writer. Returns false (and leaves glb untouched) if glb is not a valid GLB.
+inline bool postProcessGlb(std::vector<char> &glb,
+                           const GlbJsonPostProcessCallback &jsonCallback,
+                           const GlbBinaryAppendCallback &binaryCallback) {
+  using namespace glb_detail;
+
+  if (!jsonCallback && !binaryCallback) {
+    return true;
+  }
+  if (glb.size() < 20 || readU32(glb, 0) != GLB_MAGIC ||
+      readU32(glb, 4) != 2) {
+    std::cerr << "Error: postProcessGlb: not a glTF 2.0 binary" << std::endl;
+    return false;
+  }
+
+  // JSON chunk (always first)
+  const uint32_t jsonLen = readU32(glb, 12);
+  if (readU32(glb, 16) != GLB_CHUNK_JSON || 20 + (size_t)jsonLen > glb.size()) {
+    std::cerr << "Error: postProcessGlb: invalid JSON chunk" << std::endl;
+    return false;
+  }
+  std::string json(glb.data() + 20, jsonLen);
+  // strip the space padding added by the writer
+  while (!json.empty() && (json.back() == ' ' || json.back() == '\0')) {
+    json.pop_back();
+  }
+
+  // Optional BIN chunk
+  std::string bin;
+  size_t off = 20 + jsonLen;
+  if (off + 8 <= glb.size() && readU32(glb, off + 4) == GLB_CHUNK_BIN) {
+    const uint32_t binLen = readU32(glb, off);
+    if (off + 8 + (size_t)binLen > glb.size()) {
+      std::cerr << "Error: postProcessGlb: invalid BIN chunk" << std::endl;
+      return false;
+    }
+    bin.assign(glb.data() + off + 8, binLen);
+  }
+
+  if (jsonCallback) {
+    json = jsonCallback(json);
+  }
+  padTo4(json, ' ');
+
+  if (binaryCallback) {
+    padTo4(bin, '\0');
+    std::ostringstream extra;
+    const uint32_t existing = static_cast<uint32_t>(bin.size());
+    binaryCallback(extra, existing);
+    bin += extra.str();
+  }
+  padTo4(bin, '\0');
+
+  const uint64_t total =
+      12 + 8 + json.size() + (bin.empty() ? 0 : 8 + bin.size());
+  if (total > UINT32_MAX) {
+    std::cerr << "Error: postProcessGlb: GLB exceeds 4 GiB" << std::endl;
+    return false;
+  }
+
+  std::vector<char> out;
+  out.reserve(static_cast<size_t>(total));
+  appendU32(out, GLB_MAGIC);
+  appendU32(out, 2);
+  appendU32(out, static_cast<uint32_t>(total));
+  appendU32(out, static_cast<uint32_t>(json.size()));
+  appendU32(out, GLB_CHUNK_JSON);
+  out.insert(out.end(), json.begin(), json.end());
+  if (!bin.empty()) {
+    appendU32(out, static_cast<uint32_t>(bin.size()));
+    appendU32(out, GLB_CHUNK_BIN);
+    out.insert(out.end(), bin.begin(), bin.end());
+  }
+  glb.swap(out);
+  return true;
+}
