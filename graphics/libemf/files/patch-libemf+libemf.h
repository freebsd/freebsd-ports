--- libemf/libemf.h.orig	Wed Mar 17 20:00:10 2004
+++ libemf/libemf.h	Wed Mar 17 20:00:10 2004
@@ -338,7 +338,7 @@
 	fread( &dword, sizeof(DWORD), 1, fp_ );
       return *this;
     }
-#if !defined(__alpha__)
+#if !defined(__alpha__) && !defined(__amd64__) && !defined(__ia64__) && !defined(__sparc64__)
     /*!
      * Output a long int to the stream (swabbed).
      * \param long long int to output.
@@ -408,7 +408,7 @@
 	fread( &int_, sizeof(INT), 1, fp_ );
       return *this;
     }
-#if !defined(__alpha__)
+#if !defined(__alpha__) && !defined(__amd64__) && !defined(__ia64__) && !defined(__sparc64__)
     /*!
      * Output a (long) unsigned int to the stream (swabbed).
      * \param uint (long) unsigned int to output.
