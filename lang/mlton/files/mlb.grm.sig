signature MLB_TOKENS =
sig
type ('a,'b) token
type svalue
val STRING: (string) *  'a * 'a -> (svalue,'a) token
val FILE: (string) *  'a * 'a -> (svalue,'a) token
val PRIM:  'a * 'a -> (svalue,'a) token
val ANN:  'a * 'a -> (svalue,'a) token
val STRUCTURE:  'a * 'a -> (svalue,'a) token
val SIGNATURE:  'a * 'a -> (svalue,'a) token
val OPEN:  'a * 'a -> (svalue,'a) token
val LOCAL:  'a * 'a -> (svalue,'a) token
val LET:  'a * 'a -> (svalue,'a) token
val IN:  'a * 'a -> (svalue,'a) token
val FUNCTOR:  'a * 'a -> (svalue,'a) token
val EQUALOP:  'a * 'a -> (svalue,'a) token
val END:  'a * 'a -> (svalue,'a) token
val BASIS:  'a * 'a -> (svalue,'a) token
val BAS:  'a * 'a -> (svalue,'a) token
val AND:  'a * 'a -> (svalue,'a) token
val EOF:  'a * 'a -> (svalue,'a) token
val SEMICOLON:  'a * 'a -> (svalue,'a) token
val COMMA:  'a * 'a -> (svalue,'a) token
val ID: (string) *  'a * 'a -> (svalue,'a) token
end
signature MLB_LRVALS=
sig
structure Tokens : MLB_TOKENS
structure ParserData:PARSER_DATA
sharing type ParserData.Token.token = Tokens.token
sharing type ParserData.svalue = Tokens.svalue
end
