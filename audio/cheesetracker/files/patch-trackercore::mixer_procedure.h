--- trackercore/mixer_procedure.h.orig	Tue Apr 30 16:11:28 2002
+++ trackercore/mixer_procedure.h	Sun Dec 29 01:44:12 2002
@@ -19,7 +19,13 @@
 #define MIXER_PROCEDURE_H
 
 #include  "sample_data.h"
-#include <hash_map>
+
+#if defined(__GNUC__) && (__GNUC__ > 2)
+#include <ext/hash_map>  
+using namespace __gnu_cxx;
+#else
+#include <hash_map>  
+#endif
 
 /**Mixer Procedure
 
