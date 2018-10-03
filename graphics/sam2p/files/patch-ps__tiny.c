--- ps_tiny.c.orig	2014-09-16 08:52:28 UTC
+++ ps_tiny.c
@@ -1,10 +1,3 @@
-#define DUMMY \
-set -ex; \
-gcc -O3 -s -DNDEBUG=1 -DNO_CONFIG=1 -ansi -pedantic -Wunused \
-  -Wall -W -Wstrict-prototypes -Wtraditional -Wnested-externs -Winline \
-  -Wpointer-arith -Wbad-function-cast -Wcast-qual -Wmissing-prototypes \
-  -Wmissing-declarations ps_tiny.c -o ps_tiny; \
-exit
 /* ps_tiny.c -- read .pin files, write short PostScript code
  * by pts@fazekas.hu at Sat Aug 24 12:46:14 CEST 2002
  * -- Sat Aug 24 18:23:08 CEST 2002
@@ -151,7 +144,7 @@ static void ungetcc(int c) {
 }
 
 static void erri(char const*msg1, char const*msg2) {
-  fprintf(stderr, "%s: error at %"SLEN_P"u.%"SLEN_P"u.%"SLEN_P"u: %s%s\n",
+  fprintf(stderr, "%s: error at %" SLEN_P "u.%" SLEN_P "u.%" SLEN_P "u: %s%s\n",
     PROGNAME, curline, curofs-leftofs+1, curofs, msg1, msg2?msg2:"");
   exit(3);
 }
@@ -230,7 +223,7 @@ static sbool is_wordx(char const *s) {
 /** @param b: assume null-terminated @return true on error */
 static /*inline*/ sbool toInteger(char *s, psint_t *ret) {
   int n=0; /* BUGFIX?? found by __CHECKER__ */
-  return sscanf(s, "%"SLEN_P"i%n", ret, &n)<1 || s[n]!='\0';
+  return sscanf(s, "%" SLEN_P "i%n", ret, &n)<1 || s[n]!='\0';
 }
 
 /** @param b: assume null-terminated @return true on error */
@@ -700,7 +693,7 @@ int main(int argc, char**argv) {
   getotag("Abbr");
   getkey("acount");  acount=getuintval();
   getkey("xcount");  xcount=getuintval();
-  sprintf(tmp,"%"SLEN_P"u dict%%</I>", acount+xcount);
+  sprintf(tmp,"%" SLEN_P "u dict%%</I>", acount+xcount);
   setifmt(tmp,0); copy("I"); noifmt();
   gettagbeg();
 
