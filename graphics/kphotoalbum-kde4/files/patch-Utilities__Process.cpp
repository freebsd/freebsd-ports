--- ./Utilities/Process.cpp.orig	2012-09-25 17:40:43.000000000 +0200
+++ ./Utilities/Process.cpp	2013-01-06 03:18:46.827523021 +0100
@@ -20,6 +20,17 @@
 #include "Process.h"
 #include <KDebug>
 
+/*
+ * <KDebug> pulls in <stdio.h> which defines stdout/stderr to
+ *__stdoutp/__stderrp which is obviously not what is intended here.
+ */
+#ifdef stdout
+#  undef stdout
+#endif
+#ifdef stderr
+#  undef stderr
+#endif
+
 /**
   \class Utilities::Process
   \brief QProcess subclass which collects stdout and print stderr
