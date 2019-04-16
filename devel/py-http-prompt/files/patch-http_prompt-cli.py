Obtained from:	https://github.com/jonathanslenders/http-prompt/commit/34de86178d8ae2b478e0ad989222aab24dd4c046
		https://github.com/jonathanslenders/http-prompt/commit/d3d84de2aa7f3fce521e5ac63f4bbcf9a2166501

--- http_prompt/cli.py.orig	2018-11-04 14:03:53 UTC
+++ http_prompt/cli.py
@@ -9,11 +9,11 @@ import click
 
 from httpie.plugins import FormatterPlugin  # noqa, avoid cyclic import
 from httpie.output.formatters.colors import Solarized256Style
-from prompt_toolkit import prompt, AbortAction
+from prompt_toolkit import prompt
 from prompt_toolkit.auto_suggest import AutoSuggestFromHistory
 from prompt_toolkit.history import FileHistory
-from prompt_toolkit.layout.lexers import PygmentsLexer
-from prompt_toolkit.styles.from_pygments import style_from_pygments
+from prompt_toolkit.lexers import PygmentsLexer
+from prompt_toolkit.styles.pygments import style_from_pygments_cls
 from pygments.styles import get_style_by_name
 from pygments.util import ClassNotFound
 from six.moves.http_cookies import SimpleCookie
@@ -135,7 +135,7 @@ def cli(spec, env, url, http_options):
         style_class = get_style_by_name(cfg['command_style'])
     except ClassNotFound:
         style_class = Solarized256Style
-    style = style_from_pygments(style_class)
+    style = style_from_pygments_cls(style_class)
 
     listener = ExecutionListener(cfg)
 
@@ -159,7 +159,9 @@ def cli(spec, env, url, http_options):
             text = prompt('%s> ' % context.url, completer=completer,
                           lexer=lexer, style=style, history=history,
                           auto_suggest=AutoSuggestFromHistory(),
-                          on_abort=AbortAction.RETRY, vi_mode=cfg['vi'])
+                          vi_mode=cfg['vi'])
+        except KeyboardInterrupt:
+            continue  # Control-C pressed
         except EOFError:
             break  # Control-D pressed
         else:
