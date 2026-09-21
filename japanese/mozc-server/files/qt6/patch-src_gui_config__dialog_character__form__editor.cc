--- src/gui/config_dialog/character_form_editor.cc.orig	2026-09-15 03:57:29 UTC
+++ src/gui/config_dialog/character_form_editor.cc
@@ -153,7 +153,7 @@ void CharacterFormEditor::Load(const config::Config &c
     // Preedit Katakan is always FULLWIDTH
     // This item should not be editable
     if (group == QObject::tr("Katakana")) {
-      item_preedit->setFlags(0);   // disable flag
+      item_preedit->setFlags(Qt::ItemFlags(0));   // disable flag
     }
 
     setItem(row, 0, item_group);
