--- src/spot/pskrep.cxx.orig	2009-01-17 14:45:24.000000000 -0500
+++ src/spot/pskrep.cxx	2009-01-17 14:50:02.000000000 -0500
@@ -64,7 +64,7 @@
 // It must define at least two capturing groups, the second of which is the
 // spotted callsign.
 #define CALLSIGN_RE "[[:alnum:]]?[[:alpha:]/]+[[:digit:]]+[[:alnum:]/]+"
-#ifdef __linux__
+#ifdef __linux__ || __FreeBSD__
 #  define PSKREP_RE "(de|cq|qrz)[^[:alnum:]/\n]+"  "(" CALLSIGN_RE ")"  " +(.* +)?\\2[^[:alnum:]]+$"
 #else
 #  define PSKREP_RE "(de|cq|qrz)[^[:alnum:]/\n]+"  "(" CALLSIGN_RE ")"  " +(.* +)?" \
