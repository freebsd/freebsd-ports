
$FreeBSD$

--- setup.py
+++ setup.py
@@ -94,7 +94,7 @@
         cc_extra.append("-DDL_HACK")
         extra_ext.append(Extension(name = "perl",
                                    sources = ["dlhack.c"],
-                                   libraries = ["dl"],
+                                   libraries = [],
                                    ))
         
 
