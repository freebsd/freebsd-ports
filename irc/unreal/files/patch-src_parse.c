--- src/parse.c.orig	2016-09-03 19:34:06 UTC
+++ src/parse.c
@@ -156,7 +156,7 @@ void ban_flooder(aClient *cptr)
 /*
  * This routine adds fake lag if needed.
  */
-inline void parse_addlag(aClient *cptr, int cmdbytes)
+static inline void parse_addlag(aClient *cptr, int cmdbytes)
 {
 	if (!IsServer(cptr) && !IsNoFakeLag(cptr) &&
 #ifdef FAKELAG_CONFIGURABLE
