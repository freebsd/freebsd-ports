--- libretro-fceumm/src/general.c.orig	2015-10-16 01:08:30 UTC
+++ libretro-fceumm/src/general.c
@@ -66,7 +66,7 @@ void FCEUI_SetDirOverride(int which, cha
          FCEUSS_CheckStates();
    }
 }
-
+/*
 #ifndef HAVE_ASPRINTF
 static int asprintf(char **strp, const char *fmt, ...) {
 	va_list ap;
@@ -83,7 +83,7 @@ static int asprintf(char **strp, const c
 	return(ret);
 }
 #endif
-
+*/
 char *FCEU_MakeFName(int type, int id1, char *cd1)
 {
    char *ret = 0;
