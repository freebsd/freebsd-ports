diff -up ./generator/qtscript_masterinclude.h.kde_phonon ./generator/qtscript_masterinclude.h
--- ./generator/qtscript_masterinclude.h.kde_phonon	2010-10-26 02:53:53.000000000 -0500
+++ ./generator/qtscript_masterinclude.h	2010-12-11 17:00:08.456338081 -0600
@@ -58,7 +58,7 @@
 #endif
 
 #ifndef QT_NO_PHONON
-#  include <phonon/phonon>
+#  include <phonon/phononnamespace.h>
 #endif
 
 #include "../qtbindings/qtscript_core/qtscriptconcurrent.h"
