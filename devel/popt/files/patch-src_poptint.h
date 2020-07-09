--- src/poptint.h.orig	2020-05-18 07:43:13 UTC
+++ src/poptint.h
@@ -94,6 +94,7 @@ struct poptContext_s {
     struct optionStackEntry * os;
     poptArgv leftovers;
     int numLeftovers;
+    int allocLeftovers;
     int nextLeftover;
     const struct poptOption * options;
     int restLeftover;
