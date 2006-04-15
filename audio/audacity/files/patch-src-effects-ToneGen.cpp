--- work/audacity-src-1.2.4b/src/effects/ToneGen.cpp.old	Sat Feb 11 11:53:25 2006
+++ src/effects/ToneGen.cpp	Sat Feb 11 11:52:07 2006
@@ -265,7 +265,7 @@
    item2->Add(item3, 0, wxALIGN_CENTRE | wxALL, 5);
 
    wxChoice *item4 = new wxChoice(parent, ID_WAVEFORM, wxDefaultPosition,
-                                  wxSize(80, -1), 0, NULL);
+                                  wxSize(80, -1), 0, NULL, 0);
    item2->Add(item4, 0, wxALIGN_CENTRE | wxALL, 5);
 
    item0->Add(item2, 1, wxALIGN_CENTRE | wxALL, 5);
