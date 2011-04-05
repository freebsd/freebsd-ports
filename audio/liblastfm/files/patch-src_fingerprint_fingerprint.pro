--- src/fingerprint/fingerprint.pro.orig        2011-03-06 17:36:13.070963361 -0500
+++ src/fingerprint/fingerprint.pro     2011-03-06 17:36:32.901964223 -0500
@@ -23,6 +23,6 @@
         # the difference with win32 is that windows doesn't have the f suffix
         # but I think this may be because doug didn't compile it with single
         # precision, and I'm not sure if that matters or not
-        PKGCONFIG += fftw3f
+        LIBS += -lsamplerate -lfftw3f
     }
-}
\ No newline at end of file
+}
