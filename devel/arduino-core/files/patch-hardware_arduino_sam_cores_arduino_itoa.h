--- hardware/arduino/sam/cores/arduino/itoa.h.orig	2016-10-14 15:00:09 UTC
+++ hardware/arduino/sam/cores/arduino/itoa.h
@@ -31,7 +31,7 @@ extern void itoa( int n, char s[] ) ;
 
 extern char* itoa( int value, char *string, int radix ) ;
 extern char* ltoa( long value, char *string, int radix ) ;
-extern char* utoa( unsigned long value, char *string, int radix ) ;
+extern char* utoa( unsigned int value, char *string, int radix ) ;
 extern char* ultoa( unsigned long value, char *string, int radix ) ;
 #endif /* 0 */
 
