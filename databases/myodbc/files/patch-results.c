--- results.c	4 Dec 2001 18:47:05 -0000	1.1
+++ results.c	2 Mar 2002 18:18:21 -0000	1.2
@@ -743,14 +743,14 @@
   case SQL_C_SBIGINT:
   {
     if (rgbValue)
-      *((longlong*) rgbValue)= atoll(value);
+      *((longlong*) rgbValue)= strtoll(value, NULL, 10);
     *pcbValue=sizeof(longlong);
     break;
   }
   case SQL_C_UBIGINT:
   {
     if (rgbValue)
-      *((ulonglong*) rgbValue)= (ulonglong) atoll(value);
+      *((ulonglong*) rgbValue)= strtoull(value, NULL, 10);
     *pcbValue=sizeof(ulonglong);
     break;
   }
