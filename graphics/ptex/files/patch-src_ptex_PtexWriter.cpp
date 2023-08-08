--- src/ptex/PtexWriter.cpp.orig	2022-08-05 02:02:51 UTC
+++ src/ptex/PtexWriter.cpp
@@ -66,6 +66,7 @@ OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY O
 #include <algorithm>
 #include <iostream>
 #include <sstream>
+#include <unistd.h>
 
 #include "Ptexture.h"
 #include "PtexUtils.h"
