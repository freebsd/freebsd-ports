--- lib/qwav.hh.orig	Fri Feb 23 21:29:12 2001
+++ lib/qwav.hh	Fri Feb 13 19:17:38 2004
@@ -28,6 +28,14 @@
     qwav (string filename, u_int32_t flags = READ);
 
    /*!
+   * copy constructor, ensuring that both the qfile and qwavheader
+   * superclasses get copied (qwavheader needs a deep copy)
+   */
+  qwav(const qwav &w)
+	:qfile(w),qwavheader(w)
+  {}
+
+   /*!
     * \brief compares both wavs whether they're compatible or not
     * \param wav the wav to check for compatibility
     * \return whether compatible or not
