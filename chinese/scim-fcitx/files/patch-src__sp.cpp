--- src/sp.cpp.orig	2005-05-08 16:11:29 UTC
+++ src/sp.cpp
@@ -7,10 +7,12 @@
 #include "scim_fcitx_imengine.h"
 using namespace scim;
 
+#include <cstring>
 #include <stdio.h>
 #include <sys/stat.h>
 #include <limits.h>
 #include <ctype.h>
+#include <unistd.h> // for access()
 
 #include "main.h"
 #include "sp.h"
