--- UI/CwCheatScreen.cpp.orig	2015-02-26 20:05:06 UTC
+++ UI/CwCheatScreen.cpp
@@ -72,7 +72,7 @@ void CwCheatScreen::CreateViews() {
 	leftColumn->Add(new Choice(d->T("Back")))->OnClick.Handle<UIScreen>(this, &UIScreen::OnBack);
 	//leftColumn->Add(new Choice(k->T("Add Cheat")))->OnClick.Handle(this, &CwCheatScreen::OnAddCheat);
 	leftColumn->Add(new Choice(k->T("Import Cheats")))->OnClick.Handle(this, &CwCheatScreen::OnImportCheat);
-#if defined(_WIN32) || defined(__APPLE__) || defined(__linux__)
+#if !defined(MOBILE_DEVICE)
 	leftColumn->Add(new Choice(k->T("Edit Cheat File")))->OnClick.Handle(this, &CwCheatScreen::OnEditCheatFile);
 #endif
 	leftColumn->Add(new Choice(k->T("Enable/Disable All")))->OnClick.Handle(this, &CwCheatScreen::OnEnableAll);
@@ -179,11 +179,11 @@ UI::EventReturn CwCheatScreen::OnEditChe
 	if (!retval) {
 		ERROR_LOG(BOOT, "Failed creating notepad process");
 	}
-#elif defined(__APPLE__) || defined(__linux__)
-#if defined(__linux__)
-	cheatFile = "xdg-open ";
-#elif defined(__APPLE__)
+#elif !defined(MOBILE_DEVICE)
+#if defined(__APPLE__)
 	cheatFile = "open ";
+#else
+	cheatFile = "xdg-open ";
 #endif
 	cheatFile.append(activeCheatFile);
 	NOTICE_LOG(BOOT, "Launching %s", cheatFile.c_str());
