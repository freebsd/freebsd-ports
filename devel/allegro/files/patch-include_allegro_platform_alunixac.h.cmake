--- include/allegro/platform/alunixac.h.cmake.orig	2019-03-04 01:30:11 UTC
+++ include/allegro/platform/alunixac.h.cmake
@@ -146,6 +146,9 @@
 /* Define if JACK DIGI driver is supported. */
 #cmakedefine ALLEGRO_WITH_JACKDIGI
 
+/* Define if SNDIO DIGI driver is supported. */
+#cmakedefine ALLEGRO_WITH_SNDIODIGI
+
 /* Define if OSS DIGI driver is supported. */
 #cmakedefine ALLEGRO_WITH_OSSDIGI
 
