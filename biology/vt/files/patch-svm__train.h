--- svm_train.h.orig	2020-06-04 16:32:44 UTC
+++ svm_train.h
@@ -25,9 +25,9 @@
 #define SVM_TRAIN_H
 
 #include "program.h"
-#include "libsvm/svm.h"
+#include <svm.h>
 #include "Rmath/Rmath.h"
 
 void svm_train(int argc, char ** argv);
 
-#endif
\ No newline at end of file
+#endif
