--- anthem/settings/Instrument.cpp.orig	Thu May 27 22:07:04 2004
+++ anthem/settings/Instrument.cpp	Thu May 27 22:07:48 2004
@@ -87,7 +87,7 @@
     // Add new instrument
     QString file = KFileDialog::getOpenFileName
         ("", "*.ins", this, "Select an instrument definition file");
-    if (file)
+    if (!file.isEmpty())
     {
         InstrumentChoiceWindow *icw = new InstrumentChoiceWindow(file, this);
         connect(icw, SIGNAL(instrument(TSE3::Ins::Instrument*)),
