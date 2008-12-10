signature ML_TOKENS =
sig
type ('a,'b) token
type svalue
val PRIM:  'a * 'a -> (svalue,'a) token
val SYMBOL:  'a * 'a -> (svalue,'a) token
val IMPORT:  'a * 'a -> (svalue,'a) token
val EXPORT:  'a * 'a -> (svalue,'a) token
val ADDRESS:  'a * 'a -> (svalue,'a) token
val CONST:  'a * 'a -> (svalue,'a) token
val COMMAND_LINE_CONST:  'a * 'a -> (svalue,'a) token
val BUILD_CONST:  'a * 'a -> (svalue,'a) token
val WITHTYPE:  'a * 'a -> (svalue,'a) token
val WITH:  'a * 'a -> (svalue,'a) token
val WILD:  'a * 'a -> (svalue,'a) token
val WHILE:  'a * 'a -> (svalue,'a) token
val WHERE:  'a * 'a -> (svalue,'a) token
val VAL:  'a * 'a -> (svalue,'a) token
val TYPE:  'a * 'a -> (svalue,'a) token
val THEN:  'a * 'a -> (svalue,'a) token
val STRUCTURE:  'a * 'a -> (svalue,'a) token
val STRUCT:  'a * 'a -> (svalue,'a) token
val SIGNATURE:  'a * 'a -> (svalue,'a) token
val SIG:  'a * 'a -> (svalue,'a) token
val SHARING:  'a * 'a -> (svalue,'a) token
val SEMICOLON:  'a * 'a -> (svalue,'a) token
val RPAREN:  'a * 'a -> (svalue,'a) token
val REC:  'a * 'a -> (svalue,'a) token
val RBRACKET:  'a * 'a -> (svalue,'a) token
val RBRACE:  'a * 'a -> (svalue,'a) token
val RAISE:  'a * 'a -> (svalue,'a) token
val OVERLOAD:  'a * 'a -> (svalue,'a) token
val OPEN:  'a * 'a -> (svalue,'a) token
val OP:  'a * 'a -> (svalue,'a) token
val OF:  'a * 'a -> (svalue,'a) token
val ORELSE:  'a * 'a -> (svalue,'a) token
val NONFIX:  'a * 'a -> (svalue,'a) token
val LPAREN:  'a * 'a -> (svalue,'a) token
val LOCAL:  'a * 'a -> (svalue,'a) token
val LET:  'a * 'a -> (svalue,'a) token
val LBRACKET:  'a * 'a -> (svalue,'a) token
val LBRACE:  'a * 'a -> (svalue,'a) token
val INFIXR:  'a * 'a -> (svalue,'a) token
val INFIX:  'a * 'a -> (svalue,'a) token
val INCLUDE:  'a * 'a -> (svalue,'a) token
val IN:  'a * 'a -> (svalue,'a) token
val IF:  'a * 'a -> (svalue,'a) token
val HASH:  'a * 'a -> (svalue,'a) token
val HANDLE:  'a * 'a -> (svalue,'a) token
val FUNCTOR:  'a * 'a -> (svalue,'a) token
val FUN:  'a * 'a -> (svalue,'a) token
val FN:  'a * 'a -> (svalue,'a) token
val DARROW:  'a * 'a -> (svalue,'a) token
val DO:  'a * 'a -> (svalue,'a) token
val EXCEPTION:  'a * 'a -> (svalue,'a) token
val EQTYPE:  'a * 'a -> (svalue,'a) token
val EQUALOP:  'a * 'a -> (svalue,'a) token
val EOF:  'a * 'a -> (svalue,'a) token
val END:  'a * 'a -> (svalue,'a) token
val ELSE:  'a * 'a -> (svalue,'a) token
val DOTDOTDOT:  'a * 'a -> (svalue,'a) token
val DATATYPE:  'a * 'a -> (svalue,'a) token
val COMMA:  'a * 'a -> (svalue,'a) token
val COLONGT:  'a * 'a -> (svalue,'a) token
val COLON:  'a * 'a -> (svalue,'a) token
val CASE:  'a * 'a -> (svalue,'a) token
val BAR:  'a * 'a -> (svalue,'a) token
val ASTERISK:  'a * 'a -> (svalue,'a) token
val AS:  'a * 'a -> (svalue,'a) token
val ARROW:  'a * 'a -> (svalue,'a) token
val ANDALSO:  'a * 'a -> (svalue,'a) token
val AND:  'a * 'a -> (svalue,'a) token
val ABSTYPE:  'a * 'a -> (svalue,'a) token
val WORD: ({ digits:string,radix:StringCvt.radix } ) *  'a * 'a -> (svalue,'a) token
val TYVAR: (string) *  'a * 'a -> (svalue,'a) token
val STRING: (IntInf.t vector) *  'a * 'a -> (svalue,'a) token
val REAL: (string) *  'a * 'a -> (svalue,'a) token
val LONGID: (string) *  'a * 'a -> (svalue,'a) token
val INT: ({ digits:string,negate:bool,radix:StringCvt.radix } ) *  'a * 'a -> (svalue,'a) token
val CHAR: (IntInf.t) *  'a * 'a -> (svalue,'a) token
end
signature ML_LRVALS=
sig
structure Tokens : ML_TOKENS
structure ParserData:PARSER_DATA
sharing type ParserData.Token.token = Tokens.token
sharing type ParserData.svalue = Tokens.svalue
end
