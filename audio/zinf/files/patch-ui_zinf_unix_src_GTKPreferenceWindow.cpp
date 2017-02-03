--- ui/zinf/unix/src/GTKPreferenceWindow.cpp.orig	2003-11-20 23:58:47 UTC
+++ ui/zinf/unix/src/GTKPreferenceWindow.cpp
@@ -1752,7 +1752,7 @@ void GTKPreferenceWindow::UpdateThemeLis
              originalValues.listboxIndex = proposedValues.listboxIndex 
                                          = currentValues.listboxIndex = iLoop;
          else {
-             char *name = strrchr((*i).second.c_str(), '/');
+             const char *name = strrchr((*i).second.c_str(), '/');
              if (name) {
                  name++;
                  if (name && *name) {
