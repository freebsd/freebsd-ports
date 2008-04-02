--- unzip-5.52.orig/unzpriv.h
+++ unzpriv.h
@@ -1081,6 +1081,7 @@
 #  define FOPR  "r","ctx=stm"
 #  define FOPM  "r+","ctx=stm","rfm=fix","mrs=512"
 #  define FOPW  "w","ctx=stm","rfm=fix","mrs=512"
+#  define FOPWR "w+","ctx=stm","rfm=fix","mrs=512"
 #endif /* VMS */
 
 #ifdef CMS_MVS
@@ -1117,6 +1118,9 @@
 #  ifndef FOPWT
 #    define FOPWT "wt"
 #  endif
+#  ifndef FOPWR
+#    define FOPWR "w+b"
+#  endif
 #else /* !MODERN */
 #  ifndef FOPR
 #    define FOPR "r"
@@ -1130,6 +1134,9 @@
 #  ifndef FOPWT
 #    define FOPWT "w"
 #  endif
+#  ifndef FOPWR
+#    define FOPWR "w+b"
+#  endif
 #endif /* ?MODERN */
 
 /*
