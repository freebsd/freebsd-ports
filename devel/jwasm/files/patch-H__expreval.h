--- H/expreval.h.orig
+++ H/expreval.h
@@ -130,6 +130,7 @@
     EXPF_IN_SQBR   = 8   /* private flag, used inside expreval.c only */
 };
 
+extern void         EmitConstError( const struct expr * );
 extern ret_code     EvalOperand( int *, struct asm_tok[], int, struct expr *, uint_8 );
 extern void         ExprEvalInit( void );
 
