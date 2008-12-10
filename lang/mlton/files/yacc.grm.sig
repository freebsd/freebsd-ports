signature Mlyacc_TOKENS =
sig
type ('a,'b) token
type svalue
val BOGUS_VALUE:  'a * 'a -> (svalue,'a) token
val UNKNOWN: (string) *  'a * 'a -> (svalue,'a) token
val VALUE:  'a * 'a -> (svalue,'a) token
val VERBOSE:  'a * 'a -> (svalue,'a) token
val TYVAR: (string) *  'a * 'a -> (svalue,'a) token
val TERM:  'a * 'a -> (svalue,'a) token
val START:  'a * 'a -> (svalue,'a) token
val SUBST:  'a * 'a -> (svalue,'a) token
val RPAREN:  'a * 'a -> (svalue,'a) token
val RBRACE:  'a * 'a -> (svalue,'a) token
val PROG: (string) *  'a * 'a -> (svalue,'a) token
val PREFER:  'a * 'a -> (svalue,'a) token
val PREC_TAG:  'a * 'a -> (svalue,'a) token
val PREC: (Header.prec) *  'a * 'a -> (svalue,'a) token
val PERCENT_TOKEN_SIG_INFO:  'a * 'a -> (svalue,'a) token
val PERCENT_ARG:  'a * 'a -> (svalue,'a) token
val PERCENT_POS:  'a * 'a -> (svalue,'a) token
val PERCENT_PURE:  'a * 'a -> (svalue,'a) token
val PERCENT_EOP:  'a * 'a -> (svalue,'a) token
val OF:  'a * 'a -> (svalue,'a) token
val NOSHIFT:  'a * 'a -> (svalue,'a) token
val NONTERM:  'a * 'a -> (svalue,'a) token
val NODEFAULT:  'a * 'a -> (svalue,'a) token
val NAME:  'a * 'a -> (svalue,'a) token
val LPAREN:  'a * 'a -> (svalue,'a) token
val LBRACE:  'a * 'a -> (svalue,'a) token
val KEYWORD:  'a * 'a -> (svalue,'a) token
val INT: (string) *  'a * 'a -> (svalue,'a) token
val PERCENT_HEADER:  'a * 'a -> (svalue,'a) token
val IDDOT: (string) *  'a * 'a -> (svalue,'a) token
val ID: (string*int) *  'a * 'a -> (svalue,'a) token
val HEADER: (string) *  'a * 'a -> (svalue,'a) token
val FOR:  'a * 'a -> (svalue,'a) token
val EOF:  'a * 'a -> (svalue,'a) token
val DELIMITER:  'a * 'a -> (svalue,'a) token
val COMMA:  'a * 'a -> (svalue,'a) token
val COLON:  'a * 'a -> (svalue,'a) token
val CHANGE:  'a * 'a -> (svalue,'a) token
val BAR:  'a * 'a -> (svalue,'a) token
val BLOCK:  'a * 'a -> (svalue,'a) token
val ASTERISK:  'a * 'a -> (svalue,'a) token
val ARROW:  'a * 'a -> (svalue,'a) token
end
signature Mlyacc_LRVALS=
sig
structure Tokens : Mlyacc_TOKENS
structure ParserData:PARSER_DATA
sharing type ParserData.Token.token = Tokens.token
sharing type ParserData.svalue = Tokens.svalue
end
