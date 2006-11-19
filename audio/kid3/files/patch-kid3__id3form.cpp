--- ./kid3/id3form.cpp.orig	Sat Jun 17 14:46:00 2006
+++ ./kid3/id3form.cpp	Sat Sep 23 01:28:25 2006
@@ -588,7 +588,7 @@
 	st->track   = trackV2CheckBox->isChecked()   ? trackV2SpinBox->value()
 		: -1;
 	st->genre   = genreV2CheckBox->isChecked()   ?
-		Genres::getNumber(genreV2ComboBox->currentItem()) : -1;
+		Genres::getNumber(genreV2ComboBox->currentText()) : -1;
 	st->genreStr = st->genre == 0xff ? genreV2ComboBox->currentText()
 		: QString::null;
 }
