--- midimountain/stlini.h	Tue May  1 09:54:22 2001
+++ midimountain/stlini.h	Wed Dec 11 03:22:23 2002
@@ -1,3 +1,5 @@
+#ifndef _STLINI_H_
+#define _STLINI_H_
 #include <map>
 #include <string>
 using namespace std;
@@ -14,3 +16,4 @@
 void SaveIni(INIFile &theINI, const char *filename);
 INIFile LoadIni(const char *filename);
 
+#endif
