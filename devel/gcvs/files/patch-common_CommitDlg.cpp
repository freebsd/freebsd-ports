--- common/CommitDlg.cpp.orig	2013-09-27 10:14:52.000000000 +0200
+++ common/CommitDlg.cpp	2013-09-27 10:17:47.000000000 +0200
@@ -22,6 +22,8 @@
  * CommitDlg.cpp : the cvs commit dialog
  */
 
+#define _WITH_GETLINE
+#include <stdio.h>
 #include "stdafx.h"
 
 #ifdef WIN32
