--- src/gui.cc.orig	1999-06-09 12:14:04.000000000 +0200
+++ src/gui.cc	2007-12-18 19:55:33.000000000 +0100
@@ -31,7 +31,9 @@
 #endif
 
 #include <stdio.h>
-#include <iostream.h>
+#include <iostream>
+using namespace std;
+
 #include <ctype.h>
 #include <assert.h>
 
@@ -101,79 +103,59 @@
 static GTimer *midiTimer;
 static gulong currentTime = 0;
 
+static gchar fileEntry[] = "/_File";
+static gchar fileOpenEntry[] = "/File/_Open...";
+static gchar fileSep1Entry[] = "/File/sep1";
+static gchar fileQuitEntry[] = "/File/_Quit";
+static gchar editEntry[] = "/_Edit";
+static gchar editPlayEntry[] = "/Edit/_Play options...";
+static gchar editDevEntry[] = "/Edit/_Device options...";
+static gchar midiEntry[] = "/_Midi";
+static gchar midiNotesOffEntry[] = "/Midi/All notes off";
+static gchar midiResetEntry[] = "/Midi/Reset";
+static gchar helpEntry[] = "/_Help";
+static gchar helpAboutEntry[] = "/Help/_About ...";
+static gchar helpSep1Entry[] = "/Help/sep1";
+static gchar helpCopyEntry[] = "/Help/_Copying ...";
+static gchar branchEntry[] = "<Branch>";
+static gchar lastBranchEntry[] = "<LastBranch>";
+static gchar controlDEntry[] = "<control>D";
+static gchar controlOEntry[] = "<control>O";
+static gchar controlPEntry[] = "<control>P";
+static gchar controlQEntry[] = "<control>Q";
+static gchar separatorEntry[] = "<Separator>";
+
 static GtkItemFactoryEntry menu_items[] =
 {
-  {"/_File",                   0,            
-   0,                                      0, 
-   "<Branch>"},
-
-  {"/File/_Open...",           "<control>O", 
-   GTK_SIGNAL_FUNC(fileOpenCallback),      0, 
-   0},
-
-  {"/File/sep1",               0,            
-   0,                                      0, 
-   "<Separator>"},
-
-  {"/File/_Quit",              "<control>Q", 
-   GTK_SIGNAL_FUNC(gtk_main_quit),         0, 
-   0},
-
-  
-  {"/_Edit",                   0,            
-   0,                                      0, 
-   "<Branch>"},
-
-  {"/Edit/_Play options...",   "<control>P", 
-   GTK_SIGNAL_FUNC(optionsPlayCallback),   0, 
-   0},
-
-  {"/Edit/_Device options...", "<control>D", 
-   GTK_SIGNAL_FUNC(optionsDeviceCallback), 0, 
-   0},
-
-
-  {"/_Midi",                   0,            
-   0,                                      0, 
-   "<Branch>"},
-
-  {"/Midi/All notes off",      0, 
-   0,                                      0, 
-   0},
-
-  {"/Midi/Reset",              0, 
-   0,                                      0, 
-   0},
-
-
-  {"/_Help",                   0,            
-   0,                                      0, 
-   "<LastBranch>"},
-
-  {"/Help/_About ...",         0,            
-   GTK_SIGNAL_FUNC(helpAboutCallback),     0, 
-   0},
-
-  {"/Help/sep1",               0,            
-   0,                                      0, 
-   "<Separator>"},
-
-  {"/Help/_Copying ...",       0,            
-   GTK_SIGNAL_FUNC(helpCopyingCallback),   0, 
-   0}
+  {fileEntry, NULL, NULL, NULL, branchEntry},
+  {fileOpenEntry, controlOEntry, GTK_SIGNAL_FUNC(fileOpenCallback), 0, NULL},
+  {fileSep1Entry, NULL, NULL, 0, separatorEntry},
+  {fileQuitEntry, controlQEntry, GTK_SIGNAL_FUNC(gtk_main_quit), 0, NULL},
+  {editEntry, NULL, NULL, 0, branchEntry},
+  {editPlayEntry, controlPEntry, GTK_SIGNAL_FUNC(optionsPlayCallback), 0, NULL},
+  {editDevEntry, controlDEntry, GTK_SIGNAL_FUNC(optionsDeviceCallback), 0, NULL},
+  {midiEntry, NULL, NULL, NULL, branchEntry},
+  {midiNotesOffEntry, NULL, NULL, 0, NULL},
+  {midiResetEntry, NULL, NULL, 0, NULL},
+  {helpEntry, NULL, NULL, 0, lastBranchEntry},
+  {helpAboutEntry, NULL, GTK_SIGNAL_FUNC(helpAboutCallback), 0, NULL},
+  {helpSep1Entry, NULL, NULL,  0, separatorEntry},
+  {helpCopyEntry, NULL, GTK_SIGNAL_FUNC(helpCopyingCallback), 0, NULL}
 };
 
