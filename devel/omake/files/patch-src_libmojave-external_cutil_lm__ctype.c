$NetBSD: patch-aj,v 1.1 2010/12/17 09:40:14 wiz Exp $

From upstream SVN.

--- src/libmojave-external/cutil/lm_ctype.c.orig	2006-12-01 21:13:14.000000000 +0000
+++ src/libmojave-external/cutil/lm_ctype.c
@@ -59,7 +59,7 @@ static value get_chars(int (*f)(int))
         if(f(i))
             *p++ = (char) i;
     }
-    s = alloc_string(p - buf);
+    s = caml_alloc_string(p - buf);
     memcpy(String_val(s), buf, p - buf);
     return s;
 }
