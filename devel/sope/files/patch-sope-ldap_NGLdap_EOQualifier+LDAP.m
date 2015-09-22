--- sope-ldap/NGLdap/EOQualifier+LDAP.m.orig	2015-09-16 18:26:50 UTC
+++ sope-ldap/NGLdap/EOQualifier+LDAP.m
@@ -26,7 +26,7 @@
 #define sel_eq(sel1, sel2) ((sel1)) == ((sel2))
 #endif
 
-#if __GNU_LIBOBJC__ >= 20100911
+#if (defined(__GNU_LIBOBJC__) && (__GNU_LIBOBJC__ >= 20100911)) || defined(APPLE_RUNTIME) || defined(__GNUSTEP_RUNTIME__)
 #  define sel_eq(__A__,__B__) sel_isEqual(__A__,__B__)
 #endif
 
