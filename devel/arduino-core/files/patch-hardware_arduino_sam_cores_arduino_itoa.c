--- hardware/arduino/sam/cores/arduino/itoa.c.orig	2016-10-14 15:00:06 UTC
+++ hardware/arduino/sam/cores/arduino/itoa.c
@@ -121,7 +121,7 @@ extern char* ltoa( long value, char *str
   return string;
 }
 
-extern char* utoa( unsigned long value, char *string, int radix )
+extern char* utoa( unsigned int value, char *string, int radix )
 {
   return ultoa( value, string, radix ) ;
 }
