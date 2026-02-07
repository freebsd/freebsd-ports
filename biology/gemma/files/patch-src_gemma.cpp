--- src/gemma.cpp.orig	2018-12-11 05:34:29 UTC
+++ src/gemma.cpp
@@ -75,9 +75,9 @@ void gemma_gsl_error_handler (const char * reason,
   std::raise(SIGINT); // keep the stack trace for gdb
 }
 
-#if defined(OPENBLAS) && !defined(OPENBLAS_LEGACY)
-#include <openblas_config.h>
-#endif
+//#if defined(OPENBLAS) && !defined(OPENBLAS_LEGACY)
+//#include <openblas_config.h>
+//#endif
 
 void GEMMA::PrintHeader(void) {
 
@@ -154,7 +154,7 @@ void GEMMA::PrintHelp(size_t option) {
 
   if (option == 0) {
     cout << endl;
-    cout << " type ./gemma -h [num] for detailed help" << endl;
+    cout << " type gemma -h [num] for detailed help" << endl;
     cout << " options: " << endl;
     cout << "  1: quick guide" << endl;
     cout << "  2: file I/O related" << endl;
@@ -176,116 +176,116 @@ void GEMMA::PrintHelp(size_t option) {
   if (option == 1) {
     cout << " QUICK GUIDE" << endl;
     cout << " to generate a relatedness matrix: " << endl;
-    cout << "         ./gemma -bfile [prefix] -gk [num] -o [prefix]" << endl;
-    cout << "         ./gemma -g [filename] -p [filename] -gk [num] -o [prefix]"
+    cout << "         gemma -bfile [prefix] -gk [num] -o [prefix]" << endl;
+    cout << "         gemma -g [filename] -p [filename] -gk [num] -o [prefix]"
          << endl;
     cout << " to generate the S matrix: " << endl;
-    cout << "         ./gemma -bfile [prefix] -gs -o [prefix]" << endl;
-    cout << "         ./gemma -p [filename] -g [filename] -gs -o [prefix]"
+    cout << "         gemma -bfile [prefix] -gs -o [prefix]" << endl;
+    cout << "         gemma -p [filename] -g [filename] -gs -o [prefix]"
          << endl;
-    cout << "         ./gemma -bfile [prefix] -cat [filename] -gs -o [prefix]"
+    cout << "         gemma -bfile [prefix] -cat [filename] -gs -o [prefix]"
          << endl;
-    cout << "         ./gemma -p [filename] -g [filename] -cat [filename] -gs "
+    cout << "         gemma -p [filename] -g [filename] -cat [filename] -gs "
             "-o [prefix]"
          << endl;
-    cout << "         ./gemma -bfile [prefix] -sample [num] -gs -o [prefix]"
+    cout << "         gemma -bfile [prefix] -sample [num] -gs -o [prefix]"
          << endl;
-    cout << "         ./gemma -p [filename] -g [filename] -sample [num] -gs -o "
+    cout << "         gemma -p [filename] -g [filename] -sample [num] -gs -o "
             "[prefix]"
          << endl;
     cout << " to generate the q vector: " << endl;
-    cout << "         ./gemma -beta [filename] -gq -o [prefix]" << endl;
-    cout << "         ./gemma -beta [filename] -cat [filename] -gq -o [prefix]"
+    cout << "         gemma -beta [filename] -gq -o [prefix]" << endl;
+    cout << "         gemma -beta [filename] -cat [filename] -gq -o [prefix]"
          << endl;
     cout << " to generate the ldsc weigthts: " << endl;
-    cout << "         ./gemma -beta [filename] -gw -o [prefix]" << endl;
-    cout << "         ./gemma -beta [filename] -cat [filename] -gw -o [prefix]"
+    cout << "         gemma -beta [filename] -gw -o [prefix]" << endl;
+    cout << "         gemma -beta [filename] -cat [filename] -gw -o [prefix]"
          << endl;
     cout << " to perform eigen decomposition of the relatedness matrix: "
          << endl;
-    cout << "         ./gemma -bfile [prefix] -k [filename] -eigen -o [prefix]"
+    cout << "         gemma -bfile [prefix] -k [filename] -eigen -o [prefix]"
          << endl;
-    cout << "         ./gemma -g [filename] -p [filename] -k [filename] -eigen "
+    cout << "         gemma -g [filename] -p [filename] -k [filename] -eigen "
             "-o [prefix]"
          << endl;
     cout << " to estimate variance components: " << endl;
-    cout << "         ./gemma -bfile [prefix] -k [filename] -vc [num] -o "
+    cout << "         gemma -bfile [prefix] -k [filename] -vc [num] -o "
             "[prefix]"
          << endl;
-    cout << "         ./gemma -p [filename] -k [filename] -vc [num] -o [prefix]"
+    cout << "         gemma -p [filename] -k [filename] -vc [num] -o [prefix]"
          << endl;
-    cout << "         ./gemma -bfile [prefix] -mk [filename] -vc [num] -o "
+    cout << "         gemma -bfile [prefix] -mk [filename] -vc [num] -o "
             "[prefix]"
          << endl;
     cout
-        << "         ./gemma -p [filename] -mk [filename] -vc [num] -o [prefix]"
-        << endl;
-    cout << "         ./gemma -beta [filename] -cor [filename] -vc [num] -o "
+         << "         gemma -p [filename] -mk [filename] -vc [num] -o [prefix]"
+         << endl;
+    cout << "         gemma -beta [filename] -cor [filename] -vc [num] -o "
             "[prefix]"
          << endl;
-    cout << "         ./gemma -beta [filename] -cor [filename] -cat [filename] "
+    cout << "         gemma -beta [filename] -cor [filename] -cat [filename] "
             "-vc [num] -o [prefix]"
          << endl;
     cout << "         options for the above two commands: -crt -windowbp [num]"
          << endl;
-    cout << "         ./gemma -mq [filename] -ms [filename] -mv [filename] -vc "
+    cout << "         gemma -mq [filename] -ms [filename] -mv [filename] -vc "
             "[num] -o [prefix]"
          << endl;
     cout << "         or with summary statistics, replace bfile with mbfile, "
             "or g or mg; vc=1 for HE weights and vc=2 for LDSC weights"
          << endl;
-    cout << "         ./gemma -beta [filename] -bfile [filename] -cat "
+    cout << "         gemma -beta [filename] -bfile [filename] -cat "
             "[filename] -wsnp [filename] -wcat [filename] -vc [num] -o [prefix]"
          << endl;
-    cout << "         ./gemma -beta [filename] -bfile [filename] -cat "
+    cout << "         gemma -beta [filename] -bfile [filename] -cat "
             "[filename] -wsnp [filename] -wcat [filename] -ci [num] -o [prefix]"
          << endl;
     cout << " to fit a linear mixed model: " << endl;
-    cout << "         ./gemma -bfile [prefix] -k [filename] -lmm [num] -o "
+    cout << "         gemma -bfile [prefix] -k [filename] -lmm [num] -o "
             "[prefix]"
          << endl;
-    cout << "         ./gemma -g [filename] -p [filename] -a [filename] -k "
+    cout << "         gemma -g [filename] -p [filename] -a [filename] -k "
             "[filename] -lmm [num] -o [prefix]"
          << endl;
     cout << " to fit a linear mixed model to test g by e effects: " << endl;
-    cout << "         ./gemma -bfile [prefix] -gxe [filename] -k [filename] "
+    cout << "         gemma -bfile [prefix] -gxe [filename] -k [filename] "
             "-lmm [num] -o [prefix]"
          << endl;
-    cout << "         ./gemma -g [filename] -p [filename] -a [filename] -gxe "
+    cout << "         gemma -g [filename] -p [filename] -a [filename] -gxe "
             "[filename] -k [filename] -lmm [num] -o [prefix]"
          << endl;
     cout << " to fit a univariate linear mixed model with different residual "
             "weights for different individuals: "
          << endl;
-    cout << "         ./gemma -bfile [prefix] -weight [filename] -k [filename] "
+    cout << "         gemma -bfile [prefix] -weight [filename] -k [filename] "
             "-lmm [num] -o [prefix]"
          << endl;
-    cout << "         ./gemma -g [filename] -p [filename] -a [filename] "
+    cout << "         gemma -g [filename] -p [filename] -a [filename] "
             "-weight [filename] -k [filename] -lmm [num] -o [prefix]"
          << endl;
     cout << " to fit a multivariate linear mixed model: " << endl;
-    cout << "         ./gemma -bfile [prefix] -k [filename] -lmm [num] -n "
+    cout << "         gemma -bfile [prefix] -k [filename] -lmm [num] -n "
             "[pheno cols...] -o [prefix]"
          << endl;
-    cout << "         ./gemma -g [filename] -p [filename] -a [filename] -k "
+    cout << "         gemma -g [filename] -p [filename] -a [filename] -k "
             "[filename] -lmm [num] -n [pheno cols...] -o [prefix]"
          << endl;
     cout << " to fit a Bayesian sparse linear mixed model: " << endl;
-    cout << "         ./gemma -bfile [prefix] -bslmm [num] -o [prefix]" << endl;
-    cout << "         ./gemma -g [filename] -p [filename] -a [filename] -bslmm "
+    cout << "         gemma -bfile [prefix] -bslmm [num] -o [prefix]" << endl;
+    cout << "         gemma -g [filename] -p [filename] -a [filename] -bslmm "
             "[num] -o [prefix]"
          << endl;
     cout << " to obtain predicted values: " << endl;
-    cout << "         ./gemma -bfile [prefix] -epm [filename] -emu [filename] "
+    cout << "         gemma -bfile [prefix] -epm [filename] -emu [filename] "
             "-ebv [filename] -k [filename] -predict [num] -o [prefix]"
          << endl;
-    cout << "         ./gemma -g [filename] -p [filename] -epm [filename] -emu "
+    cout << "         gemma -g [filename] -p [filename] -epm [filename] -emu "
             "[filename] -ebv [filename] -k [filename] -predict [num] -o "
             "[prefix]"
          << endl;
     cout << " to calculate correlations between SNPs: " << endl;
-    cout << "         ./gemma -bfile [prefix] -calccor -o [prefix]" << endl;
-    cout << "         ./gemma -g [filename] -p [filename] -calccor -o [prefix]"
+    cout << "         gemma -bfile [prefix] -calccor -o [prefix]" << endl;
+    cout << "         gemma -g [filename] -p [filename] -calccor -o [prefix]"
          << endl;
     cout << endl;
   }
@@ -3148,7 +3148,7 @@ void GEMMA::WriteLog(int argc, char **argv, PARAM &cPa
 #ifdef OPENBLAS
 
   #ifndef OPENBLAS_LEGACY
-  outfile << "## OpenBlas         =" << OPENBLAS_VERSION << " - " << openblas_get_config() << endl;
+  //outfile << "## OpenBlas         =" << OPENBLAS_VERSION << " - " << openblas_get_config() << endl;
   outfile << "##   arch           = " << openblas_get_corename() << endl;
   outfile << "##   threads        = " << openblas_get_num_threads() << endl;
   #else
