--- H/parser.h.orig
+++ H/parser.h
@@ -302,7 +302,6 @@
 extern ret_code   MemtypeFromSize( int, enum memtype * );
 extern int        SizeFromRegister( int );
 extern ret_code   GetLangType( int *, struct asm_tok[], enum lang_type * );
-extern void       EmitConstError( const struct expr * );
 
 extern void       sym_add_table( struct symbol_queue *, struct dsym * );
 extern void       sym_remove_table( struct symbol_queue *, struct dsym * );
