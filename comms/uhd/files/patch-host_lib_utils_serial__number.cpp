--- host/lib/utils/serial_number.cpp.orig	2026-10-16 14:05:41 UTC
+++ host/lib/utils/serial_number.cpp
@@ -13,13 +13,16 @@ bool serial_numbers_match(const std::string& serial_a,
 bool serial_numbers_match(const std::string& serial_a, const std::string& serial_b)
 {
     try {
-        const uint32_t a = std::stoi(serial_a, 0, 16);
-        const uint32_t b = std::stoi(serial_b, 0, 16);
-        return a == b;
-    } catch (std::out_of_range& e) {
-        return false;
-    } catch (std::invalid_argument& e) {
-        return false;
+        size_t pos_a          = 0;
+        size_t pos_b          = 0;
+        const unsigned long a = std::stoul(serial_a, &pos_a, 16);
+        const unsigned long b = std::stoul(serial_b, &pos_b, 16);
+        if (pos_a == serial_a.size() && pos_b == serial_b.size()) {
+            return a == b;
+        }
+    } catch (std::out_of_range&) {
+    } catch (std::invalid_argument&) {
     }
+    return serial_a == serial_b;
 }
 }} // namespace uhd::utils
