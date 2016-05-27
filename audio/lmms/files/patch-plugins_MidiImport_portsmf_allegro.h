--- plugins/MidiImport/portsmf/allegro.h.orig	2015-03-08 02:47:14 UTC
+++ plugins/MidiImport/portsmf/allegro.h
@@ -904,6 +904,7 @@ public:
     void insert_silence(double t, double len);
     Alg_track_ptr copy_track(int track_num, double t, double len, bool all);
     Alg_seq *copy(double start, double len, bool all);
+    using Alg_track::paste;
     void paste(double start, Alg_seq *seq);
     virtual void clear(double t, double len, bool all);
     virtual void merge(double t, Alg_event_list_ptr seq);
