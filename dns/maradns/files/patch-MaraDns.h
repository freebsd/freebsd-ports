--- ./MaraDns.h.orig	2014-02-12 08:17:18.000000000 +0000
+++ ./MaraDns.h	2014-02-20 15:23:22.000000000 +0000
@@ -77,21 +77,21 @@
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
    DUENDE MAN PAGE */
-#define DUENDE_CHROOT_DIR "/etc/maradns/logger"
+#define DUENDE_CHROOT_DIR "/var/empty/"
 
 /* The default IP address that Askmara uses; this used to be 127.0.0.3
    but is now 127.0.0.1 because many non-Linux systems only use 127.0.0.1
