--- branches/KDE/3.5/kdegraphics/kfile-plugins/exr/kfile_exr.cpp	2005/09/29 14:33:08	465369
+++ kfile-plugins/exr/kfile_exr.cpp	2007/08/22 12:19:02	703387
@@ -32,6 +32,7 @@
 #include <ImfVecAttribute.h>
 #include <ImfPreviewImage.h>
 #include <ImfVersion.h>
+#include <ImfCRgbaFile.h>
 
 #include <iostream>
 
@@ -226,7 +227,14 @@
 			qcapDateString.setLength(capDateString.size());
 			appendItem( stdgroup, "Capture Date", qcapDateString );
 		}
+		// This define was introduced in EXR 1.6.0
+#ifndef IMF_B44_COMPRESSION
+		// This is the 1.4 and earlier version
 		if ( hasutcOffset(h) ) {
+#else
+		// This is the 1.6.0 and later version
+		if ( hasUtcOffset(h) ) {
+#endif
 			QString UTCOffset;
 			if (utcOffset(h)>0.0) {
 				UTCOffset.append(QString("%1").arg(utcOffset(h)/3600, 0, 'f', 1));
