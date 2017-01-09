Obtained from:	https://github.com/jedisct1/pure-ftpd/commit/3823d00dee089b998d1f40943e9aa3f619c238b2

--- src/simpleconf_ftpd.h.orig	2016-12-16 19:17:52 UTC
+++ src/simpleconf_ftpd.h
@@ -59,8 +59,8 @@ static const SimpleConfEntry simpleconf_
     {"ProhibitDotFilesRead? <bool>",              "--prohibitdotfilesread"},
     {"Quota (<digits>):(<digits>)",               "--quota=$0:$1"},
     {"SyslogFacility (<alnum>)",                  "--syslogfacility=$0"},
-    {"TLS (<digits>)",                            "--tls=$0"},
     {"TLSCipherSuite (<nospace>)",                "--tlsciphersuite=$0"},
+    {"TLS (<digits>)",                            "--tls=$0"},
     {"TrustedGID (<digits>)",                     "--trustedgid=$0"},
     {"TrustedIP (<nospace>)",                     "--trustedip=$0"},
     {"Umask (<digits>):(<digits>)",               "--umask=$0:$1"},
