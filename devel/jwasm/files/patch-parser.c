--- parser.c.orig
+++ parser.c
@@ -787,16 +787,6 @@
     return( NOT_ERROR );
 }
 
-void EmitConstError( const struct expr *opnd )
-/********************************************/
-{
-    if ( opnd->hlvalue != 0 )
-        EmitErr( CONSTANT_VALUE_TOO_LARGE_EX, opnd->hlvalue, opnd->value64 );
-    else
-        EmitErr( CONSTANT_VALUE_TOO_LARGE, opnd->value64 );
-    return;
-}
-
 /* get an immediate operand without a fixup.
  * output:
  * - ERROR: error
