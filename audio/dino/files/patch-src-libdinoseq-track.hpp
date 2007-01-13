--- src/libdinoseq/track.hpp.orig	Sat Jan 13 16:51:54 2007
+++ src/libdinoseq/track.hpp	Sat Jan 13 16:52:02 2007
@@ -194,13 +194,13 @@
     
     /// @name Signals
     //@{
-    signal<void, const string&> signal_name_changed;
-    signal<void, int> signal_pattern_added; 
-    signal<void, int> signal_pattern_removed;
-    signal<void, int, int, int> signal_sequence_entry_added;
-    signal<void, int, int, int> signal_sequence_entry_changed;
-    signal<void, int> signal_sequence_entry_removed;
-    signal<void, int> signal_length_changed;
+    sigc::signal<void, const string&> signal_name_changed;
+    sigc::signal<void, int> signal_pattern_added; 
+    sigc::signal<void, int> signal_pattern_removed;
+    sigc::signal<void, int, int, int> signal_sequence_entry_added;
+    sigc::signal<void, int, int, int> signal_sequence_entry_changed;
+    sigc::signal<void, int> signal_sequence_entry_removed;
+    sigc::signal<void, int> signal_length_changed;
     //@}
     
   private:
