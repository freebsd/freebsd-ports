--- ./platform/emulator/urlc.cc.orig	Fri Sep 15 02:54:21 2000
+++ ./platform/emulator/urlc.cc	Sat Sep  3 18:46:09 2005
@@ -9,8 +9,8 @@
  *    Organization or Person (Year(s))
  * 
  *  Last change:
- *    $Date: 2000/09/15 06:54:21 $ by $Author: annan $
- *    $Revision: 1.40 $
+ *    $Date: 2005/05/19 17:48:45 $ by $Author: duchier $
+ *    $Revision: 1.40.18.1 $
  * 
  *  This file is part of Mozart, an implementation 
  *  of Oz 3:
@@ -203,7 +203,7 @@
 /* characters not to be escaped in HTTP requests.
    if I well understood RFC 1945! ##
    */
-static char URLC_hs[] = "%:@&=+$-_.!*'(),;/?";
+static char URLC_hs[] = "%:@&=+$-_.!*'(),;/?#";
 
 /* throw simulators */
 #define th1(reason) { clean(); return (reason); }
