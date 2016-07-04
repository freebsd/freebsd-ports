$NetBSD: patch-ao,v 1.1 2010/12/17 09:40:14 wiz Exp $

From upstream SVN.

--- src/libmojave-external/cutil/lm_uname_ext.c.orig	2006-12-08 19:21:40.000000000 +0000
+++ src/libmojave-external/cutil/lm_uname_ext.c
@@ -147,21 +147,21 @@ value lm_uname(value x)
 
     /* Get sysinfo */
     if(uname(&name) < 0)
-        failwith("uname");
+        caml_failwith("uname");
 
     /* Copy data */
-    result = alloc_tuple(5);
+    result = caml_alloc_tuple(5);
     Field(result, 0) = Val_unit;
     Field(result, 1) = Val_unit;
     Field(result, 2) = Val_unit;
     Field(result, 3) = Val_unit;
     Field(result, 4) = Val_unit;
 
-    Field(result, 0) = copy_string(name.sysname);
-    Field(result, 1) = copy_string(name.nodename);
-    Field(result, 2) = copy_string(name.release);
-    Field(result, 3) = copy_string(name.version);
-    Field(result, 4) = copy_string(name.machine);
+    Field(result, 0) = caml_copy_string(name.sysname);
+    Field(result, 1) = caml_copy_string(name.nodename);
+    Field(result, 2) = caml_copy_string(name.release);
+    Field(result, 3) = caml_copy_string(name.version);
+    Field(result, 4) = caml_copy_string(name.machine);
 
     /* Return it */
     CAMLreturn(result);
