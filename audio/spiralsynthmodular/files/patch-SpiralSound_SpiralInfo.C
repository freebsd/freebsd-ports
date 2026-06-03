--- SpiralSound/SpiralInfo.C.orig	2003-08-16 06:16:08 UTC
+++ SpiralSound/SpiralInfo.C
@@ -31,25 +31,25 @@ float RandFloat (float s, float e) {
 
 
 
-string SpiralInfo::LOCALE      = "EN";
-int    SpiralInfo::BUFSIZE     = 512;
-int    SpiralInfo::FRAGSIZE    = 256;
-int    SpiralInfo::FRAGCOUNT   = 8;
-int    SpiralInfo::SAMPLERATE  = 44100;
-long   SpiralInfo::MAXSAMPLE   = 32767;
-float  SpiralInfo::VALUECONV   = 1.0f/MAXSAMPLE;
-bool   SpiralInfo::WANTMIDI    = false;
-int    SpiralInfo::FILTERGRAN  = 50;
-string SpiralInfo::OUTPUTFILE  = "/dev/dsp";
-string SpiralInfo::MIDIFILE    = "/dev/midi";
-int    SpiralInfo::POLY        = 1;
-bool   SpiralInfo::USEPLUGINLIST = false;
-unsigned SpiralInfo::GUI_COLOUR = 179;
-unsigned SpiralInfo::SCOPE_BG_COLOUR = fl_rgb_color (20, 60, 20);
-unsigned SpiralInfo::SCOPE_FG_COLOUR = fl_rgb_color (100, 200, 100);
-unsigned SpiralInfo::SCOPE_SEL_COLOUR = FL_WHITE;
-unsigned SpiralInfo::SCOPE_IND_COLOUR = fl_rgb_color (203, 255, 0);
-unsigned SpiralInfo::SCOPE_MRK_COLOUR = fl_rgb_color (155, 155, 50);
+//string SpiralInfo::LOCALE      = "EN";
+//int    SpiralInfo::BUFSIZE     = 512;
+//int    SpiralInfo::FRAGSIZE    = 256;
+//int    SpiralInfo::FRAGCOUNT   = 8;
+//int    SpiralInfo::SAMPLERATE  = 44100;
+//long   SpiralInfo::MAXSAMPLE   = 32767;
+//float  SpiralInfo::VALUECONV   = 1.0f/MAXSAMPLE;
+//bool   SpiralInfo::WANTMIDI    = false;
+//int    SpiralInfo::FILTERGRAN  = 50;
+//string SpiralInfo::OUTPUTFILE  = "/dev/dsp";
+//string SpiralInfo::MIDIFILE    = "/dev/midi";
+//int    SpiralInfo::POLY        = 1;
+//bool   SpiralInfo::USEPLUGINLIST = false;
+//unsigned SpiralInfo::GUI_COLOUR = 179;
+//unsigned SpiralInfo::SCOPE_BG_COLOUR = fl_rgb_color (20, 60, 20);
+//unsigned SpiralInfo::SCOPE_FG_COLOUR = fl_rgb_color (100, 200, 100);
+//unsigned SpiralInfo::SCOPE_SEL_COLOUR = FL_WHITE;
+//unsigned SpiralInfo::SCOPE_IND_COLOUR = fl_rgb_color (203, 255, 0);
+//unsigned SpiralInfo::SCOPE_MRK_COLOUR = fl_rgb_color (155, 155, 50);
 
 /*int SpiralInfo::GUICOL_Tool=179;
 int SpiralInfo::GUICOL_Button=181;
@@ -57,11 +57,11 @@ int SpiralInfo::GUIDEVICE_Box=30;*/
 int SpiralInfo::GUICOL_Device=181;
 int SpiralInfo::GUIDEVICE_Box=30;*/
 
-int SpiralInfo::GUICOL_Tool=48;
-int SpiralInfo::GUICOL_Button=42;
-int SpiralInfo::GUICOL_Canvas=50;
-int SpiralInfo::GUICOL_Device=52;
-int SpiralInfo::GUIDEVICE_Box=30;
+//int SpiralInfo::GUICOL_Tool=48;
+//int SpiralInfo::GUICOL_Button=42;
+//int SpiralInfo::GUICOL_Canvas=50;
+//int SpiralInfo::GUICOL_Device=52;
+//int SpiralInfo::GUIDEVICE_Box=30;
 
 vector<string> SpiralInfo::PLUGINVEC;
 
