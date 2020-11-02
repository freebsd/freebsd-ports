--- doc/source/_util/cql.py.orig	2020-10-03 15:05:17 UTC
+++ doc/source/_util/cql.py
@@ -26,7 +26,6 @@ from pygments.lexer import Lexer, RegexLexer, do_inser
 from pygments.token import Punctuation, Whitespace, Error, \
     Text, Comment, Operator, Keyword, Name, String, Number, Generic, Literal
 from pygments.lexers import get_lexer_by_name, ClassNotFound
-from pygments.util import iteritems
 
 __all__ = [ 'CQLLexer' ]
 
