--- widgets/FrequencyDeltaLineEdit.cpp.orig	2021-02-01 18:08:30 UTC
+++ widgets/FrequencyDeltaLineEdit.cpp
@@ -39,8 +39,8 @@ namespace
 FrequencyDeltaLineEdit::FrequencyDeltaLineEdit (QWidget * parent)
   : QLineEdit (parent)
 {
-  setValidator (new MHzValidator {-std::numeric_limits<FrequencyDelta>::max () / 10.e6,
-        std::numeric_limits<FrequencyDelta>::max () / 10.e6, this});
+  setValidator (new MHzValidator {-(float)std::numeric_limits<FrequencyDelta>::max () / 10.e6,
+        (float)std::numeric_limits<FrequencyDelta>::max () / 10.e6, this});
 }
 
 auto FrequencyDeltaLineEdit::frequency_delta () const -> FrequencyDelta
