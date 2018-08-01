--- SpiralSound/Plugins/PoshSamplerPlugin/PoshSamplerPluginGUI.C.orig	2018-08-01 05:59:24 UTC
+++ SpiralSound/Plugins/PoshSamplerPlugin/PoshSamplerPluginGUI.C
@@ -502,7 +502,7 @@ inline void PoshSamplerPluginGUI::cb_Load_i(Fl_Button*
 { 
 	char *fn=fl_file_chooser("Load a sample", "{*.wav,*.WAV}", NULL);
 		
-	if (fn && fn!='\0')
+	if (fn && *fn!='\0')
 	{
 		strcpy(m_TextBuf,fn);
 		m_GUICH->SetData("Name",m_TextBuf);
@@ -523,7 +523,7 @@ inline void PoshSamplerPluginGUI::cb_Save_i(Fl_Button*
 {
 	char *fn=fl_file_chooser("Save sample", "{*.wav,*.WAV}", NULL);
 		
-	if (fn && fn!='\0')
+	if (fn && *fn!='\0')
 	{		
 		strcpy(m_TextBuf,fn);
 		m_GUICH->Set("Name",m_TextBuf);
