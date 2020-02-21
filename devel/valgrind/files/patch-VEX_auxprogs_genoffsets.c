--- VEX/auxprogs/genoffsets.c	2016-01-13 19:20:20 UTC
+++ VEX/auxprogs/genoffsets.c
@@ -59,7 +59,7 @@
 #define VG_STRINGIFZ(__str)  #__str
 #define VG_STRINGIFY(__str)  VG_STRINGIFZ(__str)
 
-#define my_offsetof(__type,__field) (&((__type*)0)->__field)
+#define my_offsetof(__type,__field) offsetof(__type,__field)
 
 /* This forces gcc to evaluate the my_offsetof call at compile time,
    and then emits it in the assembly, along with the nonsense string
