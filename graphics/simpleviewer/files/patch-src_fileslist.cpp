--- src/fileslist.cpp.orig	2010-05-13 07:15:11.000000000 +0000
+++ src/fileslist.cpp
@@ -8,6 +8,7 @@
 #include "fileslist.h"
 #include <iostream>
 #include <dirent.h>
+#include <unistd.h>
 
 CFilesList::CFilesList(const char* file, bool recursive) : m_listCreated(false), m_recursive(recursive), m_position(0), m_removeCurrent(false) {
 	if(file != 0) {
