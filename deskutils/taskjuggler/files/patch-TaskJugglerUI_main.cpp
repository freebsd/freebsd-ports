--- TaskJugglerUI/main.cpp.orig	Sat Jul  8 14:30:32 2006
+++ TaskJugglerUI/main.cpp	Sat Jul  8 14:30:39 2006
@@ -22,6 +22,7 @@
 #include <kaboutdata.h>
 #include <kcmdlineargs.h>
 #include <klocale.h>
+#include <pthread.h>
 
 static const char description[] =
     I18N_NOOP("A Project Management Software for Linux");
@@ -36,6 +37,7 @@
 
 int main(int argc, char **argv)
 {
+    pthread_yield();
     KAboutData about("taskjuggler", I18N_NOOP("TaskJuggler"), version,
                      description,
                      KAboutData::License_GPL,
