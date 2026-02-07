--- components.h.orig	2002-07-07 16:34:23.000000000 +0900
+++ components.h	2011-12-07 11:31:45.000000000 +0900
@@ -61,6 +61,8 @@
 #define HNUM  (PKIND*2)      // Number of pairs to pick up
 #define SCORENUM  10         // Number of people to register in high-score
 #define NAMELEN   28         // Length of name in high-score
+#define NBUFLEN  127         // Length of namebuf-1
+#define GECOSLEN (NBUFLEN-12)    // Length for GECOS field-1
 
 class Timer {
 private:

