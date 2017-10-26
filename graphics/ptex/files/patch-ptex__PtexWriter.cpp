--- src/ptex/PtexWriter.cpp.orig	2015-02-12 16:37:58 UTC
+++ src/ptex/PtexWriter.cpp
@@ -66,6 +66,7 @@ OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 #include <algorithm>
 #include <iostream>
 #include <sstream>
+#include <unistd.h>
 
 #include "Ptexture.h"
 #include "PtexUtils.h"