+static gchar stringEntry[] = "STRING";
+static gchar textplainEntry[] = "text/plain";
 
 static GtkTargetEntry target_table[] =
 {
-  { "STRING",                     0, 0 },
-  { "text/plain",                 0, 0 }
+  { stringEntry,    0, 0 },
+  { textplainEntry, 0, 0 }
 };
 
 
 typedef struct 
 {
-  char **pixmap;
+  const char **pixmap;
   char *text;
   char *tooltip_text;
   GtkSignalFunc callback;
@@ -181,15 +163,24 @@
   GtkWidget *widget;
 } toolbarEntry;
 
+static char rewindEntry[] = "Rewind";
+static char rewindEntryDescr[] = "Rewind MIDI file";
+static char stopEntry[] = "Stop";
+static char stopEntryDescr[] = "Stop playing and shut off all MIDI controllers";
+static char playEntry[] = "Play";
+static char playEntryDescr[] = "Play MIDI file";
+static char pauseEntry[] = "Pause";
+static char pauseEntryDescr[] = "Pause playing";
+static char ffwdEntry[] = "Ffwd";
+static char ffwdEntryDescr[] = "Fast forward";
 
 static toolbarEntry toolbar_items[] =
 {
-  { rewind_xpm,      "Rewind", "Rewind MIDI file", GTK_SIGNAL_FUNC(rewindCallback),  0, 0},
-  { stop_xpm,        "Stop",   
-    "Stop playing and shut off all MIDI controllers", GTK_SIGNAL_FUNC(stopCallback), 0, 0},
-  { play_xpm,        "Play",  "Play MIDI file",    GTK_SIGNAL_FUNC(playCallback),    0, 0},
-  { pause_xpm,       "Pause", "Pause playing",     GTK_SIGNAL_FUNC(pauseCallback),   0, 0},
-  { fastforward_xpm, "Ffwd",  "Fast forward",      0,                                0, 0}
+  { rewind_xpm,      rewindEntry, rewindEntryDescr, GTK_SIGNAL_FUNC(rewindCallback), NULL, NULL},
+  { stop_xpm,        stopEntry,   stopEntryDescr,   GTK_SIGNAL_FUNC(stopCallback),   NULL, NULL},
+  { play_xpm,        playEntry,   playEntryDescr,   GTK_SIGNAL_FUNC(playCallback),   NULL, NULL},
+  { pause_xpm,       pauseEntry,  pauseEntryDescr,  GTK_SIGNAL_FUNC(pauseCallback),  NULL, NULL},
+  { fastforward_xpm, ffwdEntry,   ffwdEntryDescr,   NULL,                            NULL, NULL}
 };
 
 
@@ -212,7 +203,7 @@
 
 
 
-GtkWidget *createMainWindow(char *filename = 0)
+GtkWidget *createMainWindow(char *filename)
 {
   GtkWidget *mainVbox;
   GtkWidget *hbox;
@@ -509,7 +500,7 @@
     {
       pmap = gdk_pixmap_create_from_xpm_d(window->window, &mask,
 					  &style->bg[GTK_STATE_NORMAL],
-					  toolbar_items[i].pixmap);
+					  (gchar **)toolbar_items[i].pixmap);
       pixmap = gtk_pixmap_new(pmap, mask);
       // FIXME: is this enough to destroy pmap and mask?
       gdk_pixmap_unref(pmap); 
