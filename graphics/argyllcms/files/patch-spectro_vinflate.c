--- spectro/vinflate.c.orig	2020-08-19 12:08:33 UTC
+++ spectro/vinflate.c
@@ -92,7 +92,7 @@ int vinflate(void);
 */
 
 #define WSIZE 0x8000
-unsigned int wp;             /* current position in slide */
+extern unsigned int wp;             /* current position in slide */
 uch slide[32768];
 
 static int vflush_output(unsigned int w) {
@@ -160,8 +160,8 @@ static ush cpdext[] = {         /* Extra bits for dist
    the stream.
  */
 
-ulg bb;                         /* bit buffer */
-unsigned bk;                    /* bits in bit buffer */
+extern ulg bb;                         /* bit buffer */
+extern unsigned bk;                    /* bits in bit buffer */
 
 ush vmask_bits[] = {
     0x0000,
@@ -239,7 +239,7 @@ int vdbits = 6;          /* bits in base distance look
 #define N_MAX 288       /* maximum number of codes in any set */
 
 
-unsigned hufts;         /* track memory usage */
+extern unsigned hufts;         /* track memory usage */
 
 /* Given a list of code lengths and a maximum table size, make a set of
    tables to decode that set of codes.  Return zero on success, one if
