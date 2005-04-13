--- src/projects.h.orig	Sat Dec  9 22:57:49 2000
+++ src/projects.h	Thu Apr  7 17:30:36 2005
@@ -21,22 +21,24 @@
 #define _PROJECTS_H 
 
 #include <string>
-#include <hash_map>
+#include <ext/hash_map>
 #include <list>
 
 #include "dialogs.h"
 #include "files.h"
 
+using namespace std;
+
 struct str_hasher
 {
 	size_t operator()(const string &str) const
 	{
-		hash<char *> hasher;
+		__gnu_cxx::hash<char *> hasher;
 		return hasher(str.c_str());
 	};
 };
 
-typedef hash_map<string,File *,str_hasher> files_map;
+typedef __gnu_cxx::hash_map<string,File *,str_hasher> files_map;
 typedef list<string> files_list;
 
 typedef enum {UNKNOWN,C_HEADER,C_SOURCE} FileType;
