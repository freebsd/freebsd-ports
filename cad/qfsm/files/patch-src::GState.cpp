--- src/GState.cpp.orig	Sat Jan  5 23:15:26 2002
+++ src/GState.cpp	Sat Dec 21 16:41:56 2002
@@ -312,7 +312,7 @@
     s->reflist.append(t);
 }
 
-void GState::addTransition(Project* p, GTransition* t, bool withundo=TRUE)
+void GState::addTransition(Project* p, GTransition* t, bool withundo)
 {
   tlist.append(t);
   if (withundo)
