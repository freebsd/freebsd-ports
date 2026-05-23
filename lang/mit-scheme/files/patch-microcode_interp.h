--- microcode/interp.h.orig	2022-09-07 06:01:33 UTC
+++ microcode/interp.h
@@ -93,7 +93,7 @@ USA.
   SCHEME_OBJECT * Will_Push_Limit;					\
 									\
   STACK_CHECK (N);							\
-  Will_Push_Limit = (STACK_LOC (- (N)))
+  Will_Push_Limit = (STACK_NEG (N))
 
 #define Pushed()							\
   if (STACK_LOCATIVE_ABOVE_P (stack_pointer, Will_Push_Limit))		\
