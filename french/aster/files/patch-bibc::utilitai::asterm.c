--- bibc/utilitai/asterm.c.orig	Wed Apr 23 11:41:04 2003
+++ bibc/utilitai/asterm.c	Thu Aug  7 21:14:44 2003
@@ -271,7 +271,12 @@
 #define REP_SPY "/aster/stat/"
 #define LREP  12
 #elif defined SOLARIS || HPUX || IRIX || P_LINUX || TRU64 || SOLARIS64 
+#if defined(__FreeBSD__)
+/* Note: spycod does not exist any more, but... */
+#define REP_SPY "/var/aster/stat/"
+#else
 #define REP_SPY "/export/docaster/asa/aster/stat/"
+#endif
 #define LREP  32
 #elif defined PPRO_NT
 #define REP_SPY " "
@@ -300,6 +305,10 @@
 #define REP_MAT "/aster/materiau/"
 #define REP_OUT "/aster/outils/"
 #define REP_DON "/aster/donnees/"
+#elif defined __FreeBSD__
+#define REP_MAT "%%inst_dir%%/materiau/"
+#define REP_OUT "%%inst_dir%%/outils/"
+#define REP_DON "/var/aster/donnees/"
 #elif defined SOLARIS || HPUX || P_LINUX 
 #define REP_MAT "/logiciels/aster/materiau/"
 #define REP_OUT "/logiciels/aster/outils/"
