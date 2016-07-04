$NetBSD: patch-al,v 1.1 2010/12/17 09:40:14 wiz Exp $

From upstream SVN.

--- src/libmojave-external/cutil/lm_printf.c.orig	2009-02-06 16:41:21.000000000 +0000
+++ src/libmojave-external/cutil/lm_printf.c
@@ -61,12 +61,12 @@ value ml_print_char(value v_fmt, value v
     char c = (char) Int_val(v_char);
 #ifdef HAVE_SNPRINTF
     if(snprintf(buffer, sizeof(buffer), fmt, c) < 0)
-        failwith("ml_print_char");
+        caml_failwith("ml_print_char");
 #else
     if(sprintf(buffer, fmt, c) < 0)
-        failwith("ml_print_char");
+        caml_failwith("ml_print_char");
 #endif
-    return copy_string(buffer);
+    return caml_copy_string(buffer);
 }
 
 /*
@@ -79,12 +79,12 @@ value ml_print_int(value v_fmt, value v_
     int i = Int_val(v_int);
 #ifdef HAVE_SNPRINTF
     if(snprintf(buffer, sizeof(buffer), fmt, i) < 0)
-        failwith("ml_print_int");
+        caml_failwith("ml_print_int");
 #else
     if(sprintf(buffer, fmt, i) < 0)
-        failwith("ml_print_int");
+        caml_failwith("ml_print_int");
 #endif
-    return copy_string(buffer);
+    return caml_copy_string(buffer);
 }
 
 
@@ -98,12 +98,12 @@ value ml_print_float(value v_fmt, value 
     double x = Double_val(v_float);
 #ifdef HAVE_SNPRINTF
     if(snprintf(buffer, sizeof(buffer), fmt, x) < 0)
-        failwith("ml_print_float");
+        caml_failwith("ml_print_float");
 #else
     if(sprintf(buffer, fmt, x) < 0)
-        failwith("ml_print_float");
+        caml_failwith("ml_print_float");
 #endif
-    return copy_string(buffer);
+    return caml_copy_string(buffer);
 }
 
 /*
@@ -132,7 +132,7 @@ value ml_print_string(value v_fmt, value
         size = len * 2;
         bufp = malloc(size);
         if(bufp == 0)
-            failwith("ml_print_string");
+            caml_failwith("ml_print_string");
     }
 
 #ifdef HAVE_SNPRINTF
@@ -143,9 +143,9 @@ value ml_print_string(value v_fmt, value
     if(code < 0) {
         if(bufp != buffer)
             free(bufp);
-        failwith("ml_print_string");
+        caml_failwith("ml_print_string");
     }
-    v_result = copy_string(bufp);
+    v_result = caml_copy_string(bufp);
     if(bufp != buffer)
         free(bufp);
     return v_result;
@@ -180,7 +180,7 @@ value ml_print_string2(value v_width, va
         size = len * 2;
         bufp = malloc(size);
         if(bufp == 0)
-            failwith("ml_print_string");
+            caml_failwith("ml_print_string");
     }
 
 #ifdef HAVE_SNPRINTF
@@ -191,9 +191,9 @@ value ml_print_string2(value v_width, va
     if(code < 0) {
         if(bufp != buffer)
             free(bufp);
-        failwith("ml_print_string");
+        caml_failwith("ml_print_string");
     }
-    v_result = copy_string(bufp);
+    v_result = caml_copy_string(bufp);
     if(bufp != buffer)
         free(bufp);
     return v_result;
