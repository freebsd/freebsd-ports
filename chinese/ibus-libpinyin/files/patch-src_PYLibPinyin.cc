--- src/PYLibPinyin.cc.orig	2015-01-23 04:57:48 UTC
+++ src/PYLibPinyin.cc
@@ -21,6 +21,8 @@
 
 #include "PYLibPinyin.h"
 
+#define _WITH_GETLINE
+#include <stdio.h>
 #include <string.h>
 #include <pinyin.h>
 #include "PYPConfig.h"
