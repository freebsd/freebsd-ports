--- AltairZ80/i86_ops.c.orig	2020-09-01 09:55:27 UTC
+++ AltairZ80/i86_ops.c
@@ -109,6 +109,7 @@ extern uint32 in(const uint32 Port);
 */
 
 extern uint8 parity_tab[];
+extern volatile int intr;
 
 static void i86op_illegal_op(PC_ENV *m)
 {
