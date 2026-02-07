--- SpiralSound/Plugins/StreamPlugin/StreamPluginGUI.C.orig	2018-08-01 06:01:08 UTC
+++ SpiralSound/Plugins/StreamPlugin/StreamPluginGUI.C
@@ -220,7 +220,7 @@ void StreamPluginGUI::cb_Pos (Fl_Slider* o, void* v) {
 
 inline void StreamPluginGUI::cb_Load_i (Fl_Button* o, void* v) {
        char *fn=fl_file_chooser("Load a sample", "{*.wav,*.WAV}", NULL);
-       if (fn && fn!='\0') {
+       if (fn && *fn!='\0') {
           strcpy (m_TextBuf, fn);
 	  m_GUICH->SetData ("FileName", (void*)m_TextBuf);
 	  m_GUICH->SetCommand (StreamPlugin::LOAD);
