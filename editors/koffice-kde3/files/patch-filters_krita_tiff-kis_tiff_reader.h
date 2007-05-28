--- filters/krita/tiff/kis_tiff_reader.h	2006/10/15 22:49:50	595862
+++ filters/krita/tiff/kis_tiff_reader.h	2007/05/26 10:45:29	668416
@@ -20,15 +20,15 @@
 #ifndef _KIS_TIFF_READER_H_
 #define _KIS_TIFF_READER_H_
 
+// On some platforms, tiffio.h #defines NULL in a bad
+// way for C++, as (void *)0 instead of using the correct
+// C++ value 0. Include stdio.h first to get the right one.
+#include <stdio.h>
 #include <tiffio.h>
 
-/*#include <stdio.h>
-
-#include <qvaluevector.h>
-
-#include <kio/job.h>
-
-#include <kis_progress_subject.h> */
+// #include <qvaluevector.h>
+// #include <kio/job.h>
+// #include <kis_progress_subject.h>
 
 #include <kis_paint_device.h>
 
