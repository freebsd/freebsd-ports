--- lib/util/wordaccess.h.orig	Tue Jun 29 23:20:25 2004
+++ lib/util/wordaccess.h	Mon Jul 26 23:08:10 2004
@@ -65,7 +65,7 @@
    exact same format as wordintBytes.  It's a simple matter of casting
    to fool the compiler.  
 */
-static __inline__ wordn
+static __inline__ wordint
 bytesToWordint(wordintBytes bytes) {
     return *((wordint *)bytes);
 }
