Backport of [1] to handle the 'L' integer suffix.

[1] https://code.qt.io/cgit/qt/qtbase.git/commit/?id=f0039bd5170ad84d972a023316e8d153b89f841a

--- src/tools/moc/preprocessor.cpp.orig	2025-11-01 21:43:44 UTC
+++ src/tools/moc/preprocessor.cpp
@@ -247,7 +247,8 @@ Symbols Preprocessor::tokenize(const QByteArray& input
                             ++data;
                             while (is_hex_char(*data) || *data == '\'')
                                 ++data;
-                        }
+                        } else if (*data == 'L')
+                            ++data;
                         break;
                     }
                     token = FLOATING_LITERAL;
@@ -424,7 +425,8 @@ Symbols Preprocessor::tokenize(const QByteArray& input
                         ++data;
                         while (is_hex_char(*data) || *data == '\'')
                             ++data;
-                    }
+                    } else if (*data == 'L')
+                        ++data;
                     break;
                 }
                 token = PP_FLOATING_LITERAL;
@@ -951,7 +953,12 @@ int PP_Expression::primary_expression()
         test(PP_RPAREN);
     } else {
         next();
-        value = lexem().toInt(nullptr, 0);
+        const QByteArray &lex = lexem();
+        if (lex.endsWith('L')) {
+            value = lex.left(lex.size() - 1).toInt(nullptr, 0);
+        } else {
+            value = lex.toInt(nullptr, 0);
+        }
     }
     return value;
 }
