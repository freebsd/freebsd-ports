--- libs/wxservdisc/wxServDisc.cpp.orig	2020-07-15 18:02:29 UTC
+++ libs/wxservdisc/wxServDisc.cpp
@@ -42,11 +42,9 @@
 
 
 // Compatability defines
-#ifdef __APPLE__
 #ifndef IPV6_ADD_MEMBERSHIP
 #define IPV6_ADD_MEMBERSHIP IPV6_JOIN_GROUP
 #define IPV6_DROP_MEMBERSHIP IPV6_LEAVE_GROUP
-#endif
 #endif
 
 
