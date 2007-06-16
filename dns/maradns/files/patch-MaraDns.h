--- MaraDns.h.orig	Sat Jun  2 13:46:12 2007
+++ MaraDns.h	Sat Jun  2 13:47:12 2007
@@ -75,16 +75,16 @@
      line to point to Bash
  */
 
-#define MARADNS_DEFAULT_UID 99
+#define MARADNS_DEFAULT_UID 53
 
 /* The default GID (Group ID) that MaraDNS has; see the default UID notes
    above.  Again: CHANGE THE MARARC MAN PAGE IF YOU CHANGE THIS VALUE */
-#define MARADNS_DEFAULT_GID 99
+#define MARADNS_DEFAULT_GID 53
 
 /* The UID that the Duende logging process uses.  CHANGE THE DUENDE MAN
    PAGE IF YOU CHANGE THIS VALUE (same general process as changing the
    mararc man page; the source file for the duende man page is duende.ej) */
-#define DUENDE_LOGGER_UID 66
+#define DUENDE_LOGGER_UID 65534
 
 /* The directory that Duende runs in.  This directory has to exist for
    Duende to be able to run.  Again, IF YOU CHANGE THIS, CHANGE THE
