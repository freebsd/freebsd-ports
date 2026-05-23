--- microcode/stack.h.orig	2022-09-07 06:01:33 UTC
+++ microcode/stack.h
@@ -66,12 +66,13 @@ USA.
     stack_death (s);							\
 } while (false)
 
-#define CAN_PUSH_P(n) (SP_OK_P (STACK_LOC (- (n))))
+#define CAN_PUSH_P(n) (SP_OK_P (STACK_NEG (n)))
 #define SP_OK_P(sp) ((sp) >= stack_guard)
 
 #define STACK_LOCATIVE_DECREMENT(locative) (-- (locative))
 #define STACK_LOCATIVE_INCREMENT(locative) ((locative) ++)
-#define STACK_LOCATIVE_OFFSET(locative, offset) ((locative) + (offset))
+#define STACK_LOCATIVE_ADD(locative, offset) ((locative) + (offset))
+#define STACK_LOCATIVE_SUB(locative, offset) ((locative) - (offset))
 #define STACK_LOCATIVE_REFERENCE(locative, offset) ((locative) [(offset)])
 #define STACK_LOCATIVE_DIFFERENCE(newer, older) ((older) - (newer))
 #define STACK_LOCATIVE_ABOVE_P(loc1, loc2) ((loc1) < (loc2))
@@ -88,5 +89,6 @@ USA.
 
 #define STACK_PUSH(object) (STACK_LOCATIVE_PUSH (stack_pointer)) = (object)
 #define STACK_POP() (STACK_LOCATIVE_POP (stack_pointer))
-#define STACK_LOC(offset) (STACK_LOCATIVE_OFFSET (stack_pointer, (offset)))
+#define STACK_LOC(offset) (STACK_LOCATIVE_ADD (stack_pointer, (offset)))
+#define STACK_NEG(offset) (STACK_LOCATIVE_SUB (stack_pointer, (offset)))
 #define STACK_REF(offset) (STACK_LOCATIVE_REFERENCE (stack_pointer, (offset)))
