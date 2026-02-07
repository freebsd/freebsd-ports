--- tws.h.orig	2025-07-18 07:31:08 UTC
+++ tws.h
@@ -33,7 +33,7 @@ struct tws
 
 /* Declarations of routines. */
 
-struct tws *dlocaltime( );
+struct tws *dlocaltime( long * );
         /* dlocaltime( &clock ) turns a time(3) clock value into a tws */
 
 struct tws *dtwstime( );
