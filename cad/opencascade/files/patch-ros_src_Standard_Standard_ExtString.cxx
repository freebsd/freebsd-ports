--- ros/src/Standard/Standard_ExtString.cxx.orig	Fri Sep 21 10:02:01 2001
+++ ros/src/Standard/Standard_ExtString.cxx	Thu Aug 10 21:41:33 2006
@@ -40,7 +40,7 @@
 
   if ( (((long ) Value ) & 3 ) == 2 ) {
     aHashCode = Value[ 0 ] ;
-#if defined(WNT) || defined(DECOSF1) || defined(LININTEL)
+#if defined(WNT) || defined(DECOSF1) || defined(LININTEL) || defined(__FreeBSD__)
     aHashCode = aHashCode << 16 ;
 #endif
     aValue = &Value[1] ;
