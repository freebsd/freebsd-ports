--- src/scheme.h.orig	2022-12-03 07:29:22 UTC
+++ src/scheme.h
@@ -142,7 +142,7 @@ enum {
 
 //#define UC(a) (reinterpret_cast<const ucs4char*>(L##""a))
 
-typedef int32_t ucs4char; // use -1 for EOF
+typedef char32_t ucs4char; // use -1 for EOF
 
 // For Fixnum.
 // sizeof(fixedint) = 4 for 32 bits.
@@ -201,7 +201,7 @@ struct ltstr EXTEND_GC
               return false;
           }
       }
-    return(*s1 - *--s2) < 0;
+    return(*s1 < *--s2);
   }
 };
 
