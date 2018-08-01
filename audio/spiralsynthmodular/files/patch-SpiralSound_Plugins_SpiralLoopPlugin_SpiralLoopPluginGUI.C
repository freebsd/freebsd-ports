--- SpiralSound/Plugins/SpiralLoopPlugin/SpiralLoopPluginGUI.C.orig	2018-08-01 06:00:29 UTC
+++ SpiralSound/Plugins/SpiralLoopPlugin/SpiralLoopPluginGUI.C
@@ -350,7 +350,7 @@ inline void SpiralLoopPluginGUI::cb_Load_i(Fl_Button* 
 {
 	char *fn=fl_file_chooser("Load a sample", "{*.wav,*.WAV}", NULL);
 	
-	if (fn && fn!='\0')
+	if (fn && *fn!='\0')
 	{
 		strcpy(m_TextBuf,fn);
 		m_GUICH->SetData("Name",m_TextBuf);
@@ -368,7 +368,7 @@ inline void SpiralLoopPluginGUI::cb_Save_i(Fl_Button* 
 {	
 	char *fn=fl_file_chooser("Load a sample", "{*.wav,*.WAV}", NULL);
 	
-	if (fn && fn!='\0')
+	if (fn && *fn!='\0')
 	{
 		strcpy(m_TextBuf,fn);
 		m_GUICH->SetData("Name",m_TextBuf);
