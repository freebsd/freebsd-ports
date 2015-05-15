--- src/exportcdcatdb.cpp.orig	2013-08-29 06:08:32 UTC
+++ src/exportcdcatdb.cpp
@@ -30,6 +30,7 @@ Copyright : (C) 2003 Christoph Thielecke
 #include <QGridLayout>
 #include <QVBoxLayout>
 #include <iostream>
+#include <unistd.h>
 
 #include "icons.h"
 #include "cdcat.h"
