--- include/allegro/platform/alunixac.h.cmake.orig	2010-05-08 05:55:30 UTC
+++ include/allegro/platform/alunixac.h.cmake
@@ -143,6 +143,9 @@
 /* Define if JACK DIGI driver is supported. */
 #cmakedefine ALLEGRO_WITH_JACKDIGI
 
+/* Define if SNDIO DIGI driver is supported. */
+#cmakedefine ALLEGRO_WITH_SNDIODIGI
+
 /* Define if OSS DIGI driver is supported. */
 #cmakedefine ALLEGRO_WITH_OSSDIGI
 
