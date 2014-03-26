$NetBSD: patch-ar,v 1.1 2010/12/17 09:40:14 wiz Exp $

From upstream SVN.

--- src/libmojave-external/stdlib/lm_string_util.ml.orig	2008-06-28 01:21:34.000000000 +0000
+++ src/libmojave-external/stdlib/lm_string_util.ml
@@ -613,18 +613,13 @@ let tokens_create wrap group =
  * Get the tokens list.
  *)
 let tokens_flush info =
-   let { tokens_group  = group;
-         tokens_list   = tokens;
-         tokens_prefix = prefix
-       } = info
-   in
    let tokens =
-      match prefix with
+      match info.tokens_prefix with
          NoPrefix ->
-            tokens
+            info.tokens_list
        | WordPrefix prefix
        | QuotePrefix (_, prefix) ->
-            group prefix :: tokens
+            info.tokens_group prefix :: info.tokens_list
    in
       List.rev tokens
 
@@ -632,38 +627,29 @@ let tokens_flush info =
  * End the current word.
  *)
 let tokens_break info =
-   let { tokens_group  = group;
-         tokens_list   = tokens;
-         tokens_prefix = prefix
-       } = info
-   in
-      match prefix with
-         NoPrefix ->
-            info
-       | WordPrefix prefix
-       | QuotePrefix (_, prefix) ->
-            { info with tokens_list   = group prefix :: tokens;
-                        tokens_prefix = NoPrefix
-            }
+   match info.tokens_prefix with
+      NoPrefix ->
+         info
+    | WordPrefix prefix
+    | QuotePrefix (_, prefix) ->
+         { info with tokens_list   = info.tokens_group prefix :: info.tokens_list;
+                     tokens_prefix = NoPrefix
+         }
 
 (*
  * Add a value directly.
  * This also performs a break.
  *)
 let tokens_atomic info x =
-   let { tokens_group  = group;
-         tokens_list   = tokens;
-         tokens_prefix = prefix
-       } = info
-   in
-      match prefix with
+   let tokens = info.tokens_list in
+      match info.tokens_prefix with
          NoPrefix ->
             { info with tokens_list   = x :: tokens;
                         tokens_prefix = NoPrefix
             }
        | WordPrefix prefix
        | QuotePrefix (_, prefix) ->
-            { info with tokens_list   = x :: group prefix :: tokens;
+            { info with tokens_list   = x :: info.tokens_group prefix :: tokens;
                         tokens_prefix = NoPrefix
             }
 
@@ -758,11 +744,8 @@ let tokens_string info s =
       if len = 0 then
          info
       else
-         let { tokens_list = tokens;
-               tokens_prefix = prefix
-             } = info
-         in
-            match prefix with
+         let tokens = info.tokens_list in
+            match info.tokens_prefix with
                NoPrefix ->
                   scan_white tokens 0
              | WordPrefix prefix ->
@@ -809,13 +792,11 @@ let buffer_get_token lexer s i len =
                BufChar
 
 let tokens_lex info s =
-   let { tokens_lexer       = lexer;
-         tokens_wrap_string = wrap_string;
-         tokens_wrap_data   = wrap_data;
-         tokens_wrap_token  = wrap_token;
-         tokens_group       = group
-       } = info
-   in
+   let lexer = info.tokens_lexer in
+   let wrap_string = info.tokens_wrap_string in
+   let wrap_data = info.tokens_wrap_data in
+   let wrap_token = info.tokens_wrap_token in
+   let group = info.tokens_group in
    let len = String.length s in
 
    (* Don't add empty strings *)
@@ -902,11 +883,8 @@ let tokens_lex info s =
       if len = 0 then
          info
       else
-         let { tokens_list = tokens;
-               tokens_prefix = prefix
-             } = info
-         in
-            match prefix with
+         let tokens = info.tokens_list in
+            match info.tokens_prefix with
                NoPrefix ->
                   scan_white tokens 0
              | WordPrefix prefix ->
