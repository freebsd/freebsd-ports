--- MaraDns.h.orig	2022-05-07 06:11:04 UTC
+++ MaraDns.h
@@ -51,7 +51,7 @@
 /* The default UID (User ID) that MaraDNS has; I put this here so packagers
    can change this easily.  This should be the 'nobody' user, or, optionally
    a special 'MaraDNS' user.  This user needs to be able to enter
-   the /etc/maradns directory, and read all zone files in /etc/maradns
+   the /usr/local/etc/maradns directory, and read all zone files in /usr/local/etc/maradns
 
    If you change this from 707, please also change the mararc man page, 
    which states the default value for this is 707.  To change the 
@@ -75,21 +75,21 @@
      line to point to Bash
  */
 
-#define MARADNS_DEFAULT_UID 707
+#define MARADNS_DEFAULT_UID 53
 
 /* The default GID (Group ID) that MaraDNS has; see the default UID notes
    above.  Again: CHANGE THE MARARC MAN PAGE IF YOU CHANGE THIS VALUE */
-#define MARADNS_DEFAULT_GID 707
+#define MARADNS_DEFAULT_GID 53
 
 /* The UID that the Duende logging process uses.  CHANGE THE DUENDE MAN
    PAGE IF YOU CHANGE THIS VALUE (same general process as changing the
    mararc man page; the source file for the duende man page is duende.ej) */
-#define DUENDE_LOGGER_UID 707
+#define DUENDE_LOGGER_UID 65534
 
 /* The directory that Duende runs in.  This directory has to exist for
    Duende to be able to run.  Again, IF YOU CHANGE THIS, CHANGE THE
    DUENDE MAN PAGE */
-#define DUENDE_CHROOT_DIR "/etc/maradns/logger"
+#define DUENDE_CHROOT_DIR "/var/empty/"
 
 /* The default IP address that Askmara uses; this used to be 127.0.0.3
    but is now 127.0.0.1 because many non-Linux systems only use 127.0.0.1
