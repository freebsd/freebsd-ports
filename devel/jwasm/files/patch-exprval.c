--- expreval.c.orig
+++ expreval.c
@@ -79,6 +79,16 @@
     LS_FAR32  = 0xFF06,
 };
 
+void EmitConstError( const struct expr *opnd )
+/********************************************/
+{
+    if ( opnd->hlvalue != 0 )
+        EmitErr( CONSTANT_VALUE_TOO_LARGE_EX, opnd->hlvalue, opnd->value64 );
+    else
+        EmitErr( CONSTANT_VALUE_TOO_LARGE, opnd->value64 );
+    return;
+}
+
 static const uint_16 tbaseptr[] = { T_BP, T_EBP
 #if AMD64_SUPPORT
 , T_RBP
