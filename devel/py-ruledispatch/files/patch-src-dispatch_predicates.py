--- src/dispatch/predicates.py.orig	2009-05-14 22:55:57.000000000 +0200
+++ src/dispatch/predicates.py	2009-05-14 22:56:15.000000000 +0200
@@ -236,7 +236,7 @@
 
         return or_, (EXPR_GETTER_ID,)
 
-    [as(classmethod)]
+    [fas(classmethod)]
     def immediate(klass,seq):
         for item in seq:
             if item:
@@ -260,7 +260,7 @@
 
         return and_, (EXPR_GETTER_ID,)
 
-    [as(classmethod)]
+    [fas(classmethod)]
     def immediate(klass,seq):
         for item in seq:
             if not item:
@@ -278,7 +278,7 @@
             return get(argIds[2])
         return ifelse, (EXPR_GETTER_ID,)
 
-    [as(classmethod)]
+    [fas(classmethod)]
     def immediate(klass,seq):
         if seq[1]: return seq[0]
         return seq[2]
