--- gcc/gengenrtl.c.orig	2013-01-10 20:38:27 UTC
+++ gcc/gengenrtl.c
@@ -52,7 +52,7 @@ type_from_format (int c)
       return "int ";
 
     case 'w':
-      return "HOST_WIDE_INT ";
+      return " HOST_WIDE_INT ";
 
     case 's':
       return "const char *";
