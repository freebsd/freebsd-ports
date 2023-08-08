--- plugins/builtin/source/content/tools_entries.cpp.orig	2023-05-21 08:44:41 UTC
+++ plugins/builtin/source/content/tools_entries.cpp
@@ -1501,9 +1501,6 @@ namespace hex::plugin::builtin {
                 enum class InputType { infinity, notANumber, quietNotANumber, signalingNotANumber, regular, invalid };
                 std::string specialNumbers[] = {"inf", "Inf", "INF", "nan", "Nan", "NAN", "qnan", "Qnan", "QNAN", "snan", "Snan", "SNAN"};
 
-                // We allow any input in order to accept infinities and NaNs, all invalid entries
-                // are detected by from_chars. You can also enter -0 or -inf.
-                std::from_chars_result res;
                 if (ImGui::InputText("##resultFloat", decimalFloatingPointNumberString, flags)) {
                     // Always obtain sign first.
                     if (decimalFloatingPointNumberString[0] == '-') {
@@ -1531,11 +1528,7 @@ namespace hex::plugin::builtin {
 
                     if (inputType == InputType::regular) {
                         decimalStrView = decimalFloatingPointNumberString;
-                        res = std::from_chars(decimalStrView.data(), decimalStrView.data() + decimalStrView.size(), resultFloat);
-                        // this is why we use from_chars
-                        if (res.ec != std::errc()) {
-                            inputType = InputType::invalid;
-                        }
+                        resultFloat = std::strtold(decimalStrView.data(), nullptr);
                     } else if (inputType == InputType::infinity) {
                         resultFloat = std::numeric_limits<long double>::infinity();
                         resultFloat *= (signBits == 1 ? -1 : 1);
