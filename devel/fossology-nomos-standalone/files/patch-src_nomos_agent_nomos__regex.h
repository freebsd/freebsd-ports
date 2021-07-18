--- src/nomos/agent/nomos_regex.h.orig	2021-05-07 09:49:07 UTC
+++ src/nomos/agent/nomos_regex.h
@@ -25,8 +25,6 @@
 #include "util.h"
 #include "_autodefs.h"
 
-regex_t regc[NFOOTPRINTS];
-
 void regexError(int ret, regex_t *regc, char *regex);
 int endsIn(char *s, char *suffix);
 int lineInFile(char *pathname, char *regex);
