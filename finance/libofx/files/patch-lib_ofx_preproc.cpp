
$FreeBSD$

--- lib/ofx_preproc.cpp.orig	Sat Nov 23 23:09:24 2002
+++ lib/ofx_preproc.cpp	Sat Apr 12 22:10:56 2003
@@ -22,6 +22,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <string>
+#include <unistd.h>
 #include "ParserEventGeneratorKit.h"
 #include "libofx.h"
 #include "messages.hh"
