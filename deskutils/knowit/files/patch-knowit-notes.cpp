--- knowit/notes.cpp.orig	Sun Dec  8 01:24:02 2002
+++ knowit/notes.cpp	Sun Dec  8 01:50:11 2002
@@ -80,12 +80,13 @@
 bool TNotesCollection::changeNote(QListViewItem* item, const QString& s)
 {
    TNote* changed = find(item);
-   if (!changed) qWarning("Internal error: change note\n");
-   else {
-      bool change = changed->change(s);
-      modified = modified or change;
-      return change;
-      }
+   if (!changed) {
+     qWarning("Internal error: change note\n");
+     return false;
+   }
+   if (changed->change(s)) {
+     return modified = true;
+   }
    return false;
 }
 
