--- library/include/drumstickcommon.h.orig	2016-09-24 21:08:23 UTC
+++ library/include/drumstickcommon.h
@@ -27,7 +27,8 @@
 #include <QtDebug>
 
 extern "C" {
-#include <alsa/asoundlib.h>
+// ALSA isn't disabled cleanly, see https://sourceforge.net/p/drumstick/bugs/9
+//#include <alsa/asoundlib.h>
 }
 
 /**
@@ -73,7 +74,7 @@ public:
      */
     const QString qstrError() const 
     {
-        return QString(snd_strerror(m_errCode));
+        return QString((m_errCode));
     }
 
     /**
@@ -110,7 +111,7 @@ private:
 inline int checkErrorAndThrow(int rc, const char *where)
 {
     if (rc < 0) {
-        qDebug() << "Error code:" << rc << "(" <<  snd_strerror(rc) << ")";
+        qDebug() << "Error code:" << rc << "(" <<  (rc) << ")";
         qDebug() << "Location:" << where;
         throw SequencerError(QString(where), rc);
     }
@@ -127,7 +128,7 @@ inline int checkErrorAndThrow(int rc, co
 inline int checkWarning(int rc, const char *where)
 {
     if (rc < 0) {
-        qWarning() << "Exception code:" << rc << "(" <<  snd_strerror(rc) << ")";
+        qWarning() << "Exception code:" << rc << "(" <<  (rc) << ")";
         qWarning() << "Location:" << where;
     }
     return rc;
@@ -152,7 +153,7 @@ inline int checkWarning(int rc, const ch
  * different to the runtime library.
  * @see getRuntimeALSALibraryVersion
  */
-const QString LIBRARY_VERSION(SND_LIB_VERSION_STR);
+const QString LIBRARY_VERSION("???");
 
 } /* namespace drumstick */
 
