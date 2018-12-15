--- setup.py.orig	2018-12-15 08:37:12 UTC
+++ setup.py
@@ -87,7 +87,8 @@ extensions = [
 ]
 
 # Check if we have access to FFTW3 and if so, use that implementation
-if has_c_library('fftw3'):
+# has_c_library fails to use CFLAGS: https://github.com/pavlin-policar/fastTSNE/issues/43
+if True or has_c_library('fftw3'):
     lm_opt = '/lm' if IS_WINDOWS else '-lm'
     fftw3_opt = '/lfftw3' if IS_WINDOWS else '-lfftw3'
     extensions.append(
