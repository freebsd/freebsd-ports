--- SpiralSound/SpiralInfo.h.orig	2003-07-22 22:08:41 UTC
+++ SpiralSound/SpiralInfo.h
@@ -23,6 +23,8 @@
 #include <string>
 #include <vector>
 #include <stdlib.h>
+#include "FL/fl_draw.H"
+#include "FL/fl_message.H"
 #include "Sample.h"
 
 using namespace std;
@@ -40,34 +42,34 @@ class SpiralInfo {
       void SavePrefs();
       static void Alert (string Text);
       static void Log (string Text);
-      static int    BUFSIZE;
-      static int    FRAGSIZE;
-      static int    FRAGCOUNT;
-      static int    SAMPLERATE;
-      static long   MAXSAMPLE;
-      static float  VALUECONV;
-      static bool   WANTMIDI;
-      static int    FILTERGRAN;
-      static string OUTPUTFILE;
-      static string MIDIFILE;
-      static bool   USEPLUGINLIST;
-      static int    POLY;
-      static string LOCALE;
-      static unsigned GUI_COLOUR;
-      static unsigned SCOPE_BG_COLOUR;
-      static unsigned SCOPE_FG_COLOUR;
-      static unsigned SCOPE_SEL_COLOUR;
-      static unsigned SCOPE_IND_COLOUR;
-      static unsigned SCOPE_MRK_COLOUR;
+      inline static int    BUFSIZE=512;
+      inline static int    FRAGSIZE=256;
+      inline static int    FRAGCOUNT=8;
+      inline static int    SAMPLERATE=44100;
+      inline static long   MAXSAMPLE=32767;
+      inline static float  VALUECONV=1.0f/MAXSAMPLE;
+      inline static bool   WANTMIDI=false;
+      inline static int    FILTERGRAN=50;
+      inline static string OUTPUTFILE="/dev/dsp";
+      inline static string MIDIFILE="/dev/midi";
+      inline static bool   USEPLUGINLIST=false;
+      inline static int    POLY=1;
+      inline static string LOCALE="EN";
+      inline static unsigned GUI_COLOUR=179;
+      inline static unsigned SCOPE_BG_COLOUR=fl_rgb_color (20, 60, 20);
+      inline static unsigned SCOPE_FG_COLOUR=fl_rgb_color (100, 200, 100);
+      inline static unsigned SCOPE_SEL_COLOUR= FL_WHITE;
+      inline static unsigned SCOPE_IND_COLOUR= fl_rgb_color (203, 255, 0);
+      inline static unsigned SCOPE_MRK_COLOUR= fl_rgb_color (155, 155, 50);
       static SpiralInfo* Get();
       void SetColours();
       static string PLUGIN_PATH;
       static vector<string> PLUGINVEC;
-      static int GUICOL_Tool;
-      static int GUICOL_Button;
-      static int GUICOL_Canvas;
-      static int GUICOL_Device;
-      static int GUIDEVICE_Box;
+      inline static int GUICOL_Tool=48;
+      inline static int GUICOL_Button=42;
+      inline static int GUICOL_Canvas=50;
+      inline static int GUICOL_Device=52;
+      inline static int GUIDEVICE_Box=30;
    private:
       string m_ResFileName;
       int m_Version;
