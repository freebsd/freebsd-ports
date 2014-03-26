$NetBSD: patch-ah,v 1.1 2010/12/17 09:40:14 wiz Exp $

From upstream SVN.

--- src/ir/omake_value_type.ml.orig	2010-10-07 19:59:08.000000000 +0000
+++ src/ir/omake_value_type.ml
@@ -162,7 +162,7 @@ type path =
  *)
 type command =
    CommandSection of value * free_vars * exp list   (* Name of the section, its free variables, and the expression *)
- | CommandValue of loc * value
+ | CommandValue of loc * env * string_exp
 
 (*
  * Kinds of rules.
