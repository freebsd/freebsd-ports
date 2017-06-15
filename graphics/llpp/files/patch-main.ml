Fix brightness increase key

Upstream commit: 35113fbe37a385e8a886288a86cf970ac85e742e

--- main.ml.orig	2017-02-01 01:49:58 UTC
+++ main.ml
@@ -5057,7 +5057,7 @@ let viewkeyboard key mask =
 
   | Ascii ('['|']' as c) ->
      conf.colorscale <-
-       bound (conf.colorscale +. (if c = '>' then 0.1 else -0.1)) 0.0 1.0;
+       bound (conf.colorscale +. (if c = ']' then 0.1 else -0.1)) 0.0 1.0;
      G.postRedisplay "brightness";
 
   | Ascii 'c' when state.mode = View ->
