--- handy.h.orig	2020-12-18 10:04:36 UTC
+++ handy.h
@@ -1288,7 +1288,7 @@ or casts
 #define inRANGE(c, l, u) (__ASSERT_((u) >= (l))                                \
    (  (sizeof(c) == sizeof(U8))  ? withinCOUNT(((U8)  (c)), (l), ((u) - (l)))  \
     : (sizeof(c) == sizeof(U32)) ? withinCOUNT(((U32) (c)), (l), ((u) - (l)))  \
-    : (__ASSERT_(sizeof(c) == sizeof(WIDEST_UTYPE))                            \
+    : (__ASSERT_(sizeof(c) == sizeof(WIDEST_UTYPE) || sizeof(c) == sizeof(UV)) \
                           withinCOUNT(((WIDEST_UTYPE) (c)), (l), ((u) - (l))))))
 
 #ifdef EBCDIC
