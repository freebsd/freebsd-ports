--- svm_predict.h.orig	2020-06-04 16:33:17 UTC
+++ svm_predict.h
@@ -25,8 +25,8 @@
 #define SVM_PREDICT_H
 
 #include "program.h"
-#include "libsvm/svm.h"
+#include <svm.h>
 
 void svm_predict(int argc, char ** argv);
 
-#endif
\ No newline at end of file
+#endif
