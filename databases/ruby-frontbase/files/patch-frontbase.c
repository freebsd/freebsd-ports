--- frontbase.c.orig	2006-04-15 07:57:23.000000000 +1000
+++ frontbase.c	2008-05-29 12:55:37.000000000 +1000
@@ -9,57 +9,10 @@
 
 #include "ruby.h"
 
-#if defined(__APPLE__)
-#include "/Library/FrontBase/include/FBCAccess/FBCAccess.h"
-#else
-#warning I don't know where FBCAccess.h is installed on non-OSX platforms
-#include "/Library/FrontBase/include/FBCAccess/FBCAccess.h"
-#endif
+#include "/usr/local/include/FBCAccess/FBCAccess.h"
 
 #pragma mark --- structure definitions ---
 
-typedef struct FBCLob
-{
-   unsigned char  kind;               // 0 => direct, 1 => indirect
-   char           handleAsString[28]; // @'<24 hex digits>'\0
-} FBCLob;
-
-typedef union FBCColumn FBCColumn;
-
-union FBCColumn
-{
-   char               tinyInteger;
-   short              shortInteger;
-   int                integer;
-   int                primaryKey;
-   long long          longInteger;
-   unsigned char      boolean;
-   char               character[0x7fffffff];
-   double             numeric;
-   double             real;
-   double             decimal;
-   FBCBitValue        bit;
-   char               date[11];   // YYYY-MM-DD
-   int                unformattedDate;
-   char               time[9];    // HH:MM:SS
-   char               timeTZ[34];   // YYYY-MM-DD HH:MM:SS.sssss+HH:MM
-   char               timestampTZ[34];
-   char               timestamp[28];
-   char               yearMonth[64];    
-   char               dayTime[32];  //  days:hh:ss.ffffff
-   FBCLob             blob;
-   FBCLob             clob;
-   double             rawDate;
-   FBCUnformattedTime rawTime;
-   FBCUnformattedTime rawTimeTZ;
-   FBCUnformattedTime rawTimestamp;
-   FBCUnformattedTime rawTimestampTZ;
-   int                rawYearMonth;
-   double             rawDayTime;
-};
-
-typedef FBCColumn* FBCRow;
-
 struct fbsqlconnect
 {
    int port;
