$NetBSD: patch-ad,v 1.1 2010/12/17 09:40:14 wiz Exp $

From upstream SVN.

--- src/builtin/omake_builtin_target.ml.orig	2008-01-15 19:57:00.000000000 +0000
+++ src/builtin/omake_builtin_target.ml
@@ -221,8 +221,8 @@ let split_command venv (values1, lines1)
                match line with
                   CommandSection (_, _, e) ->
                      ValBody (e, ExportNone)
-                | CommandValue (_, v) ->
-                     v
+                | CommandValue (_, exp, v) ->
+                     ValStringExp(exp,v)
             in
                v :: lines) lines1 lines2
    in
