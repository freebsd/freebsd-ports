--- asis/a4g-contt.ads.orig	Sun Dec 31 10:43:40 2006
+++ asis/a4g-contt.ads	Sun Dec 31 10:49:23 2006
@@ -425,7 +425,7 @@
       Parameters : String_Access;
       --  to keep the parameters set by the ASIS Associate routine
 
-      GCC : String_Access;
+      GCC : String_Access := new String'("/usr/local/bin/gnatgcc");
       --  If non-null, contains the full path to the compiler to be used when
       --  creating trees on the fly. (If null, the standard gcc/GNAT
       --  installation is used)
