--- src/rapidfuzz/utils_cpp.hpp.orig	2024-08-06 20:55:30 UTC
+++ src/rapidfuzz/utils_cpp.hpp
@@ -9,20 +9,20 @@ static inline PyObject* default_process_impl(PyObject*
     switch (c_sentence.kind) {
     case RF_UINT8:
     {
-        auto proc_str = default_process(
-            std::basic_string<uint8_t>(static_cast<uint8_t*>(c_sentence.data), c_sentence.length));
+        auto data = static_cast<uint8_t*>(c_sentence.data);
+        auto proc_str = default_process(std::vector<uint8_t>(data, data + c_sentence.length));
         return PyUnicode_FromKindAndData(PyUnicode_1BYTE_KIND, proc_str.data(), (Py_ssize_t)proc_str.size());
     }
     case RF_UINT16:
     {
-        auto proc_str = default_process(
-            std::basic_string<uint16_t>(static_cast<uint16_t*>(c_sentence.data), c_sentence.length));
+        auto data = static_cast<uint16_t*>(c_sentence.data);
+        auto proc_str = default_process(std::vector<uint16_t>(data, data + c_sentence.length));
         return PyUnicode_FromKindAndData(PyUnicode_2BYTE_KIND, proc_str.data(), (Py_ssize_t)proc_str.size());
     }
     case RF_UINT32:
     {
-        auto proc_str = default_process(
-            std::basic_string<uint32_t>(static_cast<uint32_t*>(c_sentence.data), c_sentence.length));
+        auto data = static_cast<uint32_t*>(c_sentence.data);
+        auto proc_str = default_process(std::vector<uint32_t>(data, data + c_sentence.length));
         return PyUnicode_FromKindAndData(PyUnicode_4BYTE_KIND, proc_str.data(), (Py_ssize_t)proc_str.size());
     }
     // ToDo: for now do not process these elements should be done in some way in the future
