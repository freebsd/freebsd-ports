--- widgets/FrequencyLineEdit.cpp.orig	2021-02-01 18:08:30 UTC
+++ widgets/FrequencyLineEdit.cpp
@@ -39,7 +39,7 @@ namespace
 FrequencyLineEdit::FrequencyLineEdit (QWidget * parent)
   : QLineEdit (parent)
 {
-  setValidator (new MHzValidator {0., std::numeric_limits<Radio::Frequency>::max () / 10.e6, this});
+  setValidator (new MHzValidator {0., (float)std::numeric_limits<Radio::Frequency>::max () / 10.e6, this});
 }
 
 auto FrequencyLineEdit::frequency () const -> Frequency
